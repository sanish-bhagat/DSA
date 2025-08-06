#include <bits/stdc++.h>
using namespace std;

class Trie
{
    vector<Trie *> children;
    int freq;
    char ch;

public:
    Trie(char x)
    {
        freq = 0;
        ch = x;
        children = vector<Trie *>(26, NULL);
    }

    // insert word into Trie, with the freq count
    void insert(string word)
    {
        Trie *curr = this;

        for (char c : word)
        {
            if (curr->children[c - 'a'] == NULL)
                curr->children[c - 'a'] = new Trie(c);

            curr = curr->children[c - 'a'];
            curr->freq++;
        }
    }

    // find the end index of min prefix for given word
    int findPrefix(string &word)
    {
        Trie *curr = this;

        for (int i = 0; i < word.length(); i++)
        {
            curr = curr->children[word[i] - 'a'];

            // if freq is 1, we found the unique prefix
            if (curr->freq == 1)
                return i;
        }

        return word.length() - 1;
    }

    // delete the Trie
    void deleteTrie(Trie *root)
    {
        if (!root)
            return;

        for (int i = 0; i < 26; i++)
        {
            deleteTrie(root->children[i]);
            delete root->children[i];
        }
    }
};

//! TC is O(n * m)
//! SC is O(n * m)

vector<string> findPrefixes(vector<string> &arr)
{
    int n = arr.size();

    // create root node of Trie
    Trie *root = new Trie('*');

    // insert all the words into the Trie
    for (int i = 0; i < n; i++)
        root->insert(arr[i]);

    vector<string> res;

    // traverse the input arr, and find min unique prefix for each word
    for (int i = 0; i < n; i++)
    {
        string word = arr[i];

        // get end index of min prefix
        int endIndex = root->findPrefix(word);

        // add substr from start to endIndex into res
        res.push_back(word.substr(0, endIndex + 1));
    }

    // free up the Trie space
    root->deleteTrie(root);

    return res;
}

int main()
{
    vector<string> arr = {"zebra", "dog", "duck", "dove"};
    vector<string> ans = findPrefixes(arr);
    for (string val : ans)
    {
        cout << val << " ";
    }
    cout << endl;
}