// https://programmers.co.kr/learn/courses/30/lessons/72412?language=cpp

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// 주어진 문자열을 바탕으로 공백, 'and' 빼고 유의미한 데이터만 남겨서 문자열 배열 반환
vector<string> data_parse(string data) {
    vector<string> ret;
    
    string tmp = "";
    for(auto c: data) {
        if(c == ' ') {
            if(tmp != "and") ret.push_back(tmp);
            tmp = "";
        }
        else tmp += c;
    }        
    ret.push_back(tmp);
    
    return ret;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    // 해당 조건에 해당되는 점수들 모아주기
    map<string, vector<int>> db;
    for(auto inf: info) {
        vector<string> key = data_parse(inf);
        
        // 비트마스킹 부분
        // 현재 다루고 있는 조건 문자열을 바탕으로 해당 조건이 모두 포함되는 문자 생성
        // 4종류의 조건이 있고 각각을 신경 or 신경X의 경우가 다 포함되어야 하기에
        // 각 문자열마다 총 16가지의 경우의 수를 신경써주면 됨
        for(int i=0; i<16; ++i) {
            string tmp = "";            
            for(int j=0; j<4; ++j) {
                tmp += (i & (1 << j)) ? key[j] : "-";
            }
            db[tmp].push_back(stoi(key[4]));
        }
    }
    
    // lower_bound 사용 위해 sort
    // 해당 배열 sort해서 바꿀거기 때문에 &로 접근해야 함
    for(auto &iter: db) 
        sort(iter.second.begin(), iter.second.end());    
    
    // 쿼리 하나씩 체크하면서 조건 문자열 생성하고
    // 해당 문자열의 값들 중에서 lower_bound 이용해서 이상인 수의 개수 구해주기
    for(auto q: query) {
        vector<string> key = data_parse(q);
        string k = key[0] + key[1] + key[2] + key[3];
        
        vector<int> res = db[k];
        int cnt = res.end() - lower_bound(res.begin(), res.end(), stoi(key[4]));
        answer.push_back(cnt);
    }
    
    return answer;
}