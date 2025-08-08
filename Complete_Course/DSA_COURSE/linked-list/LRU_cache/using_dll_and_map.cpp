#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key, value;
    Node *prev, *next;

    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache
{
public:
    int capacity;
    unordered_map<int, Node *> cache;
    Node *head, *tail;

    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head - new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    //! TC is O(1)
    int get(int key)
    {
        if (cache.find(key) == cache.end())
            return -1;

        Node *node = cache[key];
        remove(node);
        add(node);
        return node->value;
    }

    //! TC is O(1)
    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            Node *oldNode = cache[key];
            remove(oldNode);
            delete oldNode;
        }

        Node *node = new Node(key, value);
        cache[key] = node; // map the node to key
        add(node);

        if (cache.size() > capacity)
        {
            Node *nodeToDelete = tail->prev;
            remove(nodeToDelete);
            cache.erase(nodeToDelete->key);
            delete nodeToDelete;
        }
    }

    void add(Node *node)
    {
        Node *nextNode = head->next;
        head->next = node;
        node->prev = head;
        node->next = nextNode;
        nextNode->prev = node;
    }

    void remove(Node *node)
    {
        Node *nextNode = node->next;
        Node *prevNode = node->prev;
        nextNode->prev = prevNode;
        prevNode->next = nextNode;
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