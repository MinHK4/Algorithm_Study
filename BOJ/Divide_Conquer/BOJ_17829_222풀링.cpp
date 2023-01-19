// https://www.acmicpc.net/problem/17829

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector<vector<int>> arr;

int recurs_call(int size, int row, int col){
  
  // end case
  if(size == 1)
    return arr[row][col];

  // 4등분으로 분할하고 합치면서 해당 영역의 2번째로 큰 수 찾아가면서 정복
  vector<int> v;
  v.push_back(recurs_call(size/2, row, col));
  v.push_back(recurs_call(size/2, row+size/2, col));
  v.push_back(recurs_call(size/2, row, col+size/2));
  v.push_back(recurs_call(size/2, row+size/2, col+size/2));

  sort(v.begin(), v.end());
  return v[2];
}


int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  arr.resize(N, vector<int>(N));
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++)
      cin >> arr[i][j];
  }

  cout << recurs_call(N, 0, 0);
}

/*
분할 정복 문제
*/