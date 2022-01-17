#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);
  
  int N;
  cin >> N;

  vector <int> res;
  vector <int> seq;
  deque <int> org;

  for(int i=1; i<=N; i++){
    res.push_back(i);
    int temp;
    cin >> temp;
    seq.push_back(temp);
  }

  for(int i=N-1, j=0; i>=0; i--, j++){
    if(seq[i]==1)
      org.push_front(res[j]);
    else if(seq[i]==2){
      int front = org.front();
      org.pop_front();
      org.push_front(res[j]);
      org.push_front(front);
    }
    else
      org.push_back(res[j]);
  }
  for(int x : org)
    cout << x << ' ';
}