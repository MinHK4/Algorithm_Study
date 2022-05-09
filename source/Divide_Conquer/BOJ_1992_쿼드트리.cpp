// https://www.acmicpc.net/problem/1992

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector <vector<string>> arr;
int N;

string recurse(int row, int col, int size) {
  
  // base case - 1개짜리씩 확인할 때
  if (size == 1)
    return arr[row][col];
  
  // 현재 사이즈를 기준으로 각 4분면의 정보 수합하기
  string temp[4], ret;
  temp[0] = recurse(row, col, size / 2);
  temp[1] = recurse(row, col + size / 2, size / 2);
  temp[2] = recurse(row + size / 2, col, size / 2);
  temp[3] = recurse(row + size / 2, col + size / 2, size / 2);

  // 수합한 정보를 바탕으로 플래그 셋
  // 다 같은 경우에는 해당 문자와 플래그 설정하고
  // 하나라도 다른 경우네는 괄호에 감싸서 모든 정보 return
  bool allZero = true, allOne = true;
  for (int i = 0; i < 4; i++) {
    if (temp[i] != "0")
      allZero = false;
    if (temp[i] != "1")
      allOne = false;
    ret += temp[i];
  }
  if (allZero)
    return "0";
  if (allOne)
    return "1";
  else
    return "(" + ret + ")";
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  // input
  cin >> N;
  arr.resize(N, vector<string>(N));

  for (int i = 0; i < N; i++) {
    string input;
    cin >> input;
    for (int j = 0; j < N; j++)
      arr[i][j] = input[j];
  }

  cout << recurse(0, 0, N);
}

/*
재귀함수 이용해서 분할정복 풀이하기

4분면으로 계속 나눠서 탐색해서 들어가고
정복해올 때 얻은 정보를 계속해서 업데이트 및 수정해오면서 올라오기
*/