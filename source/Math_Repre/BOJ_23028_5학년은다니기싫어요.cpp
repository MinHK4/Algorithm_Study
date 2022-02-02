// https://www.acmicpc.net/problem/23028

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int N, A, B;
  cin >> N >> A >> B;

  vector<pii> arr(10);
  for(int i=0; i<10; i++)
    cin >> arr[i].first >> arr[i].second;
    
  bool flag = false;
  int major = 0;
  int none = 0;
  for(int i=0; i<8-N; i++){
    major += arr[i].first;
    none += min(6-arr[i].first, arr[i].second);
  }

  if(A + major*3 >= 66 && B+(major+none)*3 >= 130)
    flag = true;

  if(flag)
    cout << "Nice";
  else
    cout << "Nae ga wae";
}