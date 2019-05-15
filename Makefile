CC=gcc
OPCOES_COMPILADOR=-I. -I/usr/include/SOIL -lglut -lGLU -lGLEW -lGL -lm -lSOIL -lSDL -lSDL_mixer
TODOS_ARQUIVOS_PONTOH = glm.h glmint.h
TODOS_ARQUIVOS_OBJ = glm.o  glm_util.o  glmimg.o musica.o

%.o: ../%.c $(TODOS_ARQUIVOS_PONTOH)
	$(CC) -o $@ -c $< $(OPCOES_COMPILADOR)

run: $(TODOS_ARQUIVOS_OBJ) teste.o 
	gcc -o teste $^ $(OPCOES_COMPILADOR)
	./teste

clean:
	rm *.o teste

