#include <bits/stdc++.h>
using namespace std;

// TC is O(log(sum - max + 1)) * O(N)

int students(vector<int> v, int pages)
{
    int stu = 1, pagesStu = 0;

    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        if (pagesStu + v[i] <= pages)
        {
            pagesStu += v[i];
        }
        else
        {
            stu++;
            pagesStu = v[i];
        }
    }
    return stu;
}

int allocationBook(vector<int> v, int student)
{
    if (student > v.size())
        return -1;

    int low = *max_element(v.begin(), v.end());
    int high = accumulate(v.begin(), v.end(), 0);

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int noOfStu = students(v, mid);

        if (noOfStu > student)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    vector<int> v = {25, 46, 28, 49, 24};

    int student = 4;

    cout << allocationBook(v, student);
}