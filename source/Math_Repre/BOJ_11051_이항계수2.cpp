// https://www.acmicpc.net/problem/11051

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  int N, K;
  cin >> N >> K;
  
  vector<vector<int>> dp(N+1, vector<int>(K+1, 1));
  for(int i=1; i<=N; i++){
    for(int j=1; j<=K; j++)
      if(i!=j)
        dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % 10007;
  }
  cout << dp[N][K];
}

/*
이항계수 nCk = (n-1)Ck + (n-1)C(k-1) 의 핵심 아이디어 바탕으로 DP로 값 채워가기
nC0, nCn은 1이라는 점만 유심해서 풀이하기!!
*/