setline

ver tamanho da linha atual com strlen

----------------------------------------------------------------------------


read_line

lê do ficheiro para um buffer

junta esse conteúdo ao que já tínha guardado (strjoin → colecionar pedaços)

----------------------------------------------------------------------------


free_line

liberta apenas o que já não vai ser usar (a linha que já foi devolvida)


----------------------------------------------------------------------------

get_next_line

chama as funções auxiliares para montar 1 linha

usa strchr para ver se já existe \n

se encontrou \n:

usa substr para cortar a linha até \n (linha pronta a devolver)

usa substr outra vez para guardar o resto depois do \n (para a próxima chamada)

se ainda não encontrou \n:

continua a ler e a fazer strjoin até encontrar ou acabar o ficheiro

quando a linha está pronta, faz strdup (ou equivalente) para devolver uma cópia segura

guarda o resto acumulado para a próxima chamada

na próxima vez, começa a partir desse resto

----------------------------------------------------------------------------

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c