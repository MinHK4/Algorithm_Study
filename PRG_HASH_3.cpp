#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
  int answer = 1;
  
  map <string, int> m;
  for(auto clothe : clothes){
      m[clothe[1]]++;
  }
  
  vector<int> v;
  for(auto it : m)
      v.push_back(it.second);
  
  for(auto x : v)
      answer *= x+1;
  return answer - 1;
}

/*
모든 경우의 수는 (a+1)(b+1) - 1 의 개념처럼
각 종류에다가 1을 더한 값들의 곱에서 아무것도 선택 안 한 경우 한 가지를 뺴준 것과 같다!!
*/