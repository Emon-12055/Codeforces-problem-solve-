#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    int matrix[10][10];

    cout << "Enter distance matrix:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int dis[10];
    bool visit[10];

    // initialize
    for(int i = 0; i < n; i++)
    {
        dis[i] = 9999;
        visit[i] = false;
    }

    dis[0] = 0; // start city (Baghabari)

    for(int i = 0; i < n - 1; i++)
    {
        int min = 9999, u = -1;

        // find minimum distance unvisited node
        for(int j = 0; j < n; j++)
        {
            if(!visit[j] && dis[j] < min)
            {
                min = dis[j];
                u = j;
            }
        }

        visit[u] = true;

        // update neighbors
        for(int v = 0; v < n; v++)
        {
            if(matrix[u][v] != 0 &&
               dis[u] + matrix[u][v] < dis[v])
            {
                dis[v] = dis[u] + matrix[u][v];
            }
        }
    }

    // output
    cout << "\nShortest distances:\n";
    for(int i = 0; i < n; i++)
    {
        cout << dis[i] << " ";
    }

    return 0;
}

