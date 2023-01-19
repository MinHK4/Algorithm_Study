// https://www.acmicpc.net/problem/1980

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;


bool sortby(pii a, pii b){
  if(a.second == b.second)
    return a.first > b.first;
  return a.second < b.second;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);
  vector<pii> ans;
  int n, m, t;
  cin >> n >> m >> t;
  
  // n이 더 작은 값이게 설정
  if(m < n)
    swap(n, m);

  // iterative하게 모든 경우 조합 만들어보기
  for(int i=0; i*n <= t; i++){
    for(int j=0; j*m <= t; j++){
      if(i*n + j*m > t)
        break;
      if(t - (i*n + j*m) <= m)
        ans.push_back({i+j, t - (i*n + j*m) });
    }
  }

  // 가능한 모든 경우 중에서 우선순위에 맞춰서 출력
  sort(ans.begin(), ans.end(), sortby);
  cout << ans[0].first << ' ' << ans[0].second;
}

/*
Bruteforce 기법을 이용해 t시간 안에 넣을 수 있는 모든 햄버거 조합을 만들어보고
그 중에서 조건에 가장 부합하는 값 출력하기

-- 메모리 초과 발생 1

ans에 작은 경우도 다 넣다보니 vector 공간 메모리 초과 발생하는 듯
우리가 보고자 하는 것은 최대한 많이 넣은 경우들이니 t-m보다 큰 경우만 고려합시다

-- 메모리 초과 발생 2
생각해보니 재귀함수로 돌리는 것 자체에서 stack overflow 발생하는 문제일 듯
재귀말고 iterative하게 재구현
*/