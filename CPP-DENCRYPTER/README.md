# 🔐 Custom Text Encryptor & Decryptor in C++

A simple console-based encryption/decryption program that allows you to create your own custom “language” by pairing letters together. The program can encrypt or decrypt any message based on a user-defined letter-mapping stored in a text file.

This was built as part of my ongoing C/C++ mini practice projects.

📌 Features

✔️ Create your own custom 13-pair letter mapping (“language”)<br>
✔️ Saves mappings to a text file (language_source_code.txt)<br>
✔️ Encrypt messages<br>
✔️ Decrypt messages<br>
✔️ File handling using fstream<br>
✔️ Clean console UI with repeated operations<br>
✔️ Same function used for both encryption and decryption (symmetrical mapping)<br>

# 📍 How the Program Works<br>
1️⃣ Creating the Language (L option)

- The program asks you to enter 13 unique letter pairs (like a b, c d, etc.).<br>
- Each pair represents a two-way mapping, meaning:<br>

&nbsp;&nbsp;a ↔ b<br>
&nbsp;&nbsp;c ↔ d<br>

- These are stored in language_source_code.txt for later use.<br>
- This creates a simple substitution cipher.<br>

2️⃣ Encrypting a Message (E option)

- You enter any message (letters + spaces).<br>
- The program reads each character and looks for it in the mapping file.<br>
- If the character matches the first letter of a pair → it is replaced with the second letter.<br>
- If it matches the second letter → replaced with the first letter.<br>
- Spaces are preserved.<br>

Example:
If file contains a z, entering "amazing" becomes "zmzning".

3️⃣ Decrypting a Message (D option)

- Decryption uses the same function as encryption.
- Since every pair is symmetric, running the encoded message again restores the original text.

# 📍 Internal Logic Overview
#Language Maker

- Writes 13 user-defined letter pairs to a file.
- Ensures persistent mappings for encryption/decryption.

#Encryption/Decryption Algorithm

- For each character:
- Loop through all 13 letter pairs.
- If character matches either side of the pair → output its partner.
- After each character, reset file reading pointer with seekg(0) to start again.

#File Handling

Uses:
- ofstream to write mappings
- ifstream to read mappings
- seekg() & clear() to repeatedly scan the file for each character

# 📍 How to Compile & Run

Compile<br>
- g++ dencrypter.cpp -o dencrypter

Run<br>
- ./dencrypter

You will see the menu:
- Make Language (L)/ Encrypt (E)/ Decrypt (D)

# 📚 What I Learned

- Basic encryption logic (substitution cipher)
- File handling with C++ (fstream, reading/writing, reset pointers)
- Using symmetric mappings for reversible encryption
- Building reusable functions
- Strengthening console I/O handling
- Looping workflows and simple UI structure
