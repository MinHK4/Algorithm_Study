  // https://programmers.co.kr/learn/courses/30/lessons/43238

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

bool solve(long long key, int num, vector<int> times){
    ll sum = 0;
    for(auto time : times)
        sum += key / (long long)time;
    if(sum >= num)
        return true;
    return false;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    
    long long s = 0;
    long long e = (long long)n * times[times.size()-1];
    
    while(s <= e){
        long long mid = (s + e) / 2;
        if(solve(mid, n, times)){
            answer = mid;
            e = mid-1;
        }
        else
            s = mid+1;   
    }
    
    return answer;
}

/*
Parametric Search 기법
*/