#include <iostream>
#include "MazeInterface.h"

class Maze : public MazeInterface {
public:
    Maze(int height, int width, int layers) {
        // Dynamically Allocate 3D Maze Array
        int ***maze = new int **[height];
        
        // Initilize 3D Array
        for (int i = 0; i < height; i++) {
            maze[i] = new int *[width];
            
            for (int j = 0; j < width; j++) {
                maze[i][j] = new int [layers];
            }
        }
        
    }

    ~Maze();

    void setValue(int height, int width, int layer, int value) {
        std::cout << "FIX ME" << std::endl;
    }
    
    bool find_maze_path() {
        std::cout << "FIX ME" << std::endl;
        return false;
    }

    std::string toString() const {
        return "FIX ME";
    }
};