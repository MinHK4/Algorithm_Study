#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector<int> dp;
int N;

void DFS(int cur, int cnt){
  dp[cur] += cnt;
  int temp = cur;
  int temp_sum = temp;
  while(temp){
    temp_sum += temp % 10;
    temp /= 10;
  }
  if(temp_sum <= N)
    DFS(temp_sum, cnt+1);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  cin >> N;

  dp.resize(N+1, 0);

  for(int i=1; i<=N; i++){
    if(dp[i] == 0)
      DFS(i, 1);
  }
  
  cout << dp[N];
}