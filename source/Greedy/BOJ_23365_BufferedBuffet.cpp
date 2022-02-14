// https://www.acmicpc.net/problem/23365

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  ll N;
  cin >> N;

  vector<ll> arr(N);
  for(ll i=0; i<N; i++)
    cin >> arr[i];
  sort(arr.begin(), arr.end());
  
  ll ans = arr[N-1];
  for(ll i=N-1; i>0; i--)
    ans += arr[i];

  cout << ans;
}

/*
그리디 기법
테이블을 각각이 요구하는 최소한 거리만큼 띄워주면서 배치하기
어차피 가장 큰 값은 항상 2번은 들어가기 때문에
최대한 작은 값들도 선택될 수 있게 하려면 정렬을 해주면 됨
*/ 