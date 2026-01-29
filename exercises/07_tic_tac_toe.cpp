#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

void saveResult(string winner, int n_moves){
    ofstream file("tictactoe_result.txt", ios::app);

    if(file.is_open()){
        if(n_moves < 9){
            file << ("Winner: "+winner+"\n");
        } else{
            file << "Draw\n";
        }
        file.close();
    }
}

void showGame(char board[3][3], string message){
    //system("cls");
    system("clear");
    cout << "= TIC TAC TOE =" << endl << endl;
    for(int r = 0; r < 3; r++){
        cout << "  ";
        for(int c = 0; c < 3; c++){
            cout << " "<<board[r][c] << " ";
            if(c != 2) cout << "|";
        }
        cout << endl;
        if(r != 2) cout << "  ---+---+---" << endl;
    }
    cout << message << endl;
}

void playTicTacToe(){
    string players[2]= {"",""};
    char symbols[2] = {'X','O'};
    int i = 0, n = 0;
    string msg = "";
    char tab[3][3] = {{' ', ' ', ' '},
                      {' ', ' ', ' '},
                      {' ', ' ', ' '}
                     };

    cout << "= TIC TAC TOE =" << endl << endl;
    cout << "Enter player name (X): ";
    cin >> players[0];
    cout << "Enter player name (O): ";
    cin >> players[1];

    while(i < 9){
        int r(0), c(0);
        n = (i%2);
        string player = players[n];
        char symbol = symbols[n];
        showGame(tab, msg);

        cout << "Turn: " << players[n] << endl;
        cout << "Enter row:";
        cin >> r;
        cout << "Enter column:";
        cin >> c;

        if(r > 2 || r < 0 || c > 2 || c < 0){
            msg = "~Non-existent coordinate, try a valid one.";
            continue;
        } else if(tab[r][c] != ' '){
            msg = "~Area already filled, choose another.";
            continue;
        }

        tab[r][c] = symbols[n];
        //row
        if(tab[0][0] == symbols[n] && tab[0][0] == tab[0][1] && tab[0][0] == tab[0][2]) break;
        if(tab[1][0] == symbols[n] && tab[1][0] == tab[1][1] && tab[1][0] == tab[1][2]) break;
        if(tab[2][0] == symbols[n] && tab[2][0] == tab[2][1] && tab[2][0] == tab[2][2]) break;
        //column
        if(tab[0][0] == symbols[n] && tab[0][0] == tab[1][0] && tab[0][0] == tab[2][0]) break;
        if(tab[0][1] == symbols[n] && tab[0][1] == tab[1][1] && tab[0][1] == tab[2][1]) break;
        if(tab[0][2] == symbols[n] && tab[0][2] == tab[1][2] && tab[0][2] == tab[2][2]) break;
        //diagonal
        if(tab[0][0] == symbols[n] && tab[0][0] == tab[1][1] && tab[0][0] == tab[2][2]) break;
        if(tab[0][2] == symbols[n] && tab[0][2] == tab[1][1] && tab[0][2] == tab[2][0]) break;

        msg = "";
        i++;
    }

    showGame(tab, msg);
    if(i < 9){
        cout << (players[n]+"("+symbols[n]+")"+" won!") << endl;
    } else{
        cout << "      Draw!" << endl;
    }
    saveResult(players[n], i);
}

int main(){
    playTicTacToe();
    return 0;
}