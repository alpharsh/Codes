#include <bits/stdc++.h>
using namespace std;

bool isWithinBounds(int x, int y, int gridSize, const vector<vector<char>> &grid)
{
    return x >= 0 && x < gridSize && y >= 0 && y < gridSize && grid[x][y] != 'M';
}

int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int findShortestPath(int gridSize, const vector<vector<char>> &grid, pair<int, int> source, pair<int, int> dest)
{
    vector<vector<int>> minCost(gridSize, vector<int>(gridSize, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> prior;

    prior.push({0, source});
    minCost[source.first][source.second] = 0;

    while (!prior.empty())
    {
        auto top = prior.top();
        int currentCost = top.first;
        pair<int, int> currentPos = top.second;
        int x = currentPos.first, y = currentPos.second;
        prior.pop();

        if (x == dest.first && y == dest.second)
            return currentCost;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];

            if (isWithinBounds(nx, ny, gridSize, grid))
            {
                int additionalCost = (grid[x][y] == 'T' && grid[nx][ny] == 'T') ? 0 : 1;
                int newCost = currentCost + additionalCost;

                if (newCost < minCost[nx][ny])
                {
                    minCost[nx][ny] = newCost;
                    prior.push({newCost, {nx, ny}});
                }
            }
        }
    }

    return -1; // Return -1 if no path exists.
}

int main()
{
    int gridSize;
    cin >> gridSize;
    vector<vector<char>> grid(gridSize, vector<char>(gridSize));
    pair<int, int> source, dest;

    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')
                source = {i, j};
            if (grid[i][j] == 'E')
                dest = {i, j};
        }
    }

    int result = findShortestPath(gridSize, grid, source, dest);
    cout << result << endl;

    return 0;
}

// https://youtu.be/3r4pYCrpXe8?si=gfIR2Ch_bLUT6A3P