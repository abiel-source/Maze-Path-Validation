#pragma once
#include "Maze.hpp"

//Driver code
int main()
{
    // PROMPT USER
    // ===========
    std::string userDoesCustomizeResponse;
    std::cout << "\nwould you like to create your own maze? (y/n) ";
    std::cin >> userDoesCustomizeResponse;
    bool userDoesCustomize = (userDoesCustomizeResponse == "y") ? true : false;

    // INITIALIZE DATA
    // ===============
    int** maze = createMaze(userDoesCustomize);
    int fx = 3;
    int fy = 4;
    
    // RESULTS
    // =======
    printf("\n");
    std::string res = (isReachable(maze, fx, fy)) ? "\nPATH FOUND!\n" : "\nNO PATH POSSIBLE!\n";
    res += "Where starting point = top left and finish point = bottom right\n";
    std::cout << res;

    // PRINT MAZE MAP
    // ==============
    printMazeMap(maze);
    printf("\n");

    return 0;
}