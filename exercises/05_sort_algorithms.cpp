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

void shellSort(int v[], int size){
    for(int gap = size/2; gap > 0; gap /= 2){
        for(int i = gap; i < size; i++){
            for(int j = i; (j - gap) >= 0; j -= gap){
                if(v[j - gap] > v[j]){
                    swap(v[j - gap], v[j]);
                }
            }
        }
    }
}

void mergeSort(int v[], int s){
    if(s == 1) return;

    int s1 = s/2;
    int s2 = s - s1;
    int array1[s1], array2[s2];
    for(int i = 0; i < s1; i++){
        array1[i] = v[i];
    }
    for(int i = 0; i < s2; i++){
        array2[i] = v[i + s1];
    }
    mergeSort(array1, s1);
    mergeSort(array2, s2);
    
    int i = 0, j = 0, k = 0;
    while(i < s1 && j < s2){
        if(array1[i] < array2[j]) v[k++] = array1[i++];
        else v[k++] = array2[j++];
    }
    
    while(i < s1) v[k++] = array1[i++];
    while(j < s2) v[k++] = array2[j++];
}

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