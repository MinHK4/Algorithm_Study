// https://www.acmicpc.net/problem/11727

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  int N;
  cin >> N;

  vector <int> dp(N+1, 0);
  dp[1] = 1;
  dp[2] = 3;
  for(int i=3 ; i<=N; i++)
    dp[i] = (dp[i-1] + dp[i-2]*2) % 10007;
  cout << dp[N];
}

/*
dp[i] 길이가 i인 직사각형을 타일들로 채울 수 있는 방법의 수
하나 차이는 한 가지 방식으로 매꿀 수 있고
두 개 차이는 두 가지 방식으로 매꿀 수 있으므로
dp[i] = dp[i-1] + dp[i-2]*2
*/