#ifndef MAZE
#define MAZE

#include <iostream>
#include <sstream>
#include <fstream>

#include "MazeInterface.h"

using namespace std;

class Maze : public MazeInterface {
public:
    // 3D Maze Array Pointer
    int ***maze;
    int height;
    int width;
    int layers;

    enum pathState { OPEN , BLOCKED, VISITED, EXIT, LEFT, RIGHT, UP, DOWN, OUT, IN };

    Maze(int height, int width, int layers) { 
        this->height = height;
        this->width = width;
        this->layers = layers;
    
    // Dynamically Allocate 3D Maze Array
        maze = new int **[height];
        
        for (int i = 0; i < height; i++) {
            maze[i] = new int *[width];
            
            for (int j = 0; j < width; j++) {
                maze[i][j] = new int [layers];

                for (int k = 0; k < layers; k++) {
                    setValue(i, j, k, OPEN);
                }
            } 
        }
    }
    
    ~Maze() { 
        for (size_t i = 0; i < height; i++) {
            for (size_t j = 0; j < width; j++)
                delete[] maze[i][j];
            delete[] maze[i];
        }
        delete[] maze;
    }

    void setValue(int height, int width, int layer, int value) {
        maze[height][width][layer] = value;
    }
    
    bool find_maze_path() {    
        return solveMaze(0, 0, 0);
    }
    
    bool solveMaze(int i, int j, int k) {

        // Out of bounds, hit a wall, or have been down this path before 
        if (((i >= height) || (i < 0) || (j >= width) || (j < 0) || (k >= layers) || (k < 0))) {
            return false;
        } 

        if (maze[i][j][k] != OPEN) {
            return false;
        }
        
        // End of maze
        if ((i == height - 1) && (j == width - 1) && (k == layers - 1)) {
            setValue(i, j, k, EXIT);

            return true;
        }

        setValue(i, j, k, VISITED);

        if (solveMaze(i, j-1, k)) { 
            setValue(i, j, k, LEFT);
            return true; 
        };
        
        if (solveMaze(i, j+1, k)) { 
            setValue(i, j, k, RIGHT);
            return true; 
        };
        
        if (solveMaze(i-1, j, k)) { 
            setValue(i, j, k, UP);
            return true; 
        };
        
        if (solveMaze(i+1, j, k)) {
            setValue(i, j, k, DOWN);
            return true; 
        };
        
        if (solveMaze(i, j, k-1)) {
            setValue(i, j, k, OUT);
            return true; 
        };
        
        if (solveMaze(i, j, k+1)) { 
            setValue(i, j, k, IN);
            return true; 
        };


        return false;
    }


/**
 * Print 3D maze in a nice format.
*/
std::string toString() const {
    stringstream out;

    for (int i = 0; i < layers; i++) {
        out << "Layer " << (i+1) << endl;

        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {

                if (maze[j][k][i] == OPEN) {
                    out << "_ ";
                } else if (maze[j][k][i] == BLOCKED) {
                    out << "X ";
                } else if (maze[j][k][i] == VISITED) {
                    out << "* ";
                } else if (maze[j][k][i] == LEFT) {
                    out << "L ";
                } else if (maze[j][k][i] == RIGHT) {
                    out << "R ";
                } else if (maze[j][k][i] == UP) {
                    out << "U ";
                } else if (maze[j][k][i] == DOWN) {
                    out << "D ";
                } else if (maze[j][k][i] == IN) {
                    out << "I ";
                } else if (maze[j][k][i] == OUT) {
                    out << "O ";
                } else if (maze[j][k][i] == EXIT) {
                    out << "E ";
                }
            }
            out << endl;
        }   
    }
    
    return out.str();
}

};

#endif