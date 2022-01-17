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