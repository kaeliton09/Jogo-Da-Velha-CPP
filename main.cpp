/*  ___       ___       ___       ___            ___       ___            ___       ___       ___       ___       ___   
   /\  \     /\  \     /\  \     /\  \          /\  \     /\  \          /\__\     /\  \     /\__\     /\__\     /\  \  
  _\:\  \   /::\  \   /::\  \   /::\  \        /::\  \   /::\  \        /:/ _/_   /::\  \   /:/  /    /:/__/_   /::\  \ 
 /\/::\__\ /:/\:\__\ /:/\:\__\ /:/\:\__\      /:/\:\__\ /::\:\__\      |::L/\__\ /::\:\__\ /:/__/    /::\/\__\ /::\:\__\
 \::/\/__/ \:\/:/  / \:\:\/__/ \:\/:/  /      \:\/:/  / \/\::/  /      |::::/  / \:\:\/  / \:\  \    \/\::/  / \/\::/  /
  \/__/     \::/  /   \::/  /   \::/  /        \::/  /    /:/  /        L;;/__/   \:\/  /   \:\__\     /:/  /    /:/  / 
             \/__/     \/__/     \/__/          \/__/     \/__/                    \/__/     \/__/     \/__/     \/__/  
                                                                                                                                  
  Projeto: Jogo da Velha
  Data: 30/01/2024
  by: Kaeliton Cardoso
  */
#include <iostream>

using namespace std;

#define C_RED "\033[31m"
#define C_PADRAO "\033[0m"
#define C_BLUE "\033[34m"


//tela inicial
void inicial(){
    cout << endl;
    cout << ".......##..#######...######....#######.....########.....###.......##.....##.########.##.......##.....##....###..." << endl;
    cout << ".......##.##.....##.##....##..##.....##....##.....##...##.##......##.....##.##.......##.......##.....##...##.##.." << endl;
    cout << ".......##.##.....##.##........##.....##....##.....##..##...##.....##.....##.##.......##.......##.....##..##...##." << endl;
    cout << ".......##.##.....##.##...####.##.....##....##.....##.##.....##....##.....##.######...##.......#########.##.....##" << endl;
    cout << ".##....##.##.....##.##....##..##.....##....##.....##.#########.....##...##..##.......##.......##.....##.#########" << endl;
    cout << ".##....##.##.....##.##....##..##.....##....##.....##.##.....##......##.##...##.......##.......##.....##.##.....##" << endl;
    cout << "..######...#######...######....#######.....########..##.....##.......###....########.########.##.....##.##.....##" << endl;
    cout << endl;
}

//definindo x ou o 1
char jogador(int opcao){
    if(opcao == 1){
        return 'x';
    }else{
        return 'o';
    }
}
//definindo x ou o 2
char jogador2(int opcao){
    if(opcao == 1){
        return 'o';
    }else{
        return 'x';
    }
}

//menu de escolha do jogador
int escolha(int vez){
    int opcao;
    cout << "Jogador " << vez << " escolha entre: " << endl;
    cout << "(1) X" << endl << "(2) Bola" << endl;
    cin >> opcao;
    return opcao;
}

//imprimindo qual icone de cada jogador
char imprindo_jogador(int vez, char posicao){
    cout << endl;
    cout << "Jogador " << vez << " escolha onde jogar: ";
    cin >> posicao;
    return posicao;
}

//zerendo tabuleiro
void zerando_tabuleiro(char tabuleiro[][3]){
    char x = 'a';
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            tabuleiro[i][j] = x;
            x++;
        }
    }
}

//imprimindo tabuleiro
void imprimindo_tabuleiro(char tabuleiro[][3]){
    cout << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(j < 2){
                if(tabuleiro[i][j] == 'o'){
                    printf(C_RED " %c" C_PADRAO, tabuleiro[i][j]);
                    cout << "  | ";
                }
                else{
                    if(tabuleiro[i][j] == 'x'){
                        printf(C_BLUE " %c" C_PADRAO, tabuleiro[i][j]);
                        cout << "  | ";
                    }else{
                        cout << " " << tabuleiro[i][j] << "  | ";
                    }
                }
            }
            else{
                if(tabuleiro[i][j] == 'o'){
                    printf(C_RED " %c" C_PADRAO, tabuleiro[i][j]);
                    cout << endl;
                }
                else{
                    if(tabuleiro[i][j] == 'x'){
                        printf(C_BLUE " %c" C_PADRAO, tabuleiro[i][j]);
                        cout << endl;
                    }
                    else{
                        cout << tabuleiro[i][j] << endl;
                    }
                }
            }
        }
        if(i < 2){
            cout << "- - - - - - - -" << endl;
        }
    }
}

//substituindo no tabuleiro
void troca(char tabuleiro[][3], int vez, char posicao, char icon, char icon2){
    switch (posicao){
        case 'a':
            if(vez == 1){
                tabuleiro[0][0] = icon;
            }
            else{
                tabuleiro[0][0] = icon2;
            }
            break;
        case 'b':
            if(vez == 1){
                tabuleiro[0][1] = icon;
            }
            else{
                tabuleiro[0][1] = icon2;
            }
            break;
        case 'c':
            if(vez == 1){
                tabuleiro[0][2] = icon;
            }
            else{
                tabuleiro[0][2] = icon2;
            }
            break;
        case 'd':
            if(vez == 1){
                tabuleiro[1][0] = icon;
            }
            else{
                tabuleiro[1][0] = icon2;
            }
            break;
        case 'e':
            if(vez == 1){
                tabuleiro[1][1] = icon;
            }
            else{
                tabuleiro[1][1] = icon2;
            }
            break;
        case 'f':
            if(vez == 1){
                tabuleiro[1][2] = icon;
            }
            else{
                tabuleiro[1][2] = icon2;
            }
            break;
        case 'g':
            if(vez == 1){
                tabuleiro[2][0] = icon;
            }
            else{
                tabuleiro[2][0] = icon2;
            }
            break;
        case 'h':
            if(vez == 1){
                tabuleiro[2][1] = icon;
            }
            else{
                tabuleiro[2][1] = icon2;
            }
            break;
        case 'i':
            if(vez == 1){
                tabuleiro[2][2] = icon;
            }
            else{
                tabuleiro[2][2] = icon2;
            }
            break;    
        default:
            while(posicao != 'a' && posicao != 'b' && posicao != 'c' && posicao != 'd' && posicao != 'e' && posicao != 'f' && posicao != 'g' && posicao != 'h' && posicao != 'i'){
                cout << "Digite uma posicao valida: ";
                cin >> posicao;
            }
            troca(tabuleiro, vez, posicao, icon, icon2);  
    }
}

//verificando vitoria e empate
int verificacao(char tabuleiro[][3], int vez){
    //primeira linha igual
    if(tabuleiro[0][0] == tabuleiro[0][1] && tabuleiro[0][0] == tabuleiro[0][2]){
        cout << endl;
        cout << "Jogador " << vez << " ganhou." << endl;
        return 1;
    }
    else{//segunda linha igual
        if(tabuleiro[1][0] == tabuleiro[1][1] && tabuleiro[1][0] == tabuleiro[1][2]){
            cout << endl;
            cout << "Jogador " << vez << " ganhou." << endl;
            return 1;
        }
        else{//terceira linha igual
            if(tabuleiro[2][0] == tabuleiro[2][1] && tabuleiro[2][0] == tabuleiro[2][2]){
                cout << endl;
                cout << "Jogador " << vez << " ganhou." << endl;
                return 1;
            }
            else{//primeira cooluna igual
                if(tabuleiro[0][0] == tabuleiro[1][0] && tabuleiro[0][0] == tabuleiro[2][0]){
                    cout << endl;
                    cout << "Jogador " << vez << " ganhou." << endl;
                    return 1;
                }
                else{//segunda coluna igual
                    if(tabuleiro[0][1] == tabuleiro[1][1] && tabuleiro[0][1] == tabuleiro[2][1]){
                        cout << endl;
                        cout << "Jogador " << vez << " ganhou." << endl;
                        return 1;
                    }
                    else{//teceira coluna igual
                        if(tabuleiro[0][2] == tabuleiro[1][2] && tabuleiro[0][2] == tabuleiro[2][2]){
                            cout << endl;
                            cout << "Jogador " << vez << " ganhou." << endl;
                            return 1;
                        }
                        else{//diagonal principal igual
                            if(tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[0][0] == tabuleiro[2][2]){
                                cout << endl;
                                cout << "Jogador " << vez << " ganhou." << endl;
                                return 1;
                            }
                            else{//diagonal secundaria
                                if(tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[0][2] == tabuleiro[2][0]){
                                    cout << endl;
                                    cout << "Jogador " << vez << " ganhou." << endl;
                                    return 1;
                                }
                                else{
                                    if((tabuleiro[0][0] == 'x' || tabuleiro[0][0] == 'o') && (tabuleiro[0][1] == 'x' || tabuleiro[0][1] == 'o') && (tabuleiro[0][2] == 'x' || tabuleiro[0][2] == 'o') && (tabuleiro[1][0] == 'x' || tabuleiro[1][0] == 'o') && (tabuleiro[1][1] == 'x' || tabuleiro[1][1] == 'o') && (tabuleiro[1][2] == 'x' || tabuleiro[1][2] == 'o') && (tabuleiro[2][0] == 'x' || tabuleiro[2][0] == 'o') && (tabuleiro[2][1] == 'x' || tabuleiro[2][1] == 'o') && (tabuleiro[2][2] == 'x' || tabuleiro[2][2] == 'o')){
                                        cout << endl;
                                        cout << "EMPATE" << endl;
                                        return 1;
                                    }
                                    else{
                                         return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
}


//trocando a vez
int troca_vez(int vez){
    if(vez == 1){
        return 2;
    }
    else{
        return 1;
    }
}

//novo jogo
int jogar_outra(){
    int num;
    cout << endl;
    cout << "Deseja Jogar Outra Partida?" << endl << "(1) SIM - (2) NAO" << endl;
    cin >> num;
    if(num == 1){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    int opcao, vez = 1, posicao, vitoria = 0, jogar_novamente = 0;
    char icon, icon2, tabuleiro[3][3];


    inicial();
    opcao = escolha(vez);

    zerando_tabuleiro(tabuleiro);
    icon = jogador(opcao);
    icon2 = jogador2(opcao);

    while(vitoria == 0){
        
        system("cls");
        imprimindo_tabuleiro(tabuleiro);
        posicao = imprindo_jogador(vez, opcao);

        troca(tabuleiro, vez, posicao, icon, icon2);
        vitoria = verificacao(tabuleiro, vez);
        if(vitoria){
            system("cls");
            vitoria = verificacao(tabuleiro, vez);
            imprimindo_tabuleiro(tabuleiro);
            jogar_novamente = jogar_outra();
            if(jogar_novamente == 1){
                zerando_tabuleiro(tabuleiro);
                vitoria = 0;
            }
        }
        vez = troca_vez(vez);
    }

    return 0;
}