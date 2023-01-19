#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

vector <vector<int>> G;
vector <int> color;
bool flag;

void DFS(int cur, int clr){
  
  color[cur] = clr;
  
  for(int next : G[cur]){
    if(color[next] == 0){
      if(clr == 1)
        DFS(next, 2);
      else
        DFS(next, 1);
    }
    if(color[next] == color[cur]){
      flag = false;
      return;
    }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);
  
  int T;
  cin >> T;
  while(T--){
    int v, e;
    cin >> v >> e;
    
    G.resize(v+1);
    for(int i=0; i<=v; i++){
      while(!G[i].empty())
        G[i].pop_back();
    }
    
    color.resize(v+1);
    fill(color.begin(), color.end(), 0);
    
    flag = true;

    while(e--){
      int src, dst;
      cin >> src >> dst;
      G[src].push_back(dst);
      G[dst].push_back(src);
    }
    
    for(int i=1; i<=v; i++){
      if(color[i]==0)
        DFS(i, 1);
    }

    if(flag)
      cout << "YES\n";
    else 
      cout << "NO\n";
  }
}