// https://www.acmicpc.net/problem/9076

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  //freopen("inp.txt", "r", stdin);

  int N;
  cin >> N;

  for(int i=0; i<N; i++){
    vector<int> score(5);
    int sum = 0;
    for(int j=0; j<5; j++){
      cin >> score[j];
      sum += score[j];
    }
    
    sort(score.begin(), score.end());
    if(score[3] - score[1] >= 4)
      cout << "KIN\n";
    else
      cout << sum - score[0] - score[4]<< '\n';
  }
}