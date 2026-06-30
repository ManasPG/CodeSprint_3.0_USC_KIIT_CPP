#include<bits/stdc++.h>
using namespace std;
int main()
{
  int P;
  cin>>P;

  unordered_map<string,int> id;
  vector<int> indeg,outdeg;
  vector<vector<int>> undirected;

  auto getId=[&](const string &s) {
    if (id.count(s)) return id[s];
    int idx=id.size();
    id[s]=idx;
    indeg.push_back(0);
    outdeg.push_back(0);
    undirected.push_back({});
    return idx;
  };

  for(int i=0;i<P;i++)
    {
      string u,v;
      cin>>u>>v;

      int a=getId(u);
      int b=getId(v);

      outdeg[a]++;
      indeg[b]++;

      undirected[a].push_back(b);
      undirected[b].push_back(a);
      
    }
  
  int n=id.size();

  vector<int> vis(n,0);
  queue<int> q;

  int start = -1;
  for(int i=0;i<n;i++)
    {
      if(indeg[i]+outdeg[i]>0)
      {
        start=i;
        break;
      }
    }

  if(start!=-1)
  {
    q.push(start);
    vis[start]=1;

    while(!q.empty())
      {
        int u=q.front();
        q.pop();

        for(int v:undirected[u])
          {
            if(!vis[v])
            {
              vis[v]=1;
              q.push(v);
            }
          }
      }

    for(int i=0;i<n;i++)
      {
        if((indeg[i]+outdeg[i]>0)&& !vis[i])
        {
          cout<<"ASSEMBLY IMPOSSIBLE";
          return 0;
        }
      }
  }

  int startNodes=0,endNodes=0;

  for(int i=0;i<n;i++)
    {
      if(outdeg[i]-indeg[i]==1)
        startNodes++;
      else if(indeg[i]-outdeg[i]==1)
        endNodes++;
      else  if(indeg[i]!=outdeg[i])
      {
        cout<<"ASSEMBLY IMPOSSIBLE";
        return 0;
      }
    }

  if((startNodes==1 && endNodes==1) || (startNodes==0 && endNodes==0))
    cout<<"ASSEMBLY POSSIBLE";
  else
    cout<<"ASSEMBLY IMPOSSIBLE";

  return 0;
}