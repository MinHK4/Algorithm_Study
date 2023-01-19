// https://programmers.co.kr/learn/courses/30/lessons/42628#

#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    
    multiset<int> ms;
    
    int cnt = 0;
    for(auto op : operations){
        if(op[0] == 'I'){
            ms.insert(stoi(op.substr(2)));
            cnt++;
        }
        else{
            if(cnt == 0)
                continue;
            cnt--;
            if(op[2] == '1')
                ms.erase(--ms.end());
            else
                ms.erase(ms.begin());
        }
    }
    
    if(cnt){
        answer[0] = *(--ms.end());
        answer[1] = *(ms.begin());
    }
    
    return answer;
}