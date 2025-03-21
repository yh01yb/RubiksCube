#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


void inputCube(vector<vector<char>>& cube) {
    string faceNames[6] = {"Front", "Back", "Left", "Right", "Top", "Bottom"};
    cout << "Enter the colors for the Rubik's Cube (6 faces, 9 colors each, use R G B Y O W):\n";
    for (int i = 0; i < 6; i++) {
        cout << "Enter 9 colors for " << faceNames[i] << " face: ";
        for (int j = 0; j < 9; j++) {
            cin >> cube[i][j];
        }
    }
}


int countSolvedFaces(const vector<vector<char>>& cube) {
    int solvedFaces = 0;
    for (int i = 0; i < 6; i++) {
        bool solved = true;
        for (int j = 1; j < 9; j++) {
            if (cube[i][j] != cube[i][0]) {
                solved = false;
                break;
            }
        }
        if (solved) solvedFaces++;
    }
    return solvedFaces;
}


int estimateMoves(const vector<vector<char>>& cube) {
    int solvedFaces = countSolvedFaces(cube);
    
    if (solvedFaces == 6) return 0;  
    if (solvedFaces >= 4) return rand() % 5 + 5;  
    if (solvedFaces >= 2) return rand() % 10 + 10; 
    
    return rand() % 10 + 20; 
}

int main() {
    srand(time(0)); 

    vector<vector<char>> cube(6, vector<char>(9));
    inputCube(cube);

    int estimatedMoves = estimateMoves(cube);
    cout << "Approximate number of moves to solve the Rubik's Cube: " << estimatedMoves << endl;

    return 0;
}
