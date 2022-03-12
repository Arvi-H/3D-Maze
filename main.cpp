#include <iostream>
#include <fstream>

#include "Maze.h"

using namespace std;

/**
 * Initalize 3D maze, turning 0s to "_" and 1s to "X".
*/
void initMaze(Maze maze, int layers, int height, int width, ifstream &in) {
    int input;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < layers; k++) {
                in >> input;
                 
                if (input == 0) {
                    maze.maze[i][j][k] = maze.OPEN;
                } else if (input == 1) {
                    maze.maze[i][j][k] = maze.BLOCKED;
                }
            }
        }
    } 
}

/**
 * Print 3D maze in a nice format.
*/
void printMaze(Maze maze, int height, int width, int layers, ofstream &out) {
    int count = 0;

    for (int i = 0; i < layers; i++) {
        out << "Layer " << (i+1) << endl;
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                
                if (maze.maze[i][j][k] == maze.OPEN) {
                    out << "_ ";
                } else if (maze.maze[i][j][k] == maze.BLOCKED) {
                    out << "X ";
                }
            }
            out << endl;
        }   
        out << endl;
    }
}

int main(int argc, char* argv[]) {
    // File streams
    // ifstream in (argv[1]);
    // ofstream out (argv[2]);
    ifstream in ("input.txt");
    ofstream out ("output.txt");


    // Maze size
    int height, width, layers;
    in >> height >> width >> layers;
    
    // Maze object
    Maze maze (height, width, layers);

    // Initalize maze board
    initMaze(maze, layers, height, width, in);
    
    // Print inital maze board
    out << "Solve Maze:" << endl;
    string mazeLayout = maze.toString();
    printMaze(maze, height, width, layers, out);


}   