#include <bits/stdc++.h>
using namespace std;

double determinant(vector<vector<double>> &mat)
{
    int n = mat.size();
    double det = 1.0;

    // Loop over each column to perform elimination
    for (int i = 0; i < n; i++)
    {
        int pivot = i;

        // Find the row with the largest absolute value in current column for numerical stability
        for (int j = i + 1; j < n; j++)
        {
            if (fabs(mat[j][i]) > fabs(mat[pivot][i]))
                pivot = j;
        }

        // If pivot is zero (or near-zero), determinant is zero
        if (fabs(mat[pivot][i]) < 1e-9)
            return 0.0;

        // Swap current row with pivot row if needed; swapping flips determinant sign
        if (pivot != i)
        {
            swap(mat[pivot], mat[i]);
            det *= -1;
        }

        // Multiply determinant by the pivot element    
        det *= mat[i][i];
        double diag = mat[i][i];

        // Normalize pivot row to 1 (optional for elimination)
        for (int j = i; j < n; j++)
            mat[i][j] /= diag;

        // Eliminate all elements below the pivot in current column
        for (int j = i + 1; j < n; j++)
        {
            double factor = mat[j][i];

            for (int k = i; k < n; k++)
                mat[j][k] -= factor * mat[i][k];
        }
    }

    return det;
}

int numOfSpanningTree(vector<vector<int>> &graph, int n, int m)
{
    // Step 1: Build Laplacian matrix
    // L[i][i] = degree of vertex i
    // L[i][j] = -1 if edge exists between i and j, else 0
    vector<vector<double>> laplacian(n, vector<double>(n, 0));

    for (int i = 0; i < m; i++)
    {
        int u = graph[i][0];
        int v = graph[i][1];

        laplacian[u][u]++; // increment degree of u
        laplacian[v][v]++; // increment degree of v
        laplacian[u][v]--; // mark edge between u and v
        laplacian[v][u]--; // symmetric entry for undirected graph
    }

    vector<vector<double>> reduced(n - 1, vector<double>(n - 1, 0));
    
    // Step 2: Create reduced Laplacian by removing one row and column
    // This ensures the matrix is non-singular for determinant computation
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            reduced[i][j] = laplacian[i][j];
        }
    }

    // Step 3: Compute determinant of reduced matrix
    // According to Kirchhoff's theorem, this determinant equals the number of spanning trees
    double det = determinant(reduced);

    // Step 4: Round to nearest integer and return
    return static_cast<int>(llround(det));
}

int main()
{
    int v = 4;
    int e = 6;

    vector<vector<int>> graph = {
        {0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};

    cout << numOfSpanningTree(graph, v, e);

    return 0;
}