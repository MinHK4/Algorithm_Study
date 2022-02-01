#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector<vector<int>> chess;
vector<bool> left_down;
vector<bool> right_down;
int black_max = -1;
int white_max = -1;
int N;

void place_bishop(int row, int col, int cnt){
  
  // 다음 행으로 넘어가는 경우 인덱싱 조정 필요
  if(col > N){
    row++;
    if(col&1) 
      col = 2;
    else
      col = 1;
  }

  // 모든 경우의 수 다 탐색했을 경우 최대 값 갱신해주기
  if(row > N){
    if((row+col)&1)
      black_max = max(black_max, cnt);
    else
      white_max = max(white_max, cnt);
    return;
  }

  // 비숍 배치 가능한지 체크 후 놓고 다음 경우 탐색 
  if(chess[row][col] && !left_down[row+col] && !right_down[col-row+N]){
    left_down[row+col] = true;
    right_down[col-row+N] = true;
    place_bishop(row, col+2, cnt+1);
    left_down[row+col] = false;
    right_down[col-row+N] = false;
  }

  // 모든 경우 탐색을 위해 놓을 수 있더라도 현 위치에 안 놓는 경우의 수도 봐줘야 하므로
  place_bishop(row, col+2, cnt);

}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  cin >> N;
  chess.resize(N+1, vector<int>(N+1));
  left_down.resize(N*2 + 1, false);
  right_down.resize(N*2 + 1, false);
  
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++)
      cin >> chess[i][j];
  }

  place_bishop(1, 1, 0);
  place_bishop(1, 2, 0);

  cout << black_max + white_max;
}