/*
    Gabriel Mingle
    CS 33211: Operating Systems
    Dr. Qiang Guan
    Programming Assignment #2: Banker's Algorithm Problem
*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n, m, i, j, k;
    n = 5; // Number of processes
    m = 3; // Number of resources

    ifstream allocFile("alloc.txt");
    int alloc[n][m];
    if (!allocFile)
    {
        cout << "Unable to open alloc.txt";
    }

    for (int i = 0; i < n; i++)
    {
        {
            for (int j = 0; j < m; j++)
                allocFile >> alloc[i][j];
        }
    }

    ifstream maxFile("max.txt");
    int max[n][m];
    if (!maxFile)
    {
        cout << "Unable to open max.txt";
    }

    for (int i = 0; i < n; i++)
    {
        {
            for (int j = 0; j < m; j++)
                maxFile >> max[i][j];
        }
    }

    ifstream availFile("avail.txt");
    int avail[m];
    if (!availFile)
    {
        cout << "Unable to open avail.txt";
    }
    {
        for (int j = 0; j < m; j++)
            availFile >> avail[j];
    }

    return 0;
}