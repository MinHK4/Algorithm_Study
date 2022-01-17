#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);
  
  int T;
  cin >> T;
  while(T--){
    int N, M;
    cin >> N;
    vector<int> coin(N+1);
    for(int i=1; i<=N; i++)
      cin >> coin[i];
    cin >> M;
    
    vector<int> dp(M+1, 0);
    dp[0] = 1;
    for(int i=1; i<=N; i++){
      for(int j=1; j<=M; j++){
        
        // 동전 종류가 하나일 경우
        // 나누어 떨어지는 경우만 1가지로 카운트
        if(i == 1){
          if(j % coin[i] == 0)
            dp[j]++;
        }
        
        // 동전 종류가 여러가지일 경우
        // 동전보다 만들어야 하는 돈의 크기가 크면
        // 기존에 만들어진 조합에 자기만 추가하면 되므로 이전값에 자기만 추가
        else{
          if(j>=coin[i])
            dp[j] += dp[j-coin[i]];
        }
      }
    }
    cout << dp[M] << '\n';
  }
}