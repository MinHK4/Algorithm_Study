#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
  string answer = "";
  
  map <string, int> m;
  
  for(auto p : participant)
      m[p]++;
  for(auto c : completion)
      m[c]--;
  
  for(auto i: m){
      if(i.second != 0)
          answer = i.first;
  }
  return answer;
}
/*
map을 이용해서 언급된 횟수를 value로 해서 넣고
하나씩 뺴준 후 남아있는 key 값 answer로 리턴
*/