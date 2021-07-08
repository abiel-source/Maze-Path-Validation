#pragma once
#include <cstring> // for memset
#include <iostream>
#include <stack>
#include <string>

#define N 4
#define M 5

class node
{
public:
    int x, y;

    node(int i, int j)
    {
        x = i;
        y = j;
    }
};

bool isReachable(int** maze, int fx, int fy)
{
    std::stack<node> s; // stack of nodes to go through
    int i, j;      // current location
    s.push(node(0, 0));

    if (maze[0][0] == 0)
    {
        return false;
    }

    std::stack<int> dir; // direction
    int d;          // current direction
    dir.push(3);    // initial dir set to 3
    // 3 --> right
    // 2 --> down
    // 1 --> left
    // 0 --> up

    bool visited[N][M]; // maintain state for backtracing
    memset(visited, false, sizeof(bool) * N * M);
    visited[0][0] = true;

    while (!s.empty())
    {
        i = s.top().x;
        j = s.top().y;

        d = dir.top();
        dir.top()--; // decrement BEFORE we pop a level off dir stack

        // cout << "( " << i << ", " << j << " ) " << endl;

        if (i == fx && j == fy)
        {
            return true;
        }

        if (d == 3)
        {
            if (j + 1 < M && maze[i][j + 1] == 1 && !visited[i][j + 1])
            {
                s.push(node(i, j + 1));
                dir.push(3);
                visited[i][j + 1] = true;
            }
        }
        else if (d == 2)
        {
            if (i + 1 < N && maze[i + 1][j] == 1 && !visited[i + 1][j])
            {
                s.push(node(i + 1, j));
                dir.push(3);
                visited[i + 1][j] = true;
            }
        }
        else if (d == 1)
        {
            if (j - 1 >= 0 && maze[i][j - 1] == 1 && !visited[i][j - 1])
            {
                s.push(node(i, j - 1));
                dir.push(3);
                visited[i][j - 1] = true;
            }
        }
        else if (d == 0)
        {
            if (i - 1 >= 0 && maze[i - 1][j] == 1 && !visited[i - 1][j])
            {
                s.push(node(i - 1, j));
                dir.push(3);
                visited[i - 1][j] = true;
            }
        }
        else
        {
            // exhausted all options; backtrace
            s.pop();
            dir.pop();
        }
    }

    return false;
}

// POST: 
// 
//  {1,0,1,1,0}
//  {1,1,1,0,1}
//  {0,1,0,1,1}
//  {1,1,1,1,1}
// 
// 
int** createDefaultMaze()
{
    // initialize 2d maze array
    int **maze = new int*[N];

    // initialize maze rows
    int* row0 = new int[M];
    int* row1 = new int[M];
    int* row2 = new int[M];
    int* row3 = new int[M];
    
    row0[0] = 1;
    row0[1] = 0;
    row0[2] = 1;
    row0[3] = 1;
    row0[4] = 0;

    row1[0] = 1;
    row1[1] = 0;
    row1[2] = 1;
    row1[3] = 1;
    row1[4] = 0;

    row2[0] = 1;
    row2[1] = 0;
    row2[2] = 1;
    row2[3] = 1;
    row2[4] = 0;

    row3[0] = 1;
    row3[1] = 0;
    row3[2] = 1;
    row3[3] = 1;
    row3[4] = 0;

    // attach maze rows to maze double-pointer
    maze[0] = row0;
    maze[1] = row1;
    maze[2] = row2;
    maze[3] = row3;

    return maze;
}

// prompt user row by row, column by colum
int** createMaze(bool customizeMaze)
{
    // initialize 2d array
    int **maze = new int*[N];
    for (int i = 0; i < N; i++)
    {
        maze[i] = new int[M];
    }

    if (customizeMaze)
    {
        int val;
        // get user input
        for (int i=0; i<N; i++)
        {
            for (int j=0; j<M; j++)
            {
                std::cout << std::endl;
                std::cout << "value for row " << i << "and column " << j << ": ";
                std::cin >> val;
                maze[i][j] = val;
            }
        }
        return maze;
    }

    maze = createDefaultMaze();
    return maze;
}

void printMazeMap(int** maze)
{
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}