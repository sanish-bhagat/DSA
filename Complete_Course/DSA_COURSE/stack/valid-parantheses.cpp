#include <iostream>
#include <stack>
using namespace std;

// Tc is O(N)
// SC is O(N)

bool isValidParantheses(string input)
{
    stack<char> s;
    for (int i = 0; i < input.length(); i++)
    {
        char ch = input[i];

        // if opening bracket, stack push
        // if closing bracket, stacktop check and pop

        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else
        {
            // for closing bracket
            if (!s.empty())
            {
                char top = s.top();

                if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '['))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if (s.empty())
        return true;

    else
        return false;
}

int main()
{
    string input = "[{()}]";

    if (isValidParantheses(input))
    {
        cout << "Valid Parantheses" << endl;
    }
    else
    {
        cout << "Not Valid" << endl;
    }
}