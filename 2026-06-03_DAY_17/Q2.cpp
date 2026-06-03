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

int main()
{
    int n;
    cin >> n;

    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ListNode *node = new ListNode(x);

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

    int k;
    cin >> k;

    if (k > n || k <= 0)
    {
        cout << "Error";
        return 0;
    }

    if (k == n)
    {
        ListNode *del = head;
        head = head->next;
        delete del;
    }
    else
    {

        ListNode *prev = nullptr;
        ListNode *del = head;

        for (int i = 0; i < n - k; i++)
        {
            prev = del;
            del = del->next;
        }

        prev->next = del->next;
        delete del;
    }

    ListNode *temp = head;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
}