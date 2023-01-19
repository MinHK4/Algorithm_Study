#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

vector<vector<int>> arr;
vector<vector<int>> dp;

void dfs(int row, int col){
  
  int value = 1;
  
  // 상 탐색 가능
  if(arr[row][col] < arr[row-1][col]){
    if(dp[row-1][col]==0)
      dfs(row-1, col);
    value = max(value, 1+dp[row-1][col]);
  }
  // 하 탐색 가능
  if(arr[row][col] < arr[row+1][col]){
    if(dp[row+1][col]==0)
      dfs(row+1, col);
    value = max(value, 1+dp[row+1][col]);
  }
  // 좌 탐색 가능
  if(arr[row][col] < arr[row][col-1]){
    if(dp[row][col-1]==0)
      dfs(row, col-1);
    value = max(value, 1+dp[row][col-1]);
  }
  // 우 탐색 가능
  if(arr[row][col] < arr[row][col+1]){
    if(dp[row][col+1]==0)
      dfs(row, col+1);
    value = max(value, 1+dp[row][col+1]);
  }
  dp[row][col] = value;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);
  
  int N;
  cin >> N;

  arr.resize(N+2, vector<int>(N+2, -1));
  dp.resize(N+2, vector<int>(N+2, 0));
  
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++)
      cin >> arr[i][j];
  }

  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      dfs(i, j);
    }
  }

  int ans = -1;
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++)
      ans = max(ans, dp[i][j]);
  }
  cout << ans;
}