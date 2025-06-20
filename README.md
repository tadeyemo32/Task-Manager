
# 📝 Task Manager in C

A simple command-line task manager built in C to demonstrate foundational **Data Structures and Algorithms (DSA)** knowledge, file I/O handling, and dynamic memory management using **linked lists**.

---

## ⚙️ Features

- ✅ Add tasks with title and description
- ❌ Remove tasks by position
- 🔎 Search tasks by ID or title (via internal functions)
- 📂 Save tasks to a file (`app.txt`)
- 📥 Load tasks from a file
- 📋 Print all tasks in list format
- 💡 Hash-based task ID generation
- 📁 Uses a **singly linked list** to manage dynamic task storage in memory

---

## 📚 Why This Project?

This project was created as a practical demonstration of:
- Dynamic memory allocation in C
- Custom data structures (`struct Task`, `struct Node`)
- Linked list operations:
  - Insertion at head, tail, and specific position
  - Deletion
  - Search
- Basic file handling using `fopen`, `fgets`, `fprintf`, and `fscanf`
- Command-line interface (CLI) programming

---

## 🧠 Core Concepts Demonstrated

| Concept            | Usage in Project                                  |
|--------------------|----------------------------------------------------|
| **Linked Lists**   | To manage the dynamic task list                    |
| **File I/O**       | Saving and loading task data in a text format      |
| **Hash Function**  | Used to generate a unique ID from a task title     |
| **Memory Handling**| Proper `malloc` / `free` usage to avoid leaks      |
| **Modular Design** | Functions like `createNode()`, `insertNodeAtEnd()` |

---

## 💻 How to Compile & Run

### ✅ Requirements:
- GCC (or any C compiler)
- Unix-like terminal (Linux/macOS) or MinGW on Windows

### 📦 Compile:
```bash
gcc -o task_manager task_manager.c
```

### ▶️ Run:
```bash
./task_manager
```

---

## 🧪 Sample Output

```plaintext
--- TASK MANAGER ---
1. Add Task
2. Remove Task
3. View All Tasks
4. Save Tasks to File
5. Load Tasks from File
6. Exit
Choose an option:
```

---

## 📄 File Format (app.txt)

Tasks are saved in the following format:

```
Id:12345|Title:Buy groceries|Description:Milk and eggs|State:0
```

- `State:0` means **Pending**
- `State:1` means **Done** (currently not toggleable but extensible)

---

## 🧱 Possible Improvements

- [ ] Task state toggle (mark as complete)
- [ ] Search tasks via user input
- [ ] Priority or due dates
- [ ] Cross-platform GUI (with raylib or ncurses)

---

## 📌 Author Notes

> This project was written from scratch to reinforce my understanding of core data structures and how to manage memory and files in C. It showcases my ability to build real-world CLI tools and apply key programming principles in a low-level language.

---

## 📁 License

MIT License — free to use and modify.

---
