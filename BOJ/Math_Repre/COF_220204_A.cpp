// https://codeforces.com/contest/1279/problem/A

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int TC;
  cin >> TC;
  while(TC--){
    vector<int> arr(3);
    for(int i=0; i<3; i++)
      cin >> arr[i];
    sort(arr.begin(), arr.end());
    
    if(arr[2]-1-arr[1]>arr[0])
      cout << "No\n";
    else
      cout << "Yes\n";
  }
}

/*
수학적 아이디어
안 겹칠려면 가장 큰 애 사이에 끼워넣기
*/