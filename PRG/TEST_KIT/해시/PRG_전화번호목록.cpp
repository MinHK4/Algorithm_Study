// https://school.programmers.co.kr/learn/courses/30/lessons/42577?language=cpp 

#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i=1; i<phone_book.size(); i++){
        if(phone_book[i].substr(0, phone_book[i-1].size()) == phone_book[i-1]) return false;
    }
    
    return true;
}