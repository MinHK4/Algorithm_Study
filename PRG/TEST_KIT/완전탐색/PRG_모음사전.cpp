#include<bits/stdc++.h>

using namespace std;

vector<string> dictionary;
char c[5] = {'A', 'E', 'I', 'O', 'U'};

void makeWord(string cur){
    if(cur.size() == 5) return;
    
    for(int i=0; i<5; i++){
        dictionary.push_back(cur+c[i]);
        makeWord(cur+c[i]);
    }
}

int solution(string word) {
    makeWord("");
    
    int answer = 0;
    for(auto dict : dictionary){
        answer++;
        if(dict == word) break;
    }
    return answer;
}

////------------
// 규칙성을 찾아서 진행한 풀이 방식
////------------
#include<bits/stdc++.h>

using namespace std;

int solution(string word){
  int answer = 0;
  map<char, int> alp;
  int next_word[5] = {781, 156, 31, 6, 1};

  alp.insert({'A', 0});
  alp.insert({'E', 1});
  alp.insert({'I', 2});
  alp.insert({'O', 3});
  alp.insert({'U', 4});

  int i=0;
  for(auto w: word){
    answer += 1 + alp[w] * next_word[i++];
  }

  return answer
}