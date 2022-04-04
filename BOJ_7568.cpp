// https://www.acmicpc.net/problem/7568

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  int N;
  cin >> N;

  vector<pii> info(N);
  for(int i=0; i<N; i++)
    cin >> info[i].first >> info[i].second;

  // Default 순위를 1로 잡아놓고 
  // 자기보가 키,몸무게가 둘 다 큰 경우에 순위 증가
  vector<int> rank(N, 1);
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
BruteForce 기법 : 하나씩 다 체크해보기
순위 결정에 있어서 default값 배정하고 그에 맞춰서 활용하기
*/