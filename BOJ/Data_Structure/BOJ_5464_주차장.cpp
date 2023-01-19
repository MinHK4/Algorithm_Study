// https://www.acmicpc.net/problem/5464

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n, m;
	cin >> n >> m;

	vector<int> r(n + 1), w(m + 1);
	for (int i = 1; i <= n; i++)
		cin >> r[i];
	for (int i = 1; i <= m; i++)
		cin >> w[i];

	set<int> s;
	for (int i = 1; i <= n; i++)
		s.insert(i);

	unordered_map<int, int> pos;
	queue<int> q;
	int ans = 0;
	for (int i = 0; i < 2 * m; i++) {
		int car;
		cin >> car;

		if (car > 0)
			q.push(car);
		else {
			s.insert(pos[-car]);
			pos.erase(-car);
		}

		while (!q.empty() && !s.empty()) {
			set<int>::iterator it = s.begin();
			pos[q.front()] = *it;
			ans += w[q.front()] * r[*it];
			s.erase(*it);
			q.pop();
		}
	}

	cout << ans << '\n';
}