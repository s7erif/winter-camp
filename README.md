# Library Management System

## 📚 Overview
This is a simple command-line library management system written in C++. It allows users to:
- Sign up and create new accounts.
- Sign in to their accounts.
- Access English and Arabic book libraries.
- Add or delete books.
- Borrow and return books.

## 🚀 How to Run the Program

### Prerequisites
- A C++ compiler (e.g., g++, Visual Studio, or any other IDE supporting C++)
- `users.txt` file for storing user credentials (it will be automatically created if not present).

### Steps to Run
1. Clone the repository or download the project files.
2. Open a terminal or command prompt in the project directory.
3. Compile the code using a C++ compiler. For example, with g++:
   ```bash
   g++ -o library_management library_management_system.cpp
   ```
4. Run the compiled program:
   ```bash
   ./library_management
   ```

## 📝 Features
- **User Authentication:**
  - Sign up: Create a new account.
  - Sign in: Log in using a valid username and password.

- **Book Libraries:**
  - Choose between English and Arabic libraries.
  - View book lists.
  - Add new books.
  - Delete books.
  - Borrow and return books.

- **Sample Books:**
  - **English Books:**
    - The Push
    - Bride Read
    - The Hedge
    - It
    - The Coming of the Ice

  - **Arabic Books:**
    - في قلبي انثى عبرية
    - ارض زيكولا 1
    - ارض زيكولا 2
    - ارض زيكولا 3
    - ما وراء الكواليس الدحيح

## 📂 File Structure
- `library_management_system.cpp`: The main source code.
- `users.txt`: Stores user credentials (auto-created upon signup).

## ⚠️ Notes
- Ensure `users.txt` is located in the same directory as the compiled executable.
- If the program is terminated abruptly, borrowed books information may be lost as no persistent storage is implemented for borrowing.

## 🛠️ Future Enhancements
- Implement persistent storage for borrowed books.
- Add book search functionality.
- Improve user interface with better menu navigation.

## 💻 Author
Developed by: Sherif

## 📄 License
This project is not licensed use it as you like 😘

