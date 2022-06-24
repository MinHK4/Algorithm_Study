#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> temp1 = {1, 2, 3, 4, 5};
    vector<int> temp2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> temp3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector <int> try1, try2, try3;
    while(try1.size() < answers.size())
        try1.insert(try1.end(), temp1.begin(), temp1.end());
    while(try2.size() < answers.size())
        try2.insert(try2.end(), temp2.begin(), temp2.end());
    while(try3.size() < answers.size())
        try3.insert(try3.end(), temp3.begin(), temp3.end());
    
    int cnt1 = 0, cnt2  = 0, cnt3 = 0;
    for(int i=0; i<answers.size(); i++){
        if(answers[i] == try1[i])
            cnt1++;
        if(answers[i] == try2[i])
            cnt2++;
        if(answers[i] == try3[i])
            cnt3++;
    }
    
    int m = max(cnt1, max(cnt2, cnt3));
    if(m == cnt1)
        answer.push_back(1);
    if(m == cnt2)
        answer.push_back(2);
    if(m == cnt3)
        answer.push_back(3);
    
    return answer;
}