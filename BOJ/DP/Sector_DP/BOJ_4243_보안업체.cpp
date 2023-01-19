// https://www.acmicpc.net/problem/4243

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

ll dp[104][104][2];
ll sum[104];
ll N, a;

ll dfs(ll l, ll r, ll flag){
  // 기존에 탐색했던 적 있는 구간
  if(dp[l][r][flag] != -1)
    return dp[l][r][flag];
  
  // 모든 구간을 탐색해서 완료한 경우
  // 현재 구간 외에 남아있는 지점들이 없으므로 빈 손으로 돌아가기
  if(l==1 && r ==N){
    dp[l][r][flag] = 0;
    return dp[l][r][flag];
  }

  // 추가로 구간 탐색하기
  // flag는 다음 지점까지의 이동 시간을 구하기 위한 현재 위치를 구하기 위해서만 사용
  // 다음 재귀함수로 보내는 경우은 구간을 기준으로 하나씩 더 넓히는 방식으로만 접근
  // ++ 
  dp[l][r][flag] = LLONG_MAX;
  ll cur = flag? r : l;
  ll remain = N - r + l - 1;
  if(1<l)
    dp[l][r][flag] = min(dp[l][r][flag], dfs(l-1, r, 0) + remain * (sum[cur] - sum[l-1]));
  if(r<N)
    dp[l][r][flag] = min(dp[l][r][flag], dfs(l, r+1, 1) + remain * (sum[r+1] - sum[cur]));

  return dp[l][r][flag];
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);

  ll TC;
  cin >> TC;
  while(TC--){
    memset(dp, -1, sizeof(dp));
    memset(sum, 0, sizeof(sum));

    // 누적합으로 지점 간 이동시간 저장
    cin >> N >> a;
    for(ll i=2; i<=N; i++){
      cin >> sum[i];
      sum[i] += sum[i-1];
    }

    cout << min(dfs(a,a,0), dfs(a,a,1)) << '\n';
  }
}

/*
누적합 + DP(Topdown)
특정 시작점에서부터 시작해서 순찰을 해나가는데 현재 도달한 지점까지의 대기 시간이 계속해서 누적되는 방식
그러므로 당연히 어떤 시작점에서 시작했으면 그 구간을 하나씩 넓혀가는 것이 최소의 대기 시간을 구하는 방법
시작점 (a,a) -> min(구간(a-1, a), 구간(a,a+1))
이런 방식으로 구간을 조금씩 넓혀가면서 현재 선택한 지점으로 이동하기 위해서 드는 대기시간을 남아있는 지점 수만큼 곱해서 누적

추가로 같은 구간 (a,b)에 대해서 (a+1, b)에서 온 것과 (a, b-1)에서 온 것이 다른 경우임
따라서 이를 표현하기 위해서 추가 flag값을 설정해줘서 최종적인 dp 값을 정의해준다.
dp[l][r][flag] : flag 0 이면 l, 1이면 r가 중심인 구간 (r, l)에 대하여 현재까지 얻은 최소 대기 시간
다만 Top_Down 방식으로 구성되어있기 때문에 보내서 값을 얻어오는 형식이라서
(l, r)을 제외한 지점이 남아있을 때의 최소값 구성이 조금 더 정확한 표현
*/