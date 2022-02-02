#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

bool cmp(pii a, pii b){
  if(a.first == b.first)
    return a.second < b.second;
  return a.first < b.first;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int N, M;
  cin >> N >> M;

  vector<pii> v;
  int T;
  cin >> T;
  while(T--){
    int row, col;
    cin >> row >> col;
    if(row <= N && col <= M)
      v.push_back({row, col});
  }
  sort(v.begin(), v.end(), cmp);

  vector<pii> ans;
  ans.push_back(v[0]);
  for(int i=1; i<v.size(); i++){
    if(ans.back().first <= v[i].first && ans.back().second <= v[i].second)
      ans.push_back(v[i]);
    else{
      auto iter = lower_bound(ans.begin(), ans.end(), v[i], cmp);
      *iter = v[i];
    }
  }
  cout << ans.size();
}