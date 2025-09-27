#include <bits/stdc++.h>
using namespace std;

int findMaxValue(vector<vector<int>> &mat) {

    int n = mat.size();

    int maxi = INT_MIN;

    for(int i = 0; i<n - 1; i++) {

        for(int j = 0 ; j<n - 1; j++) {

            for(int k = i + 1; k<n; k++) {

                for(int l = j + 1; l <n; l++) {

                    maxi = max(maxi, mat[k][l] - mat[i][j]);
                }
            }
        }
    }

    return maxi;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 2, -1, -4, -20},
        {-8, -3, 4, 2, 1},
        {3, 8, 6, 1, 3},
        {-4, -1, 1, 7, -6},
        {0, -4, 10, -5, 1}};


    cout << "Maximum Value is "
         << findMaxValue(mat);

    return 0;
}