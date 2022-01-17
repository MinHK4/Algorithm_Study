#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

bool cmp(pii a, pii b){
  if(a.second == b.second)
    return a.first < b.first;
  return a.second < b.second;
}


int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int num;
  cin >> num;

  vector <pii> arr;
  while(num--){
    int tempx, tempy;
    cin >> tempx >> tempy;
    arr.push_back({tempx, tempy});
  }
  
  sort(arr.begin(), arr.end(), cmp);

  for(pii x : arr)
    cout << x.first << ' ' << x.second << '\n';
}  