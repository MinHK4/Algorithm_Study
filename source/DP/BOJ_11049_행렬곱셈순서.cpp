#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);
  
  int N;
  cin >> N;

  vector <pii> arr(N+1);
  for(int i=1; i<=N; i++)
    cin >> arr[i].first >> arr[i].second;

  vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
  
  for(int dif=1; dif<N; dif++){
    for(int i=1; i<=N-dif; i++){
      int j = i + dif;
      int min_temp = INT_MAX;
      for(int k=i; k<j; k++)
        min_temp = min(min_temp, dp[i][k] + dp[k+1][j] + (int)(arr[i].first * arr[k].second * arr[j].second));
      dp[i][j] = min_temp;
    }
  }
  cout << dp[1][N];
}