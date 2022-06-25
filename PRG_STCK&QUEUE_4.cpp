// https://programmers.co.kr/learn/courses/30/lessons/42584

#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    
    vector<int> answer(prices.size());
    stack<int> s;
    
    int size = prices.size();
    for(int i=0;i<size;i++){
        // 스택에는 지금 인덱스의 값보다 작거나 같은 값만 남겨놓음
        // 자신보다 큰 값이 스택에 있을 경우에는 해당 값을 빼주면서 현재 인덱스에서 해당 값의 인덱스를 빼줌
        // 그럼 해당 값이 자신보다 낮은 가격을 만나기 전까지 버틴 시간이 계산됨
        // 한번 자신보다 낮은 가격이 나온 값들은 그 이후에 고려해줄 필요없으므로 스택에서 pop 해줌
        while(!s.empty() && prices[s.top()]>prices[i]){
            answer[s.top()] = i-s.top();
            s.pop();
        }
        // 지금가지고 있는 값들보다 큰 값이 나오면 계속 쌓아줌
        s.push(i);
    }
    
    // 아직까지 스택에 남아있는 아이들은 자신보다 뒤쪽에 작은 값이 나오지 않았다는 뜻임
    // 전체 크기에서 자기의 위치만큼 빼준 값을 저장해주면 됨
    while(!s.empty()){
        answer[s.top()] = size-s.top()-1;
        s.pop();
    }
    return answer;
}