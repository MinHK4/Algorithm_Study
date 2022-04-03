// https://www.acmicpc.net/problem/2422

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  int N, M;
  cin >> N >> M;

  // 가능한 조합인지 체크할 수 있는 2차원 bool 벡터 활용
  vector<vector<bool>> cons(N+1, vector<bool>(N+1, true));
  while(M--){
    int a, b;
    cin >> a >> b;
    cons[a][b] = false;
    cons[b][a] = false;
  }

  int ans = 0;
  
  // 하나씩 조합 넣어서 만들어보기
  // 조합 만들때 가능한지 체크하고 반복문 돌리기
  for(int i=1; i<=N-2; i++){
    for(int j=i+1; j<=N-1; j++){
      if(cons[i][j]){
        for(int k=j+1; k<=N; k++){
          if(cons[i][j] && cons[i][k] && cons[j][k])
            ans++;
        }
      }
    }
  }

  cout << ans;
}

/*
Bruteforce 기법을 사용해서 다 확인해주기
그대로 하나씩 다 조합을 만들면 200C3(~10^6) * 10^4이라서 시간초과가 뜸

- 시간초과 발생

가능한 조합인지 체크할 수 있는 2차원 bool 벡터 활용해서
조합체크하면서 반복문 돌리기
*/