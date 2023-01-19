// https://www.acmicpc.net/problem/15654

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector<int> arr;
vector<int> check;
vector<int> ans;
int N, M;

void rcs(int idx){
  if(idx > M){
    for(int i=1; i<=M; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for(int i=1; i<=N; i++){
    if(!check[i]){
      check[i] = true;
      ans[idx] = arr[i];
      rcs(idx+1);
      check[i] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  cin >> N >> M;
  
  arr.resize(N+1);
  arr[0] = -1;
  for(int i=1;i <=N; i++)
    cin >> arr[i];
  sort(arr.begin(), arr.end());

  check.resize(N+1);
  ans.resize(M+1);

  rcs(1);
}

/*
백트래킹으로 중복 가능 순열 주어진 수 안에서 만들기
*/