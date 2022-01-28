#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int TC;
  cin >> TC;
  while(TC--){
    int n, p, k;
    cin >> n >> p >> k;
    
    int sum = 0;
    vector<int> arr(n+1, 0);
    for(int i=1; i<=n; i++){
      cin >> arr[i];
      sum += arr[i];
    }
    sort(arr.begin(), arr.end());
    
    if(sum <= p)
      cout << n << '\n';

    else{
      vector<int> dp(p+1, 0);
      for(int i=1; i<=n; i++){
        for(int j=p; j>=arr[i]; j--)
          if(j == arr[i])
            dp[j] = max(dp[j], 1);
          else
            dp[j] = max(dp[j], dp[j-arr[i]] + 1);
      }

      vector<int> v;
      int idx = p;
      for(int i=n; i>=1; i--){
        if( idx >= arr[i] && dp[idx-arr[i]] == dp[idx]-1){
          v.push_back(i);
          idx = idx - arr[i];
        }
      }

      int ans = 0;
      int size = v.size();
      if(size != 0){
        for(int i=0; i<size-1; i++){
          if(v[i] - v[i+1] > 1)
            ans += 2;
          else
            ans++;
        }

        if(v[size-1]-1 >= 1)
          ans +=2;
        else 
          ans++;
      }
      cout << ans << '\n';
    }
  }
}