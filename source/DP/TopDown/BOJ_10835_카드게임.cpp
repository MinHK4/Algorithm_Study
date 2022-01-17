#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

vector<vector<int>> dp;
vector<int> A;
vector<int> B;
int N;

int DFS(int l, int r){
  if(l >= N+1 || r >= N+1)
    return 0;

  if(dp[l][r] == -1){
    int score = max(DFS(l+1, r+1), DFS(l+1, r));
    if(A[l] > B[r])
      score = max(score, DFS(l, r+1) + B[r]);
    dp[l][r] = score;
  }

  return dp[l][r];
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  
  freopen("inp.txt", "r", stdin);

  // input 
  cin >> N;
  A.resize(N+1);
  B.resize(N+1);
  dp.resize(N+1, vector<int>(N+1, -1));
  for(int i=1; i<=N; i++)
    cin >> A[i];
  for(int i=1; i<=N; i++)
    cin >> B[i];

  cout << DFS(1, 1);
}