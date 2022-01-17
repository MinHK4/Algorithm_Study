#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair <ll, ll>;
 
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  freopen("inp.txt", "r", stdin);

  int D, P;
  cin >> D >> P;

  vector<int> dp(D+1, 0);
  dp[0] = 1;

  // Kanpsack + 2to1DP
  for(int i=1; i<=P; i++){
    int L, C;
    cin >> L >> C;
    
    // 인덱싱 큰 쪽에서부터 내려와야 하나의 파이프라인 중복적으로 사용 안 할 수 있음
    for(int j=D; j>=L; j--){
      if(dp[j-L]){
        if(j==L) 
          dp[j] = max(dp[j], C);
        else
          dp[j] = max(min(dp[j-L], C), dp[j]);
      }
    }
  }
  cout << dp[D];
}