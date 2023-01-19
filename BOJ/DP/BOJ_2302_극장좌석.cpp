#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  // DP 선행처리
  int dp[41];
  dp[0] = 1;
  dp[1] = 1;
  for(int i=2; i<=40; i++)
    dp[i] = dp[i-1] + dp[i-2];

  vector <int> val;
  int N, M;
  cin >> N;
  cin >> M;

  // VIP로 구분된 좌석의 연속 수 저장하기
  if(M == 0)
    val.push_back(N);
  else{
    int idx = 1;
    while(M--){
      int vip;
      cin >> vip;
      val.push_back(vip-idx);
      idx = vip + 1;
    }
    val.push_back(N+1-idx);
  }

  // 좌석의 연속된 수 만큼 곱해서 모든 경우의 수 처리하기
  int ans = 1;
  for(int x : val)
    ans *= dp[x];
  cout << ans;
}