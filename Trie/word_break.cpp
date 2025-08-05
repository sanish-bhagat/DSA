#include <bits/stdc++.h>
using namespace std;

// ---------- Trie Node ----------
class TrieNode
{
public:
    TrieNode *children[26];
    bool isLeaf;

    TrieNode()
    {
        isLeaf = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

// ---------- Trie Class ----------
class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(const string &word)
    {
        TrieNode *curr = root;
        for (char c : word)
        {
            if (!curr->children[c - 'a'])
                curr->children[c - 'a'] = new TrieNode();
            curr = curr->children[c - 'a'];
        }
        curr->isLeaf = true;
    }

    bool search(const string &A, int start, vector<int> &dp)
    {
        if (start == A.size())
            return true;
        if (dp[start] != -1)
            return dp[start];

        TrieNode *curr = root;
        for (int i = start; i < A.size(); i++)
        {
            int index = A[i] - 'a';
            if (!curr->children[index])
                break;

            curr = curr->children[index];
            if (curr->isLeaf)
            {
                if (search(A, i + 1, dp))
                {
                    dp[start] = 1;
                    return true;
                }
            }
        }

        dp[start] = 0;
        return false;
    }
};

//! TC is O(n * n)
//! SC is O(m * L + n)
// m -> no of words in dict and L is length of words, n -> for dp

class Solution
{
public:
    int wordBreak(string A, vector<string> &B)
    {
        Trie tree;
        for (string &word : B)
            tree.insert(word);

        vector<int> dp(A.size(), -1); // -1: unvisited, 1: true, 0: false
        return tree.search(A, 0, dp);
    }
};

int main()
{
    vector<string> dictionary = {
        "mobile", "samsung", "sam", "sung", "ma",
        "mango", "icecream", "and", "go", "i",
        "like", "ice", "cream"};

    vector<string> testCases = {
        "ilikesamsung",
        "iiiiiiii",
        "",
        "ilikelikeimangoiii",
        "samsungandmango",
        "samsungandmangok"};

    Solution sol;
    for (const string &test : testCases)
    {
        cout << "Input: " << test << "\nOutput: ";
        cout << (sol.wordBreak(test, dictionary) ? "Yes" : "No") << "\n\n";
    }

    return 0;
}