#include "biblioteca.h"
#include "musica.h"


void tocarMusica (char const nome[40],int loop){

    Mix_Music *som = NULL;

    int canal;

    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,4096) != 0){

        printf ("Não pode inicializar audio:  %s\n",Mix_GetError());
    }

    som = Mix_LoadMUS(nome);

    if(som == NULL){
        printf ("Não pode inicializar audio:  %s\n",Mix_GetError());
    }
    canal = Mix_PlayMusic(som,loop);
    
    if(canal == -1) {
                printf ("Não pode inicializar audio:  %s\n",Mix_GetError());
    }
}

void tocarSom (char const nome[40],int loop){

    Mix_Chunk *som = NULL;

    int canal;

    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,4096) != 0){

        printf ("Não pode inicializar audio:  %s\n",Mix_GetError());
    }

    som = Mix_LoadWAV(nome);

    if(som == NULL){
        printf ("Não pode inicializar audio:  %s\n",Mix_GetError());
    }

    Mix_HaltChannel(-1);
    canal = Mix_PlayChannel(-1,som,loop);
    
    if(canal == -1) {
                printf ("Não pode inicializar audio:  %s\n",Mix_GetError());
    }
}

void pararMusica (){
    Mix_HaltChannel(-1);
}