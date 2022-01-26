#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector<int> arr;
vector<bool> visited;
int N, K;
bool flag = false;

void DFS(int cur){

  visited[cur] = true;

  if(cur == N-1){
    flag = true;
    return;
  }

  for(int i=cur+1; i<N; i++){
    if(!flag && !visited[i] && (i-cur)*(1+abs(arr[cur]-arr[i])) <= K)
      DFS(i);
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  cin >> N >> K;
  arr.resize(N);
  visited.resize(N, false);
  for(int i=0; i<N; i++)
    cin >> arr[i];
  
  DFS(0);

  if(flag)
    cout << "YES";
  else
    cout << "NO";
}