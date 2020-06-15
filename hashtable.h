#ifndef HASHTABLE_H
#define HASHTABLE_H
#define MAX 15

struct Node
{
    int key;
    char value[MAX];
    struct Node *next;
};

struct LinkedList
{
    struct Node *head;
};

struct HashTable
{
    int size;
    struct LinkedList *hashtable;
};

void createHashTable(int, struct HashTable *);

int asciiValue(char [], int);

int hashKey(char[], int); 

void addToHashTable(char[], struct HashTable *);

struct Node *addName(char [], struct Node *);

void addToLinkedList(char [], struct LinkedList *);

void removeFromHashTable(char [], struct HashTable *);

void removeFromLinkedList(char [], struct LinkedList *);

struct Node * removeName(char [], struct Node *);

int searchNames(char v[], struct HashTable *);

#endif