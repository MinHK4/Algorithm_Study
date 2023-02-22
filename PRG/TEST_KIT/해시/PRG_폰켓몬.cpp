// https://school.programmers.co.kr/learn/courses/30/lessons/1845#

#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> nums)
{
    
    set<int> s;
    for(auto num : nums){
        s.insert(num);
    }
    
    if(nums.size() / 2 < s.size()) return nums.size() / 2;
        return s.size();
}

// 훨씬 깔끔한 풀이 방식
int solution(vector<int> nums) {
  unordered_set<int> s(nums.begin(), nums.end());

  return min(nums.size() / 2, s.size());
}
