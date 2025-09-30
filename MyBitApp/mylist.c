// Name: Skanda, Nadig
// BU username: skandan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylist.h"

// Convert number to binary string representation
void numberToBinary(unsigned int num, char *binary_str)
{
    binary_str[32] = '\0'; // Null terminate

    for (int i = 31; i >= 0; i--)
    {
        binary_str[i] = (num & 1) ? '1' : '0';
        num >>= 1;
    }
}

// Convert number to ASCII representation
void numberToASCII(unsigned int num, char *ascii_str)
{
    int index = 0;

    // Extract each byte and convert to ASCII character if printable
    for (int i = 24; i >= 0; i -= 8)
    {
        unsigned char byte = (num >> i) & 0xFF;

        // Only include printable ASCII characters (32-126)
        if (byte >= 32 && byte <= 126)
        {
            ascii_str[index++] = (char)byte;
        }
    }

    ascii_str[index] = '\0'; // Null terminate
}

// Create a new list node
ListNode *createNode(unsigned int input_num, unsigned int mirrored, unsigned int seq_count)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->input_number = input_num;
    newNode->mirrored_number = mirrored;
    newNode->sequence_count = seq_count;
    newNode->next = NULL;

    // Generate binary and ASCII representations
    numberToBinary(input_num, newNode->binary_representation);
    numberToASCII(input_num, newNode->ascii_representation);

    return newNode;
}

// Insert node in sorted ascending order based on ASCII representation
void insertSorted(ListNode **head, ListNode *newNode)
{
    if (newNode == NULL){
        printf("Could not insert a null node\n");
        return;
    }
    // If list is empty or new node should be first
    if (*head == NULL || strcmp(newNode->ascii_representation, (*head)->ascii_representation) < 0)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Find the correct position to insert
    ListNode *current = *head;
    while (current->next != NULL &&
           strcmp(current->next->ascii_representation, newNode->ascii_representation) < 0)
    {
        current = current->next;
    }

    // Insert the new node
    newNode->next = current->next;
    current->next = newNode;
}

// Print the entire list to output file
void printList(ListNode *head, FILE *output_file)
{
    ListNode *current = head;

    while (current != NULL)
    {
        fprintf(output_file, "%u %u %s %s\n",
                current->mirrored_number,
                current->sequence_count,
                current->binary_representation,
                current->ascii_representation);
        current = current->next;
    }
}

// Free all memory
void freeList(ListNode *head)
{
    ListNode *current = head;
    ListNode *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}