#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);
  
  string str1, str2, str3;
  cin >> str1;
  cin >> str2;
  cin >> str3;

  int len1 = str1.length();
  int len2 = str2.length();
  int len3 = str3.length();

  vector <vector <vector<int>>> dp(len1+1, vector<vector<int>>(len2+1, vector<int>(len3+1, 0)));

  for(int i=1; i<=len1; i++){
    for(int j=1; j<=len2; j++){
      for(int k=1; k<=len3; k++){
        if(str1[i-1] == str2[j-1] && str2[j-1] == str3[k-1])
          dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
        else{
          dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k]);
          dp[i][j][k] = max(dp[i][j][k], dp[i][j][k-1]);
        }
      }
    }
  }
  cout << dp[len1][len2][len3] << '\n';
}