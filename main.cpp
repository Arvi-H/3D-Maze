#include <iostream>
#include <fstream>

using namespace std;

/**
 * Print our 3D maze, replacing 0s with "_" and 1s with "X".
*/
void printMaze(int height, int width, int layers, ifstream &in, ofstream &out) {
    int input;
    
    for (int i = 0; i < layers; i++) {
        out << "Layer " << (i+1) << endl;

        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                in >> input;

                if (input == 1) {
                    out << "X" << " ";
                } else {
                    out << "_" << " ";
                }
            }
            out << endl;
        }
        out << endl; // ********** For my sanity, delete before turning it in **********
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
    
    // Print maze board
    out << "Solve Maze:" << endl;
    printMaze(height, width, layers, in, out);

    

}   