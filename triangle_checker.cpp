#include <iostream>
#include <string>
using namespace std;

string triangleType(string As, string Bs, string Cs){
    float A = stof(As), B = stof(Bs), C = stof(Cs);
    float sumAB = A + B;
    float sumAC = A + C;
    float sumBC = B + C;
    if(sumAB > C && sumAC > B && sumBC > A){
        if(A == B && B == C) return "Equilateral";
        else if(A != B && A != C && B != C) return "Scalene";
        else return "Isosceles";
    }
    return "";
} 

int main(){
    string sides[3] = {};
    cout << "Enter the lengths of the three sides of a triangle:" << endl;
    for(int i = 0; i <= 2; i++){
        cout << "Side " << i + 1 << ": ";
        cin >> sides[i];
    }
    string triangle = triangleType(sides[0], sides[1], sides[2]);
    cout << "The sides ";
    if(!triangle.empty()){
        cout << "form a " << triangle << " Triangle.";
    } else{
        cout << "DO NOT form a triangle.";
    }
    return 0;
}