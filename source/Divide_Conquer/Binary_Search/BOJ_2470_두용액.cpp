// https://www.acmicpc.net/problem/2470

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

bool sortby(pii a, pii b){
  return abs(a.first + a.second) < abs(b.first + b.second);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  int N;
  cin >> N;

  // 산성과 알칼리 따로 구분해서 저장
  vector<int> acid, alcal;
  while(N--){
    int temp;
    cin >> temp;
    if(temp > 0)
      acid.push_back(temp);
    else 
      alcal.push_back(temp);
  }

  // 이분탐색을 하기 위함 + 한 종류만 사용의 예최처리를 위해서 정렬
  sort(acid.begin(), acid.end());
  sort(alcal.begin(), alcal.end());
  
  // 한 종류만 사용하는 경우 예외처리
  // 음수의 정렬이니까 뒤에서 두 개 + 순서 조심!!
  vector<pii> answer;
  if(acid.size() >= 2)
    answer.push_back({acid[0], acid[1]});
  if(alcal.size() >= 2)
    answer.push_back({alcal[alcal.size()-2], alcal[alcal.size()-1]});
  
  // 이분탐색 기반의 lowerbound로 가장 유사한 값 찾아주기
  for(auto x : alcal){
    auto lower = lower_bound(acid.begin(), acid.end(), -x);
    if(lower != acid.begin())
      answer.push_back({x, *(lower-1)});
    if(lower != acid.end())
      answer.push_back({x, *(lower)});
  }

  // 구한 모든 조합 중에서 합이 0가 가장 가깝게 정렬 후 정답 출력
  sort(answer.begin(), answer.end(), sortby);  
  cout << answer[0].first << ' ' << answer[0].second;
}

/*
이분탐색 기반의 lower bound 활용해서 탐색하기

산성과 알칼리 각각을 구분해서 벡터에 담아준 뒤에
정렬해서 한 종류의 용액만으로 나오는 경우 예외 처리해주고
lower bound 이용해서 값 보다 이상인 최초의 값 찾아서 그것과 그 뒤에 값 추가
answer에서 다시 한 번 정렬해서 첫 원소 출력

-- 틀렸습니다
alcal은 음수 값이라서 정렬하고 알칼리만으로 구성된 경우 처리해주려면
가장 앞이 아니라 뒤에 두 개를 잡아주어야 함

++ 한 쌍 내에서 순서도 조심!!
*/