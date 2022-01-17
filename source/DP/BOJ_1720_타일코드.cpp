#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);
  
  int N;
  cin >> N;

  vector<int> dp(31, 0);
  dp[1] = 1;
  dp[2] = 3;
  for(int i=3; i<=N; i++)
    dp[i] = dp[i-1] + (dp[i-2] * 2);
  if(N == 1)
    cout << 1;
  else 
    cout << (dp[N] + (N&1? dp[N/2] : dp[N/2 + 1])) / 2;
}