// https://www.acmicpc.net/problem/1379

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

struct lecture{
  int id, start, end;
};

// PQ 구조체 연산자 오버로딩하는 방법
struct cmp{
  bool operator()(lecture a, lecture b){
    return a.end > b.end;
  }
};

bool comp_s(lecture a, lecture b){
  if(a.start == b.start)
    return a.end < b.end;
  return a.start < b.start; 
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int N;
  cin >> N;

  vector<lecture> lectures(N);
  for(int i=0; i<N; i++)
    cin >> lectures[i].id >> lectures[i].start >> lectures[i].end;
  sort(lectures.begin(), lectures.end(), comp_s);
  
  // 한 강의가 진행 중일 때 겹치는 강의의 최대 수 구하면서 강의실 배정
  priority_queue<lecture, vector<lecture>, cmp> pq;
  vector<int> room(N+1);
  int ans = 0;
  for(int i=0; i<N; i++){
    
    // 이전 강의와 겹치지 않는 경우
    // 이전 강의와 동일한 강의실 사용해도 무관하므로 강의실 id 공유 받아오기
    if(!pq.empty() && pq.top().end <= lectures[i].start){
      room[lectures[i].id] = room[pq.top().id];
      pq.pop();
    }

    // 첫 강의이거나 이전 강의가 현재 강의와 겹쳐서 새로운 강의실 필요한 경우
    // ans(강의실 id 역할) 늘리면서 새 강의를 배당
    else{
      ans++;
      room[lectures[i].id] = ans; 
    }

    // 현재 강의 넣어서 이후 고려해주기
    pq.push(lectures[i]);
  }
  cout << ans << '\n';

  for(int i=1; i<=N; i++)
    cout << room[i] << '\n';
}

/*
핵심 아이디어
: 한 강의가 진행되고 있을 때 진행되고 있는 강의의 수의 최댓값을 구해주기
강의시작 시간을 기준으로 정렬을 해주고 PQ에는 강의 끝나는 시간을 저장
현재 확인하려고 하는 강의와 겹치지 않는(끝나는 시간이 현재 강의보다 이르거나 같은) 강의 제거
그러고 나서 현재 강의로 넣고 PQ 사이즈 확인하면 겹치는 강의들의 묶음이 됨

+ PQ 구조체 연산자 오버로딩해서 처리하기 (strucr operator)
*/ 