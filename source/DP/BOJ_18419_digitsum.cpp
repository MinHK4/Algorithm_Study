// https://www.acmicpc.net/problem/18419

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;


int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  // freopen("inp.txt", "r", stdin);
  
  int N;
  cin >> N;

  vector<int> dp(N+1, 0);

  for(int i=1; i<=N; i++){
    dp[i]++;
    
    int digit_sum = 0;
    int temp = i;
    while(temp){
      digit_sum += temp % 10;
      temp /= 10;
    }
    if(digit_sum + i <= N)
      dp[digit_sum + i] += dp[i];
  }
  
  cout << dp[N];
}

/*
DP문제 방식으로 접근하는데 Bottom-Up 형식이긴 하지만 오묘하게 다른 접근방식
기존의 Bottom-Up 방식은 dp[i]가 자신보다 작은 인덱싱으로 정의되는 방식이었음
예를 들어, dp[i] = dp[i-1] + dp[i-2]
하지만 이번 문제는 Bottom-Up이긴 하지만 현재 인덱스에서 다음 인덱스들에게 미리 뿌려주는 방식
자기 자신의 dp값을 자신의 digit_sum+i에게 뿌려주는 방식
dp[i] ~~> dp[digit_sum + i]
*/ 