#include <stdio.h>
#include <memory.h>

/*
Every email consists of a local name and a domain name, separated by the @ sign.

For example, in alice@leetcode.com, alice is the local name, and leetcode.com is the
 domain name.

Besides lowercase letters, these emails may contain '.'s or '+'s.

If you add periods ('.') between some characters in the local name part of an email address,
 mail sent there will be forwarded to the same address without dots in the local name.
 For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email
 address.  (Note that this rule does not apply for domain names.)

If you add a plus ('+') in the local name, everything after the first plus sign will be
 ignored. This allows certain emails to be filtered, for example m.y+name@email.com will
 be forwarded to my@email.com.  (Again, this rule does not apply for domain names.)

It is possible to use both of these rules at the same time.

Given a list of emails, we send one email to each address in the list.  How many different
 addresses actually receive mails?
*/

int numUniqueEmails(char ** emails, int emailsSize){
    char res[emailsSize][100];
    int ans = 0;
    for (int i = 0; i < emailsSize; i++) {
        size_t n = strlen(emails[i]);
        char local[n], domain[n];

        int j = 0, k = 0;
        while (emails[i][j] != '@') {
            if (emails[i][j] == '+') {
                while (emails[i][j] != '@') {
                    j++;
                }
                break;
            } else if (emails[i][j] != '.') {
                local[k++] = emails[i][j];
            }
            j++;
        }
        local[k] = '\0';
        k = 0;
        while (emails[i][j] != '\0') {
            domain[k++] = emails[i][j++];
        }
        domain[k] = '\0';

        int cnt = 0;
        char* email = NULL;
        email = strcat(local, domain);
        while (email[cnt] != '\0') {
            cnt++;
        }

        int check = 0;
        for (j = 0; j < i; j++) {
            for (k = 0; email[k] != '\0'; k++) {
                if (res[j][k] == email[k]) {
                    check++;
                } else {
                    break;
                }
            }
        }

        if (check == cnt) {
           ans++;
        } else {
            for (k = 0; email[k] != '\0'; k++) {
                res[i][k] = email[k];
            }
            res[i][k] = '\0';
        }



    }
    return emailsSize - ans;

}


int main() {
//    char* emails[] = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
    char* emails[] = {"testemail@leetcode.com","testemail1@leetcode.com","testemail+david@lee.tcode.com"};
    int emailsSize = 3;
    printf("%d ", numUniqueEmails(emails, emailsSize));

    return 0;
}

