// Name: Skanda, Nadig
// BU username: skandan

#ifndef MYLIST_H
#define MYLIST_H

// linked list: ListNode
typedef struct ListNode
{
    unsigned int input_number;
    char binary_representation[33];
    char ascii_representation[9];
    unsigned int mirrored_number;
    unsigned int sequence_count;
    struct ListNode *next; // Pointer to 'next' node
} ListNode;

// Function declarationns
ListNode *createNode(unsigned int input_num, unsigned int mirrored, unsigned int seq_count);
void insertSorted(ListNode **head, ListNode *newNode);
void printList(ListNode *head, FILE *output_file);
void freeList(ListNode *head);
void numberToBinary(unsigned int num, char *binary_str);
void numberToASCII(unsigned int num, char *ascii_str);

#endif