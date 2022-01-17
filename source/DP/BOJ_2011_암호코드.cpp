#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

#define mod 1000000

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int dp[5004] = {0 ,};
  dp[0] = 1;
  dp[1] = 1;
  string str;
  cin >> str;

  // 1~26까지만 코드로 해석할 수 있음
  // 예외처리 -> 코드가 0으로 시작하는 건 불가능
  if(str[0] == '0'){
    cout << 0;
    return 0;
  }
  
  for(int i=2; i<=str.length(); i++){
    // *0, 0~9인 경우
    if(str[i-2] == '0'){
      if(str[i-1] == '0'){
       cout << 0;
       return 0;
      }
      dp[i] += dp[i-1];
    }
    
    // 10~19인 경우 
    else if(str[i-2] == '1'){
      dp[i] += dp[i-2];
      if(str[i-1]!='0')
        dp[i] += dp[i-1];
    }

    // 20~29인 경우
    else if(str[i-2] == '2'){
      if(str[i-1] == '0')
        dp[i] += dp[i-2];
      else if(str[i-1] > '6'){
        dp[i] += dp[i-1];
      }
      else{
        dp[i] += dp[i-1];
        dp[i] += dp[i-2];
      }
    }

    // 30~99인 경우
    else{
      if(str[i-1] == '0'){
        cout << 0;
        return 0;
      }
      dp[i] = dp[i-1];
    }
    dp[i] %= mod;
  }
  cout << dp[str.length()];
}