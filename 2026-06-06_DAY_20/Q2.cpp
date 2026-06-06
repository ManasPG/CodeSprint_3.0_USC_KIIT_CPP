#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *npx;
    Node(int x)
    {
        val = x;
        npx = nullptr;
    }
};

Node *XOR(Node *a, Node *b)
{
    return (Node *)((uintptr_t)a ^ (uintptr_t)b);
}

void insert(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *prev = nullptr;
    Node *curr = head;
    Node *next;

    while (true)
    {
        next = XOR(prev, curr->npx);
        if (next == nullptr)
        {
            break;
        }
        prev = curr;
        curr = next;
    }

    curr->npx = XOR(prev, newNode);
    newNode->npx = XOR(curr, nullptr);
}

void printList(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;
    Node *next;

    while (curr != nullptr)
    {
        cout << curr->val;
        next = XOR(prev, curr->npx);

        if (next)
            cout << " ";

        prev = curr;
        curr = next;
    }

    cout << '\n';
}

int main()
{
    int n;
    cin >> n;

    Node *head = nullptr;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        insert(head, x);
    }
    printList(head);
    return 0;
}