#include <iostream>
#include <vector>
using namespace std;

//! TC is O(n * n)
//! SC is O(n)

vector<int> findWays(vector<vector<int>> &grid)
{
    const int MOD = 1e9 + 7;
    int n = grid.size();

    // Arrays to store the data of the "next" row below (i + 1)
    vector<int> nextWays(n, 0);

    // Initialize as unreachable (-1)
    vector<int> nextAdv(n, -1);

    // Iterate backwards from the bottom row to the top row
    for (int i = n - 1; i >= 0; i--)
    {
        vector<int> currWays(n, 0);
        vector<int> currAdv(n, -1);

        for (int j = n - 1; j >= 0; j--)
        {
            // Base Case: Bottom-right cell (The Exit)
            if (i == n - 1 && j == n - 1)
            {
                currWays[j] = 1;
                currAdv[j] = grid[i][j];
                continue;
            }

            long long totalWays = 0;
            int maxAdventure = -1;
            int cellValue = grid[i][j];

            // Option 1: Move Right (Valid for cell values 1 and 3)
            if (cellValue == 1 || cellValue == 3)
            {
                // Check if right neighbor is within boundaries and reachable
                if (j + 1 < n && currAdv[j + 1] != -1)
                {
                    totalWays = (totalWays + currWays[j + 1]) % MOD;
                    maxAdventure = max(maxAdventure, grid[i][j] + currAdv[j + 1]);
                }
            }

            // Option 2: Move Down (Valid for cell values 2 and 3)
            if (cellValue == 2 || cellValue == 3)
            {

                // Check if bottom neighbor is within boundaries and reachable
                if (i + 1 < n && nextAdv[j] != -1)
                {
                    totalWays = (totalWays + nextWays[j]) % MOD;
                    maxAdventure = max(maxAdventure, grid[i][j] + nextAdv[j]);
                }
            }

            currWays[j] = totalWays;
            currAdv[j] = maxAdventure; // Remains -1 if no valid path exists
        }

        // Move row states upwards efficiently using std::move
        nextWays = move(currWays);
        nextAdv = move(currAdv);
    }

    // Results are aggregated back at the entry point (0, 0)
    int finalPaths = nextWays[0];
    int finalAdv = (nextAdv[0] == -1) ? 0 : nextAdv[0];

    return {finalPaths, finalAdv};
}

int main()
{

    vector<vector<int>> grid = {{3, 1, 2}, {3, 3, 2}, {1, 1, 3}};

    vector<int> ans = findWays(grid);

    cout << "Paths = " << ans[0] << "\n";
    cout << "Adventure = " << ans[1] << "\n";
}