// https://www.acmicpc.net/problem/2512

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector<int> arr;
int N, M;

// 문제풀이 조건 만족 : 기준대로 예산 배정 했을 때 총 예산보 안의 범위인지
bool solve(int key){
  int sum = 0;
  for(auto x : arr)
    sum += x >= key ? key : x;
  
  if(sum <= M)
    return true;
  return false;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  cin >> N;
  int max_val = -1;
  for(int i=0; i<N; i++){
    int temp;
    cin >> temp;
    max_val = max(max_val, temp);
    arr.push_back(temp);
  }
  cin >> M;


  // 이분탐색 활용해서 Parametric Seach
  int s = 1;
  int e = max_val;
  int ans;
  while(s <= e){
    int mid = (s+e) / 2;
    if(solve(mid)){
      s = mid + 1;
      ans = mid;
    }
    else
      e = mid - 1;
  }

  cout << ans;
}

/*
Parametric Search 풀이

-- 틀렸습니다
총 예산이 항상 충족하지 않을 수도 있음
모든 지방 예산을 다 못 채워주는 경우를 위해서 s를 min으로 잡으면 안 됨
*/