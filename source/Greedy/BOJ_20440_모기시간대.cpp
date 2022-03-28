// https://www.acmicpc.net/problem/20440

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

struct sortby{
  bool operator()(pii a, pii b){
    return a.second > b.second;
  }
};

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int N;
  cin >> N;
  
  vector<pii> arr(N);
  for(int i=0; i<N; i++)
    cin >> arr[i].first >> arr[i].second;
  sort(arr.begin(), arr.end());
  
  priority_queue<pii, vector<pii>, sortby> pq;
  pq.push(arr[0]);

  int max_cnt = 1;
  int max_start = arr[0].first;
  int max_end = arr[0].second;

  int tmp_start = arr[0].first;
  int tmp_end = arr[0].second;
  
  for(int i=1; i<N; i++){
    
    // 모기 한 마리 더 쌓임 (기존 끝나는 시간보다 일찍 시작하는 모기 입장)
    if(arr[i].first < pq.top().second){
      tmp_start = arr[i].first;
      tmp_end = min(pq.top().second, arr[i].second);
    }

    // 모기 교체1 (한 마리 나가자마자 바로 들어옴)
    bool flag = false;
    if(arr[i].first == pq.top().second){
      pq.pop();
      // PQ가 다 비는 경우 고려해줘야 함
      if(pq.empty())
        tmp_end = arr[i].second;
      else
        tmp_end = min(pq.top().second, arr[i].second);
      flag = true;
    }

    // 모기 교체2 (들어오려는 모기보다 기존 끝나는 시간이 빠름)
    if(arr[i].first > pq.top().second){
      pq.pop();
      tmp_start = arr[i].first;
      tmp_end = min(pq.top().second, arr[i].second);
    }
    
    pq.push(arr[i]);

    // 모기 최대 입장 구간에 대한 업데이트
    // 모기 교체1시에는 카운트 증가는 없지만 끝나는 시간이 늘어나므로 체크해주어야 함
    if(max_cnt < pq.size()){
      max_cnt = pq.size();
      max_start = tmp_start;
      max_end = tmp_end; 
    }
    if(max_cnt == pq.size() && flag)
      max_end = tmp_end;
  }

  cout << max_cnt << '\n' << max_start << ' ' << max_end;
}

/*
BOJ1379와 유사한 풀이 방식
시작 시간 정렬해서 넣어주고 PQ는 끝나는 시간 기준으로 관리해서 서로 겹치는 구간 확인
구간의 시간대 확인하기 위해서 조금의 변형 추가

-틀렸습니다 at 92% ?!?!?

PQ가 비는데 이어지는 경우에서 pq.top() 참조하는 문제 발생
3
1 5
5 7
7 9
와 같은 예시 생각해서 예외처리 추가
*/