// https://school.programmers.co.kr/learn/courses/30/lessons/86491?language=cpp

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int w = 0, h = 0;
    for(auto size: sizes){
        w = max(w, max(size[0], size[1]));
        h = max(h, min(size[0], size[1]));
    }
    
    return w * h;
}