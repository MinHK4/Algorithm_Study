// https://www.acmicpc.net/problem/15650

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector<bool> check;
vector<int> ans;
int N, M;

void rcs(int cur, int idx){
  if(idx > M){
    for(int i=1; i<=M; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for(int i=cur; i<=N; i++){
    // 조합이므로 이전과 동일한 조합 안 나오게 확인해주기
    if(!check[i]){
      check[i] = true;
      ans[idx] = i;
      rcs(i+1, idx+1);
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

  rcs(1, 1);
}

/*
백트래킹으로 조합 만들기
이전에 활용했는지 여부를 확인해줘야 함
*/