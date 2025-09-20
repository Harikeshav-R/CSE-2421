/*
BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED
TO THE TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY
WITH RESPECT TO THIS ASSIGNMENT.
*/

/*
Author: Harikeshav R

Program Description:
This program decrypts a sequence of hexadecimal characters using an 8-bit key.
The user first provides a key as a sequence of 0s and 1s, which is used to
determine the decryption key. The encrypted text is then entered in hexadecimal
format, and the program decrypts and outputs the corresponding plain text.

Overall Method:
1. Read and construct the 8-bit decryption key from binary input.
2. Continuously read encrypted characters in hexadecimal form.
3. Decrypt each character by applying alternating bit rotations and an XOR with
   the decryption key.
4. Print the decrypted message to the console.
*/

#include <stdio.h>
#include <stdlib.h>

/**--
 * @brief Creates an 8-bit key based on user input of binary digits.
 *
 * @return An unsigned char representing the 8-bit key derived from input.
 */
unsigned char create_key(void);

/**
 * @brief Rotates the bits of an 8-bit unsigned value to the left by one position.
 *
 * @param value The 8-bit unsigned value to be rotated.
 * @return The resulting 8-bit unsigned value after the left rotation.
 */
unsigned char rotate_left(unsigned char value);

/**
 * @brief Rotates the bits of an 8-bit unsigned value to the right by one position.
 *
 * @param value The 8-bit unsigned char value to be rotated.
 * @return The resulting 8-bit unsigned value after the right rotation.
 */
unsigned char rotate_right(unsigned char value);

/**
 * @brief Decrypts a single encrypted character using a decryption key.
 *
 * @param encrypted_char The encrypted character to be decrypted.
 * @param decryption_key A pointer to the decryption key used for the XOR operation.
 * @return The decrypted character as an unsigned char.
 */
unsigned char decrypt_char(unsigned char encrypted_char, const unsigned char* decryption_key);

/**
 * @brief Decrypts a series of hexadecimal characters using a specified decryption key.
 *
 * @param decryption_key A pointer to an 8-bit decryption key used for decoding the input.
 */
void decrypt(const unsigned char* decryption_key);


int main(void)
{
#ifdef PROMPT
    /* Prompt the user for the 8-bit binary decryption key */
    printf("Enter 8-bit key: ");
#endif

    /* Generate the decryption key from user input */
    const unsigned char decryption_key = create_key();

#ifdef PROMPT
    /* Prompt the user to enter the encrypted message in hex format */
    printf("\nEnter encrypted text: ");
#endif

    /* Begin decryption process using the provided key */
    decrypt(&decryption_key);

    return EXIT_SUCCESS;
}


unsigned char create_key(void)
{
    unsigned char key = 0;
    int bits_read = 0;

    /* Continue reading until 8 valid binary digits are entered */
    while (bits_read < 8)
    {
        const int c = getchar();

        /* Only accept '0' or '1' as valid key input */
        if (c == '0' || c == '1')
        {
            key = key << 1; /* Shift left to make space for next bit */
            if (c == '1') { key = key | 1; } /* Set least significant bit to 1 if input is '1' */
            bits_read++; /* Count the bit read */
        }
    }
    return key;
}


unsigned char rotate_left(const unsigned char value)
{
    /* Perform circular left shift by moving MSB to LSB */
    return (value << 1) | (value >> 7);
}


unsigned char rotate_right(const unsigned char value)
{
    /* Perform circular right shift by moving LSB to MSB */
    return (value >> 1) | (value << 7);
}


unsigned char decrypt_char(const unsigned char encrypted_char, const unsigned char* decryption_key)
{
    static int count = 0; /* Keeps track of character position */
    count++;

    /* Odd positions use right rotation, even positions use left rotation */
    return (count % 2 != 0)
               ? rotate_right(encrypted_char) ^ *decryption_key
               : rotate_left(encrypted_char) ^ *decryption_key;
}


void decrypt(const unsigned char* decryption_key)
{
    unsigned int encrypted_char;

    /* Continuously read hexadecimal values until end of input */
    while (scanf("%x", &encrypted_char) != EOF)
    {
        /* Decrypt and print the current character */
        putchar(decrypt_char((unsigned char)encrypted_char, decryption_key));

        /* Stop if newline is encountered */
        if (getchar() == '\n') break;
    }

    /* Print newline after decryption output */
    putchar('\n');
}
