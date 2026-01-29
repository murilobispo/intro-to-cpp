#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

void initializeBoard(char* p, char* aux_p, int size){
    for(int i = 0; i < (size*size); i++){
        p[i] = '0';
        aux_p[i] = '~';
    }
    srand(time(0));
    p[(rand() % (size*size))] = '1';
}

void printBoard(int size, char visual[5][5], char real[5][5], string msg = ""){
        cout << "= BATTLESHIP =" << endl;
        cout << "    0 1 2 3 4 X" << endl << endl;
        for(int i = 0; i < size; i++){
            cout  << i << "   ";
            for(int j = 0; j < size; j++){
                if(real[i][j] == 'x'){
                    cout << real[i][j] << " ";
                    continue;
                }
                cout << visual[i][j]<< " ";
            }
            cout << endl;
        }
        cout << "Y" << endl;
        cout << msg << endl;
}
void playBattleship(int size, int *attempts){
    char board[5][5], aux_board[5][5];
    string msg("~ You have 5 attempts.");
    bool won = false;
    initializeBoard(&board[0][0],&aux_board[0][0], size);
    
    while(*attempts){
        int x(0), y(0);
        printBoard(size, aux_board, board, msg);
        cout << "Enter column(x): ";
        cin >> x;
        cout << "Enter row(y): ";
        cin >> y;
        system("clear"); // lin
        //system("cls");   // win
        
        if(x >= size || x < 0 || y >= size || y < 0){
            msg = "~ Coordinates out of bounds, try again.";
            continue;
        } else if(aux_board[y][x] == 'x'){
            msg = "~ Coordinate repeated, choose another.";
            continue;
        }

        if(board[y][x] == '1') break;
        else aux_board[y][x] = 'x';
        
        msg = "";
        --*attempts;
    }
    if(*attempts){
        msg = "\n   You Won!";
    } else{
        msg = "\n   You Lost!";
    }
    printBoard(size, board, aux_board, msg);
}

void saveHistory(int *attempts){
    string result("");
    ofstream file("history.txt", ios::app);
    
    if(*attempts)result = "Victory";
    else result = "Defeat";
    
    if(file.is_open()){
        file << (result + "\n");
        file.close();
    }
}

int main(){
    int size(5), attempts(5);
    
    playBattleship(size, &attempts);
    saveHistory(&attempts);
    
    return 0;
}