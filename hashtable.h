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
    unsigned int size;
    struct LinkedList *hashtable;
    //struct Name *hashtable[TABLESIZE];
    //int HashTable[TABLESIZE];
};

void createHashTable(int, struct HashTable *);

int asciiValue(char [], int);

int hashKey(int , char[]); 

void addToHashTable(int, char[], struct Node *);

struct Node *addName(char [], struct Node *);

struct Node *removeLastName(struct Node *);

void add(char [], struct LinkedList *);

void removeLast(struct LinkedList *);

void printLinkedList(struct Node *);

int searchNames(struct Node *);

#endif