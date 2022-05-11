// https://www.acmicpc.net/problem/2630

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector<vector<int>> arr;

string rec_find(int size, int row, int col){
  
  // base case - 1개짜리 사각형 확인
  if(size == 1){
    return to_string(arr[row][col]);
  }

  // 각 사분면에 대해서 분할 탐색
  vector<string> recs;
  recs.push_back(rec_find(size/2, row, col));
  recs.push_back(rec_find(size/2, row, col+size/2));
  recs.push_back(rec_find(size/2, row+size/2, col));
  recs.push_back(rec_find(size/2, row+size/2, col+size/2));

  // 탐색 후 수합해서 정복할 때 각 분면이 하나의 문자로 구성됐는지 확인
  string sum = "";
  bool allZero = true; 
  bool allOne = true;
  for(auto x : recs){
    if(x != "0")
      allZero = false;
    if(x != "1")
      allOne = false;
    sum += x;
  }

  // 하나의 문자면 해당 문자를 아니면 문자들의 조합 return
  if(allZero)
    return "0";
  if(allOne)
    return "1";
  return sum;
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

  string ans = rec_find(N, 0, 0);

  int zero = 0;
  int one = 0;
  for(auto x : ans){
    if(x == '0')
      zero++;
    if(x == '1')
      one++;
  }
  cout << zero << '\n' << one;
}

/*
분할정복 이용한 풀이
분할해서 base case까지 내려간 뒤에 올라오면서 합치는 과정에서 정보 처리
*/