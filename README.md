# RC4 Encryption Library and Example

This repository provides an implementation of the RC4 (Rivest Cipher 4) encryption algorithm along with an example demonstrating how to use the library for encryption and decryption operations.

## Project Structure

- **rc4.c**: The implementation of the RC4 encryption algorithm.
- **rc4.h**: Header file containing the necessary declarations and macros for RC4.
- **example.c**: A simple example program that demonstrates how to use the RC4 library for encryption and decryption of a "Hello, World!" message.
- **Makefile**: Build script to compile and link the RC4 library and example program.

## Files

### rc4.c

Contains the implementation of the RC4 encryption algorithm. It provides functions for initializing the cipher, generating the keystream, and performing encryption and decryption.

### rc4.h

The header file includes necessary declarations and the structure of the RC4 cipher. It also provides function prototypes for:

- `rc4_init`: Initializes the RC4 cipher with a given key.
- `rc4Byte`: Returns the next byte of the keystream for RC4 encryption.
- `rc4_encrypt`: Encrypts or decrypts the given data using the RC4 cipher.

### example.c

A simple program that generates a random key, encrypts a "Hello, World!" message, then decrypts it using the RC4 cipher. The program prints the encrypted text in hexadecimal and the decrypted text.

### Makefile

The Makefile provides instructions for building the RC4 library and example program. It compiles the source files and links them into an executable.

## Usage

### Compilation

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/encryptionLib.git
   cd encryptionLib

2. Build the project sugin `make`:

   ```bash
   make

## Running the Example
After compiling, run the example program:
  
  ```bash
  ./example
  ```
This will output the generated key, encrypted text, and decrypted text.

## Cleaning Up
To remove all compiled files and the executable, run:
   
   ```bash
   make clean
   ```


## Contributing

Feel free to fork the repository, create a pull request, or open an issue if you encounter any problems or have suggestions for improvements.

   
