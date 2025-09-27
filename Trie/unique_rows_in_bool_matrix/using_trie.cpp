#include <bits/stdc++.h>
using namespace std;
#define ROW 4
#define COL 5

class TrieNode
{
public:
    bool isLeaf; // marks end of a row
    TrieNode *child[2];

    TrieNode()
    {
        isLeaf = false;
        child[0] = child[1] = NULL;
    }
};

void insertRow(TrieNode *root, int row[], int col, vector<vector<int>> &res)
{
    TrieNode *curr = root;
    bool isNew = false; // tracks if the curr row is new

    // insert the current row into the Trie
    for (int i = 0; i < col; i++)
    {
        if (!curr->child[row[i]])
        {
            curr->child[row[i]] = new TrieNode();
            isNew = true;
        }

        curr = curr->child[row[i]];
    }

    // if the curr row is unique then insert it into the res[][]
    if (!curr->isLeaf)
    {
        curr->isLeaf = true;
        vector<int> v(row, row + col);
        res.push_back(v);
    }
}

//! TC is O(n * m)
//! SC is O(n * m)

vector<vector<int>> findUniqueRows(int M[ROW][COL])
{
    TrieNode *root = new TrieNode();

    vector<vector<int>> res;

    // traverse each row and stire the unique ones
    for (int i = 0; i < ROW; i++)
        insertRow(root, M[i], COL, res);

    return res;
}

int main()
{
    int M[ROW][COL] = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0}};

    vector<vector<int>> res = findUniqueRows(M);

    for (auto &row : res)
    {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }

    return 0;
}