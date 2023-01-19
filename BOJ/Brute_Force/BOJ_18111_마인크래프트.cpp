// https://www.acmicpc.net/problem/18111

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);
  
  int N, M, B;
  cin >> N >> M >> B;

  int arr[504][504];
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++)
      cin >> arr[i][j];
  }

  // 0~256의 높이까지 맞추는 것 다 실행
  int time = INT_MAX;
  int height = 0;
  for(int i=0; i<=256; i++){
    int build_cnt = 0;
    int remove_cnt = 0;

    // 하나씩 다 둘러보면서 지정한 높이랑 안 맞는 것들 세어주기
    // 기준 높이보다 높은지 낮은지는 다르게 체크해주어야 함
    for(int j=0; j<N; j++){
      for(int k=0; k<M; k++){
        if(arr[j][k] < i)
          build_cnt += i - arr[j][k];
        else
          remove_cnt += arr[j][k] - i;
      }
    }

    // 가지고 있는 블록의 개수로 해결 가능한 경우에만
    // 걸리는 최소 시간 구해주기
    if(build_cnt <= remove_cnt + B){
      int tmp_time = build_cnt + remove_cnt * 2;
      if(time > tmp_time){
        time = tmp_time;
        height = i;
      }
      // 답이 여러개일 경우 땅의 높이가 가장 높은 것
      else if(time == tmp_time)
        height = max(height, i);
    }
  }
  cout << time << ' ' << height;
}

/*
500*500의 범위에 땅의 높이도 256d으로 제한되어있어서 BruteForce로 가능!
*/