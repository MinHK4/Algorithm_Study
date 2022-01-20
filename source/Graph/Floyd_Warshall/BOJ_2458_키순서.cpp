#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

#define INF 40000

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);
  
  int v, e;
  cin >> v >> e;
  vector<vector<int>> relation(v+1, vector<int>(v+1, INF));
  
  for(int i=1; i<=v; i++)
    relation[i][i] = 0;

  while(e--){
    int small, big;
    cin >> small >> big;
    relation[small][big] = 1;
  }

  for(int mid=1; mid<=v; mid++){
    for(int src=1; src<=v; src++){
      for(int dst=1; dst<=v; dst++)
        relation[src][dst] = min(relation[src][dst], relation[src][mid]+relation[mid][dst]); 
    }
  }

  int ans = 0;
  for(int i=1; i<=v; i++){
    bool flag = true;
    for(int j=1; j<=v; j++){
      if(relation[i][j]==INF && relation[j][i] == INF)
        flag = false;
    }
    if(flag)
     ans++;
  }
  cout << ans;
}