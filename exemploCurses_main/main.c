// https://pubs.opengroup.org/onlinepubs/7908799/xcurses/curses.h.html
#include <stdlib.h>
#include <time.h>
#include "APSLib/APSLib.h"

int main(int argc, char *argv[])
{
    // estrutura com dados internos da aplica��o
    gameData game;

    // inicializa a tela pelo Curses e o estado inicial da aplica��o
    initScreen(GAME);
    initGame(&game);

    // La�o principal sem retorno, pode ser removido para exibi��o direta de informa��o na tela
	while(1)
    {
        // Gerencia entradas do usu�rio pelo teclado
        handleInputs(&game);

        // Gerencia l�gica da aplica��o
        doUpdate(&game);

        // Atualiza a tela
        if(game.menuInicial){
            drawScreen(&game, MENU);
        }else{
            drawScreen(&game, GAME);
        }

        // Controla o FPS da aplica��o
        napms(10);
    }

    // Encerra a tela inicializada em initScreen
    endwin();

	return 0;
}
