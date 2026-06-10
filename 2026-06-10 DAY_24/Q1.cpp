#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int x)
    {
        val = x;
        next = nullptr;
    }
};

int findmidnode(Node *head)
{
    Node *slow, *fast;
    slow = fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->val;
}

int main()
{
    int n;
    cin >> n;

    Node *head = nullptr;
    Node *tail = nullptr;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Node *node = new Node(x);
        if (head == nullptr)
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }

    cout << findmidnode(head);
    return 0;
}