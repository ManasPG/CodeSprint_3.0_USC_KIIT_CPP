#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

void reverseInorder(Node* root, int &k, int &ans) {
    if (root == NULL || k == 0)
        return;

    reverseInorder(root->right, k, ans);

    k--;
    if (k == 0) {
        ans = root->data;
        return;
    }

    reverseInorder(root->left, k, ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    Node* root = NULL;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    int K;
    cin >> K;

    int ans = 0;
    reverseInorder(root, K, ans);

    cout << ans << "\n";

    return 0;
}