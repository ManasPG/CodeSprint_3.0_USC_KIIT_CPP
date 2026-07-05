#include <bits/stdc++.h>
using namespace std;

struct Node{
    int v;
    Node *l,*r;
    Node(int x){ v=x; l=r=NULL; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    if(n==0 || a[0]==-1) return 0;

    Node *root=new Node(a[0]);
    queue<Node*> q;
    q.push(root);

    int i=1;
    while(!q.empty() && i<n){
        Node *t=q.front();
        q.pop();

        if(i<n && a[i]!=-1){
            t->l=new Node(a[i]);
            q.push(t->l);
        }
        i++;

        if(i<n && a[i]!=-1){
            t->r=new Node(a[i]);
            q.push(t->r);
        }
        i++;
    }

    Node *first=NULL,*second=NULL,*prev=NULL,*cur=root;

    while(cur){
        if(!cur->l){
            if(prev && prev->v>cur->v){
                if(!first) first=prev;
                second=cur;
            }
            prev=cur;
            cur=cur->r;
        }
        else{
            Node *p=cur->l;
            while(p->r && p->r!=cur) p=p->r;

            if(!p->r){
                p->r=cur;
                cur=cur->l;
            }
            else{
                p->r=NULL;
                if(prev && prev->v>cur->v){
                    if(!first) first=prev;
                    second=cur;
                }
                prev=cur;
                cur=cur->r;
            }
        }
    }

    swap(first->v, second->v);

    queue<Node*> out;
    out.push(root);

    for(int k=0;k<n;k++){
        Node *t=out.front();
        out.pop();

        if(t){
            cout<<t->v;
            out.push(t->l);
            out.push(t->r);
        }
        else{
            cout<<-1;
        }

        if(k!=n-1) cout<<" ";
    }

    return 0;
}