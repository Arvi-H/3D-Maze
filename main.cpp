#include <iostream>
#include <fstream>

#include "Maze.h"

using namespace std;

/**
 * Initalize 3D maze, turning 0s to "_" and 1s to "X".
*/
void initMaze(Maze &maze, int layers, int height, int width, ifstream &in) {
    int input;

    for (int i = 0; i < layers; i++) {
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                in >> input;
                 
                if (input == 0) {
                    maze.setValue(j, k, i, maze.OPEN);
                } else if (input == 1) {
                    maze.setValue(j, k, i, maze.BLOCKED);
                }
            }
        }
    } 
}
 
int main(int argc, char* argv[]) {
    // File streams
    ifstream in (argv[1]);
    ofstream out (argv[2]);

    // Maze size
    int height, width, layers;
    in >> height >> width >> layers;
    
    // Maze object
    Maze maze (height, width, layers);

    // Initalize maze board
    initMaze(maze, layers, height, width, in);
    
    // Print inital maze board
    out << "Solve Maze:" << endl;
    out << maze.toString();

    // Print solved maze board
    if (maze.find_maze_path()) {
        out << "Solution:" << endl;
        out << maze.toString();
    } else {

        out << "No Solution Exists!" << endl;
        out << maze.toString();
    }
}   