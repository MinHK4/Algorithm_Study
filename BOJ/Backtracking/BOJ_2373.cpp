#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector<int> ans;
vector<int> arr;
vector<bool> correct;
bool done = false;
int N, M;

void backtrack(int idx){
  
  //end case
  if(idx == N+1){
    done = true;
    return;
  }
  
  // 현재 위치가 정답일 경우
  // 이전 값과 일치하는지만 확인하고 다를 경우 진행
  if(!done && correct[idx]){
    if(arr[idx] == arr[idx-1])
      return;
    backtrack(idx+1);
  }

  // 현재 위치가 오답일 경우
  // 이전에 표기한 값과 다르고 현재 위치 정답과도 다른 값 넣고 진행
  else if(!done && !correct[idx]){
    for(int i=1; i<=5; i++){
      if(!done && i!=arr[idx-1] && i!=ans[idx]){
        arr[idx] = i;
        backtrack(idx+1); 
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  cin >> N >> M;
  
  ans.resize(N+1);
  arr.resize(N+1, 0);
  for(int i=1; i<=N; i++)
    cin >> ans[i];

  correct.resize(N+1, false);
  while(M--){
    int temp;
    cin >> temp;
    correct[temp] = true;
    arr[temp] = ans[temp];
  }

  backtrack(1);

  for(int i=1; i<=N; i++)
    cout << arr[i] << ' ';
}