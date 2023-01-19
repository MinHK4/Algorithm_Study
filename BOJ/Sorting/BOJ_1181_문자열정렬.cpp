#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

bool comp(string a, string b){
  if(a.length() == b.length())
    return a < b;
  return a.length() < b.length();
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  int N;
  cin >> N;

  vector<string> arr(N);
  for(int i=0; i<N; i++){
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end(), comp);
  
  string prev = "";
  for(auto str: arr){
    if(prev != str){
      cout << str << '\n';
      prev = str;
    }
  }
}