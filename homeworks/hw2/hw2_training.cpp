#include<iostream>

using namespace std;

bool isRotation(int arr1[], int arr2[], int size){
    for (int i = 0; i < size; i++){
        bool match = true;
        for (int j = 0; j < size; j++){
            if (arr1[j] != arr2[(i+j) % size]){
                match = false;
                break;
            }
        }
        if (match) {
            return true;
        }
    }
    return false;
}

int main () {
    int size = 3;
    int arr1[size] = {6,5,4};
    int arr2[size] = {4,6,5};
    cout << isRotation(arr1,arr2,size) << endl;
    return 0;
}