// https://www.acmicpc.net/problem/11399

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int N;
  cin >> N;
  vector<int> arr(N);
  for(int i=0; i<N; i++)
    cin >> arr[i];

  sort(arr.begin(), arr.end());
  
  int ans = arr[0];
  for(int i=1; i<N; i++){
    arr[i] += arr[i-1];
    ans += arr[i];
  }
  cout << ans;  
}

/*
그리디 기법
기다리는 시간의 총합의 최소를 만들기 위해서는
시간이 적게 걸리는 사람이 먼저 오게 정렬해주면 됨
*/ 