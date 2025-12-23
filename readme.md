*This project has been created as part of the 42 curriculum by sarfreit.*

## Description
The **get_next_line** project consists of implementing a function that reads and returns one line at a time from a file descriptor.
Its goal is to allow efficient line-by-line reading while handling partial reads and preserving state between function calls.

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

## Instructions
The project is written in C and must be compiled with a defined `BUFFER_SIZE`.

# Define BUFFER_SIZE and compile the mandatory files
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main_mandatory.c get_next_line.c get_next_line_utils.c -o test_mandatory
```
# Execute the tester
```bash
./test_mandatory
```

# Define BUFFER_SIZE and compile the bonus files
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=10 main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c -o test_bonus
```

# Execute the tester
```bash
./test_bonus
```

# Check for Leaks
```bash
valgrind --leak-check=full --show-leak-kinds=all ./test_mandatory
```
```bash
valgrind --leak-check=full --show-leak-kinds=all ./test_bonus
```

---

## Resources

For this project I used the help of some GitBooks from older students, and websites like GeeksforGeeks and W3Schools.
