#include<iostream>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch) {
            data = ch;

            for(int i=0; i<26; i++) {
                children[i] = NULL;
            }

            isTerminal = false;
        }
};

class Trie {
    public:
        TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word)  {
        //base case
        if(word.length() == 0) {
            root -> isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        //present
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
            //absent
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }

        //recursion
        insertUtil(child, word.substr(1));
    }

    //! TC is O(l)  l = length of word
    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word) {
        //base case
        if(word.length() == 0) {
            return root -> isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        //present
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
            //absent
            return false;
        }

        //recursion
        return searchUtil(child, word.substr(1));
    }

    //! TC is O(l)
    bool searchWord(string word) {
        return searchUtil(root, word);
    }

    bool prefixUtil(TrieNode* root, string prefix) {
        if(prefix.length() == 0)
            return true;

        int index = prefix[0] - 'a';
        TrieNode* child;

        if(root -> children[index] != NULL) 
            child = root -> children[index];
        else    
            return false;

        return prefixUtil(child, prefix.substr(1));
    }

    bool startsWith(string prefix) {
        return prefixUtil(root, prefix);
    }
};

//remove word =>
//search for the word and then isTerminal = false;

int main() {
    Trie* t = new Trie;
    
    t -> insertWord("arm");
    t -> insertWord("do");
    t -> insertWord("time");

    cout << "Present or not: " << t -> searchWord("time") << endl;
    cout << t -> startsWith("ti");
}