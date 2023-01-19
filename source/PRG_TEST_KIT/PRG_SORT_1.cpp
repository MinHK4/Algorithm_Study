#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(auto command : commands){
        vector<int> temp;
        for(int i=command[0]-1; i<=command[1]-1; i++)
            temp.push_back(array[i]);
        sort(temp.begin(), temp.end());
        
        answer.push_back(temp[command[2]-1]);
    }
    
    return answer;
}