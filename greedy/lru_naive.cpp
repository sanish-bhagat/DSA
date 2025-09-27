#include <bits/stdc++.h>
using namespace std;

//! TC is O(n * c)
//! SC is O(c)

int pageFaults(int n, int c, vector<int> &pages)
{
    // memory array
    vector<int> v;

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        // find the position of the current page
        auto it = find(v.begin(), v.end(), pages[i]);

        // if page is not present in the memory
        if (it == v.end())
        {
            // memory full
            if (v.size() == c)
            {
                v.erase(v.begin());
            }

            // push the page into the memory
            v.push_back(pages[i]);

            // increment the oage fault count
            count++;
        }
        // page is present in the memory
        else
        {

            // remove it from its previous position
            v.erase(it);

            // add it as the most recent page in the memory
            v.push_back(pages[i]);
        }
    }

    return count;
}

int main()
{

    vector<int> pages = {1, 2, 1, 4, 2, 3, 5};
    int n = 7, c = 3;

    cout << pageFaults(n, c, pages);

    return 0;
}