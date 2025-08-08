#include<bits/stdc++.h>
using namespace std;

//Tc is O( n * log m)


//O(n)
int maxIndex(vector<vector<int>> v, int n, int m, int col) {
    int maxvalue = -1;
    int index = -1;

    for(int i=0; i<n; i++) {
        if(v[i][col] > maxvalue) {
            maxvalue = v[i][col];
            index = i;
        }
    }
    return index;
}


//O(log m)
vector<int> findPeakGrid(vector<vector<int>> v) {
    int n = v.size(), m= v[0].size();
    int low = 0, high = m - 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        int maxRowIndex = maxIndex(v,n,m,mid);
        int left = mid - 1 >= 0 ? v[maxRowIndex][mid - 1] : -1;
        int right = mid + 1 < m ? v[maxRowIndex][mid + 1] : -1;

        if(v[maxRowIndex][mid] > left && v[maxRowIndex][mid] > right) {
            return {maxRowIndex,mid};
        } else if(v[maxRowIndex][mid] < left) {
            high = mid - 1;
        } else {
            low = mid+ 1;
        }
    }
    return {-1,-1};
}

int main() {
    vector<vector<int>> v = {
        {1,2,5,1,4,5},
        {2,9,3,2,3,2},
        {1,7,6,0,1,3},
        {3,6,2,3,7,2}
    };

    vector<int> res = findPeakGrid(v);

    for(int i=0 ; i<res.size(); i++) {
        cout << res[i] << " " ;
    }
}