// https://www.acmicpc.net/problem/20921 

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int N, K;
  cin >> N >> K;

  vector<int> ans(N+1, 0);
  int num;
  
  // 큰 수부터 만들 수 있는 사이 최대한 만들면서 배치 
  for(num=N; num>=1; num--){
    if(K==0)
      break;
    if(K >= num-1){
      ans[N-num+1] = num;
      K -= num-1;
    }
    else{
      ans[N-K] = num;
      K = 0;
    }
  }

  // 모든 사이 만들고 난 후 남은 수들 오름차순으로 남은 자리에 배치
  int temp = 1;
  int idx = 1;
  while(temp <= num){
    if(ans[idx]==0){
      ans[idx] = temp;
      temp++;
    }
    idx++;
  }

  for(int i=1; i<=N; i++)
    cout << ans[i] << ' '; 
}

/*
그리디 기법
큰 수가 왼쪽에 위치할수록 사이 많이 발생
큰 수부터 채워 줄 수 있는 만큼 사이를 만들어줄 수 있는 위치에 배정하고
모든 사이가 다 만들어지고 나면 남아있는 작은 수들을 남은 자리들에 오름차순으로 배치
*/