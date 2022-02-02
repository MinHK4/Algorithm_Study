// https://www.acmicpc.net/problem/20937

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
  
  sort(arr.begin(), arr.end(), greater<>());

  int ans = 1;
  int cnt = 1;
  for(int i=0; i<N-1; i++){
    if(arr[i] == arr[i+1]){
      cnt++;
      ans = max(ans, cnt);
    }
    else
      cnt = 1;
  }
  cout << ans;
}

/*
4, 3, 3, 3, 2, 2, 1의 예시를 생각하면 풀 수 있음
*/