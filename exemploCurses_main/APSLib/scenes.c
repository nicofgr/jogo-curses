#include "APSLib.h"

void MainMenu(gameData * game){

    int os = 38;

    setColor(COLOR_GREEN, COLOR_BLACK, 0);
    mvprintw(7,game->meioTela.x - os, "   8888888                                             d8b 888             ");
    mvprintw(8,game->meioTela.x - os, "     888                                               Y8P 888             ");
    mvprintw(9,game->meioTela.x - os, "     888                                                   888             ");
    mvprintw(10,game->meioTela.x - os, "     888   88888b.   .d8888b .d88b.   .d88b.  88888b.  888 888888  8888b.  ");
    mvprintw(11,game->meioTela.x - os, "     888   888 \"88b d88P\"   d88\"\"88b d88P\"88b 888 \"88b 888 888        \"88b ");
    mvprintw(12,game->meioTela.x - os, "     888   888  888 888     888  888 888  888 888  888 888 888    .d888888 ");
    mvprintw(13,game->meioTela.x - os, "     888   888  888 Y88b.   Y88..88P Y88b 888 888  888 888 Y88b.  888  888 ");
    mvprintw(14,game->meioTela.x - os, "   8888888 888  888  \"Y8888P \"Y88P\"   \"Y88888 888  888 888  \"Y888 \"Y888888 ");
    mvprintw(15,game->meioTela.x - os, "                                          888                              ");
    mvprintw(16,game->meioTela.x - os, "                                     Y8b d88P                              ");
    mvprintw(17,game->meioTela.x - os, "                                      \"Y88P\"                               ");

    ///BORDAS
    for(int lin = 0; lin < (game->meioTela.y*2); lin++){
        for(int col = 0; col < (game->meioTela.x*2); col++){
            if(lin == 0 || col == 0 || lin == (game->meioTela.y*2)-1 || col == (game->meioTela.x*2)-1){
                setColor(COLOR_BLACK, COLOR_GREEN, 0);
                mvaddch(lin, col, ACS_BOARD);
            }
        }
    }

    switch(game->telaMenuInicial){
        case 0: ///TELA INICIAL
            setColor(COLOR_GREEN, COLOR_BLACK, 0);
            printw("\n\n\n\n\n\n\n\n\n");


            mvprintw(20,game->meioTela.x - 15,"Pressione ENTER para continuar.");

            break;
        case 1: ///TELA 2
            echo();
            setColor(COLOR_GREEN, COLOR_BLACK, 0);
            mvprintw(20, game->meioTela.x - 25, "Digite o nome do seu personagem: ");
            getstr(game->nomePersonagem);
            game->telaMenuInicial = 3;
            noecho();
            break;
        case 3: ///PROLOGO
            clear();
            curs_set(0);
            setColor(COLOR_GREEN, COLOR_BLACK, 0);
            mvprintw(4,game->meioTela.x - 30, "Era uma noite escura e chuvosa, relampejava sem parar,");
            mvprintw(5,game->meioTela.x - 32, "estava tudo tao quieto, que qualquer barulho lhe chamava atencao");
            mvprintw(6,game->meioTela.x - 30, "Olhando ao seu redor, as unicas coisas que voce ve sao");
            mvprintw(7,game->meioTela.x - 32, "a sua mesa com o telefone e alguns papeis em cima.");
            mvprintw(8,game->meioTela.x - 30, "Voce esta quase pegando no sono...");
            mvprintw(10,game->meioTela.x - 8, "TRIN TRIN TRIN\n");
            mvprintw(12,game->meioTela.x - 30, "O telefone toca, uma voz misteriosa comeca a fala do outro lado da linha.");
            mvprintw(14,game->meioTela.x - 34, ">>> Detetive %s, certo? O prefeito estava fazendo uma festa em sua mansao hoje,", game->nomePersonagem);
            mvprintw(15,game->meioTela.x - 32, " mas durante uma queda de energia, sua esposa sumiu,");
            mvprintw(16,game->meioTela.x - 32, " quando a luz voltou a mulher estava morta!");
            mvprintw(17,game->meioTela.x - 34, ">>> Preciso que voce va ate la urgente!");
            mvprintw(19,game->meioTela.x - 30, "A ligacao cai, voce sai correndo para a garagem,");
            mvprintw(20,game->meioTela.x - 32, " entra no carro e parte em direcao a mansao do prefeito.");
            mvprintw(21,game->meioTela.x - 30, "Ao chegar no local, voce sobe as escadas e bate na porta.");
            mvprintw(22,game->meioTela.x - 30, "Quando a porta se abre voce eh surpreendido.");
            char str[5];
            getstr(str);
            game->currentScreen = OVERWORLD;
            break;

    }



    ///Meio da tela
    //mvaddch(game->meioTela.y, game->meioTela.x, 'x');

}

void Overworld(gameData * game){

    ///TESTE


    setColor(COLOR_RED, COLOR_BLACK, A_BOLD);
    if(game->devMode){

        printw("Nome do personagem: %s\n", game->nomePersonagem);
        printw("Posicao jogador: (%d, %d)\n", game->posJogador.x, game->posJogador.y);
        printw("Posicao tela: (%d, %d)\n", game->posMapa.x, game->posMapa.y);
        printw("Posicao tela anterior: (%d, %d)\n", game->posMapaAnterior.x, game->posMapaAnterior.y);
        printw("Centro do terminal: (%d, %d)\n", game->meioTela.x, game->meioTela.y);
        printw("Colisao: %d\n", game->colisao);
        printw("Ultima tecla: %c\n", game->ultimaTecla);
    }else
        printw("Pressione F1 para mostrar informacoes do jogo.\n");

    setColor(COLOR_WHITE, COLOR_BLACK, A_BOLD);
    printw("Pressione q para salvar sua posicao atual\n");
    printw("Pressione Q para sair do jogo\n");

    //DESENHA JOGADOR
    setColor(COLOR_WHITE, COLOR_BLACK, A_BOLD);
    mvaddch(game->meioTela.y, game->meioTela.x, ACS_DIAMOND);

    //DESENHA MUNDO
    DesenhaMundo(game->posMapa.x, game->posMapa.y, game->posJogador.x, game->posJogador.y, game->mapa, game);

    //INTERACAO
    if(game->interagir && game->interacaoDisponivel){
        game->currentScreen = DIALOGUE;
        //Dialogo(game->ultimaTecla, &game->interagir, game->interacaoDisponivel, game);
    }else{
        game->interagir = 0;
    }

    setColor(COLOR_WHITE, COLOR_BLACK, A_STANDOUT);
    if(game->interacaoDisponivel && !(game->interagir)){
        mvprintw(game->meioTela.y + 10, 0, " > Interacao disponivel, pressione 'e' para interagir");
        if(game->interacaoDisponivel == 4){
                setColor(COLOR_RED, COLOR_WHITE, A_STANDOUT);
                mvprintw(game->meioTela.y + 11, 0, " > Pressione F para denunciar o suspeito");
        }
    }


    // Exibe o conte�do na tela (stdscr), getch() tamb�m ativa um refresh

}

void DialogueScreen(gameData * game){

    initscr();
    printw("Hello World !!!");
	refresh();
	getch();
	game->currentScreen = OVERWORLD;
	endwin();

}
