#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> replies, int n, int k) {
    vector<int> answer;

    for(auto reply: replies){
        int len = reply.size();
        bool flag = true;

        for(int i=0; i<len && flag; i++){
            for(int j=n; i+k*j<=len && flag; j++){
                int cnt = 0;

                for(int l=1; l<k; l++){
                    if(reply.substr(i+j*(l-1), j) == reply.substr(i+j*l, j)){
                        cnt++;
                    }
                }
                if(cnt == k-1){
                    cout << reply.substr(i, j) << ' ' << reply.substr(i+j, j) << '\n';    
                    flag = false;
                }
            }
        }

        if(flag)
            answer.push_back(1);
        else
            answer.push_back(0);
    }

    return answer;
}