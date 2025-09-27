#include <bits/stdc++.h>
using namespace std;

struct meeting
{
    int startTime, endTime, pos;
};

// custom commpare function for sorting on the basis of endtime
bool compare(meeting m1, meeting m2)
{
    return m1.endTime < m2.endTime;
}

vector<int> maxMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();

    vector<int> res;

    // store the meetings in (start-time, end-time, pos) manner
    vector<meeting> meets(n);
    for (int i = 0; i < n; i++)
    {
        meets[i].startTime = start[i];
        meets[i].endTime = end[i];
        meets[i].pos = i + 1;
    }

    // sort the meetings based on the endtime, in increasing order
    sort(meets.begin(), meets.end(), compare);

    int currTime = -1;

    for (int i = 0; i < n; i++)
    {
        // check if the meeting room is free at the start of the ith meeting
        if (meets[i].startTime > currTime)
        {
            currTime = meets[i].endTime;
            res.push_back(meets[i].pos);
        }
    }

    sort(res.begin(), res.end());
    return res;
}

int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    vector<int> res = maxMeetings(start, end);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}