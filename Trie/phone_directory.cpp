#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    bool isLeaf;
    unordered_map<char, TrieNode *> child;

    TrieNode()
    {
        isLeaf = false;
        for (char i = 'a'; i <= 'z'; i++)
            child[i] = NULL;
    }
};

TrieNode *root = NULL;

// insert the string into the Trie
void insert(string &s)
{
    int len = s.length();

    TrieNode *curr = root;

    for (int i = 0; i < len; i++)
    {
        if (curr->child[s[i]] == NULL)
            curr->child[s[i]] = new TrieNode();

        curr = curr->child[s[i]];
    }

    curr->isLeaf = true;
}

// insert the contacts[] strings into the Trie
void insertIntoTrie(string contacts[], int n)
{
    root = new TrieNode();

    for (int i = 0; i < n; i++)
        insert(contacts[i]);
}

void displayContactsUtil(TrieNode *curr, string prefix, vector<string> &matchedContacts)
{
    // if the curr ptr is the last node of the word, then we found one string with the prefix
    if (curr->isLeaf)
        matchedContacts.push_back(prefix);

    for (char i = 'a'; i <= 'z'; i++)
    {
        // recursivelly check the next node with the updated prefix
        if (curr->child[i])
            displayContactsUtil(curr->child[i], prefix + i, matchedContacts);
    }
}

//! TC is O(n * m)
//! SC is O(n * m)

vector<vector<string>> displayContacts(int n, string contacts[], string s)
{
    // insert the contact strings into the Trie
    insertIntoTrie(contacts, n);

    vector<vector<string>> res;

    // initialise the prefix key
    TrieNode *prevNode = root;
    string prefix = "";

    for (int i = 0; i < s.length(); i++)
    {
        // update the prefix
        prefix += s[i];

        // Travserse the string
        TrieNode *curr = prevNode->child[s[i]];

        // If no match found, append "0" for remaining characters
        if (curr == NULL)
        {
            while (i < s.length())
            {
                res.push_back({"0"});
                i++;
            }

            break;
        }

        // or push the matched contacts into the res
        vector<string> matchedContacts;

        displayContactsUtil(curr, prefix, matchedContacts);

        res.push_back(matchedContacts);

        // move the ptr
        prevNode = curr;
    }

    return res;
}

int main()
{
    string contacts[] = {"alice", "alicia", "bob", "bobby", "alex"};
    string searchQuery = "ali";

    vector<vector<string>> result = displayContacts(5, contacts, searchQuery);

    for (int i = 0; i < result.size(); i++)
    {
        for (string name : result[i])
        {
            cout << name << " ";
        }
        cout << endl;
    }

    return 0;
}