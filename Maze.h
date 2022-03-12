#include <iostream>
#include <sstream>
#include <fstream>

#include "MazeInterface.h"

using namespace std;

class Maze : public MazeInterface {
public:
    // 3D Maze Array Pointer
    char ***maze;
    int height, width, layers;

    Maze(int height, int width, int layers) {
        this->height = height;
        this->width = width;
        this->layers = layers;
    
    // Dynamically Allocate 3D Maze Array
        maze = new char **[height];
        
        for (int i = 0; i < height; i++) {
            maze[i] = new char *[width];
            
            for (int j = 0; j < width; j++) {
                maze[i][j] = new char [layers];

                for (int k = 0; k < layers; k++) {
                    maze[i][j][k] = '0';
                }
            } 
        }
    }

    void setValue(int height, int width, int layer, int value) {
        if (value == 0) {
            maze[height][width][layer] = '_';
        } else if (value == 1) {
            maze[height][width][layer] = 'X';
        }
        
    }
    
    bool find_maze_path() {
        std::cout << "FIX ME" << std::endl;
        return false;
    }

    std::string toString() const {
        stringstream out;
    
        for (int i = 0; i < layers; i++) {
            for (int j = 0; j < height; j++) { 
                for (int k = 0; k < width; k++) {
                    out << maze[i][j][k];
                }
            }
        }
        
        return out.str();
    }

};