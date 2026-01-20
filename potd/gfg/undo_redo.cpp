#include <bits/stdc++.h>
using namespace std;

//! TC is O(1)
//! SC is O(n)

class Solution
{
    // use two stack to keep track of the state changes
    stack<string> undoStack, redoStack;
    string res = "";

public:
    void append(char x)
    {
        // store the curr state for undo
        undoStack.push(res);

        // new operation clears the redo history
        while (!redoStack.empty())
            redoStack.pop();

        // apply changes to curr state
        res += x;
    }

    void undo()
    {
        if (undoStack.empty())
            return;

        // save curr state to redo
        redoStack.push(res);

        // restore the previous state
        res = undoStack.top();
        undoStack.pop();
    }

    void redo()
    {
        if (redoStack.empty())
            return;

        // save curr state to undo
        undoStack.push(res);

        // restore the redone state
        res = redoStack.top();
        redoStack.pop();
    }

    string read()
    {
        // return the curr state
        return res;
    }
};

int main()
{
    Solution s = Solution();

    s.append('a');
    s.append('b');
    s.append('c');
    s.undo();
    cout << s.read() << endl;
    s.undo();
    cout << s.read() << endl;
    s.redo();
    cout << s.read() << endl;
    s.append('d');
    cout << s.read() << endl;
}