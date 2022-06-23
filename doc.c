///===========APSLib.h===========///

 ///Esse enum define dois modos que algumas fun��es podem operar:
 ///GAME para a maior parte do jogo
 ///MENU para alguns menus do jogo
enum screenMode{
    MENU,
    GAME
};



/// Para f�cil troca de informa��es, essa struct cont�m a maioria das vari�veis usadas pelas fun��es.
typedef struct gameData
{
    ///MENU INICIAL
    bool menuInicial; //Menu inicial ligado ou desligado
    int telaMenuInicial; //Pagina do menu inicial

    ///JOGO
    char nomePersonagem[50]; //Nome do personagem
    bool devMode; //Estado da op��o de mostrar as informa��es do jogo na tela
    int ultimaTecla; //Ultima tecla pressionada
    int colisao; //Estado de colis�o entre o jogador e outros elementos
    int interacaoDisponivel; //Armazena o valor da intera��o disponivel atualmente (varia de acordo com o npc que est� pr�ximo do jogador)
    int interagir; //Varia se o jogador estiver atualmente interagindo ou n�o 

    struct pos{  ///Struct criada para armazenar as duas coordenadas de diferentes elementos necess�rios para o jogo
        int x;
        int y;
    } posJogador; //Posi��o relativa do jogador com o mapa
    struct pos posMapa; //Posi��o do mapa no terminal
    struct pos posMapaAnterior; //�ltima posi��o do mapa no terminal antes de ser movido
    struct pos meioTela; //Posi��o do centro do terminal (pode mudar junto com o tamanho da tela)

    char mapa[100][100]; //Armazena uma c�pia do mapa do jogo, que � originalmente um arquivo txt
    int interactionMap[100][100]; //Outro mapa do jogo contendo somente as intera��es poss�veis

} gameData;

///GAME
void initScreen(screenMode); //Inicializa a tela de acordo com o modo escolhido (inicializa cores, liga/desliga cursor, teclas digitadas e tempo que getch pausa a tela) 
void setColor(short int fg, short int bg, chtype attr); // Namoral n fa�o a ideia doq isso faz

void initGame(gameData * game); //Inicializa os valores iniciais das vari�veis (roda uma vez na inicializa��o do programa, n�o faz parte do loop)
void handleInputs(gameData * game); //L� as teclas pressionadas e define o que elas fazem
void doUpdate(gameData * game); //Atualiza em cada itera��o, para definir valores e coisas afim
void drawScreen(gameData * game, enum screenMode); //Atualiza a tela a cada itera��o e mostra os componentes gr�ficos do jogo

///SCENES 
//Componentes gr�ficos do jogo, rodam no drawScreen
void MainMenu(gameData * game); //Menu Principal
void Overworld(gameData * game);  //Todo o resto

///WORLD
//Fun��es referentes ao mapa do jogo
void LeMundo(char* nomeArquivo, gameData * game); //Copia o mapa do txt e salva em um vetor
void DesenhaSala(int xMin, int yMin, int xMax, int yMax, char mapa[100][100], int telaOffsetX, int telaOffsetY); //Desenha alguma sala do jogo, usado v�rias vezes no DesenhaMundo
void DesenhaMundo(const int ,const int ,const int,const int, char mapa[100][100]); //Desenha o mapa do jogo
void DetectaColisoes(char mapa[100][100], int posJogadorX, int posJogadorY, int *colidindo); //Detecta se o jogador est� colidindo com alguma coisa

///INTERACTIONS
void Dialogo(int a, int* interagir, int npcNum, gameData * game); //Gerencia que dialogo mostrar na tela
int DetectaInteracoes(int interactionMap[100][100], int x, int y); //Detecta se tem alguma intera��o dispon�vel ao redor

///DIALOGOS DOS PERSONAGENS
//Todas as conversas dos personagens est�o nas seguintes fun��es:
void prefeito(gameData * game); 
void policial(gameData * game);
void corpo(gameData * game);
void policial_2 (gameData * game);
void professor(gameData * game);
void filho(gameData * game);
void mordomo(gameData * game);
