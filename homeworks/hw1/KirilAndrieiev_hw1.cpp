#include<iostream>

using namespace std;

int max(int a, int b);
void checkInterval(int x);
void checkBigNumber();
int main(){
    int m = max(1, 2);
    cout<< m << endl;
    checkInterval(10);
    checkBigNumber();
    return 0;

}

// Problem 2
int max(int a, int b){
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

// Problem 3
void checkInterval(int x){
    if ((x > 5 && x < 15) || (x > 95 && x < 202)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}

// Problem 4
void checkBigNumber(){
    int x;
    while (true) {
        cout << "Enter a number: ";
        cin >> x;
        if (x > 100) {
            cout << "Congratulations! You know about big numbers!" << endl;
            break;
        } else {
            cout << "Try again with a bigger number:" << endl;
        }
    }   
}