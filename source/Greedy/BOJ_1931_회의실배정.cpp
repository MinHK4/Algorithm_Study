// https://www.acmicpc.net/problem/1931

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

bool sortby(pii a, pii b) {
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  int N;
  cin >> N;
  
  vector <pii> v(N);
  for (int i = 0; i < N; i++) 
    cin >> v[i].first >> v[i].second;
  sort(v.begin(), v.end(), sortby);

  int ans = 0, last_end = 0;
  for (int i = 0; i < N; i++) {
    if (v[i].first < last_end)
      continue;
    ans++;
    last_end = v[i].second;
  }
  cout << ans;
}

/*
Greedy기법
강의가 끝나는 시간을 기준으로 정렬해서
시작시간 기준으로 겹치는 애들은 보내고 안 겹치는 애들만 카운트해주기
*/ 
