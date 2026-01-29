#include <iostream>
#include <algorithm>
#include <string>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;

namespace sort {

    void bubble(int v[], int size){
        for(int i = 0; i < size - 1; i++){
            for(int j = 0; j < size - 1 - i; j++){
                if(v[j] > v[j + 1]){
                    std::swap(v[j], v[j + 1]);
                }
            }
        }
    }

    void insertion(int v[], int size){
        for(int i = 0; i < size - 1; i++){
            for(int j = i; j >= 0; j--){
                if(v[j + 1] < v[j]){
                    std::swap(v[j], v[j + 1]);
                } else break;
            }
        }
    }

    void selection(int v[], int size){
        for(int i = 0; i < size; i++){
            int min = i;
            for(int j = i; j < size; j++){
                if(v[j] < v[min]) min = j;
            }
            std::swap(v[i], v[min]);
        }
    }

    void shell(int v[], int size){
        for(int gap = size / 2; gap > 0; gap /= 2){
            for(int i = gap; i < size; i++){
                for(int j = i; j - gap >= 0; j -= gap){
                    if(v[j - gap] > v[j]){
                        std::swap(v[j - gap], v[j]);
                    }
                }
            }
        }
    }

    void merge(int v[], int size){
        if(size <= 1) return;

        int mid = size / 2;
        int left[mid], right[size - mid];

        for(int i = 0; i < mid; i++) left[i] = v[i];
        for(int i = 0; i < size - mid; i++) right[i] = v[i + mid];

        merge(left, mid);
        merge(right, size - mid);

        int i = 0, j = 0, k = 0;
        while(i < mid && j < size - mid){
            v[k++] = (left[i] < right[j]) ? left[i++] : right[j++];
        }
        while(i < mid) v[k++] = left[i++];
        while(j < size - mid) v[k++] = right[j++];
    }
}

int main(){
    string sort_algorithm[5] = {"Bubble", "Insertion", "Selection", "Shell", "Merge"} ;
    const int size = 100;
    int array[size];
    
    srand(time(nullptr));
    for(int i = 0; i < size; i++){
        array[i] = rand() % 1000;
    }
    int x = 0;
    
    cout << "Initial array: [";
    for(int i = 0; i < size; i++){
        cout << array[i];
        if (i < (size - 1)){
            cout << ", ";
        }
    }
    cout << "]" << endl << endl;
    
    cout << "Select an algorithm to sort the array by digit" << endl;
    for(int i = 0; i < 5; i++){
        cout << "[" << i << "] " << sort_algorithm[i] << endl;
    }
    cout << ">";
    
    if (cin >> x){
        auto start = std::chrono::high_resolution_clock::now();
        
        switch(x){
            case 0: sort::bubble(array, size); break;
            case 1: sort::insertion(array, size); break;
            case 2: sort::selection(array, size); break;
            case 3: sort::shell(array, size); break;
            case 4: sort::merge(array, size); break;
            default:
                cout << "Invalid input." << endl;
                return 0;
        }
        
        auto end = std::chrono::high_resolution_clock::now();
        
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        cout << "Sorted array: [";
        for(int i = 0; i < size; i++){
            cout << array[i];
            if (i < (size - 1)){
                cout << ", ";
            }
        }
        cout << "]" << endl << endl;
        cout << "Execution time: " << duration.count() << " microseconds" << endl;
            
    } else {
        cout << "Invalid input. Exiting program." << endl;
    }
    
    return 0;
}