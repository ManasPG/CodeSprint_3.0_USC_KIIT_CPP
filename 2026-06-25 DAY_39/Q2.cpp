#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m;
vector<vector<char>> grid;
string word;


bool dfs(int r, int c, int idx, vector<vector<bool>>& vis){
  if(idx==word.size()) return true;

  if(r<0 || r>=n || c<0 || c>=n) return false;

  if(vis[r][c] || grid[r][c] !=word[idx]) return false;

  vis[r][c]=true;

  bool found=
  dfs(r+1, c, idx+1, vis) || dfs(r-1, c, idx+1, vis) || dfs(r, c+1, idx+1, vis) || dfs(r, c-1, idx+1, vis);

  vis[r][c]=false;
  return found;
}

int main(){
  cin>>n>>m;

  grid.assign(n, vector<char>(m));

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> grid[i][j];
    }
  }

  cin >> word;

  vector<vector<bool>> vis(n, vector<bool>(m,false));

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(dfs(i,j,0,vis)){
        cout<<"YES";
        return 0;
      }
    }
  }

  cout << "NO";
  return 0;
}