// https://www.acmicpc.net/problem/1799

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

/*
체스크기 사이즈가 10까지인데 그대로 모든 칸을 이어서 탐색해가면
모든 경우의 수 탐색의 시간복잡도는 O(2^(10*10))이 나와서 시간초과 뜰 수 밖에 없음
1초 = 10^9 = 2^30 정도라고 봤을 때
10 * 2^30 정도의 시간 범위 안에 해결할 수 있어야 함
따라서 접근은 체스를 분할적으로 볼 수 있는가의 방식으로 진행

비숍의 움직임 상 흰색 칸을 움직이는 비숍과 검정 칸을 움직이는 비숍은 서로 독립적
그러므로 개별적으로 각각의 최대값을 구하고 합해줘도 문제가 없고
시간적으로는 엄청나게 세이브 할 수 있음
2 * 2^(5*5)의 시간이 걸리므로 해결가능해짐

또한 효율적으로 이전 상태에 정보를 얻기 위한 배열을 선언해줘야 하는데
같은 대각선 동선의 비숍을 하나로 묶어서
left_down, right_down의 종류들로 합해주고 관리해주면 훨씬 편하게 관리 가능
*/ 