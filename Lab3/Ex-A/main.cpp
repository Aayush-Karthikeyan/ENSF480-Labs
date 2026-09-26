/*
 * File Name: main.cpp
 * Assignment: Lab 3 Exercise A
 * Completed By:
 *   - Sarvesh Vettrivelan
 *   - Aayush Karthikeyan
 * Submission Date: Sept. 25, 2026
 */

#include "graphicsWorld.h"
#include "curveCut.h"
#include <cstring>
#include <iostream>

int main(int argc, char* argv[]) {
    // Run the terminating error case separately from the normal demonstration.
    if (argc == 2 && std::strcmp(argv[1], "--invalid-radius") == 0) {
        CurveCut invalid(0, 0, 10, 12, 11, "INVALID CUT");
        std::cerr << "Error: invalid radius was accepted.\n";
        return 2;
    }
    GraphicsWorld graphic;
    graphic.run();
    return 0;
}
