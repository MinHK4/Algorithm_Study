// https://www.acmicpc.net/problem/2822

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  vector<pii> score(8);
  for(int i=0; i<8; i++){
    cin >> score[i].first;
    score[i].second = i;
  }
  
  sort(score.begin(), score.end(), greater<>());

  vector<int> ans;
  int sum = 0;
  for(int i=0; i<5; i++){
    ans.push_back(score[i].second);
    sum += score[i].first;
  }
  
  sort(ans.begin(), ans.end());
  
  cout << sum << '\n';
  for(auto x : ans)
    cout << x+1 << ' ';
}