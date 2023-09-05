// https://school.programmers.co.kr/learn/courses/30/lessons/12913
// 15 min

function solution(land) {
  for (let i = 1; i < land.length; i++) {
    for (let j = 0; j < 4; j++) {
      let max = land[i][j];
      for (let k = 0; k < 4; k++) {
        if (j === k) continue;
        max = Math.max(max, land[i][j] + land[i - 1][k]);
      }
      land[i][j] = max;
    }
  }

  return Math.max(...land.slice(-1)[0]);
}
