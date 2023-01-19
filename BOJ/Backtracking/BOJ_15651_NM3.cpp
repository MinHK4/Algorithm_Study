// https://www.acmicpc.net/problem/15651

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

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
    ans[idx] = i;
    rcs(idx+1);
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  cin >> N >> M;
  ans.resize(M+1);

  rcs(1);
}

/*
백트래킹으로 중복 가능 순열 만들기
*/