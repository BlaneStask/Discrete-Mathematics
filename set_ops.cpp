// Description - This program implements set operations without using built-in
// functions/libraries that perform set operations. The set operations are union,
// intersection, difference, and symmetric difference.

#include <iostream>
#include <vector>
using namespace std;

bool isMember(int x, vector<int> A){
    // return TRUE if x is found in A,
    // return FALSE otherwise
    for(int e : A)
        if(x == e) return true;
    return false;
}

bool isSubset(vector<int> A, vector<int> B){
    // return FALSE if there's an element in A that is NOT in B.
    // return TRUE otherwise
    for(int e : A)
        if(!isMember(e, B)) return false;
    return true;
}

bool isEqual(vector<int> A, vector<int> B){
    return (isSubset(A, B) && isSubset(B, A));
}

vector<int> myUnion(vector<int> A, vector<int> B){
    vector<int> C = A;
    for(int e : B)
        if(!isMember(e, A)) C.push_back(e);
    return C;
}

vector<int> myIntersect(vector<int> A, vector<int> B){
    vector<int> C;
    for(int e : A)
        if(isMember(e, B)) C.push_back(e);
    return C;
}

vector<int> myDiff(vector<int> A, vector<int> B){
    vector<int> C;
    for(int e : A)
        if(!isMember(e, B)) C.push_back(e);
    return C;
}

vector<int> mySymDiff(vector<int> A, vector<int> B){
    vector<int> C;
    for(int e : A)
        if(!isMember(e, B)) C.push_back(e);
    for(int e : B)
        if(!isMember(e, A)) C.push_back(e);
    return C;
}

void printSet(vector<int> A){
    if(A.size() == 0) cout << "Empty";
    else{
        for(int e : A) cout << e << " ";
    }
    cout << endl;
}

int main(){
    vector<int> A = { 1, 2, 3};
    vector<int> B = { 2, 3, 4, 5};
    vector<int> N = {};
    printSet(A);
    printSet(B);
    cout << isMember(1, A) << endl;
    cout << isMember(4, N) << endl;
    cout << isSubset(A, B) << endl;
    cout << isSubset(N, A) << endl;
    cout << isSubset(B, A) << endl;
    printSet(myUnion(A, B));
    printSet(myIntersect(A, B));
    printSet(myIntersect(A, N));
    printSet(myDiff(A, B));
    printSet(mySymDiff(A, B));
    return 0;
}

