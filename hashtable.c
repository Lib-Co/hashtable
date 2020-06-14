#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

//Create HashTable
void createHashTable(int size, struct HashTable *ht)
{
    if (size < 1)
        return;
    ht->size = size;
    ht->hashtable = malloc(sizeof(struct LinkedList) * size);

    int i;
    for (int i = 0; i < size; i++)
    {
        ht->hashtable[i].head = NULL;
    }
}

//Calculate ASCII value of all characters in a string
int asciiValue(char v[], int i)
{
    if (i < strlen(v))
    {
        return (v[i] + asciiValue(v, i + 1));
    }
    else
    {
        return 0;
    }
};

//Create hash index value by calculating sum % hashtable size
int hashKey(char v[], struct HashTable *ht)
{
    if (v != NULL)
    {
        int size = ht->size;
        int sum;
        sum = asciiValue(v, 0);
        int hk = sum % size;
        printf("%d ", hk);
        return hk;
    }
    return 0;
}

void addToHashTable(char v[], struct HashTable *ht)
{
    struct Node *head;
    if (v != NULL)
    {
        int hk = hashKey(v, ht);
        //Use add to end of linked list logic
        addToLinkedList(v, &(ht->hashtable[hk]));
    }
}
//Create a node for each name added
struct Node *addName(char v[], struct Node *head)
{
    if (head == NULL)
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        strcpy(n->value, v);
        n->next = NULL;
        return n;
    }
    else
    {
        head->next = addName(v, head->next);
        return head;
    }
}

struct Node *removeLastName(struct Node *head)
{
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    else
    {
        head->next = removeLastName(head->next);
        return head;
    }
}

//Add names to linked list
void addToLinkedList(char v[], struct LinkedList *list)
{
    addName(v, list->head);
}

void removeLast(struct LinkedList *list)
{
    if (list->head == NULL)
    {
        return;
    }
    else
    {
        removeLastName(list->head);
    }
}

void printLinkedList(struct Node *name)
{
    if (name == NULL)
    {
        printf("End\n");
    }
    else
    {
        printf("%s, ", name->value);
        printLinkedList(name->next);
    }
}

int searchNames(struct Node *name)
{
    //Check if name exists in the hash table
    return 0;
}

int main(void)
{
    struct HashTable *ht = malloc(sizeof(struct HashTable));
    int size = 100;
    createHashTable(size, ht);

    addToHashTable("Emma", ht);
    addToHashTable("Lucy", ht);
    addToHashTable("Matt", ht);
    //printLinkedList(list.head);
    // add("Evie", &list);
    // printLinkedList(list.head);
    // add("Cat", &list);
    // printLinkedList(list.head);
    // add("Tia", &list);
    // printLinkedList(list.head);
    // add("Libby", &list);
    // printLinkedList(list.head);
    // removeLast(&list);
    // printLinkedList(list.head);
    // removeLast(&list);
    // printLinkedList(list.head);

    return 0;
}