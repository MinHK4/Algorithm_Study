// https://www.acmicpc.net/problem/17298

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", ddin);
  
  int N;
  cin >> N;

  vector<int> arr(N);
  for(int i=0; i<N; i++)
    cin >> arr[i];
  
  stack <int> st;
  vector<int> ans(N);
  st.push(arr[N-1]);
  ans[N-1] = -1;

  for(int i=N-2; i>=0; i--){
    while(!st.empty() && st.top() <= arr[i])
      st.pop();
    
    if(st.empty() || st.top() <= arr[i])
      ans[i] = -1;
    else
      ans[i] = st.top();
    
    if(i > 0 && arr[i-1] < arr[i] || i==0)
      st.push(arr[i]);
  }

  for(int x : ans)
    cout << x << ' ';

}
/*
IDAE : deque 이용해서 현재 인덱스의 뒤 중에서 증가하는 수 관리해주기
이전 수보다 증가하는 수들을 값과 인덱스의 페어로 deque에다가 저장
인덱스 하나마다 확인하면서 자신보다 뒷 인덱스까지 deque에서 이동한 후 값 비교해서 출력

----
5
9 5 4 8 10 의 경우 처리 불가

뒤 인덱스부터 큰 애들만 남도록 stack을 이용해서 관리하는 방식으로 수정
*/