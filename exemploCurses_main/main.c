// https://pubs.opengroup.org/onlinepubs/7908799/xcurses/curses.h.html
#include <stdlib.h>
#include <time.h>
#include "APSLib/APSLib.h"

int main(int argc, char *argv[]){

    gameData game;  // estrutura com dados internos da aplica��o

    initScreen(GAME); // inicializa a tela pelo Curses e o estado inicial da aplica��o
    initGame(&game);

	while(1){ // La�o principal sem retorno, pode ser removido para exibi��o direta de informa��o na tela

        handleInputs(&game);  // Gerencia entradas do usu�rio pelo teclado

        doUpdate(&game); // Gerencia l�gica da aplica��o

        if(game.menuInicial){
            drawScreen(&game, MENU); // Atualiza a tela
        }else{
            drawScreen(&game, GAME);
        }

        napms(10); // Controla o FPS da aplica��o
    }

    endwin(); // Encerra a tela inicializada em initScreen

	return 0;
}
