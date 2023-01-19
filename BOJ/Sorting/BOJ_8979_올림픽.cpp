// https://www.acmicpc.net/problem/8979

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

bool comp(vector<int> a, vector<int> b){
  if(a[1] == b[1]){
    if(a[2] == b[2])
      return a[3] > b[3];
    return a[2] > b[2];
  }
  return a[1] > b[1];
}

bool isSameRank(vector<int> a, vector<int> b){
  return a[1] == b[1] && a[2] == b[2] && a[3] == b[3];
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  int N, K;
  cin >> N >> K;

  vector<vector<int>> rank(N, vector<int>(4));
  for(int i=0; i<N; i++){
    cin >> rank[i][0] >> rank[i][1] >> rank[i][2] >> rank[i][3];
  }

  sort(rank.begin(), rank.end(), comp);

  // 현재 나보다 앞서 있는 사람 수
  int better;
  for(int i=0; i<N; i++){
    if(rank[i][0] == K){
      better = i;
      break;
    }
  }

  int sameRank = 0;
  for(int i=0; i<better; i++){
    if(isSameRank(rank[i], rank[better]))
      sameRank++;
  }

  cout << better - sameRank + 1;
}