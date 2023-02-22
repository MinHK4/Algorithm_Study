// https://school.programmers.co.kr/learn/courses/30/lessons/12906

#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;

    int prev = -1;
    for(auto num : arr){
        if(num != prev){
            answer.push_back(num);
            prev = num;
        }
    }

    return answer;
}

// sort하지 않고서 중복 제거 해주는 c++ 메소드 활용 가능
// arr.erase(unique(arr.begin(), arr.end()),arr.end());