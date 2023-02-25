#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector<vector<int>> arr;
int N, M;

bool isValidPos(int r, int c){
  return 0 <= r && r < N && 0 <= c && c <M;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  cin >> N >> M;
  arr.resize(N, vector<int>(M));
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cin >> arr[i][j];
    }
  }

  int ans = 0;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      // 정사각형 모양 판별
      if(isValidPos(i ,j) && isValidPos(i+1, j+1)){
        ans = max(ans, arr[i][j] + arr[i+1][j] + arr[i][j+1] + arr[i+1][j+1]);
      }

      // 길쭉이 가로 판별
      if(isValidPos(i ,j) && isValidPos(i, j+3)){
        ans = max(ans, arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i][j+3]);
      }
      // 길쭉이 세로 판별
      if(isValidPos(i ,j) && isValidPos(i+3, j)){
        ans = max(ans, arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+3][j]);
      }

      // 여러가지 모양 종합 판별 세로 직사각형
      if(isValidPos(i ,j) && isValidPos(i+2, j+1)){
        ans = max(ans, arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i][j+1]);
        ans = max(ans, arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+1][j+1]);
        ans = max(ans, arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+2][j+1]);

        ans = max(ans, arr[i][j+1] + arr[i+1][j+1] + arr[i+2][j+1] + arr[i][j]);
        ans = max(ans, arr[i][j+1] + arr[i+1][j+1] + arr[i+2][j+1] + arr[i+1][j]);
        ans = max(ans, arr[i][j+1] + arr[i+1][j+1] + arr[i+2][j+1] + arr[i+2][j]);

        ans = max(ans, arr[i][j] + arr[i+1][j] + arr[i+1][j+1] + arr[i+2][j+1]);
        ans = max(ans, arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1] + arr[i+2][j]);
      }

      // 여러가지 모양 종합 판별 가로 직사각형
      if(isValidPos(i ,j) && isValidPos(i+1, j+2)){
        ans = max(ans, arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j]);
        ans = max(ans, arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1]);
        ans = max(ans, arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+2]);

        ans = max(ans, arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2] + arr[i][j]);
        ans = max(ans, arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2] + arr[i][j+1]);
        ans = max(ans, arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2] + arr[i][j+2]);

        ans = max(ans, arr[i][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+1][j+2]);
        ans = max(ans, arr[i+1][j] + arr[i+1][j+1] + arr[i][j+1] + arr[i][j+2]);
      }
    }
  }

  cout << ans;
}