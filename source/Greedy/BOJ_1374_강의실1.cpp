// https://www.acmicpc.net/problem/1374

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

struct lecture{
  int id, start, end;
};

bool comp(lecture a, lecture b){
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
  sort(lectures.begin(), lectures.end(), comp);
  
  priority_queue<int> pq;

  int ans = -1;
  for(int i=0; i<N; i++){
    while(!pq.empty() && -pq.top() <= lectures[i].start)
      pq.pop();
    pq.push(-lectures[i].end);
    ans = max(ans, (int)pq.size());
  }

  cout << ans;
}

/*
핵심 아이디어
: 한 강의가 진행되고 있을 때 진행되고 있는 강의의 수의 최댓값을 구해주기
강의시작 시간을 기준으로 정렬을 해주고 PQ에는 강의 끝나는 시간을 저장
현재 확인하려고 하는 강의와 겹치지 않는(끝나는 시간이 현재 강의보다 이르거나 같은) 강의 제거
그러고 나서 현재 강의로 넣고 PQ 사이즈 확인하면 겹치는 강의들의 묶음이 됨
*/ 