// https://www.acmicpc.net/problem/15975

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  int N;
  cin >> N;

  vector<vector<int>> arr(N+1);
  for(int i=0; i<N; i++){
    int pos, color;
    cin >> pos >> color;
    arr[color].push_back(pos);
  }

  ll ans = 0;
  for(auto cur: arr){
    if(cur.size() > 1){
      sort(cur.begin(), cur.end());
      for(int i=0; i<cur.size(); i++){
          ll close_l = (i > 0) ? cur[i] - cur[i-1] : INT_MAX;
          ll close_r = (i < cur.size() - 1) ? cur[i+1] - cur[i] : INT_MAX;
          ans += min(close_l, close_r);
      }
    }
  }

  cout << ans;
}