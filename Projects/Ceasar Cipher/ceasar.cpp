// March 18th, 2018

#include <iostream>  // Input and output
#include <string>    // Include string helpers
#include <ctype.h>   // Includes isupper() and islower()

// Fix the encrypt function (Repeats the same thing twice just changes 0x20)
// Encrypt and decrypt are REALLY similar, find a way to make the code more unique?
// THe only difference is one does minus while the other one does plus


// Add encrypt and decrypt function
std::string encrypt(std::string plaintext, std::string alphabet, int key_shift);
void        decrypt(std::string plaintext, std::string alphabet);

// I'll put these here for now, don't know where I should put it really
std::string alphabet        = "abcdefghijklmnopqrstuvwxyz";
int         alphabet_length = 26;

int main()
{
    std::string plaintext       = "";
    std::string encrypted_text  = "";
    std::string decrypted_text  = "";
    int key_shift               = 2;

    std::cout << alphabet. << std::endl;

    // Getting the user's input
    std::getline (std::cin, plaintext);

    // Gets the encrypted sentence
    encrypted_text = encrypt(plaintext, alphabet, key_shift);

    // Prints an encrypted sentence (Inputted by the user)
    std::cout << encrypted_text << std::endl;

    std::cout << "\nTrying all shifts for the cipher...\n\n" << std::endl;

    // Prints all possibilites for a given encrypted text
    decrypt(plaintext, alphabet);

    return 0;
}

// Function encrypts plaintext using the alphabet and modulos
std::string encrypt(std::string plaintext, std::string alphabet, int key_shift) {
    std::string encrypted_text = "";

    // Loop every index in the plaintext
    for (auto l : plaintext)
    {
        // Turn to lower case if it's an uppercase
        if (isupper(l))
        {
            l += 0x20; // Turns uppercase to lowercase
            encrypted_text += (char)(alphabet[(alphabet.find(l) + key_shift) % alphabet_length] - 0x20);
        } else if (islower(l)) {
            encrypted_text += (char)(alphabet[(alphabet.find(l) + key_shift) % alphabet_length]);
        } else {
            encrypted_text += l;
        }
    }

    return encrypted_text;
}

// Add a clever comment here in the future
void decrypt(std::string plaintext, std::string alphabet) {
    // Looping through every key_shift (26 since logically there are 26 letters in the alphabet)
    for (int key_shift = 1; key_shift <= 26; key_shift++)
    {
        // Start with a new decrypted_text variable every iteration
        std::string decrypted_text = "";

        std::cout << "Key_shift (" << key_shift << ") -> ";
        // At that point the program has a new key_shift, now loop through plaintext with a new key_shift
        for (auto l : plaintext) // Doesn't need to be auto, I just use it because I can
        {
            if (isupper(l))
            {
                l += 0x20; // Turns uppercase to lowercase, could create uppercase alphabet but nah
                decrypted_text += (char)(alphabet[(alphabet.find(l) - key_shift) % alphabet_length] - 0x20); // - 0x20 removes the lowercase and makes it uppercase again
            } else if (islower(l)) {
            // Add letter to encrypted_text once it has been encrypted
                decrypted_text += (char)(alphabet[(alphabet.find(l) - key_shift) % alphabet_length]);
            } else {
                decrypted_text += l;
            }
        }

        std::cout << decrypted_text << std::endl;
    }
}