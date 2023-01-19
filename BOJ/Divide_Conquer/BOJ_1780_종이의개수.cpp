// https://www.acmicpc.net/problem/1780

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector<vector<int>> arr;
vector<int> cnt(3);

int recurs_call(int size, int row, int col){

  // end case
  if(size == 1){
    for(int i=0; i<3; i++){
      if(arr[row][col] == i-1)
        cnt[i]++;
    }
    return arr[row][col];
  }

  // 9개로 분할해서 확인하기
  vector<int> v;
  int s = size/3;
  v.push_back(recurs_call(s, row ,col ));
  v.push_back(recurs_call(s, row+s ,col ));
  v.push_back(recurs_call(s, row+s*2 ,col ));

  v.push_back(recurs_call(s, row ,col+s ));
  v.push_back(recurs_call(s, row+s ,col+s ));
  v.push_back(recurs_call(s, row+s*2 ,col+s ));

  v.push_back(recurs_call(s, row ,col+s*2 ));
  v.push_back(recurs_call(s, row+s ,col+s*2 ));
  v.push_back(recurs_call(s, row+s*2 ,col+s*2 ));

  // 합치는 과정에서 하나의 영역이 통일되었는지 확인하고
  bool allMinus = true;
  bool allZero = true;
  bool allOne = true;
  for(auto x : v){
    if(x != -1)
      allMinus = false;
    if(x != 0)
      allZero = false;
    if(x != 1)
      allOne = false;
  }

  // 개수 업데이트 해주면서 정복해오기
  if(allMinus){
    cnt[0]-=8;
    return -1;
  }
  if(allZero){
    cnt[1]-=8;
    return 0;
  }
  if(allOne){
    cnt[2]-=8;
    return 1;
  }
  return 4;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  int N;
  cin >> N;
  arr.resize(N, vector<int>(N));
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++)
      cin >> arr[i][j];
  }

  recurs_call(N, 0, 0);

  for(auto x : cnt)
    cout << x << '\n';
}

/*
분할정복 문제
*/