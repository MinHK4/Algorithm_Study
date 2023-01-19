// https://www.acmicpc.net/problem/1074

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  int N, t_row, t_col;
  cin >> N >> t_row >> t_col;
  
  int wid, row, col, ans;
  wid = pow(2, N);
  row = col = ans = 0;

  // 목표 지점에 이를 때까지 순번 지나는 것 카운트해주기
  // 현재 너비 사이즈로 나눠지는 중앙지점을 기준으로 4개의 분면 중에서 이동 
  while (row != t_row || col != t_col) {
    // 1분면은 그대로

    // 2분면으로 이동
    if (t_row < row + wid / 2 && t_col >= col + wid / 2) {
      col += wid/2;
      ans += (wid / 2) * (wid / 2);
    }
    // 3분면으로 이동 
    if (t_row >= row + wid / 2 && t_col < col + wid / 2) {
      row += wid/2;
      ans += (wid / 2) * (wid / 2) * 2;
    }
    // 4분면으로 이동
    if (t_row >= row + wid / 2 && t_col >= col + wid / 2) {
      row += wid / 2;
      col += wid / 2;
      ans += (wid / 2) * (wid / 2) * 3;
    }

    // 현재 너비 사이즈 줄이기
    wid /= 2;
  }

  cout << ans;
}

/*
Iterative하게 너비 사이즈 줄여가면서 분할정복 풀이하기
*/