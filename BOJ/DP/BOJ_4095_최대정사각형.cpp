#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);
  
  int N, M;
  while(1){
    cin >> N >> M;
    if(N==0 && M==0)
      break;
    
    vector<vector<int>> arr(N+1, vector<int>(M+1));
    vector<vector<int>> dp(N+1, vector<int>(M+1, 0));
    int ans = 0;
    for(int i=1; i<=N; i++){
      for(int j=1; j<=M; j++){
        cin >> arr[i][j];
        if(arr[i][j]){
          dp[i][j] = 1;
          dp[i][j] += min(dp[i-1][j-1],min(dp[i][j-1], dp[i-1][j]));
        }
        ans = max(ans, dp[i][j]);
      }
    }
    cout << ans << '\n';
  }
}