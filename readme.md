get_next_line
   ↓
read_and_stash   ← lê blocos até ter \n
   ↓
extract_line     ← retira o que vais devolver
   ↓
clean_stash      ← guarda sobra para próxima chamada


get_next_line() function


cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c