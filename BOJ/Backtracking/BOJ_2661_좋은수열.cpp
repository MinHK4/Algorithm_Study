// https://www.acmicpc.net/problem/2661

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector<int> ans;
int N;
bool done = false;

void backtrack(int size){
  
  // end case
  if(size > N){
    done = true;
    return;
  }

  // 숫자 작은 것부터 하나씩 넣어보기
  for(int i=1; i<=3; i++){

    // 이미 답 찾았으면 시도 안하고 나오기
    if(done)
      break;
    
    // 숫자 넣어보고
    ans[size] = i;
    
    // 중복 수열 발생하는지 확인
    // 현재 수열의 반 크기까지 다 확인해줘야 함
    bool num_flag = true;
    for(int j=1; j<=size/2; j++){
      bool rep_flag= true;
      for(int k=0; k<j; k++){
        if(ans[size-k]!=ans[size-j-k]){
          rep_flag = false;
          break;
        }
      }
      if(rep_flag){
        num_flag = false;
        break;
      }
    }

    // 중복 수열이 발생하지 않으면 다음 인덱스로 넘어가기
    if(num_flag)
      backtrack(size+1);
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);
  
  cin >> N;
  ans.resize(N+1, 0);

  backtrack(1);

  for(int i=1; i<=N; i++)
    cout << ans[i];
}


/*
기존의 수열에 새로운 숫자를 하나씩 더해가는 방식으로 좋은 수열을 찾아가기
새로운 숫자 하나 추가할 때마다 전체 수열 길이의 반 크기만큼의 수열까지 중복 여부를 체크해줘서
약간 DP같이 기존의 문제 셋이 해결된 상태로 넘어간다고 생각할 수 있음 

하지만 앞서서 숫자 하나씩 넣어줄 때의 기준은 작은 것 우선이므로
그것보다 큰 숫자를 넣어야 해결되는 경우를 고려해줘야 하므로 Backtracking 기법으로 접근해야함 
*/ 