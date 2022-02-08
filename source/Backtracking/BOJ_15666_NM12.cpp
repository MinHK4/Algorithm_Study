// https://www.acmicpc.net/problem/15666

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector<int> arr;
vector<int> ans;
int N, M;
int len;

void  backtrack(int idx, int size){
  
  // end case
  if(size > M){
    for(int i=1; i<=M; i++)
      cout << ans[i] << ' ';
    cout << '\n';
    return;
  }

  for(int i=idx; i<len; i++){
    ans[size] = arr[i];
    backtrack(i, size+1); 
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  cin >> N >> M;
  while(N--){
    int temp;
    cin >> temp;
    arr.push_back(temp);
  }

  //벡터 중복 제거
  sort(arr.begin(), arr.end());
  arr.erase(unique(arr.begin(),arr.end()),arr.end());
  len = arr.size();

  ans.resize(M+1);

  backtrack(0, 1);
}

/*
중복된 숫자가 들어오는 경우를 감안해서
입력을 벡터에다가 전부 받은 뒤에 벡터 중복 제거 처리를 해준다
이후에는 중복 가능 비감소 수열을 backtracking을 이용해 만들어주면 된다.
*/