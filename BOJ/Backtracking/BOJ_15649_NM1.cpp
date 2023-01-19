// https://www.acmicpc.net/problem/15649

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector<bool> check;
vector<int> ans;
int N, M;

void rcs(int idx){
  if(idx > M){
    for(int i=1; i<=M; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for(int i=1; i<=N; i++){
    if(!check[i]){
      check[i] = true;
      ans[idx] = i;
      rcs(idx+1);
      check[i] = false;   
    }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  cin >> N >> M;
  check.resize(N+1, false);
  ans.resize(M+1);

  rcs(1);
}

/*
백트래킹으로 순열 만들기
이전에 활용했는지 여부를 확인해줘야 함
*/