#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair <ll, ll>;
 
vector<vector<int>> G;
vector<bool> visited;
 
void DFS(int cur, int key){
  
  visited[cur] = true;
  if(cur == key)
    return;
  for(int next : G[cur]){
    if(!visited[next])
      DFS(next, key);
  }
}
 
 
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  //freopen("inp.txt", "r", stdin);
  
  int t;
  cin >> t;
  while(t--){
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    
    G.resize(n+1);
    for(int i=0; i<=n; i++){
      while(!G[i].empty())
        G[i].pop_back();
    }
    
    visited.resize(n+1, false);
    fill(visited.begin(), visited.end(), false);
 
    while(m--){
      int src, dst;
      cin >> src >> dst;
      G[src].push_back(dst);
      G[dst].push_back(src);
    }
 
    ll cnt1 = 0;
    DFS(a, b);
    for(int i=1; i<=n; i++){
      if(!visited[i])
        cnt1++;
    }
 
    ll cnt2 = 0;
    fill(visited.begin(), visited.end(), false);
    DFS(b, a);
    for(int i=1; i<=n; i++){
      if(!visited[i])
        cnt2++;
    }
 
    cout << (ll)cnt1 * cnt2 << '\n';
  }
}