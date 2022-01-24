// https://www.acmicpc.net/problem/11053

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int N;
  cin >> N;
  
  vector<int> arr(N);
  vector<int> dp(N, 1);

  for(int i=0; i<N; i++){
    cin >> arr[i];
    for(int j=0; j<i; j++){
      if(arr[j] < arr[i])
        dp[i] = max(dp[i], dp[j]+1);
    }
  }
  cout << *max_element(dp.begin(), dp.end());
}

/*
DP[i] i번째 숫자를 끝으로 하는 LIS의 길이
i번째 숫자를 입력 받을 때 자기 이전 인덱스까지의 수들 중에서
자신보다 작은 수들의 DP값+1과 현재 자기 DP값들 중 큰 값으로 업데이트
-> 자기를 끝으로 하는 LIS를 만들 수 있는지 확인하고 그 중 가장 긴 길이로 저장
*/