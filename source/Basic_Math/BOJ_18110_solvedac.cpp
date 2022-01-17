#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <ll, ll>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  freopen("inp.txt", "r", stdin);
  
  vector<int> opinion;
  int N;
  cin >> N;
  
  if(N == 0){
    cout << 0;
    return 0;
  }

  for(int i=0; i<N; i++){
    int temp;
    cin >> temp;
    opinion.push_back(temp);
  }
  sort(opinion.begin(), opinion.end());

  int exclude = round((double)N * 15 / 100);
  int sum = 0;
  for(int i=0; i<N; i++){
    if(i< exclude || i>= N-exclude)
      continue;
    sum += opinion[i];
  }

  cout << round((double)sum / (N - 2*exclude));
}