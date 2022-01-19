#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int N, M;
  cin >> N >> M;

  priority_queue<int> gift;
  for(int i=0; i<N; i++){
    int temp;
    cin >> temp;
    gift.push(temp);
  }

  vector<int> need(M);
  for(int i=0; i<M; i++)
    cin >> need[i];

  bool flag = true;
  for(int i=0; i<M; i++){
    int cur = gift.top();
    gift.pop();

    if(cur < need[i]){
      flag = false;
      break;
    }
    if(cur != need[i])
      gift.push(cur-need[i]);
  }

  if(flag)
    cout << 1;
  else
    cout << 0;
}  