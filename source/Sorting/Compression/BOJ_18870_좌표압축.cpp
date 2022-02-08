// https://www.acmicpc.net/problem/18870

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);
  
  vector <int> arr, comp;
  int N;

  cin >> N;
  arr.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    comp.push_back(arr[i]);
  }

  sort(comp.begin(), comp.end());
  comp.erase(unique(comp.begin(), comp.end()), comp.end());

  for (int i = 0; i < N; i++)
    cout << lower_bound(comp.begin(), comp.end(), arr[i]) - comp.begin() << ' ';

}