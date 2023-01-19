// https://www.acmicpc.net/problem/7346

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int trans(char c){
  switch(c){
    case 'A':
      return 0;
    case 'C':
      return 1;
    case 'G':
      return 2;
    case 'T':
      return 3;
    case '*':
      return 4;
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int ref[5][5] = {
    {5, -1, -2, -1, -3},
    {-1, 5, -3, -2, -4},
    {-2, -3, 5, -2, -2},
    {-1, -2, -2, 5, -1},
    {-3, -4, -2, -1, 0}
  };

  int TC;
  cin >> TC;
  while(TC--){
    string str1, str2;
    int len1, len2;
    cin >> len1 >> str1;
    cin >> len2 >> str2;

    vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
    for(int i=1; i<=len1; i++)
      dp[i][0] = dp[i-1][0] + ref[trans(str1[i-1])][4];
    for(int i=1; i<=len2; i++)
      dp[0][i] = dp[0][i-1] + ref[4][trans(str2[i-1])];


    // 양쪽 모두 현재 위치의 문자(i번째랑 j번째랑) 같이 매칭
    // str1의 i-1번째와 str2의 j번째까지 매칭하고 str1의 i는 공백과 매칭
    // str2의 j-1번째와 str1의 i번째까지 매칭하고 str2의 j는 공백과 매칭
    for(int i=1; i<=len1; i++){
      for(int j=1; j<=len2; j++){
        int case1 = dp[i-1][j-1] + ref[trans(str1[i-1])][trans(str2[j-1])];
        int case2 = dp[i-1][j] + ref[trans(str1[i-1])][4];
        int case3 = dp[i][j-1] + ref[trans(str2[j-1])][4];
        dp[i][j] = max(case1, max(case2, case3));
      }
    }
    cout << dp[len1][len2] << '\n';
  }
}

/*
dp[i][j] str1의 i번째 문자와 str2의 j번째 문자를 배치시켜서 얻어낼 수 있는 점수의 최댓값
직관적으로 딱 와닿기는 힘들지만 논리적으로 어떻게 돌아가는지만 이해하기
(i,j)에서 역재구성해보면 두 개 다 매칭시킬건지 아니면 둘 중 하나에 공백 넣어서 매칭할지의 문제
이런 방식으로 subproblem이 overlapping하는 구조다라는 것만 알면 dp로 풀이 가능
*/ 