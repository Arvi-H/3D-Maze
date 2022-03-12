#include <iostream>
#include "MazeInterface.h"

class Maze : public MazeInterface {
public:
    Maze();
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