#include <iostream>
using namespace std;

int main(){
    int f1(0), f2(1), x;
    bool belongs(false);
    string seq = ": ";

    cout << "Enter a number to check if it's a Fibonacci number: ";
    cin >> x;

    while(f1 <= x){
        if (f1 == x) belongs = true;
        seq += to_string(f1) + " ";
        f2 += f1;
        f1 = f2 - f1;
    }
    
    cout << x << (belongs ? " belongs" : " does not belong")
         << " to the Fibonacci sequence." << endl;
    if (belongs) cout << "Fibonacci numbers up to " << x << seq;

    return 0;
}