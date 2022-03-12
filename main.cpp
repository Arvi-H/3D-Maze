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
                    maze.setValue(i, j, k, 0);
                } else if (input == 1) {
                    maze.setValue(i, j, k, 1);
                }
            }
        }
    } 
}

/**
 * Print 3D maze in a nice format.
*/
void printMaze(string mazeLayout, int height, int width, int layers, ofstream &out) {
    int count = 0;

    for (int i = 0; i < layers; i++) {
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                out << mazeLayout[count] << " ";
                count++;
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

    // Print maze board
    out << "Solve Maze:" << endl;
    string mazeLayout = maze.toString();

    cout << mazeLayout << endl;
    initMaze(maze, layers, height, width, in);
    cout << mazeLayout << endl;
    
    mazeLayout = maze.toString();
    cout << mazeLayout << endl;

    printMaze(mazeLayout, height, width, layers, out);

}   