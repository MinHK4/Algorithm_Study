#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

vector<ll> arr;
ll K, N;

bool solve(ll key){
  ll cnt = 0;
  for(ll i=0; i<K; i++)
    cnt += arr[i] / key;
  if(cnt >= N)
    return true;
  return false;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);
  
  cin >> K >> N;

  ll max_len = -1;
  for(ll i=0; i<K; i++){
    ll temp;
    cin >> temp;
    max_len = max(max_len, temp);
    arr.push_back(temp);
  }

  ll s = 1;
  ll e = max_len;
  ll mid, ans;
  while(s <= e){
    mid = (s + e) / 2;
    if(solve(mid)){
      s = mid + 1;
      ans = mid;
    }
    else
      e = mid - 1;
  }
  cout << ans;
}