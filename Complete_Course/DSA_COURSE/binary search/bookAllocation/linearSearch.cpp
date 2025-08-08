#include <bits/stdc++.h>
using namespace std;

// TC is O(sum - max + 1) * O(N)

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

int alloctaionBook(vector<int> v, int student)
{
    int low = *max_element(v.begin(), v.end());
    int high = accumulate(v.begin(), v.end(), 0);

    for (int pages = low; pages <= high; pages++)
    {
        int cntStu = students(v, pages);

        if (cntStu == student)
        {
            return pages;
        }
    }
    return -1;
}

int main()
{
    vector<int> v = {25, 46, 28, 49, 24};

    int student = 4;

    cout << alloctaionBook(v, student);
}