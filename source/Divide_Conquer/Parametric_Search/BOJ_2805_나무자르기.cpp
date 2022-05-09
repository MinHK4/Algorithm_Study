// https://www.acmicpc.net/problem/2805

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> arr;
ll N, M;

// 문제풀이 조건 만족 : 적어도 M미터의 나무 가져갈 수 있는지
bool solve(ll key){
  ll left = 0;
  for(auto x : arr)
    left += x > key ? x-key : 0;
  
  if(left >= M)
    return true;
  return false;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  cin >> N >> M;
  
  ll end = -1;
  for(ll i=0; i<N; i++){
    ll temp;
    cin >> temp;
    arr.push_back(temp);
    end = max(end, temp);
  }

  // 이분탐색 활용해서 Parametric Seach
  ll start = 0;
  ll ans;
  while(start <= end){
    ll mid = (start + end) / 2;
    if(solve(mid)){
      start = mid + 1;
      ans = mid;
    }
    else
      end = mid - 1;
  }

  cout << ans;
}

/*
Parametric Search 풀이

-- 틀렸습니다
주어진 입력에서 개별이 최대 10^9에다가 그 개수가 10^6이므로
안에서 조건 만족 체크하면서 누적합 구해주면서 overflow 발생하므로 ll으로 자료형 변경
*/