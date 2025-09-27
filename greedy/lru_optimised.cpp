#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;

    Node(int data)
    {
        this->data = data;
        next = prev = NULL;
    }
};

//! TC is O(n)
//! SC is O(c)

int pageFaults(int n, int c, vector<int> &pages)
{
    // hash map
    unordered_map<int, Node *> map;

    Node *head = NULL, *tail = NULL;
    int size = 0;
    int faults = 0;

    for (int i = 0; i < n; i++)
    {
        // page not in memory, page fault
        if (map.find(pages[i]) == map.end())
        {

            // increment the page fault count
            faults++;

            // memory is full, remove the least recently used page
            if (size == c)
            {
                map.erase(head->data);
                head = head->next;
                size--;
            }

            // insert the new page into the memory
            Node *newNode = new Node(pages[i]);

            // first page in the memory
            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
            }

            // else, push it into the end of the list, as the most recently used page
            else
            {
                newNode->prev = tail;
                tail->next = newNode;
                tail = tail->next;
            }

            // increase the size of the memory(DLL size) and insert the entry into the hashmap
            size++;
            map[pages[i]] = newNode;
        }

        // page is present in the memory
        else
        {
            // position node of the curr page
            Node *ptr = map[pages[i]];

            // if the page is the first node,
            // then remove it from the starting of the lits and
            // push it into the end of the list(as the most recently used)
            if (ptr == head)
            {
                head = head->next;
                ptr->prev = tail;
                tail->next = ptr;
                tail = tail->next;
            }
            // if page is at any intermediate node, then remove it from its previous positon and
            // push the curr page at the end as the most recently used
            else if (tail != ptr)
            {
                ptr->next->prev = ptr->prev;
                ptr->prev->next = ptr->next;
                ptr->prev = tail;
                tail->next = ptr;
                tail = tail->next;
            }
        }
    }

    return faults;
}

int main()
{

    vector<int> pages = {1, 2, 1, 4, 2, 3, 5};
    int n = 7, c = 3;

    cout << pageFaults(n, c, pages);

    return 0;
}