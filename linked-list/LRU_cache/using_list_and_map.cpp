#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
    int capacity;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> order;

public:
    LRUCache(int cap)
    {
        capacity = cap;
    }

    //! TC is O(1)
    int get(int key)
    {
        if (cache.find(key) == cache.end())
            return -1;

        else
        {
            order.splice(order.begin(), order, cache[key].second);
            return cache[key].first;
        }
    }

    //! TC is O(1)
    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            cache[key].first = value;
            order.splice(order.begin(), order, cache[key].second);
        }
        else
        {
            if (cache.size() == capacity)
            {
                int least_recently_used = order.back();
                order.pop_back();
                cache.erase(least_recently_used);
            }

            order.push_front(key);
            cache[key] = {value, order.begin()};
        }
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