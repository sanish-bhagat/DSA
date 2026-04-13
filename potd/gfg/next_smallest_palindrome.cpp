#include <bits/stdc++.h>
using namespace std;

// boolean func to tell whether all elements of num[] is 9 or not
bool allNines(vector<int> &num)
{
    for (int i = 0; i < num.size(); i++)
    {
        if (num[i] != 9)
            return false;
    }

    return true;
}

void nextPalindromeUtil(vector<int> &num)
{
    int n = num.size();
    int mid = n / 2;
    bool leftSmaller = false;

    int i = mid - 1;
    int j = (n % 2) ? mid + 1 : mid;

    // compare the left side with the right side
    while (i >= 0 && num[i] == num[j])
        i--, j++;

    // check if we need to increment the middle digits
    if (i < 0 || num[i] < num[j])
        leftSmaller = true;

    // copy the left half to the right half
    while (i >= 0)
    {
        num[j] = num[i];
        i--, j++;
    }

    // if middle digits needs to be incremented
    if (leftSmaller)
    {
        int carry = 1;
        i = mid - 1;

        if (n % 2 == 1)
        {
            num[mid] += carry;
            carry = num[mid] / 10;
            num[mid] %= 10;
            j = mid + 1;
        }
        else
            j = mid;

        while (i >= 0)
        {
            num[i] += carry;
            carry = num[i] / 10;
            num[i] %= 10;
            num[j++] = num[i--];
        }
    }
}

vector<int> nextPalindrome(vector<int> &num)
{
    vector<int> ans;

    // all elements are 9 -> we just increase it by once and make it palindrome
    if (allNines(num))
    {
        ans.push_back(1);

        for (int i = 1; i < num.size(); i++)
            ans.push_back(0);

        ans.push_back(1);
    }

    // generate the next smaller palindrome and return it
    else
    {
        nextPalindromeUtil(num);

        for (int i = 0; i < num.size(); i++)
            ans.push_back(num[i]);
    }

    return ans;
}

int main()
{
    vector<int> num = {9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2};
    vector<int> res = nextPalindrome(num);

    for (int x : res)
        cout << x << " ";
}