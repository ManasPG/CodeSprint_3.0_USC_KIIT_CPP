#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
  int val;
  ListNode *right;
  ListNode *left;
  ListNode(int x)
  {
    val = x;
    left = right = nullptr;
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
      head = tail = node;
    }
    else
    {
      node->left = tail;
      tail->right = node;
      tail = node;
    }
  }
  tail->right = head;
  head->left = tail;

  int k;
  cin >> k;

  if (k >= n)
    k = k % n;

  for (int i = 0; i < k; i++)
  {
    head = head->left;
  }

  ListNode *temp = head->left;
  head->left = temp->right = nullptr;

  temp = head;
  while (temp)
  {
    cout << temp->val << " ";
    temp = temp->right;
  }
  return 0;
}