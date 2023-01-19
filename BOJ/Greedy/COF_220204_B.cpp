// https://codeforces.com/contest/1279/problem/B

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  ll TC;
  cin >> TC;
  while(TC--){
    ll n, s;
    cin >> n >> s;
    
    vector<ll> arr(n+1);
    for(ll i=1; i<=n; i++)
      cin >> arr[i];

    int ans = -1;
    int max = -1;
    int i;
    for(i=1; i<=n; i++){
      if(max < arr[i]){
        ans = i;
        max = arr[i];
      }
      
      if(s >= arr[i])
        s -= arr[i];
      else
        break;
    }

    // 주어진 시간제한이 넉넉한 경우
    if(i > n) 
      cout << 0 << '\n';
    else
      cout << ans << '\n';
  }
}

/*
Greedy하게 접근해서 주어진 연속성 안에서 최대값 업데이트해가기
*/