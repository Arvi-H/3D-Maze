#include <iostream>
#include <sstream>
#include <fstream>

#include "MazeInterface.h"

using namespace std;

class Maze : public MazeInterface {
public:
    // 3D Maze Array Pointer
    int ***maze;
    int height, width, layers;

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
                    maze[i][j][k] = '0';
                }
            } 
        }
    }

    void setValue(int height, int width, int layer, int value) {
        maze[height][width][layer] = value;
    }
    
    bool find_maze_path() {
        
        /* 
            False -> Out of bounds, or every state is blocked, or previously visited

            True -> If this is the exit // if up down left right in or out returns true
            Visited -> If this was not the exit

            R/L -> If adjacent cell returns true set to that direction // if (recursionCall(left) {setValue(this, L)})

            False -> Maze has no solution
        */


        int i = 0; 
        int j = 0;
        int k = 0;
       
        char path = maze[i][j][k];

        bool outOfBounds = (i > height || j > width || k > layers) || (i < 0 || j < 0 || k < 0);  
        bool blocked = (maze[i][j][k] == BLOCKED);
        bool visited = (maze[i][j][k] == VISITED);

        if (outOfBounds || blocked || visited) {
            return false;
        }

        

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