set_line(char *buffer)

ver tamanho da próxima linha usando strlen  
conta até ao '\n'; se existir, inclui-o  
se não existir '\n', devolve o tamanho total (última linha do ficheiro)
DONE

----------------------------------------------------------------------------

read_line(int fd, char **buffer)

ler e montar a string acumulada
devolver essa string (line) pronta para ser cortada por outra função

----------------------------------------------------------------------------

free_line(char **ptr)

liberta memória que já não vai ser usada  
(ex.: o buffer antigo depois de ser substituído pelo resto)

DONE

----------------------------------------------------------------------------

split_line(char **buffer)

usa set_line() para saber o tamanho da próxima linha  
cria current_line usando substr()  
cria next_buffer usando substr() para guardar o resto  
actualiza buffer para next_buffer  
liberta o buffer antigo usando free_line()

RETORNA:
current_line (char *)

----------------------------------------------------------------------------

get_next_line(int fd)

usa read_line() para garantir que buffer tem dados suficientes  
se buffer estiver vazio → devolve NULL  
chama split_line() para obter current_line e atualizar buffer  
devolve current_line  
na chamada seguinte, começa a partir do buffer atualizado

RETORNA:
a próxima linha (char *)  
NULL se acabar o ficheiro ou der erro

----------------------------------------------------------------------------

Compilação:
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

----------------------------------------------------------------------------
