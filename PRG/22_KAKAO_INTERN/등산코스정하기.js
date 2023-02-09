// https://school.programmers.co.kr/learn/courses/30/lessons/118669?language=javascript

function solution(n, paths, gates, summits) {
  // 정점 간선 그래프 만들기
  // 산봉우리에서 나가는 간선 제거
  const G = Array(n + 1)
    .fill()
    .map((_) => []);
  paths.forEach(([a, b, w]) => {
    G[a].push([w, b]);
    G[b].push([w, a]);
  });
  summits.forEach((summit) => (G[summit] = []));

  // dp[i] : i정점까지 오는데 걸리는 최대 intensity
  // 시작 위치 마이너스 값으로 초기화
  const dp = Array(n + 1).fill(Infinity);
  gates.forEach((v) => (dp[v] = -1));

  // 중첩 bfs 및 다익스트라 개념 활용
  // 현재 q에 담긴 애들로부터 갈 수 있는 정점 중 새롭게 intensity 업데이트 되는 정점을 기준으로 다시 돌려주기

  // gate -> summits 방향으로 정점의 intensity 정보 업데이트!!
  let q = gates;

  // 단계 반복
  while (q.length) {
    let set = new Set();

    // 현재 단계에서 갈 수 있는 정점 업데이트
    while (q.length) {
      const cur = q.pop();

      G[cur].forEach(([w, next]) => {
        const maxV = Math.max(dp[cur], w);
        if (dp[next] > maxV) {
          dp[next] = maxV;
          set.add(next);
        }
      });
    }

    q = [...set];
  }

  // 정렬해서 배열의 첫번 째 값 가져오기
  const res = summits
    .map((v) => [v, dp[v]])
    .sort((a, b) => {
      if (a[1] === b[1]) {
        return a[0] - b[0];
      }
      return a[1] - b[1];
    });

  return res[0];
}
