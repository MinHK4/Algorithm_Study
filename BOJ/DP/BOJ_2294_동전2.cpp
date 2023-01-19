#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);
  
  int n, k;
  cin >> n >> k;

  vector <int> coin(n+1);
  vector <vector <int>> dp(n+1, vector <int> (k+1,44444));
  for(int i=1; i<=n; i++){
    cin >> coin[i];
    
    dp[i][0] = 0;
    for(int j=1; j<=k; j++){
      if(j >= coin[i]){
        dp[i][j] = min(dp[i-1][j], dp[i][j-coin[i]]+1);
      }
      else
        dp[i][j] = dp[i-1][j];
    }
  }
  
  if(dp[n][k] == 44444)
    cout << -1;
  else
    cout << dp[n][k];
}