#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);
  
  int N, M, B;
  cin >> N >> M >> B;

  int arr[504][504];
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++)
      cin >> arr[i][j];
  }

  int time = INT_MAX;
  int height = 0;
  for(int i=0; i<=256; i++){
    int build_cnt = 0;
    int remove_cnt = 0;

    for(int j=0; j<N; j++){
      for(int k=0; k<M; k++){
        if(arr[j][k] < i)
          build_cnt += i - arr[j][k];
        else
          remove_cnt += arr[j][k] - i;
      }
    }
    if(build_cnt <= remove_cnt + B){
      int tmp_time = build_cnt + remove_cnt * 2;
      if(time > tmp_time){
        time = tmp_time;
        height = i;
      }
      else if(time == tmp_time)
        height = max(height, i);
    }
  }
  cout << time << ' ' << height;
}