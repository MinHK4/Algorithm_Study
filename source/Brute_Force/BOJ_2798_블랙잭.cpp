// https://www.acmicpc.net/problem/2798

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  int N, M;
  cin >> N >> M;
  
  vector<int> arr(N);
  for(int i=0; i<N; i++)
    cin >> arr[i];
  
  int temp_max = -1;
  for(int i=0; i<N; i++){
    for(int j=i+1; j<N; j++){
      for(int k=j+1; k<N; k++){
        if(arr[i] + arr[j] + arr[k] <= M)
          temp_max = max(temp_max, arr[i] + arr[j] + arr[k]);
      }
    }
  }
  cout << temp_max;
}

/*
Bruteforce 3중 반복문 돌리기
*/