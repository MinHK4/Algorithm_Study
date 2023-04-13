#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, W, H;
int ans;

void display(vector<vector<int>> arr2D);
void dfs(vector<vector<int>> arr, int count);

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> N >> W >> H;

		vector<vector<int>> arr(W, vector<int>(H));
		for (int i = H - 1; i >= 0; i--) {
			for (int j = 0; j < W; j++) {
				cin >> arr[j][i];
			}
		}

		ans = N * W * H;
		
		dfs(arr, 0);

		cout << '#' << test_case << ' ' << ans << '\n';
	}

	return 0;
}

bool isValidPos(int row, int col) {
	return 0 <= row && row < W && 0 <= col && col < H;
}

// 블럭 뿌셔보기 돌린 배열 반화해주는 함수
vector<vector<int>> simulate(vector<vector<int>> arr, int row, int col) {
	
	//cout << "============BEFORE==========\n";
	//display(arr);

	if (!isValidPos(row, col)) return arr;
	
	queue <pair<int, int>> q;
	q.push({ row, col });

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		int num = arr[r][c];
		q.pop();

		//cout << r << ' ' << c << ' ' << num << '\n';

		arr[r][c] = 0;
		num--;

		int d = 1;
		while (d <= num) {
			if (isValidPos(r - d, c)) q.push({ r - d, c });
			if (isValidPos(r + d, c)) q.push({ r + d, c });
			if (isValidPos(r, c - d)) q.push({ r, c - d });
			if (isValidPos(r, c + d)) q.push({ r, c + d});
			d++;
		}
	}

	vector<vector<int>> new_arr;
	for (int i = 0; i < W; i++) {
		vector<int> temp;
		for (auto x: arr[i]) {
			if (x != 0) temp.push_back(x);
		}

		while (temp.size() < H) {
			temp.push_back(0);
		}

		new_arr.push_back(temp);
	}


	//cout << "============AFTER==========\n";
	//display(new_arr);

	return new_arr;
}

// 모든 경우 탐색하는 dfs 함수
void dfs(vector<vector<int>> arr, int count) {
	
	// 최종적으로 남아있는 벽돌 개수 카운트해서 가장 적게 남은 경우 찾아주기
	if (count == N) {
		int blocks = 0;
		for (auto x : arr) {
			for (auto y : x) {
				if (y != 0) blocks++;
			}
		}
		ans = min(ans, blocks);

		return;
	}

	for (int i = 0; i < W; i++) {
		int j;
		for (j = H - 1; j >= 0; j--) {
			if (arr[i][j] != 0) break;
		}
		
		//cout << count <<"\n\n";

		vector<vector<int>> temp = simulate(arr, i, j);
		dfs(temp, count + 1);
	}
}

// 출력용 함수
void display(vector<vector<int>> arr2D) {
	for (auto arr : arr2D) {
		for (auto x : arr) {
			cout << x << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}
