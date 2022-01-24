// https://www.acmicpc.net/problem/11054

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
  
  // LIS 순방향
  vector<int> inc(N, 1);
  for(int i=0; i<N; i++){
    for(int j=0; j<i; j++){
      if(arr[i] > arr[j])
        inc[i] = max(inc[i], inc[j]+1);
    }
  }

  // LIS 역방향
  vector<int> dec(N, 1);
  for(int i=N-1; i>=0; i--){
    for(int j=N-1; j>i; j--){
      if(arr[i] > arr[j])
        dec[i] = max(dec[i], dec[j]+1);
    }
  }

  // 순,역방향으로 구한 값이 가장 크게 만나는 지점 찾아서 출력 
  int ans = -1;
  for(int i=0; i<N; i++)
    ans = max(ans, inc[i] + dec[i] - 1);
  cout << ans;
}

/*
LIS를 앞에서 오는 방향 한 번, 뒤에서 오는 방향 한 번
이렇게 각각 두 번 돌려주고 그 값이 가장 크게 만나는 지점을 찾아주면 된다
*/ 