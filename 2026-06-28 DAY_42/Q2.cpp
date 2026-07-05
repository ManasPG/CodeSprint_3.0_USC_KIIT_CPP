#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,q,timer=0;
vector<vector<int>> g;
vector<int> val,tin,tout,flat,bit;

void dfs(int u,int p){
    tin[u]=++timer;
    flat[timer]=val[u];
    for(int v:g[u]) if(v!=p) dfs(v,u);
    tout[u]=timer;
}

void upd(int i,int x){
    while(i<=n) bit[i]+=x,i+=i&-i;
}

int sum(int i){
    int s=0;
    while(i) s+=bit[i],i-=i&-i;
    return s;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>q;
    g.resize(n+1);
    val.resize(n+1);
    tin.resize(n+1);
    tout.resize(n+1);
    flat.resize(n+1);
    bit.assign(n+1,0);

    for(int i=1;i<=n;i++) cin>>val[i];

    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,0);

    for(int i=1;i<=n;i++) upd(i,flat[i]);

    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int x,v;
            cin>>x>>v;
            upd(tin[x],v-val[x]);
            val[x]=v;
        }
        else{
            int x;
            cin>>x;
            cout<<sum(tout[x])-sum(tin[x]-1)<<"\n";
        }
    }
}