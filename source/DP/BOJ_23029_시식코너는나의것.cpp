// https://www.acmicpc.net/problem/23029

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int MAX(int a, int b, int c){
  return max(a, max(b, c));
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int N;
  cin >> N;
  vector<int> arr(N+1);
  for(int i=1; i<=N; i++)
    cin >> arr[i];
  
  vector<vector<int>> dp(N+1, vector<int>(3, 0));
  dp[1][0] = 0;
  dp[1][1] = arr[1];
  dp[1][2] = 0;

  for(int i=2; i<=N; i++){
    dp[i][0] = MAX(dp[i-1][0], dp[i-1][1], dp[i-1][2]);
    dp[i][1] = dp[i-1][0] + arr[i];
    dp[i][2] = dp[i-1][1] + arr[i]/2;
  }

  cout << MAX(dp[N][0], dp[N][1], dp[N][2]);
}

/*
dp로 값을 관리해주되 연속성도 신경써주기
dp[i][j] i번째를 j번 연속해서 먹을 경우의 최대 음식 개수
*/