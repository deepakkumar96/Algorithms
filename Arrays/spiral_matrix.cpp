/*
Rotate a matrix by 90 degree in clockwise direction without using any extra space

Input:
1 2 3  
4 5 6
7 8 9  

----

1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16

13 9  5  1
14 10 6  2
15 11 7  3
16 12 8  4

Output:
7 4 1 
8 5 2
9 6 3

1 4 7 
2 5 8
3 6 9

*/

#include <iostream>
#include <vector>

using namespace std;

void rotateMatrix(vector<vector<int>>&);
void print(const vector<vector<int>>&);

int main() {
    
    vector<vector<int>> mat = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    cout << "Before Rotation:" << endl;
    print(mat);
    rotateMatrix(mat);
    
    cout << "\nAfter Rotation:" << endl;
    print(mat);
    return 0;
}


void print(const vector<vector<int>> &mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat.size(); j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

void rotateMatrix(vector<vector<int>> &mat) {
    int size = mat.size();
    if (size == 0) {
        return;
    }
    int totalDiagonals = size / 2;
    for (int i = 0; i < totalDiagonals; i++) {
        for (int j = i; j < size - i - 1; j++) {
            
            int t = mat[i][j]; // store first element to swap with last
            // last -> first
            mat[i][j] = mat[size - j - 1][i]; 
            
            // third -> last
            mat[size - j - 1][i] = mat[size - i - 1][size - j - 1];
            
            // second -> third
            mat[size - i - 1][size - j - 1] = mat[j][size - i - 1];
            
            // first -> second
            mat[j][size - i - 1] = t;
        }
    }
}














