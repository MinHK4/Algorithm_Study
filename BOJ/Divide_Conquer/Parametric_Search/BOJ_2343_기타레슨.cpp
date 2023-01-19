// https://www.acmicpc.net/problem/2343

#include <bits/stdc++.h>

using namespace std;

vector<int> lecture;
int N, M;

// 문제풀이 조건 만족 : 강의를 순서대로 묶었을 때 M개의 블루레이 안에 정리가능한지
bool solve(int key){
  int cnt = 1;
  int sum = 0;

  for(auto x: lecture){

    // 특수 예외 케이스 : 현재 설정한 블루레이보다 강의 하나가 더 큰 경우
    if(x > key)
      return false;

    if(sum+x <= key)
      sum += x;
    else{
      sum = x;
      cnt++;
    }
  }

  if(cnt <= M)
    return true;
  return false;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  cin >> N >> M;

  int sum = 0;
  for(int i=0; i<N; i++){
    int temp;
    cin >> temp;
    lecture.push_back(temp);
    sum += temp;
  }

  // 이분탐색 활용해서 Parametric Seach
  int s = 1;
  int e = sum;
  int ans;
  while(s <= e){
    int mid = (s+e) / 2;
    if(solve(mid)){
      e = mid-1;
      ans = mid;
    }
    else 
      s = mid+1;
  }
  cout << ans;
}

/*
Parametric Search 풀이

-- 틀렸습니다
특수 예외 케이스 추가
전체 합을 구한 상태에서 개별 강의에 대해서 적용하다 보니 놓치는 맹점 발생
*/