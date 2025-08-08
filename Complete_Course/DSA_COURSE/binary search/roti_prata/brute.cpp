#include <bits/stdc++.h>
using namespace std;

//! TC is O(max possible time * l)
//! SC is O(l)

int minTime(vector<int> &cook, int l, int p)
{
    //starting time
    int time = 0;
    // no. of pratas made
    int prataCount = 0;

    //track time for each cook spent
    vector<int> cookTime(l, 0);

    //track next prata for each cook
    vector<int> parataPerCook(l, 1);

    while (prataCount < p)
    {

        for (int i = 0; i < l; i++)
        {
            //check krro ki iss time tak cook prata bna pata h ya nhi
            if (cookTime[i] + (cook[i] * parataPerCook[i]) == time)
            {
                prataCount++;   //cook made one more prata
                cookTime[i] = time; //update start time
                parataPerCook[i]++; //move to next prata
            }

            if (prataCount >= p)
                break;     //or return time
        }

        time++;
    }

    //as loop increments time one extra 
    return time - 1;
}

int main()
{
    vector<int> cook = {1, 2, 3, 4};
    int l = 4;
    int p = 10;
    cout << minTime(cook, l, p);
}