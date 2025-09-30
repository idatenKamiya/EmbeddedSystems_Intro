// Name: Skanda, Nadig
// BU username: skandan

#include <stdio.h>
#include <stdlib.h>
#include "bits.h"
#include "mylist.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    // Try to open input file
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        fprintf(stderr, "Error: Cannot open input file '%s'\n", argv[1]);
        return 1;
    }

    // Open or create output file
    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL)
    {
        fprintf(stderr, "Error: Cannot create output file '%s'\n", argv[2]);
        fclose(input_file);
        return 1;
    }

    // Initialize linked list head
    ListNode *head = NULL;
    unsigned int number;

    while (fscanf(input_file, "%u", &number) == 1)
    {
        unsigned int mirrored = BinaryMirror(number);
        unsigned int sequence_count = CountSequence(number);

        // Create new node and insert it in sorted order
        ListNode *newNode = createNode(number, mirrored, sequence_count);
        if (newNode != NULL)
        {
            insertSorted(&head, newNode);
        }
    }

    // Print the sorted list to output file
    printList(head, output_file);

    freeList(head);
    fclose(input_file);
    fclose(output_file);
    printf("Done! Results written to '%s'\n", argv[2]);
    return 0;
}