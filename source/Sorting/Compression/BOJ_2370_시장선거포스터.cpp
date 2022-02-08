// https://www.acmicpc.net/problem/2370

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  int N;
  cin >> N;

  vector<pii> arr(N);
  vector<int> comp;
  for(int i=0; i<N; i++){
    cin >> arr[i].first >> arr[i].second;
    comp.push_back(arr[i].first);
    comp.push_back(arr[i].second);
  }

  // 벡터 중복 제거
  sort(comp.begin(), comp.end());
  comp.erase(unique(comp.begin(), comp.end()), comp.end());

  // 압축된 좌표로 바꿔주기
  for(int i=0; i<N; i++){
    arr[i].first = lower_bound(comp.begin(), comp.end(), arr[i].first) - comp.begin();
    arr[i].second = lower_bound(comp.begin(), comp.end(), arr[i].second) - comp.begin();
  }
  
  // 압축된 좌표를 바탕으로 포스터 덮어졌는지 여부 뒤에서부터 확인
  vector<bool> checked(comp.size(), false);
  int ans = 0;
  for(int i=N-1; i>=0; i--){

    bool flag = false;
    for(int j=arr[i].first; j<=arr[i].second; j++){
      if(!checked[j]){
        flag = true;
        checked[j] = true;
      }
    }

    if(flag)
      ans++;
  }

  cout << ans;
}

/*
구간의 참거짓 여부를 SegTree로 해서 풀이할 수도 있겠지만
전체 값의 범위가 무려 10^8이라서 사용할 수 없음 
-> SegTree 경우에는 10^5 정도의 범위까지는 사용할 수 있음 

사실 10^8을 기반으로 돌리는 건 다른 걸로도 어려워서
저 좌표를 압축해주는 것이 필요힘
좌표압축 문제
https://www.acmicpc.net/problem/18870

압축된 좌표를 바탕으로 뒤 포스터부터 덮어주는 방식으로 보이는 포스터 수 체크해주기
*/ 