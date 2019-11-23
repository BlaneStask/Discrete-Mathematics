// Description: this program uses an iteration algorithm and recursion to
// calculate problems

#include <iostream>
using namespace std;

double IterPower(double a, int n){
    double pow = 1;
    for (int i = 1; i <= n; i++){
        pow = pow * a;
    }
    return pow;
}

double RecurPower(double a, int n){
    if (n == 0) return 1;
    return a * RecurPower(a, n - 1);
}

double IterMult(double a, int n){
    double mult = 0;
    for (int i = 1; i <= n; i++){
        mult = mult + a;
    }
    return mult;
}

double RecurMult(double a, int n){
    if (n == 0) return 0;
    return a + RecurMult(a, n - 1);
    
}

int IterElement(int n){
    int element = 1;
    for (int i = 2; i <= n; i++){
        element = 2 * element + 1;
    }
    return element;

}

int RecurElement(int n){
    if (n == 1) return 1;
    return 2* RecurElement(n - 1) + 1;
    
}

int main(){
    cout << IterPower(2.0, 5) << endl;
    cout << RecurPower(2.0, 5) << endl;
    
    cout << IterMult(2.0, 5) << endl;
    cout << RecurMult(2.0, 5) << endl;
    
    cout << IterElement(4) << endl;
    cout << RecurElement(4) << endl;
    
    return 0;
}
