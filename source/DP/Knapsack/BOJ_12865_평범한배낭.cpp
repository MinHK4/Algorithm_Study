#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair <ll, ll>;
 
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  //freopen("inp.txt", "r", stdin);

  int N, K;
  cin >> N >> K;
  
  vector<int> dp(K+1, 0);
  dp[0] = 1;

  while(N--){
    int W, V;
    cin >> W >> V;
    for(int i=K; i>=W; i--){
      if(i==W)
        dp[i] = max(dp[i], V);
      else
        dp[i] = max(dp[i], dp[i-W] + V);
    }
  }
  cout << dp[K];
}