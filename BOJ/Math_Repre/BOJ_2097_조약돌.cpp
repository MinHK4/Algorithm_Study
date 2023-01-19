#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int N;
  cin >> N;
  if(N<=4)
    cout << 4; 
  else{
    int root = floor(sqrt(N));
    if(root * root == N)
      cout << ((root-1) + (root-1)) * 2;
    else{
      int temp = N - root*root;
      if(temp <= root)
        cout << (root + root-1) * 2;
      else
        cout << (root + root) * 2;
    }
  }
}