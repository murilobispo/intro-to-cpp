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

void insertionSort(int v[], int s){
    for(int i = 0; i < s - 1; i++){
        for(int j = i; j >= 0; j--){
            if(v[j + 1] < v[j]){
                swap(v[j], v[j + 1]);
            } else{
                break;
            }
        }
    }
}

void selectionSort(int v[], int size){
    for(int i = 0; i < size; i++){
        int aux = i;
        for(int j = i; j < size; j++){
            if(v[j] < v[aux]){
                aux = j;
            }
        }
        swap(v[i], v[aux]);
    }
}

/*void quickSort(int array[], int size){
    
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
    
}*/

int main(){
    int size = 6;
    int array[size] =  {3, 0, 1, 4, 2, 5};
    for(int n : array){
        cout << n << " ";
    }
    cout << endl;
    selectionSort(array, size);
    for(int n : array){
        cout << n << " ";
    }
    return 0;
}