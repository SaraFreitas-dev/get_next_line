# 📜 get_next_line

**get_next_line** is a 42 project focused on implementing a function that reads a file (or input) **one line at a time**, regardless of line length or buffer size.  
This project reinforces memory management, static variables, and low-level file reading.

---

## 🧠 Goal

Implement the function:

```c
char *get_next_line(int fd);
```

that returns the next line from a file descriptor:

- Includes the terminating `\n` (except at end-of-file)
- Uses dynamic memory allocation
- Maintains leftover data between calls using a static variable
- Works efficiently using a configurable `BUFFER_SIZE`

---

## 📚 Description

### ✅ Mandatory part

The project must:

- Read text **one line per call**
- Use only the `read()` function for input
- Store unfinished data in a static variable
- Return `NULL` when nothing is left to read
- Handle arbitrarily long lines and any buffer size

### 🧩 Bonus part

Additionally, the bonus version must:

- Support **multiple file descriptors simultaneously**
- Keep a separate static buffer for each FD
- Ensure the function remains independent across calls

---

## ⚙️ Compilation

Compile using:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c
```

Examples:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 *.c
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1000 *.c
```

Run:

```bash
./a.out file.txt
```

---

## 🧱 Project Structure

```
get_next_line/
├── get_next_line.c
├── get_next_line.h
├── get_next_line_utils.c
├── get_next_line_bonus.c
├── get_next_line_bonus.h
├── get_next_line_utils_bonus.c
└── README.md
```

---

## 🔍 How It Works

### 📌 Core logic

1. Use `read()` to fill a temporary buffer.
2. Append this buffer to leftover data stored in a static string.
3. Extract a full line (ending with `\n` if present).
4. Save the remaining data for the next call.
5. Return the extracted line.

### 📌 Important details

- The function returns `NULL` on error or when EOF is reached.
- No global variables allowed.
- Returned lines must be freed by the caller.
- Static variables preserve state between calls.

---

## ⭐ Bonus: Multiple File Descriptors

The bonus version stores leftover data **per FD**, like:

```
buffer[3] → leftover from FD 3
buffer[4] → leftover for FD 4
buffer[5] → leftover for FD 5
```

This allows alternating between descriptors:

```c
get_next_line(fd1);
get_next_line(fd2);
get_next_line(fd1);
```

Each FD continues where it left off.

---

## 🧪 Example Usage

```c
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

---

## 🧾 Notes

- Must handle very long lines correctly.
- Must compile without memory leaks.
- Must work with files, stdin, and pipes.
- Implementation must follow the 42 Norm.

---

## 📜 License

This project is part of the 42 curriculum and intended for educational use.  
Feel free to explore the code, but try to understand it rather than copying it. ✨
```
