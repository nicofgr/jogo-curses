#include "../APSLib.h"

void policialTeste(gameData * game){

    setlocale(LC_ALL, "Portuguese");
    printf("AQUI");
    p0();

    return 0;

}

///ARVORE
void p0(){
    int opt = 0;
    ///DIALOGO
    printf("\n\n##########O policial James, um velho amigo de infancia abre a porta e lhe recebe.##########\n\n");
    printf("Policial James - Vamos entre, a chuva esta muito forte, afinal de contas, o que faz aqui? N�o sabia que tamb�m era amigo do prefeito.\n");
    ///OPCOES
    printf(" 1 - Ol� James.\n");
    printf(" 2 - Eu recebi uma liga��o falando sobre um assassinato.\n");
    printf(" 3 - EU?! O QUE VOCE FAZ AQUI?\n");

    fflush(stdin);
    switch(getch()){
        case '1':
            p1();
        case '2':
            p2();
        case '3':
            p3();
        default:
            p0();
    }
}

void p1(){
    int opt = 0;
    ///DIALOGO
    printf("\n\n Policial James - Ol� de novo, mas me conte logo, o que voc� faz aqui?\n");

    ///OPCOES
    printf(" 1 - Ah, eu fui chamado para resolver algum assassinato ou algo assim.\n");
    printf(" 2 - Eu recebi uma liga��o falando sobre um assassinato.\n");
    printf(" 3 - Eu n�o vou te falar nada seu ot�rio.\n");


    fflush(stdin);
    switch(getch()){
        case '1':
            p2();
        case '2':
            p2();
        case '3':
            p3();
        default:
            p1();
    }
}

void p2(){
    int opt = 0;
    ///DIALOGO
    printf("\n\nPolicial James - Ah sim, entao tambem te chamaram, e o seguinte, o prefeito resolveu dar uma festa aqui hoje, mas nao acabou muito bem. Na verdade, a mulher dele esta morta la no banheiro, e pra piorar ninguem viu quem foi por causa das luzes terem se apagado.\n");

    ///OPCOES
    printf(" 1 - Entendo, os convidados ainda est�o a� dentro? \n");
    printf(" 2 - Um assassinato as cegas, hmmm. O prefeito esta a�? \n");
    printf(" 3 - Compreendo... Algum suspeito?\n");

    fflush(stdin);
    switch(getch()){
        case '1':
            p21();
        case '2':
            p21();
        case '3':
            p113();
        default:
            p2();
    }
}

void p21(){
    int opt = 0;
    ///DIALOGO
     printf("\n\nPolicial James - Claro! O prefeito esta no quarto aqui atr�s, os outros convidados est�o ai pela mans�o.\n");
    ///OPCOES

    fflush(stdin);
    switch(getch()){
        default:
            main();
    }
}

void p113(){
    int opt = 0;
    ///DIALOGO
    printf("\n\nPolicial James � Algum? Sinceramente, boa sorte em descobrir quem foi o culpado, ela tinha muitos... Bem... �Inimigos� assim digamos.\n");

    ///OPCOES
    printf(" 1- Inimigos? \n");
    printf(" 2- Entendi, vou entrar e procurar o prefeito para interroga-lo. \n");
    printf(" 3- Inimigos �? Vou averiguar a cena do crime\n");

    fflush(stdin);
    switch(getch()){
        case '1':
            p1131();
        default:
            main();
    }
}

void p1131(){
    int opt = 0;
    ///DIALOGO
    printf("\n\nPolicial James - �, inimigos, que Deus o tenha, mas para falar a verdade, ela era insuportavel, sempre se achando melhor que tudo e todos, digamos que era uma pessoa dificil de conviver...\n");

    ///OPCOES

    fflush(stdin);
    switch(getch()){
        default:
            main();
    }
}

void p3(){
    int opt = 0;
    ///DIALOGO
    printf("\n\nPolicial James � Ei! O que � isso cara, se acalma um pouco... \n");

    printf(" 1 - ME ACALMAR?! COM VOC� SEMPRE ROUBANDO MEUS CASOS?! EU VOU � TE QUEBRAR NA PORRADA! \n");
    printf(" 2 - Perd�o pelo susto, � que faz muito tempo que n�o te vejo... Mas me conta, o que aconteceu aqui? \n");
    printf(" 3 - **Ir embora** \n");

    ///OPCOES

    fflush(stdin);
    switch(getch()){
        case '1':
            p31();
        case '2':
            p32();
        case '3':
            p33();
        default:
            p3();
    }
}

void p31(){
    int opt = 0;
    ///DIALOGO
    printf("\n\nPolicial James � Olha o jeito que voc� fala comigo! Vai para parede com as m�os na cabe�a!!! ");
    printf("\n\n##########Nisso, James saca sua arma e aponta contra voc�.##########");
    printf("\n\nPolicial James - Ja chega %s, n�o � a primeira vez que voc� usa de desacato para me tirar do s�rio! Voc� vai para cadeia. ","nome");
    printf("\n\n##########Policial James algema suas m�os e leva voc� para a viatura.##########");
    printf("##########VOC� VAI PARA CADEIA ##########");

    ///OPCOES

    fflush(stdin);
    switch(getch()){
        default:
            main();
    }
}

void p32(){
    int opt = 0;
    ///DIALOGO
    printf("Policial James � T� t�, mas me conta logo, o que voc� faz aqui? \n");
    printf("1- Ah, eu fui chamado para resolver algum assassinato ou algo assim.\n");
    printf(" 2- Eu recebi uma ligacao falando sobre um assassinato.\n");
    printf(" 3- Eu n�o vou te falar nada seu ot�rio.\n");

    ///OPCOES

    fflush(stdin);
    switch(getch()){
        case '1':
            p2();
        case '2':
            p2();
        case '3':
            p31();
        default:
            p32();
    }
}

void p322(){
    int opt = 0;
    ///DIALOGO
    printf("\n\nPolicial James � A primeira dama foi assassinada aqui hoje durante a festa que o prefeito estava dando, mas sinceramente, boa sorte em descobrir quem foi o culpado, ela tinha muitos... Bem... �Inimigos� assim digamos.\n");
    ///OPCOES
    printf(" 1- Inimigos? \n");
    printf(" 2- Entendi, vou entrar e procurar o prefeito para interroga-lo. \n");
    printf(" 3- Inimigos �? Vou averiguar a cena do crime\n");

    fflush(stdin);
    switch(getch()){
        case '1':
            p1131();
        default:
            main();
    }
}

void p33(){
    int opt = 0;
    ///DIALOGO
    printf("Voc� chocado em rever seu velho �conhecido� de inf�ncia, se vira e vai em dire��o ao seu carro, ignorando a chuva, voc� abre a porta do seu carro, entra, liga o motor e vai para casa descansar.\n");

    ///OPCOES

    fflush(stdin);
    switch(getch()){
        default:
            main();
    }
}




