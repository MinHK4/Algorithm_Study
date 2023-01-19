// https://www.acmicpc.net/problem/9663

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector <int> queen;
int num, ans;

void Place_Q(int row) {
    
  // end case
  // 지정된 수보다 더 큰 열이면 모든 퀸 배치한 것임
  if (row > num) {
      ans++;
      return;
  }

  // row 행에서 열 하나씩 돌아가면서 배치할 수 있는지 확인
  for (int i = 1; i <= num; i++) {
      bool flag = true;

      // 이전까지의 퀸 배치 정보 확인해주기
      // 같은 열에 있거나 대각선 위치에 있거나
      for (int j = 1; j < row; j++) {
          if (i == queen[j] || (row - j) == abs(i - queen[j])) {
              flag = false;
              break;
          }
      }

      // 현재 열에 퀸을 놓을 수 있으면 놓고 다음 열로 이동하기
      if (flag) {
          queen[row] = i;
          Place_Q(row + 1);
      }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  cin >> num;
  queen.resize(num + 1);
  
  Place_Q(1);

  cout << ans;
}

/*
N*N 크기에다가 N개의 퀸을 배치하는거기 떄문에
한 줄에 하나의 퀸만 배치해주면 됨
따라서 체스판 배열 전제를 저장할 필요 없이 한 줄씩만 저장해주고
그 한 줄에서 퀸이 몇번째 열에 있었는지만 저장해주면 된다.
*/ 