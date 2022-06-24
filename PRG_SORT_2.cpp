// https://programmers.co.kr/learn/courses/30/lessons/42746

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

bool sortby(int a, int b){
    string temp1 = to_string(a);
    string temp2 = to_string(b);
        
    return temp1 + temp2 > temp2 + temp1;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), sortby);
    
    int sum = 0;
    for(auto number : numbers){
        sum += number;
        answer += to_string(number);
    }
    
    if(sum == 0)
        answer = "0";    
    return answer;
}