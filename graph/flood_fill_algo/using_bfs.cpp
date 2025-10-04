#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m)
//! SC is O(n * m)

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    // starting point is alredy colored with the new color
    if (image[sr][sc] == newColor)
        return image;

    // traversal directions from every pixel(up, down, left and right)
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // store the color of the starting pixel
    int oldColor = image[sr][sc];

    // queue for bfs traversal
    queue<pair<int, int>> q;

    // push the starting pixel into queue
    q.push({sr, sc});

    while (!q.empty())
    {
        pair<int, int> front = q.front();
        q.pop();

        // curr pixel
        int x = front.first, y = front.second;

        // explore the adjacent pixels in all the 4 directions
        for (const pair<int, int> &direction : directions)
        {
            int nx = x + direction.first;
            int ny = y + direction.second;

            // pixel in boundary and curr pixel have the same original color ->
            // update it and push the curr pixel into the queue
            if (nx >= 0 && nx < image.size() && ny >= 0 && ny < image[0].size() && image[nx][ny] == oldColor)
            {
                image[nx][ny] = newColor;
                q.push({nx, ny});
            }
        }
    }

    return image;
}

int main()
{
    // Input image (2D grid)
    vector<vector<int>> image = {
        {1, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 1, 1}};

    // Starting pixel (row, col)
    int sr = 1, sc = 2;

    // New color to apply
    int newColor = 2;

    // Perform flood fill and get the result
    vector<vector<int>> result = floodFill(image, sr, sc, newColor);

    // Print the updated image
    for (auto &row : result)
    {
        for (auto &pixel : row)
        {
            cout << pixel << " ";
        }
        cout << "\n";
    }
    return 0;
}