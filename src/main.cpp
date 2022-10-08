//============================================================================
// Name        : main.cpp
// Author      : Lucas Kelley
// Version     :
// Copyright   : Your copyright notice
// Description : Rat Maze C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;

bool ratSolve(int** matrix, int a, int b, int size, int** solution);

int main(){
    int mazeSize;
    cout << "Enter the size of the maze" << endl;
    cin >> mazeSize;
    int** maze = new int*[mazeSize];
    for (int i = 0; i < mazeSize; i++) {
        maze[i] = new int[mazeSize];
    }
    for (int i = 0; i < mazeSize; i++){
        for (int j = 0; j < mazeSize; j++){
            cin >> maze[i][j];
        }
    }
    int** solutionMaze = new int*[mazeSize];
    for (int i = 0; i < mazeSize; i++) {
        solutionMaze[i] = new int[mazeSize];
        for (int j = 0; j < mazeSize; j++){
            solutionMaze[i][j] = 0;
        }
    }
    if(ratSolve(maze, 0, 0, mazeSize, solutionMaze)){
        cout << endl << "Output" << endl;
        for (int i = 0; i < mazeSize; i++){
            for (int j = 0; j < mazeSize; j++){
                cout << solutionMaze[i][j];
                cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

bool ratSolve(int** matrix, int a, int b, int size, int** solution){
    if((a == size-1) && (b == size-1)){
        solution[a][b] = 1;
        return true;
    }
    if((a < size) && (b < size) && (matrix[a][b] == 1)){
        solution[a][b] = 1;
        if(ratSolve(matrix, a, b+1, size, solution))
        	return true;
        if(ratSolve(matrix, a+1, b, size, solution))
        	return true;
        solution[a][b] = 0;
        return false;
    }
    return false;
}
