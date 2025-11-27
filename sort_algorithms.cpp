#include <iostream>
using namespace std;

/*void test(int array[], int size){
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(array[j] < array[i]){
                swap(array[j], array[i]);
            }
        }
    }
}*/

void bubbleSort(int array[], int size){
    for(int i = 0; i < size - 1 ; i++){
        for(int j = 0; j < size - 1 - i; j++){
            if(array[j] > array[j + 1]){
                swap(array[j], array[j+1]);
            }
        }
    }
}

int main(){
    int size = 5;
    int array[size] = {7,10,5,6,8};
    
    bubbleSort(array, size);
    
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    return 0;
}