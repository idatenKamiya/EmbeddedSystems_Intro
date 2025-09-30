// Name: Skanda, Nadig
// BU username: skandan

#include "bits.h"

unsigned int BinaryMirror(unsigned int num)
{
    unsigned int result = 0;

    for (int i = 0; i < 32; i++)
    {
        result <<= 1;
        result |= (num & 1);
        num >>= 1;
    }
    return result;
}

unsigned int CountSequence(unsigned int num)
{
    unsigned int count = 0;
    unsigned int last_three_bits = 0;

    for (int i = 0; i < 32; i++)
    {
        // Shift the last three bits left, add current bit and use bit mask
        last_three_bits = ((last_three_bits << 1) | (num & 1)) & 0x7;
        if (last_three_bits == 0x2)
        { // 010 in binary is 2 in decimal
            count++;
        }
        num >>= 1;
    }

    return count;
}