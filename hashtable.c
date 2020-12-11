#include "hashtable.h"

/*
 * ht_create() - If the size is a positive integer, allocate the requisite
 * memory for a new hashtable and its indexed array. Assign the size of the
 * array in ht->size.
 * size: The size of the hashtable's array.
 *
 * Return: A pointer to the newly allocated Hashtable. If size is zero or a
 * negative number, return NULL. If a memory allocation fails, return NULL.
 */
HashTable *ht_create(unsigned int size)
{
    HashTable *ht;

    if (size < 1) {
        return NULL;
    }

    ht = malloc(sizeof(HashTable));
    if (ht == NULL) {
        return (NULL);
    }

    ht->array = (List**)malloc(size * sizeof(List));
    if (ht->array == NULL) {
        return (NULL);
    }

    memset(ht->array, 0, size * sizeof(List));

    ht->size = size;

    return ht;
}

/*
 * hash() - Find the index of the key passed, or if it does not exist, return
 * an empty array index.
 * @key: The key to find in the hash table.
 * @size: The size of the hash table.
 *
 * Return: The index of the item.
 */
unsigned int hash(const char *key, unsigned int size)
{
    unsigned int hash;
    unsigned int i;

    hash = 0;
    i = 0;
    while (key && key[i]) {
        hash = (hash + key[i]) % size;
        ++i;
    }
    return (hash);
}

/*
 * ht_put() - Allocates memory for a new node and calls the node_handler
 * function to either insert the node if the key does not exist, or update
 * a prexisting node in the case that it has the same key as that passed
 * to this function.
 * @key: The key to add to the hash table.
 * @value: The corresponding value to add to the node.
 *
 * Return: 1 if memory allocation fails, and 0 if the function returns
 * successfully.
 */
int ht_put(HashTable *hashtable, const char *key, const char *value)
{
    List *node;

    if (hashtable == NULL) {
        return 1;
    }

    node = malloc(sizeof(List));
    if (node == NULL) {
        return 1;
    }

    node->key = strdup(key);
    node->value = strdup(value);

    node_handler(hashtable, node);

    return 0;
}

/*
 * node_handler() - If the index item is a linked list, traverse it to ensure
 * that there is not already an item with the key passed. If there is,
 * reassign the value of the prexisting node to the current instead of adding
 * the new node.
 * @hashtable: The hashtable of Lists.
 * @node: The linked list to add a node to or update.
 *
 * Return: Void.
 */
void node_handler(HashTable *hashtable, List *node)
{
    unsigned int i = hash(node->key, hashtable->size);
    List *tmp = hashtable->array[i];

    if (hashtable->array[i] != NULL) {
        tmp = hashtable->array[i];
        while (tmp != NULL) {
            if (strcmp(tmp->key, node->key) == 0) {
                break;
            }
            tmp = tmp->next;
        }
        if (tmp == NULL) {
            node->next = hashtable->array[i];
            hashtable->array[i] = node;
        } else {
            free(tmp->value);
            tmp->value = strdup(node->value);
            free(node->value);
            free(node->key);
            free(node);
        }
    } else {
        node->next = NULL;
        hashtable->array[i] = node;
    }
}

/*
 * ht_get() - Traverse the list that is at the corresponding array location in
 * the hashtable. If a node with the same key is found as that passed to this
 * function, then return the value of that node. Otherwise, return NULL,
 * indicating there is no node with the key passed. Before returning, free
 * the copy of the string `key_cp`.
 * @hashtable: The hashtable in which to search for the data.
 * @key: The key to search the hashtable for.
 *
 * Return: The value that corresponds to the key if it is found, and NULL
 * otherwise. If the hashtable is NULL, return NULL.
 */
char *ht_get(HashTable *hashtable, const char *key)
{
    char *key_cp;
    unsigned int i;
    List *tmp;

    if (hashtable == NULL) {
        return NULL;
    }
    key_cp = strdup(key);
    i = hash(key, hashtable->size);
    tmp = hashtable->array[i];

    while (tmp != NULL) {
        if (strcmp(tmp->key, key_cp) == 0) {
            break;
        }
        tmp = tmp->next;
    }
    free(key_cp);

    if (tmp == NULL) {
        return NULL;
    }
    return tmp->value;
}

/*
 * ht_free() - Free the items in a hashtable. Iterate through the hashtable's
 * array. If it is a linked list, then traverse the list and free all the
 * node's attributes and then the node itself. When the end of the list is
 * reached, free the array item itself (i.e., `hashtable->array[i]`). Finally,
 * when all the array items are freed, free the hashtable array pointer and
 * the hashtable itself.
 * @hashtable: The hashtable to free.
 *
 * Return: If the hashtable is NULL, return because there is nothing to free.
 */
void ht_free(HashTable *hashtable)
{
    List *tmp;
    unsigned int i;

    if (hashtable == NULL) {
        return;
    }

    for (i = 0; i < hashtable->size; ++i) {
        if (hashtable->array[i] != NULL) {
            /* Traverse the list and free the nodes. */
            while(hashtable->array[i] != NULL) {
                tmp = hashtable->array[i]->next;
                free(hashtable->array[i]->key);
                free(hashtable->array[i]->value);
                free(hashtable->array[i]);
                hashtable->array[i] = tmp;
            }
            free(hashtable->array[i]);
        }
    }
    free(hashtable->array);
    free(hashtable);
}

int main(void) {
    HashTable *ht;

    ht = ht_create(2);
    if (ht == NULL) {
        return 1;
    }

    if (ht_put(ht, "isFun", "A") == 0) {
        printf("%s\n", ht_get(ht, "isFun"));
        ht_free(ht);
        return 0;
    }

    return 1;
}
