#include <stdio.h>
#include <stdlib.h> 
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define MAXWORDS	888
#define MAXSTRING	888

struct st { //this struct keeps track word frequency of entire file
    char s[MAXSTRING];
    int count;
};
struct detail { //this struct counts unique word per tweet
    char word[MAXSTRING];
    int freq;
};
void insert_word (struct st *words, int *n, char *s) {
	int	i;
	/* linear search for the word */
	for (i=0; i<*n; i++) if (strcmp (s, words[i].s) == 0) {
		/* if string equal increment and return. */
		words[i].count++;
		return;
	}
	/* error conditions... */
	if (strlen (s) >= MAXSTRING) {
		fprintf (stderr, "word too long!\n");
		exit (1);
	}
	if (*n >= MAXWORDS) {	
		fprintf (stderr, "too many words!\n");
		exit (1);
	}
	strcpy (words[*n].s, s); //copy the word into struct
	words[*n].count = 1; //this word occurs once
	(*n)++;
}
/* return 1 if c is keyboard characters, 0 otherwise */
int keybo_char (char c) {
	if (c >= '!' && c <= '~') return 1; 
	return 0;
}
void modify_format (char *s) {
	int	i;
	for (i=0; s[i]; i++) {
		if (!keybo_char (s[i])) {
			while (s[i]) {
				i++;
				s[i-1] = s[i];
			}
			s[i] = 0;
		}
	}
}

/* qsort struct comparison function */ 
int struct_cmp(const void *a, const void *b) 
{ 
    struct st *ia = (struct st *)a;
    struct st *ib = (struct st *)b;
    return strcmp(ia->s, ib->s);
} 
 
/* Function of struct array printing and writing into file */ 
void print_struct_array(struct st *array, size_t len, FILE *f) 
{ 
    size_t i=0, j=0;
	int repeat=0;
	for(i=0; i<len; i++) {
		if(array[i].count==0) j++;
		else break;
	}
	fseek(f, 0, SEEK_SET);  //go back to the beginning of file to start writting
	for(i=j; i<len; i++){
        printf("%s\t\t  %d\n", array[i].s, array[i].count);//printout result
		fprintf(f, "%s\t\t %d\n", array[i].s, array[i].count);//write into wc_output.txt
		
	}
	puts("---------- ");
} 

double median(int n, int x[]) {
	double temp;
    int i, j;
    // sort the array x in ascending order
    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(x[j] < x[i]) {
                // swap elements
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }
    if(n%2==0) {
        // if there is an even number of elements, return mean of the two elements in the middle
        return((x[n/2] + x[n/2 - 1]) / 2.0);
    } else {
        // else return the element in the middle
        return x[n/2];
    }
}
int update(struct detail s[], const char unit[], int count)
{
    int i; 
    for (i = 0; i < count; i++)
    {
        if (strcmp(s[i].word, unit) == 0)
        {
            s[i].freq++;
 
            return count;
        }
    }
    /*If control reaches here, it means no match found in struct*/
    strcpy(s[count].word, unit);
    s[count].freq++; 
    /*count represents the number of fields updated in array s*/
    return (count + 1);
}
int main(int argc, char *argv[]){
	DIR *dip;
	struct dirent *dit;
	int i=0, j=0, k=0;
	struct st structs[MAXWORDS] = {};
	struct detail s2[MAXWORDS] = {};
	char s[MAXWORDS];
	char string[MAXWORDS];
	char unit[MAXWORDS];
	int x[MAXWORDS];
	int n=0, count=0, repeat=0, num_word=0;
	double median(int,int[]);
	FILE *f;
	FILE *f2;
	FILE *f3;
    	char ch;
/****Change the path name here****************/
	char text_name[MAXSTRING]= "./tweet_input/"; 
	char input_path[MAXSTRING] = "./tweet_input/"; 
	char ft1[MAXSTRING] ="./tweet_output/ft1.txt";
	char median_temp[MAXSTRING]="median_temp.txt";
	char ft2[MAXSTRING]="./tweet_output/ft2.txt";
	char tweet_temp[MAXSTRING] ="tweet_temp.txt";
	char f_temp[MAXSTRING] ="f_temp.txt";
/*********************************************/
	if (argc < 2){	//check to see if user entered a directory name
		printf("Usage: %s <directory>\n", argv[0]);
		return 0;
	}
	if((dip=opendir(argv[1])) == NULL){
		perror("opendir");
		return 0;
	}
/****** Open and Sort the files into desire format ***********/
	printf("Directory tweet_input is now open\n");
	while((dit = readdir(dip))  != NULL){ //read all the text files
		if (!strcmp (dit->d_name, ".")) //skip parental file
            continue;
        if (!strcmp (dit->d_name, "..")) //skip parental file
            continue;
	   strcpy(text_name, input_path); //prepare correct file names
	   strcat(text_name,dit->d_name);
	   //printf("%s\n",text_name); //display files name
		f = fopen(text_name,"r"); //open files
		f2 = fopen(tweet_temp,"w");
		while( ( ch = fgetc(f) ) != EOF ){
			if (ch=='\n') {
				fseek(f2,SEEK_CUR-2,SEEK_END);
				fputc(' ',f2);
			}
			fputc(ch,f2); //write to tweet_temp;		  
	   }
	   fputc(' ',f2);  //adjust off for word counting
	   fputc('\n',f2);  //adjust off
	}
	printf("---------- \n");
	fclose(f);	
	fclose(f2);
/********************************************************/
/* Calculate the median number of unique words per tweet *****/
	f = fopen (tweet_temp, "r"); //read from sorted tweet_temp
	if (f==NULL) perror ("Error opening file");
	f2 = fopen (ft1, "w"); //write to ft1
	f3 = fopen (ft2, "w"); //write to ft2
	i=0;	j=0;	k=0;

	while (( ch = fgetc(f) ) != EOF ) { 
		string[j++] = ch; //string store tweet
		if(ch=='\n') 	{ //count number of word per line		
			j=0;	 count=0; repeat=0;	//reset parameter for each tweet	
			memset(&s2, 0, sizeof s2); //reset struct
	
			for (i = 0; i < strlen(string); i++) {
				while (i < strlen(string) && string[i] != ' '&&string[i] >= '!' && string[i] <= '~') {
					unit[j++] = string[i++];
				}
				if (j != 0) {
					unit[j] = '\0';					
					count = update(s2, unit, count); //count unique word
					j = 0;
				}
			}
			x[k]=count;		
			k++; 
			//printf("\tunique word: %d\n",count);
			printf("%.2f\n",median(k,x));
		    fprintf(f3, "%.2f\n",median(k,x)); //write to ft2

			num_word=0; //reset word counter after each tweet
			memset(string,0,strlen(string)); //reset memory to go for next tweet
		}
		if(ch==' ')  { //count number of word after separators
			num_word++;
			ch='\n';
		}
		fputc (ch, f2); //write into ft1		
	}
	printf("---------- \n");
	fclose(f);
	fclose(f2);
	fclose(f3);
/********************************************/	
/*** reopen sorted file to count word frequency ***/	
	f = fopen (ft1, "r+");
	if (f==NULL) printf ("Error opening file");
	n=0;
	while (fgets(s , MAXWORDS , f) !=NULL) {
		if (keybo_char (s[0])) {		
			modify_format (s);		//modify format		
			insert_word (structs, &n, s);	//put this word in the list 
		}
	}
/* quick sort using other comparision function by alphabert*/ 
	size_t structs_len = sizeof(structs) / sizeof(struct st);
	qsort(structs, structs_len, sizeof(struct st), struct_cmp);    
/**************************************************/
/****** print and write into tweet_output **************/ 
	print_struct_array(structs, structs_len,f);
	fclose(f);
/**************************************************/
/****** Close directory and End ************************/ 
	if(closedir(dip) == -1){
		perror("closedir");
		return 0;
	}
	printf("\nDirectory tweet_input is now close\n");
	return 1;
}
