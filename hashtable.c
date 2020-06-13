#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 15
#define TABLESIZE 100

struct Name
{
    //int key;
    char value[MAX];
    struct Name *next;
};

struct LinkedList
{
    struct Name *head;
};

struct HashTable
{
    int size;
    struct Name HashTable[TABLESIZE];
};

struct HashKey
{
    int hashKey;
    struct HashTable index;
};


//Caluculate ASCII value of all characters in a string
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
}

// //Hashing functionality
void hashKey(char v[])
{
    if (v != NULL)
    {
        int sum;
        sum = asciiValue(v, 0);
        printf("%d ", sum);
    }

}


//Create a node for each name added
struct Name *addName(char v[], struct Name *head)
{
    if (head == NULL)
    {
        struct Name *n = (struct Name *)malloc(strlen(v));
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

struct Name *removeLastName(struct Name *head)
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
void add(char v[], struct LinkedList *list)
{
    hashKey(v);
    if (list->head == NULL)
    {

        struct Name *h = (struct Name *)malloc(strlen(v));
        strcpy(h->value, v);
        h->next = NULL;
        list->head = h;
    }
    else
    {
        addName(v, list->head);
    }
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

void printLinkedList(struct Name *name)
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

int searchNames(struct Name *name)
{
    //Check if name exists in the hash table
    return 0;
}

int main(void)
{
    struct LinkedList list;
    list.head = NULL;
    add("Emma", &list);
    printLinkedList(list.head);
    add("Lucy", &list);
    printLinkedList(list.head);
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