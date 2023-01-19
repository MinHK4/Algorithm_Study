#include <bits/stdc++.h>

using namespace std;

// 장르 내에서 재생 횟수 같으면 id 낮은 순으로 정렬
bool sortby(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    int len = genres.size();
    
    // 장르별 아이디 기억하고 장르별 전체 재생 수 카운트 위해서 초기화
    multimap <string, int> genre_idx;
    map <string, int> genre_cnt;
    for(int i=0; i<len; i++){
        genre_idx.insert({genres[i], i});
        genre_cnt[genres[i]] = 0;
    }
    
    // 장르별 전체 재생 수 카운트해주기
    for(auto x : genre_idx)
        genre_cnt[x.first] += plays[x.second];
    
    // 전체 재생 수 기준으로 많이 재생된 장르 정렬하기
    vector<pair<int, string>> v;
    for(auto x: genre_cnt)
        v.push_back({x.second, x.first});
    sort(v.begin(), v.end(), greater<>());
    
    // 많이 재생된 장르 순서대로
    for(auto x: v){
        // 현재 장르의 id들을 바탕으로 (재생수, id)의 배열 만들고
        // 재생 수 많은 순 -> id 낮은 순으로 정렬
        vector<pair<int, int>> temp;
        for(auto i : genre_idx){
            if(i.first == x.second)
            temp.push_back({plays[i.second], i.second});
        }
        sort(temp.begin(), temp.end(), sortby);
        
        // 정렬된 장르별 노래 배열 크기에 따라서 1 or 2 개 뽑아오기
        answer.push_back(temp[0].second);
        if(temp.size() > 1)
            answer.push_back(temp[1].second);
    }
    
    return answer;
}