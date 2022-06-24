// https://programmers.co.kr/learn/courses/30/lessons/42839

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

set <int> s;
string org;
int limit, len;

bool prime_check(int num){
    if(num <= 1)
        return false;
    
    for(int i=2; i*i<=num; i++){
        if(num % i == 0)
            return false;
    }
    return true;
}

void combi(int idx, int cnt, string temp){
    if(limit == cnt){
        do {
            s.insert(stoi(temp));
        } while(next_permutation(temp.begin(), temp.end()));
        return;
    }
    
    for(int i=idx; i<len; i++)
        combi(i+1, cnt+1, temp+org[i]);
}

int solution(string numbers) {
    int answer = 0;
    
    sort(numbers.begin(), numbers.end());
    
    org= numbers;
    len = numbers.size();
    
    for(int i=1; i<=len; i++){
        limit = i;
        combi(0, 0, "");
    }

    for(auto x : s){
        if(prime_check(x))
            answer++;
    }
            
    return answer;
}