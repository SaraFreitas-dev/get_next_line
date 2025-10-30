1. get_next_line(int fd)

Função principal - Chama as outras três funções.

Retorna uma linha por chamada (ou NULL).

Fluxo:

Usa read_and_load() → garante que há dados suficientes no stash (até \n).

Usa extract_line() → cria a linha a devolver.

Usa clean_free() → limpa o stash (mantém só o resto).

Retorna a linha.

-----------------------------------------------------------------------------------------------

2. read_and_load(int fd, char **stash)

Lê do ficheiro e junta ao stash.
Faz read() em blocos de BUFFER_SIZE.
Junta ao conteúdo antigo (stash).
Para quando encontrar \n.

Garante que stash é uma string terminada por \0 - ou a foncao acrescenta.

-----------------------------------------------------------------------------------------------


3. extract_line(char *stash)

Extrai do stash apenas a próxima linha a devolver.

Copia tudo até (e incluindo) o primeiro \n.

Se não houver \n, copia até ao fim.

Não altera o stash.

Só lê, não mexe no original.

-----------------------------------------------------------------------------------------------


4. clean_free(char **stash)

Remove do stash a parte já entregue e guarda o resto.

Aponta para o texto depois do \n.

Se não restar nada, liberta o stash e põe a NULL.

Prepara o stash para a próxima chamada.


cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c