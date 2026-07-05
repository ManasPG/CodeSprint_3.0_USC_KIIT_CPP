#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

bool leaf(Node *x)
{
    return x && !x->left && !x->right;
}

Node *build(vector<int> &a)
{
    if (a.empty() || a[0] == -1)
        return NULL;
    Node *root = new Node(a[0]);
    queue<Node *> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < a.size())
    {
        Node *cur = q.front();
        q.pop();
        if (i < a.size() && a[i] != -1)
            q.push(cur->left = new Node(a[i]));
        i++;

        if (i < a.size() && a[i] != -1)
            q.push(cur->right = new Node(a[i]));
        i++;
    }
    return root;
}

void leaves(Node *r, vector<int> &ans)
{
    if (!r)
        return;
    if (leaf(r))
    {
        ans.push_back(r->val);
        return;
    }
    leaves(r->left, ans);
    leaves(r->right, ans);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    Node *root = build(a);
    if (!root)
        return 0;

    vector<int> ans, tmp;
    ans.push_back(root->val);

    Node *cur = root->left;
    while (cur)
    {
        if (!leaf(cur))
            ans.push_back(cur->val);
        cur = cur->left ? cur->left : cur->right;
    }

    if (!leaf(root))
        leaves(root, ans);

    cur = root->right;
    while (cur)
    {
        if (!leaf(cur))
            tmp.push_back(cur->val);
        cur = cur->right ? cur->right : cur->left;
    }

    reverse(tmp.begin(), tmp.end());
    ans.insert(ans.end(), tmp.begin(), tmp.end());

    for (int i = 0; i < ans.size(); i++)
    {
        if (i)
            cout << " ";
        cout << ans[i];
    }
}
