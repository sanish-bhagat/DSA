#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * m * m)
//! SC is O(n * m)

int wordLadder(string start, string target, vector<string> &arr)
{
    // keep track of visited words
    unordered_set<string> st(arr.begin(), arr.end());

    // queue to store words and do bfs traversal
    queue<string> words;
    words.push(start);

    int res = 0;
    int m = start.length();

    // bfs traversal -> level by level
    while (!words.empty())
    {
        // increment the curr level
        res++;
        int len = words.size();

        // iterate through all words at same level
        for (int i = 0; i < len; i++)
        {
            // fetch the curr word
            string word = words.front();
            words.pop();

            // alter one-character at a time
            for (int j = 0; j < m; j++)
            {
                // store the original char
                char ch = word[j];

                // replace the curr char with every possible lowercase alphabet
                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[j] = c;

                    // skip the word if not found in the set
                    if (st.find(word) == st.end())
                        continue;

                    // target word is found -> return level + 1
                    if (word == target)
                        return res + 1;

                    // remove the word from the set
                    st.erase(word);

                    // push the newly generated word into the queue
                    words.push(word);
                }

                // restore the original char
                word[j] = ch;
            }
        }
    }

    return 0;
}

int main()
{
    vector<string> arr = {"poon", "plee", "same",
                          "poie", "plie", "poin", "plea"};
    string start = "toon";
    string target = "plea";

    cout << wordLadder(start, target, arr) << endl;

    return 0;
}