# Secure Notes Manager (C)

A simple command-line Notes Manager built in C. This project allows users to create, view, search, delete, save, and load notes from a file.

## Features

- Add notes
- View all notes
- Search notes by title
- Delete notes
- Save notes to a file
- Load notes from a file
- Simple command-line interface
- Lightweight and fast

## Technologies Used

- C Programming Language
- Standard C Library
- File Handling

## Project Structure

```
secure-notes-manager-c/
│
├── notes.c
├── notes.dat
├── README.md
└── LICENSE
```

## Compilation

Using GCC:

```bash
gcc notes.c -o notes
```

## Running

Linux/macOS:

```bash
./notes
```

Windows:

```bash
notes.exe
```

## Menu Options

```
1. Add Note
2. View Notes
3. Save Notes
4. Load Notes
5. Delete Note
6. Search Note
7. Exit
```

## Example Usage

```
Enter choice: 1

Enter Title: Shopping
Enter Content: Buy milk and bread

Note added successfully!
```

## Future Improvements

- Password protection
- AES encryption
- Categories and tags
- Export notes to text files
- Multi-user support
- Better search functionality

## Learning Concepts

This project demonstrates:

- Structures in C
- Arrays
- Functions
- File handling
- String manipulation
- Menu-driven programs
- Data persistence

## License

This project is open source and available under the MIT License.

## Author

Vishesh Vishwakarma
