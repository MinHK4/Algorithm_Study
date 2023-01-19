// https://www.acmicpc.net/problem/23372

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  ll n, k;
  cin >> n >> k;

  vector<ll> arr(n);
  vector<ll> acc(n);
  for(ll i=0; i<n; i++){
    cin >> arr[i];
    acc[i] = -arr[i];
    if(i>0)
      acc[i] += acc[i-1];
    if(acc[i] < 0)
      acc[i] = 0;
  }
  sort(acc.begin(), acc.end());

  while(k--){
    ll need;
    cin >> need;
    cout << acc.end() - lower_bound(acc.begin(), acc.end(), need*5) << ' ';
  }
}

/*
누적합으로 온도 저장하고 이를 정렬하면 
모든 날들의 얼음 두께 예상 데이터를 작은 순서부터 얻을 수 있음
여기서 lower_bound 이용해서 값들 찾아주면 그 두께보다 두꺼운 일 수를 얻을 수 있음

+ 누적합 일 때 int범위 내인지 확인
++ double 사용 안 하고 int내에서 해결 할 수 있게 접근
*/

