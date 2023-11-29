/*
    Gabriel Mingle
    CS 33211: Operating Systems
    Dr. Qiang Guan
    Programming Assignment #2: Banker's Algorithm Problem
    Due: December 1, 2023
*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int row = 5; // Number of processes
    int col = 3; // Number of resources

    ifstream allocFile("alloc.txt");
    int alloc[row][col];
    if (!allocFile)
    {
        cout << "Unable to open alloc.txt";
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            allocFile >> alloc[i][j]; // Import alloc.txt
    }

    ifstream maxFile("max.txt");
    int max[row][col];
    if (!maxFile)
    {
        cout << "Unable to open max.txt";
    }
    for (int i = 0; i < row; i++)
    {
        {
            for (int j = 0; j < col; j++)
                maxFile >> max[i][j]; // import max.txt
        }
    }

    ifstream availFile("avail.txt");
    int avail[col];
    if (!availFile)
    {
        cout << "Unable to open avail.txt";
    }
    for (int j = 0; j < col; j++)
        availFile >> avail[j]; // Import avail.txt

    int need[row][col];
    for (int a = 0; a < row; a++)
    {
        for (int b = 0; b < col; b++)
        {
            need[a][b] = max[a][b] - alloc[a][b]; // Make need array to determine needed values
        };
    };

    bool s[row];       // Verify each operation is safe
    int sequence[row]; // Store order of operations
    int index = 0;     // Current index in sequence
    for (int k = 0; k < row; k++)
    {
        s[k] = false; // Populate safe array with false
    };
    for (int k = 0; k < row; k++)
    {
        for (int i = 0; i < row; i++)
        {
            if (s[i] == 0)
            {
                int safe = true;
                for (int j = 0; j < col; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        safe = false; // Not Safe, needs more than can be provided
                        break;
                    }
                }
                if (safe == true)
                {
                    // cout << "Available: ";
                    sequence[index++] = i;
                    for (int y = 0; y < col; y++)
                    {
                        avail[y] += alloc[i][y]; // Reclaim allocated resources
                        // cout << avail[y] << '\t';
                    }
                    // cout << endl;
                    s[i] = true;
                }
            }
        }
    };

    bool isSafe = true; // Bool because only 2 possible answers

    // Check if sequence is safe or not
    for (int i = 0; i < row; i++)
    {
        if (s[i] == false)
        {
            isSafe = false;
            // Not safe
            break;
        }
    }

    if (isSafe == true)
    {
        // Is Safe
        cout << "Following is the Safe Sequence" << endl;
        for (int i = 0; i < row - 1; i++)
            cout << " P" << sequence[i] << " ->"; // Print Correct Order
        cout << " P" << sequence[row - 1] << endl;
    }
    else
    {
        // Is not safe
        cout << "The given sequence is not safe";
    }

    return 0;
}