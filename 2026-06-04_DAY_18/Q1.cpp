#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

bool checkforloop(ListNode *head)
{
    ListNode *s = head;
    ListNode *f = head;

    while (f && f->next)
    {
        s = s->next;
        f = f->next->next;
        if (s == f)
            return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    for (int i = 0; i < n; i++)
    {
        int el;
        cin >> el;

        ListNode *node = new ListNode(el);

        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }

    int pos;
    cin >> pos;

    if (pos >= n)
    {
        cout << "Error";
        return 0;
    }

    if (pos != -1)
    {
        ListNode *temp = head;
        for (int i = 0; i < pos; i++)
        {
            temp = temp->next;
        }
        tail->next = temp;
    }

    if (checkforloop(head))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}