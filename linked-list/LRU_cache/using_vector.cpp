#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
    int capacity;
    vector<pair<int, int>> cache;

public:
    LRUCache(int cap)
    {
        capacity = cap;
    }
    
    //! TC is O(n)
    int get(int key)
    {
        for (auto it = cache.begin(); it != cache.end(); it++)
        {
            if (it->first == key)
            {
                pair<int, int> temp = *it;
                cache.erase(it);
                cache.insert(cache.begin(), temp);
                return temp.second;
            }
        }

        return -1;
    }

    //! TC is O(n)
    void put(int key, int value)
    {
        for (auto it = cache.begin(); it != cache.end(); it++)
        {
            if (it->first == key)
            {
                it->second = value;
                pair<int, int> temp = *it;
                cache.erase(it);
                cache.insert(cache.begin(), temp);
                return;
            }
        }

        if (cache.size() == capacity)
            cache.pop_back();

        cache.insert(cache.begin(), {key, value});
    }
};

int main()
{
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cout << cache.get(2) << endl;
    cache.put(4, 4);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;

    return 0;
}