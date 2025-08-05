#include <bits/stdc++.h>
using namespace std;

//! operations take TC -> O(n)

class Trie
{
public:
    // to track end of word
    bool isLeaf;

    // arr[] for children nodes of each node
    Trie *children[26];

    Trie()
    {
        isLeaf = false;

        // initialise every child node[] with null
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }

    void insert(Trie *root, string word)
    {
        Trie *curr = root;

        // traverse ever char
        for (char c : word)
        {
            // check if node for curr char exist or not
            if (curr->children[c - 'a'] == NULL)
            {
                // create a new node
                Trie *newNode = new Trie();

                // keep the refernce for the newly created node
                curr->children[c - 'a'] = newNode;
            }

            // move the curr ptr to the newly created node
            curr = curr->children[c - 'a'];
        }

        // mark the end of the word as true
        curr->isLeaf = true;
    }

    bool search(string word)
    {
        Trie *curr = this;

        // traverse every char
        for (char c : word)
        {
            // Check if the node exists for the
            // current character in the Trie
            if (curr->children[c - 'a'] == NULL)
                return false;

            // Move the curr pointer to the
            // already existing node for the
            // current character
            curr = curr->children[c - 'a'];
        }

        // Return true if the word exists
        // and is marked as ending
        return curr->isLeaf;
    }

    bool isPrefix(string &word)
    {
        Trie *curr = this;

        for (char c : word)
        {
            // Check if the node exists for the current character in the Trie
            if (curr->children[c - 'a'] == NULL)
                return false;

            // Move the curr pointer to the already existing node
            // for the current character
            curr = curr->children[c - 'a'];
        }

        // If we reach here, the prefix exists in the Trie
        return true;
    }

    bool hasNoChildren(Trie *root)
    {
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i])
                return true;
        }

        return false;
    }

    bool deleteHelper(Trie *root, string word, int depth)
    {
        // base case
        if (!root)
            return false;

        // base case, if last char of owrd is being processed
        if (depth == word.size())
        {
            // if the curr node is non-terminal and the size of the depth and word matches then return false
            if (!root->isLeaf)
                return false;

            // mark current terminal node as non-terminal
            root->isLeaf = false;

            // else return if it has children or not
            return !hasNoChildren(root);
        }

        int index = word[depth] - 'a';

        // recursivelly check for the next char
        if (deleteHelper(root->children[index], word, depth + 1))
        {
            // delete the char
            delete root->children[index];
            root->children[index] = NULL;

            // Return true if current node is not end of another word and has no other children
            return !root->isLeaf && !hasNoChildren(root);
        }

        return false;
    }

    bool deleteWord(Trie *root, string word)
    {
        if (!root || word.size() == 0)
            return false;

        return deleteHelper(root, word, 0);
    }
};

int main()
{
    Trie *root = new Trie();

    vector<string> arr = {"and", "ant", "do", "dad"};

    for (auto a : arr)
        root->insert(root, a);

    vector<string> searchKeys = {"do", "gee", "bat"};

    for (string s : searchKeys)
    {
        if (root->search(s))
            cout << "Found" << endl;
        else
            cout << "Not Found" << endl;
    }

    cout << "\n";

    vector<string> prefixKeys = {"ge", "ba", "do", "de"};
    for (string &s : prefixKeys)
    {

        if (root->isPrefix(s))
            cout << "true " << endl;
        else
            cout << "false " << endl;
    }

    root->deleteWord(root, "do");
    cout << "After deleting do: " << root->search("do") << endl; // 0
    cout << "Search dad: " << root->search("dad") << endl;       // 1

    return 0;
}