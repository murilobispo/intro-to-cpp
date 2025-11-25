#include <iostream>
#include <string>
using namespace std;

struct Triangle{
    float sides[3];
    bool valid = false;
    string type = "None";
    Triangle(float A, float B, float C){
        sides[0] = A, sides[1] = B, sides[2] = C;
        if(A < B+C && B < A+C && C < A+B){
            valid = true;
            if(A == B && B == C) type = "Equilateral";
            else if(A != B && A != C && B != C) type = "Scalene";
            else type = "Isosceles";
        }
    }
};

int main(){
    float sides[3] = {};
    cout << "Enter the lengths of the three sides of a triangle:" << endl;
    for(int i = 0; i <= 2; i++){
        cout << "Side " << i + 1 << ": ";
        cin >> sides[i];
    }
    Triangle t(sides[0], sides[1], sides[2]);
    cout << "The sides ";
    if(t.valid) cout << "form a " << t.type << " Triangle.";
    else cout << "DO NOT form a triangle.";

    return 0;
}