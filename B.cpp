#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;

  int usage = 0;
  int ex_phone = -1;
  int ex_usage = 0;
  while(N--){
    int phone;
    cin >> phone;

    if(ex_phone == phone){
      usage += ex_usage * 2;
      ex_usage *= 2;
    }
    else{
      usage += 2;
      ex_usage = 2;
    }
    ex_phone = phone;

    if(usage >= 100){
      usage = 0;
      ex_phone = -1;
    }
  }
  cout << usage;
}