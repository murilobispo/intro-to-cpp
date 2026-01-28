#include <iostream>
using namespace std;

bool isAmrstrong(int n = -1) {
    int sum(0);
    for(int i = n; i > 0; i/=10){
        int digit = i%10;
        int pot = 1;
        for(int j = n; j > 0; j/=10){
            pot *= digit;
        }
        sum += pot;
    }
    return sum == n;
}

int main(){
    
    int x, y;
    cout << "Armstrong numbers in a interval\n\n";
    cout << "Enter the starting number: ";
    cin >> x;
    cout << "Enter the ending number: ";
    cin >> y;
    string numbers = "";
    
    for(int n = x; n <= y ; n++){
        if(isAmrstrong(n)){
            numbers += to_string(n) + " ";
        }
    }
    cout << "Amrstrong numbers in the interval [" << x << ", " << y << "]:"<< endl;
    cout << (numbers.empty() ? "None" : numbers);
    return 0;
}