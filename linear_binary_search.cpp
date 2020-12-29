// Description - This program illustrates the difference between
// linear search and binary search.

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <thread>
using namespace std;

vector<int> generateList(int size){
    // generate a random list of integers
    // the range is 1 to 2*size
    srand(time(0));
    vector<int> A(size);
    for(int i = 0; i < size; i++){
        A[i] = rand() % (2*size) + 1;
    }
    return A;
}

void printList(vector<int> A){
    for (int i = 0; i < A.size(); i++){
        cout << A[i] << " ";
        if((i + 1) % 10 == 0) cout << endl;
    }
    //cout << endl;
}

int linearSearch(vector<int> A, int x){
    for(int i = 0; i < A.size(); i++){
        if(A[i] == x) return i;
    }
    return -1;
}

int binarySearch(vector<int> A, int x){
    int i = 0;
    int j = A.size() - 1;
    int m;
    while(i <= j){
        m = (i + j) / 2;
        if(x == A[m]) return m;
        if(x > A[m])  i = m + 1;
        else j = m - 1;
    }
    return -1;
}

int modifiedLinearSearch(vector<int> A, int x){
    // output the number of comparisons
    int comps = 0;
    for(int i = 0; i < A.size(); i++){
        comps++;
        if(A[i] == x) return comps;
    }
    return comps;
}

int modifiedBinarySearch(vector<int> A, int x){
    // output the number of comparisons
    int comps = 0;
    int i = 0;
    int j = A.size() - 1;
    int m;
    while(i <= j){
        comps++;
        m = (i + j) / 2;
        if(x == A[m]) return comps;
        if(x > A[m])  i = m + 1;
        else j = m - 1;
    }
    return comps;
}

int main(){
    srand(time(0));
    int size = 50;
    vector<int> A = generateList(size);
    printList(A);

    int searchVal = A[rand() % size];
    cout << "Search value: " << searchVal << endl;
    cout << "Found by linear search: " << linearSearch(A, searchVal) << endl;
    cout << endl;

    // sort the list for binary search to work
    std::sort(A.begin(), A.end());
    cout << "Sorted list: " << endl;
    printList(A);
    cout << "Found by binary search: " << binarySearch(A, searchVal) << endl;
    cout << "\nComparing linear search against binary search by generating the search 100 times " << endl;
    int experiments = 100;
    int compsLinear = 0;
    int compsBinary = 0;

    for(int i = 0; i < experiments; i++){
        A = generateList(size);
        searchVal = A[rand() % size];
        std::sort(A.begin(), A.end());
        compsLinear += modifiedLinearSearch(A, searchVal);
        compsBinary += modifiedBinarySearch(A, searchVal);

        // pause a while for the rand() gets more randomized
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
    cout << "Average number of comparisons in linear search: " << compsLinear / (double) experiments << endl;
    cout << "Average number of comparisons in binary search: " << compsBinary / (double) experiments << endl;
    return 0;
}
