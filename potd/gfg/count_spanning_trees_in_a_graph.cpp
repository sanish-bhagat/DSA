#include <bits/stdc++.h>
using namespace std;

// Determinant using Gaussian elimination
double determinant(vector<vector<double>> mat, int n)
{
    double det = 1.0;

    for (int i = 0; i < n; i++)
    {

        // Find pivot
        int pivot = i;
        for (int j = i + 1; j < n; j++)
        {
            if (fabs(mat[j][i]) > fabs(mat[pivot][i]))
                pivot = j;
        }

        // If pivot is zero → determinant = 0
        if (fabs(mat[pivot][i]) < 1e-9)
            return 0;

        // Swap rows
        if (i != pivot)
        {
            swap(mat[i], mat[pivot]);
            det *= -1;
        }

        det *= mat[i][i];

        // Eliminate below
        for (int j = i + 1; j < n; j++)
        {
            double factor = mat[j][i] / mat[i][i];
            for (int k = i; k < n; k++)
            {
                mat[j][k] -= factor * mat[i][k];
            }
        }
    }

    return det;
}

//! TC is O(n ^ 3)
//! SC is O(n * n)

int numOfSpanningTree(int n, vector<vector<int>> &graph)
{

    // 1. Initialize Laplacian matrix with 0s
    vector<vector<double>> L(n, vector<double>(n, 0.0));

    // 2. Iterate directly through the Edge List
    for (const auto &edge : graph)
    {
        // Assuming the graph uses 0-based indexing (0 to n-1).
        // If it uses 1-based indexing, use: edge[0] - 1 and edge[1] - 1
        int u = edge[0];
        int v = edge[1];

        // Increment the diagonal (Degree)
        L[u][u] += 1;
        L[v][v] += 1;

        // Decrement the off-diagonal (Adjacency)
        // Using -1 directly handles multiple edges if any exist
        L[u][v] -= 1;
        L[v][u] -= 1;
    }

    // 3. Build the Minor matrix (crossing out the 0th row and 0th col is standard,
    // but crossing out the last row/col like you did works perfectly too!)
    vector<vector<double>> minor(n - 1, vector<double>(n - 1));

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            minor[i][j] = L[i][j];
        }
    }

    // 4. Calculate Determinant
    return (int)round(determinant(minor, n - 1));
}

int main()
{
    int v = 4;

    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 0}};

    cout << numOfSpanningTree(v, graph);

    return 0;
}