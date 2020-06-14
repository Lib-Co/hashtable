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

int hashKey(char[], struct HashTable *); 

void addToHashTable(char[], struct HashTable *);

struct Node *addName(char [], struct Node *);

struct Node *removeLastName(struct Node *);

void addToLinkedList(char [], struct LinkedList *);

void removeLast(struct LinkedList *);

void printLinkedList(struct Node *);

int searchNames(char v[], struct HashTable *);

#endif