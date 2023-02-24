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


// ------------------------------ 
//  재풀이 : 2023.02.24
// ------------------------------ 

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector<int> arr;
ll N, K;

bool solve(int target){
  int cnt = 0;
  for(auto num : arr){
    cnt += num / target;
  }

  if(cnt >= K) return true;
  return false;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> N >> K;
  
  arr.resize(N);
  int max_val = -1;
  for(int i=0; i<N; i++){
    cin >> arr[i];
    max_val = max(max_val, arr[i]);
  }

  ll answer = 1;
  ll s = 1;
  ll e = max_val;
  while(s <= e){
    ll mid = (s + e) / 2;
    if(solve(mid)){
      answer = mid;
      s = mid + 1;
    }
    else {
      e = mid - 1;
    }
  }

  cout << answer;
}

