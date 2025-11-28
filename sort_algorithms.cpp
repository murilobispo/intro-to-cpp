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
void quickSort(int array[], int size){
    
    int pivot = array[0];
    int r = size - 1;
    int l = 0;
    while(pivot < array[r]) r--;
    array[0] = array[r];
    array[r] = pivot;
    while(pivot > l) l++;
    array[r] = array[l];
    array[l] = pivot;
    
    pivot = array[0];
    r = l - 1;
    l = 0;
    while(pivot < array[r]) r--;
    array[0] = array[r];
    array[r] = pivot;
    while(pivot > array[l]) l++;
    array[r] = array[l];
    array[l] = pivot;
    
    pivot = array[0];
    r = l - 1;
    l = 0;
    while(pivot < array[r]) r--;
    array[0] = array[r];
    array[r] = pivot;
    while(pivot > array[l]) l++;
    array[r] = array[l];
    array[l] = pivot;
    
}

int main(){
    int size = 6;
    int array[size] =  {3, 0, 1, 4, 2, 5};
    
    quickSort(array, size);
    
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    return 0;
}