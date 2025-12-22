#include<iostream>

using namespace std;

int** make2DArray(int rows, int cols);
void free_2DArray(int** arr, int rows);
int recursive_sum(int arr[], int size);
bool isRotation(const int arr1[], const int arr2[], int size);

int main()
{
    // Part 1
    int rows, cols;
    while (true){
        cout << "Enter rows: ";
        cin >> rows;
        if (rows > 0){
            break;
        }
    }
    while (true){
        cout << "Enter cols: ";
        cin >> cols;
        if (cols > 0){
            break;
        }
    }
    int** new_arr = make2DArray(rows,cols);
    free_2DArray(new_arr, rows);
    
    // Part 2
    int size = 5;
    int recursive_arr[size] = {1, 2, 3, 4, 5};
    cout << "Sum of the recursive array: " << recursive_sum(recursive_arr, size) << endl;
    
    // Part 3
    int arr1[3] = {10,20,30};
    int arr2[3] = {30,10,20};
    if (isRotation(arr1,arr2,3)){
        cout << "arr2 is a rotation of arr1" << endl;
    }else{
        cout << "arr2 is not a rotation of arr1" << endl;
    }
    int arr3[4] = {1, 2, 3, 4};
    int arr4[4] = {4, 3, 2, 1};
    if (isRotation(arr3,arr4,4)){
        cout << "arr3 is a rotation of arr4" << endl;
    }else{
        cout << "arr3 is not a rotation of arr4" << endl;
    }
    return 0;
}

int** make2DArray(int rows, int cols)
{
    int** arr = new int* [rows];
    int num = 0;
    for (int i=0; i < rows; i++){
        arr[i] = new int[cols];
        for (int j=0; j < cols; j++){
            arr[i][j] = num;
            cout << arr[i][j] << " ";
            num++;
        }
        cout << endl;
    }
    return arr;
}

void free_2DArray(int** arr, int rows){
    for(int i = 0; i < rows; i++)
    {
        delete[] arr[i];
        arr[i] = nullptr;
    }
    delete[] arr;
    arr = nullptr;
}

int recursive_sum(int arr[], int size){
    if (size == 0){
        return 0;
    }
    return arr[size-1] + (recursive_sum(arr,size-1));
}

bool isRotation(const int arr1[], const int arr2[], int size){
    for (int i = 0; i < size; i++) {
        bool match = true;
        for (int j = 0; j < size; j++) {
            if (arr1[j] != arr2[(i + j) % size]) {
                match = false;
                break;
            }
        }
        if (match) return true;
    }
    return false;
}