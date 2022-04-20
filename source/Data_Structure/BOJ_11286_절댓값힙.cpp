// https://www.acmicpc.net/problem/1927
// https://www.acmicpc.net/problem/11279
// https://www.acmicpc.net/problem/11286

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

class sortby{
  public:
    bool operator()(int a, int b){
      if(abs(a) == abs(b)) 
        return a > b;
      return abs(a) > abs(b);
    }
};

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  priority_queue<int, vector<int>, sortby> pq;
  int N;
  cin >> N;
  while(N--){
    int temp;
    cin >> temp;

    if(temp == 0){
      if(pq.empty())
        cout << 0 << '\n';
      else{
        cout << pq.top() << '\n';
        pq.pop();
      }
    }
    else
      pq.push(temp);
  }
}

// PQ 기본 개념 문제
// PQ custom sort 해줄 때는 class 만들어서 해줘야 함