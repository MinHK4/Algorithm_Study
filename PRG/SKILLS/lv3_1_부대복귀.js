// 다익스트라!!

function solution(n, roads, sources, destination) {
  var answer = [];

  const G = Array(n + 1)
    .fill()
    .map(() => []);
  roads.forEach((road) => {
    G[road[0]].push(road[1]);
    G[road[1]].push(road[0]);
  });

  const dp = Array(n + 1).fill(Infinity);
  let q = [destination];
  dp[destination] = 0;
  while (q.length) {
    let set = new Set();

    while (q.length) {
      const cur = q.pop();
      G[cur].forEach((next) => {
        if (dp[next] > dp[cur] + 1) {
          dp[next] = dp[cur] + 1;
          set.add(next);
        }
      });
    }
    q = [...set];
  }

  return sources.map((val) => (dp[val] === Infinity ? -1 : dp[val]));
}
