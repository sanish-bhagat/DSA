#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &image, int x, int y, int oldColor, int newColor)
{
    // base case: pixel out of boundary or color mismatches -> return
    if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size() || image[x][y] != oldColor)
        return;

    // update the color of the curr pixel
    image[x][y] = newColor;

    // recursively visit all the adjacent pixels(up, down, right and left)
    dfs(image, x + 1, y, oldColor, newColor);
    dfs(image, x - 1, y, oldColor, newColor);
    dfs(image, x, y + 1, oldColor, newColor);
    dfs(image, x, y - 1, oldColor, newColor);
}

//! TC is O(m * n)
//! SC is O(m * n)

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    // starting pixel is already colored with newcolor
    if (image[sr][sc] == newColor)
        return image;

    // store the color of the starting pixel
    int oldColor = image[sr][sc];

    // perform dfs recursively to fill the connected pixels with new color
    dfs(image, sr, sc, oldColor, newColor);

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