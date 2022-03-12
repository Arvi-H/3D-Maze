#include <iostream>
#include <fstream>

#include "Maze.h"

using namespace std;

/**
 * Print our 3D maze, replacing 0s with "_" and 1s with "X".
*/
 

void initMaze(Maze maze, int layers, int height, int width, ifstream &in) {
    int input;

    for (int i = 0; i < layers; i++) {
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                in >> input;
                
                if (input == 0) {
                    maze.setValue(j, k, i, 0);
                } else if (input == 1) {
                    maze.setValue(j, k, i, 1);
                }
            }
        }
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
    
    mazeLayout = maze.toString();
    cout << mazeLayout << endl;

}   