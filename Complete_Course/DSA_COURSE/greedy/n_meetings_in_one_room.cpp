#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * logn)
//! SC is O(n)

// to get the smallest pair according to the end time
//? static is used so that to avoid conflict with other file fucntion's of same name
//? declaring it as static means it can be only accessed in this file, and no other file will be able to access it
static bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int maxMeetings(vector<int> start, vector<int> end)
{
    vector<pair<int, int>> pairs;

    // make pairs of start and end timeof every meeting
    for (int i = 0; i < start.size(); i++)
    {
        // pair<int, int> p = make_pair(start[i], end[i]);
        // pairs.push_back(p);
        pairs.push_back({start[i], end[i]});
    }

    // sort the pair of meetings based on the end time
    sort(pairs.begin(), pairs.end(), compare);

    // for the first meeting the count will be 1
    int count = 1;
    int ansStart = pairs[0].first;
    int ansEnd = pairs[0].second;

    // traverse the pairs of meeting, and get the max no. of meetings
    for (int i = 1; i < pairs.size(); i++)
    {
        // if curr meeting's start time is greater than previously selcted meeting's end time, then
        // increment the counter and update the end time with the curr meeting's end time
        if (pairs[i].first > ansEnd)
        {
            count++;
            ansEnd = pairs[i].second;
        }
    }

    return count;
}

int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    int res = maxMeetings(start, end);

    cout << "Max no. of meetings: " << res << endl;
}