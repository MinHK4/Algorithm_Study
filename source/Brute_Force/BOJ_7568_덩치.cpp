// https://www.acmicpc.net/problem/7568

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int N;
  cin >> N;
  vector<pii> info(N);
  vector<int> rank(N, 1);

  for(int i=0; i<N; i++)
    cin >> info[i].first >> info[i].second;

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(i!=j && info[j].first > info[i].first && info[j].second > info[i].second)
        rank[i]++;
    }
  }
  for(int x : rank)
    cout << x << ' ';
}

/*
N 사이즈가 50밖에 안 되서 다 돌려봐도 됨
다른 모든 것들과의 관계성 체크하는 유형
어려워지면 그래프 형식의 문제로 풀이 가능할 듯
*/