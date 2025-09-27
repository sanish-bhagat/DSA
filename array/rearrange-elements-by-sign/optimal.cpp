#include <bits/stdc++.h>
using namespace std;

//! TC is O(n)
//! SC is O(n)

void rearrange(vector<int> &arr)
{
    int n = arr.size();

    vector<int> pos, neg;

    //pos aur neg element ko alag alag array meiin daal do
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
            pos.push_back(arr[i]);

        else
            neg.push_back(arr[i]);
    }

    int posIdx = 0, negIdx = 0, i = 0;


    while (posIdx < pos.size() && negIdx < neg.size())
    {
        if (i % 2 == 0)        //pos element h and even index pr h toh push krrdo
            arr[i++] = pos[posIdx++];

        else
            arr[i++] = neg[negIdx++];       //neg element h and odd index pr h toh push krrdo
    }

    //baaki baache pos ya neg elements ko array mein push krrdo
    while (posIdx < pos.size())
    {
        arr[i++] = pos[posIdx++];
    }

    while (negIdx < neg.size())
    {
        arr[i++] = neg[negIdx++];
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, -4, -1, 4};

    rearrange(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}