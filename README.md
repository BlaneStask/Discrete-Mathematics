# Discrete Mathematics and its Applications

These are the progams from CMPSC360 at Penn State University. In this course we worked on the study of logics, data structures and the analysis of algorithms.

## Library Headers

```C++
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <thread>
using namespace std;
```

## Matrix operations

Here is a sample function to find the transpose from the matrix_op.cpp program:

```C++
vector<vector<int>> tranpose(vector<vector<int>> A) {
    int nrow = A.size();
    int ncol = A[0].size();

    vector<vector<int>> AT(ncol, vector<int> (nrow));
    for (int i = 0; i < nrow; i++)
        for (int j = 0; j < ncol; j++)
            AT[j][i] = A[i][j];

    return AT;
}
```

And here is the binary search function from the linear_binary_search.cpp program:

```C++
int binarySearch(vector<int> A, int x) {
    int i = 0;
    int j = A.size() - 1;
    int m;
    while (i <= j) {
        m = (i + j) / 2;
        if (x == A[m]) return m;
        if (x > A[m])  i = m + 1;
        else j = m - 1;
    }
    return -1;
}
```
