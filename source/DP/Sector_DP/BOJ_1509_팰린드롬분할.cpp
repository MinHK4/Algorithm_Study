// https://www.acmicpc.net/problem/1509

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;


int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  string str;
  cin >> str;

  // 입력받은 문자열에 대해 각각의 구간들의 팰린드롬 여부 체크해놓기
  // 길이가 1이거나 2인 문자열들 base case들로 먼저 구해주고
  // 문자열의 길이만큼 길이를 늘려가면서 팰린드롬 여부 체크
  // 양끝이 같고 그 안쪽이 팰린드롬이면 현재 구간도 팰린드롬
  int len = str.length();
  vector<vector<bool>> isPal(len, vector<bool>(len, false));
  for(int i=0; i<len; i++){
    isPal[i][i] = true;
    if(i+1 < len && str[i] == str[i+1])
      isPal[i][i+1] = true;
  }
  for(int i=3; i<=len; i++){
    for(int j=0; j+i-1<len; j++){
      if(str[j]==str[j+i-1] && isPal[j+1][j+i-2])
        isPal[j][j+i-1] = true;
    }
  }

  // dp[i] : 0부터 i까지 얻을 수 있는 최소 팰린드롬의 수
  // i부터 j까지가 팰린드롬이면 i-1까지의 조합 수에 1 더한 것으로 볼 수 있음 
  vector<int> dp(len, INT_MAX);
  for(int i=0; i<len; i++){
    for(int j=i; j<len; j++){
      if(isPal[i][j]){
        if(i==0)
          dp[j] = 1;
        else
          dp[j] = min(dp[j], dp[i-1] + 1);
      }
    }
  }

  cout << dp[len-1];
}

/*
문자열의 길이가 2500이므로 N^3, 3중 반복문은 안 되고 이중 반복문 안에서 해결해야 함
이를 위해서 선처리로 팰린드롬 여부를 구간별로 체크해놓기
길이가 1,2인 것들 먼저 구하고 그다음 길이는 양끝이 같고 내부의 문자열이 팰린드롬이면 팰린드롬

팰린드롬 체크 후 0을 시작점으로 잡아서 문자열 끝까지로 최대 길이의 팰린드롬 구하고
다음 인덱스에서도 구해주면서 최소 조합의 수로 업데이트 하는 방식
dp[j] : 0부터 j까지의 최소 팰린드롬 조합 수
dp[j] = min(dp[j], dp[i-1]+1)
현재까지 얻은 값과 이번 i부터j까지의 팰린드롬을 조합한 경우의 값 중에서 더 작은 값 선택
*/