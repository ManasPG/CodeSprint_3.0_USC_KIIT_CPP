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

ListNode *getintersectionnode(ListNode *headA, ListNode *headB)
{
    ListNode *p1 = headA;
    ListNode *p2 = headB;

    while (p1 != p2)
    {
        p1 = (p1 == nullptr) ? headB : p1->next;
        p2 = (p2 == nullptr) ? headA : p2->next;
    }
    return p1;
}

int main()
{
    int n;
    cin >> n;
    ListNode *head1 = nullptr;
    ListNode *tail1 = nullptr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ListNode *node = new ListNode(x);
        if (!head1)
        {
            head1 = tail1 = node;
        }
        else
        {
            tail1->next = node;
            tail1 = node;
        }
    }
    int m;
    cin >> m;

    ListNode *head2 = nullptr;
    ListNode *tail2 = nullptr;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        ListNode *node = new ListNode(x);
        if (!head2)
        {
            head2 = node;
            tail2 = node;
        }
        else
        {
            tail2->next = node;
            tail2 = node;
        }
    }
    int X;
    cin >> X;
    if (X != -1)
    {
        ListNode *temp = head1;

        while (temp && temp->val != X)
        {
            temp = temp->next;
        }

        if (temp)
        {
            tail2->next = temp;
        }
    }
    ListNode *ans = getintersectionnode(head1, head2);

    if (ans)
        cout << ans->val;
    else
        cout << -1;
    return 0;
}