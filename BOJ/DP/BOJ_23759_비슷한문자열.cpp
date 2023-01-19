// https://www.acmicpc.net/problem/23759

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int N, K;
  cin >> N >> K;

  vector<vector<int>> dp(K, vector<int>(26, 0));
  
  for(int i=0; i<N; i++){
    string temp;
    cin >> temp;

    // i번쨰 위치에 'a'+j 문자가 나오게 되면 그 위치의 문자를 기점으로
    // 지금까지 만들 수 있는 최장 인접 문자열의 수를 구함
    // 그리고 문자열을 읽으면서 그 중에서 최댓값을 구해놓음
    int max_val = -1;
    for(int i=0; i<K; i++){
      dp[i][temp[i]-'a']++;
      max_val = max(max_val, dp[i][temp[i]-'a']);
    }

    // 하나의 문자열에 속하므로 비록 이번이 자기를 중점으로 연결된 것을 아니더라도 
    // 다른 위치의 문자와 함께 같은 값을 가져야 함
    // 그래서 나중에 뒤에서 같은 위치의 같은 문자가 나와서 호출될 때
    // 자신을 포함한 다른 문자들을 통해서 얻어진 최장 인접 문자열의 수 알려줌
    for(int i=0; i<K; i++)
      dp[i][temp[i]-'a'] = max_val;
  }

  // ans check & output
  int ans = -1;
  for(int i=0; i<K; i++){
    for(int j=0; j<26; j++)
      ans = max(ans, dp[i][j]);
  }
  cout << N - ans;
}

/*
DP[i][j] 
문자열에서 i번째 위치에서 j의 문자가 나왔을 때 
그 위치의 그 문자를 기준으로 구성할 수 있는 최대 인접 문자열의 수
*/