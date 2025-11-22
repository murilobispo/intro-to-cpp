#include <iostream>
using namespace std;

void mathTable(int number,char operator_){
    for(int i = 1; i <= 10 ; i++){
        switch (operator_){
            case '+':
                cout << number << " " << operator_ << " " << i << " = " << (number+i) << endl;
                break;
            case '-':
                cout << (number+i) << " " << operator_ << " " << number << " = " << ((number+i) - number) << endl;
                break;
            case 'x':
                cout << number << " " << operator_ << " " << i << " = " << (number*i) << endl;
                break;
            case '/':
                cout << (number*i) << " " << operator_ << " " << number << " = " << (number*i) / number << endl;
                break;
        }
    }
}

int main(){
    int x = 0;
    char op = ' ';
    
    cout << "Math table generator." << endl;
    while(!(x >= 1 && x <= 10)){
        cout << "Enter a number between 1 and 10 for the math table: ";
        cin >> x;
    }
    
    while(op != '+' && op != '-' && op != 'x' && op != '/'){
        cout << "Which table of " << x << " do you want to display?" << endl;
        cout << "[+] Addition\n"
             << "[-] Subtraction\n"
             << "[x] Multiplication\n"
             << "[/] Division\n";
        cout << ">";
        cin >> op;
    }
    mathTable(x,op);
    return 0;
}