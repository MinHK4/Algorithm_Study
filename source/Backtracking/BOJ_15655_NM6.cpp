// https://www.acmicpc.net/problem/15655


#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector<int> arr;
vector<int> ans;
vector<bool> checked;
int N, M;

void rcs(int idx, int size){

  if(size == M){
    for(int i=0; i<M; i++)
      cout << ans[i] << ' ';
    cout << '\n';
    return;
  }

  for(int i=idx; i<N; i++){
    if(!checked[i]){
      ans[size] = arr[i];
      checked[i] = true;
      rcs(i+1, size+1);
      checked[i] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  cin >> N >> M;

  arr.resize(N);
  for(int i=0; i<N; i++)
    cin >> arr[i];
  sort(arr.begin(), arr.end());

  checked.resize(N, false);
  ans.resize(M);

  rcs(0, 0);
    
}

/*
비중복 오름차순 수열 생성하기
*/