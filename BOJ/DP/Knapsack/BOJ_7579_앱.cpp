// https://www.acmicpc.net/problem/7579

#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair <int, int>;
 
#define INF 40000

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  freopen("inp.txt", "r", stdin);

  int N, M;
  cin >> N >> M;
  
  vector<pii> arr(N+1);
  int max_m = -1;
  for(int i=1; i<=N; i++){
    cin >> arr[i].first;
    max_m = max(max_m, arr[i].first);
  }
  for(int i=1; i<=N; i++)
    cin >> arr[i].second;

  int SIZE = max(2*max_m+1, 2*M+1);
  vector<int> dp(SIZE, INF);
  for(int i=1; i<=N; i++){
    for(int j=SIZE; j>=arr[i].first; j--){
      if(j == arr[i].first)
        dp[j] = min(dp[j], arr[i].second);
      else if(dp[j-arr[i].first] != INF)
        dp[j] = min(dp[j], dp[j-arr[i].first] + arr[i].second);
    }
  }  

  cout << *min_element(dp.begin()+M, dp.end());
}

/*
DP 1차원 큰 인덱싱부터로 중복 사용없이 처리해주고
가중치보다 크게 사용했지만 오히려 값이 더 작은 경우를 위해서
배열을 딱 그 크기만큼 선언하는 것이 아니라 더 크게 잡은 다음에
DP[가중치]부터 그 뒤 DP값들 중에서 최소값을 출력해준다.
*/