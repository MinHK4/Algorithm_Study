#include <bits/stdc++.h>

using namespace std;

int answer = 0;
int limit;
int target;

int level(int cur){
    return floor(sqrt(cur))+1;
}

int up_left(int cur){
    int cur_level = level(cur);

    // 홀수 층
    if(cur_level % 2){
        // 현재가 홀수이면
        if(cur % 2)
            return cur-(cur_level-1)*2;
        // 현재가 짝수이면
        else
            return cur-1;
    }
    //짝수 층
    else{
        // 현재가 홀수이면
        if(cur % 2)
            return cur-1;
        // 현재가 짝수이면
        else
            return cur-(cur_level-1)*2;
    }
}

int up_right(int cur){
    int cur_level = level(cur);

    // 홀수 층
    if(cur_level % 2){
        // 현재가 홀수이면
        if(cur % 2)
            return cur-(cur_level-1)*2;
        // 현재가 짝수이면
        else
            return cur+1;
    }
    //짝수 층
    else{
        // 현재가 홀수이면
        if(cur % 2)
            return cur+1;
        // 현재가 짝수이면
        else
            return cur-(cur_level-1)*2;
    }
}

int down_left(int cur){
    int cur_level = level(cur);

    // 홀수 층
    if(cur_level % 2){
        // 현재가 홀수이면
        if(cur % 2)
            return cur-1;
        // 현재가 짝수이면
        else
            return cur+cur_level*2;
    }
    //짝수 층
    else{
        // 현재가 홀수이면
        if(cur % 2)
            return cur+cur_level*2;
        // 현재가 짝수이면
        else
            return cur-1;
    }
}

int down_right(int cur){
    int cur_level = level(cur);

    // 홀수 층
    if(cur_level % 2){
        // 현재가 홀수이면
        if(cur % 2)
            return cur+1;
        // 현재가 짝수이면
        else
            return cur+cur_level*2;
    }
    //짝수 층
    else{
        // 현재가 홀수이면
        if(cur % 2)
            return cur+cur_level*2;
        // 현재가 짝수이면
        else
            return cur+1;
    }
}

bool move_check(vector<bool> v, int cur){

    int cur_level = level(cur);

    // 자기 위치 확인
    if(v[cur])
        return false;

    // 같은 층 확인 - 뒤로
    for(int i=cur-1; cur_level==level(i); i--){
        if(v[i])
            return false;
    }
    // 같은 층 확인 - 앞으로
    for(int i=cur+1; cur_level==level(i); i++){
        if(v[i])
            return false;
    }

    // 대각 좌상 확인
    int temp = up_left(cur);
    while(temp >= 0 && temp < limit){
        if(v[temp])
            return false;
        if(temp == 0)
          break;
        temp = up_left(temp);
    }

    // 대각 우상 확인
    temp = up_right(cur);
    while(temp >= 0 && temp < limit){
        if(v[temp])
            return false;
        if(temp == 0)
          break;
        temp = up_right(temp);
    }

    // 대각 좌하 확인
    temp = down_left(cur);
    while(temp >= 0 && temp < limit){
        if(v[temp])
            return false;
        if(temp == 0)
          break;
        temp = down_left(temp);
    }

    // 대각 우하 확인
    temp = down_right(cur);
    while(temp >= 0 && temp < limit){
        if(v[temp])
            return false;
        if(temp == 0)
          break;
        temp = down_right(temp);
    }

    return true;
}

void fill_in(vector<bool> &v, int cur){

    int cur_level = level(cur);

    // 자기 위치
    v[cur] = true;

    // 같은 층 확인 - 뒤로
    for(int i=cur-1; cur_level==level(i); i--){
        v[i] = true;
    }
    // 같은 층 확인 - 앞으로
    for(int i=cur+1; cur_level==level(i); i++){
        v[i] = true;
    }

    // 대각 좌상 확인
    int temp = up_left(cur);
    while(temp >= 0 && temp < limit){
        v[temp] = true;
        if(temp == 0)
          break;
        temp = up_left(temp);
    }

    // 대각 우상 확인
    temp = up_right(cur);
    while(temp >= 0 && temp < limit){
        v[temp] = true;
        if(temp == 0)
          break;
        temp = up_right(temp);
    }

    // 대각 좌하 확인
    temp = down_left(cur);
    while(temp >= 0 && temp < limit){
        v[temp] = true;
        if(temp == 0)
          break;
        temp = down_left(temp);
    }

    // 대각 우하 확인
    temp = down_right(cur);
    while(temp >= 0 && temp < limit){
        v[temp] = true;
        if(temp == 0)
          break;
        temp = down_right(temp);
    }
}

void backtrack(vector<bool> v, int idx, int cnt){
    
    // end case - 모든 룩 배치 완료
    if(cnt == target){
        answer++;
        return;
    }

    // end case - 인덱싱 넘어간 경우
    if(idx >= limit)
        return;

    // 하나씩 룩 채워서 모든 경우 다 확인해보기
    for(int i=idx; i<limit; i++){
        if(move_check(v, i)){
            vector<bool> temp = v;
            fill_in(&temp, i);
            backtrack(temp, i+1, cnt+1);
        }
    }
}

int solution(int n, int rooks) {

    vector<bool> tri(n*n, false);
    limit = n*n;
    target = rooks;

    backtrack(tri, 0, 0);

    return answer;
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n, rooks;
  cin >> n >> rooks;
  cout << solution(n, rooks);
}