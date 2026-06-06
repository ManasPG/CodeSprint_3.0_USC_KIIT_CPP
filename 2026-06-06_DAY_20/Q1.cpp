#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    int value;
    Node *prev;
    Node *next;

    Node(int k, int v)
    {
        key = k;
        value = v;
        prev = next = nullptr;
    }
};

class LRUCache
{
private:
    int capacity;
    unordered_map<int, Node *> mp;

    Node *head;
    Node *tail;

    void removeNode(Node *node)
    {
        Node *prevNode = node->prev;
        Node *nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertFront(Node *node)
    {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int cap)
    {
        capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;
        Node *node = mp[key];

        removeNode(node);
        insertFront(node);

        return node->value;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            Node *node = mp[key];
            node->value = value;
            removeNode(node);
            insertFront(node);
            return;
        }

        if ((int)mp.size() == capacity)
        {
            Node *lru = tail->prev;
            removeNode(lru);
            mp.erase(lru->key);
            delete lru;
        }

        Node *newNode = new Node(key, value);
        insertFront(newNode);
        mp[key] = newNode;
    }
};

int main()
{

    int capacity;
    cin >> capacity;

    int q;
    cin >> q;

    LRUCache cache(capacity);

    while (q--)
    {
        string op;
        cin >> op;

        if (op == "PUT")
        {
            int key, value;
            cin >> key >> value;
            cache.put(key, value);
        }
        else if (op == "GET")
        {
            int key;
            cin >> key;
            cout << cache.get(key) << '\n';
        }
    }
    return 0;
}