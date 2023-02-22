// https://school.programmers.co.kr/learn/courses/30/lessons/12909

#include<bits/stdc++.h>

using namespace std;

bool solution(string s){
    stack<char> stck;
    
    for(auto c : s){
        if(c == '(') stck.push(c);
        else {
            if(!stck.empty() && stck.top() == '(') stck.pop();
            else return false;
        }
    }
    
    return stck.size() ? false : true;
}