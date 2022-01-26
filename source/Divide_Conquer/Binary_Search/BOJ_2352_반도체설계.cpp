// https://www.acmicpc.net/problem/2352

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
  
  vector<int> L;
  L.push_back(arr[0]);
  for(int i=1; i<N; i++){
    if(L.back() < arr[i])
      L.push_back(arr[i]);
    else{
      auto iter = lower_bound(L.begin(), L.end(), arr[i]);
      *iter = arr[i];
    }
  }
  cout << L.size();
}

/*
LIS의 NlogN 풀이법 그대로 적용하기
자신보다 작은 인덱스의 포트 중 연결된 포트의 넘버가
자신과 연결된 포트의 넘버보다 작은 것들을 찾아야 한다는 점에서
N^2 풀이법은 간단하게 접근할 수 있음
다만 크기가 4*10^4이므로 제곱해주게되면 16*10^8이므로 시간초과에 좀 위험하게 걸림
이분탐색 기반의 lower_bound 풀이로 접근해서 풀이
https://www.acmicpc.net/problem/14003
*/ 