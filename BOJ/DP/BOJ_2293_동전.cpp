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
  vector <int> dp(k+1, 0);
  for(int i=1; i<=n; i++)
    cin >> coin[i];
  
  dp[0] = 1;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=k; j++){
      if(j >= coin[i])
        dp[j] += dp[j-coin[i]];
    } 
  }
  cout << dp[k];
}