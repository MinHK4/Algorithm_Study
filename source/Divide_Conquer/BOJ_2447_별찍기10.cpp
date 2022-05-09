// https://www.acmicpc.net/problem/2447

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair <int, int>;

vector <vector<char>> v;

void Star(int level, int row, int col) {
	
  // end case - 1(3^0)개짜리에 도착했을 때 
  if(level == 0) {
		v[row][col] = '*';
		return;
	}

  // 중앙 부분을 제외하고 계속 재귀적으로 별 찍기
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i != 1 || j != 1)
        Star(level - 1, i * pow(3, level - 1) + row, j*pow(3, level - 1) + col);
    }
  }

}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int num;
	cin >> num;
  v.resize(num, vector<char>(num, ' '));
	
	int level = 0;
  for (int i = 3; i <= num; i *= 3)
		level++;

	// recursive call
	Star(level, 0, 0);

	//print out stars
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++)
			cout << v[i][j];
		cout << '\n';
	}
}

/*
재귀함수로 분할정복 풀이
*/