// https://programmers.co.kr/learn/courses/30/lessons/42842

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    bool flag = false;
    
    for(int i=1; i<=yellow; i++){
        if(!flag && yellow % i == 0){
            
            if((i + (yellow / i) + 2) * 2 == brown){
                answer.push_back(i+2);
                answer.push_back(yellow / i + 2);
                sort(answer.begin(), answer.end(), greater<>());
                
                flag = true;
                break;
            }
        }
    }
    return answer;
}