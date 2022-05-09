// https://www.acmicpc.net/problem/1654

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

vector<ll> arr;
ll K, N;

// 문제풀이 조건 만족 : 적어도 N개의 랜선을 가져 갈 수 있는지
bool solve(ll key){
  ll cnt = 0;
  for(auto x : arr)
    cnt += x / key;

  if(cnt >= N)
    return true;
  return false;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  // freopen("inp.txt", "r", stdin);
  
  cin >> K >> N;

  ll max_len = -1;
  for(ll i=0; i<K; i++){
    ll temp;
    cin >> temp;
    max_len = max(max_len, temp);
    arr.push_back(temp);
  }

  // 이분탐색 활용해서 Parametric Seach
  ll s = 1;
  ll e = max_len;
  ll ans;
  while(s <= e){
    ll mid = (s + e) / 2;
    if(solve(mid)){
      s = mid + 1;
      ans = mid;
    }
    else
      e = mid - 1;
  }
  cout << ans;
}

/*
Parametric Search 풀이

-- "틀렸습니다"
Division by zero 
안전하게 이분탐색 범위 설정한다고 키워서 0을 시작점을 잡았는데
그냥 최소와 최솟값 범위로 유효한 값 범위로 잡아서 돌리기
*/