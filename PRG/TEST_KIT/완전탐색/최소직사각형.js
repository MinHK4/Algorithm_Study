// https://school.programmers.co.kr/learn/courses/30/lessons/86491

function solution(sizes) {
  let answer = [0, 0];

  for (let i = 0; i < sizes.length; i++) {
    if (!checkFit(answer[0], answer[1], sizes[i][0], sizes[i][1])) {
      answer[0] = Math.max(answer[0], Math.max(sizes[i][0], sizes[i][1]));
      answer[1] = Math.max(answer[1], Math.min(sizes[i][0], sizes[i][1]));
    }
  }

  return answer[0] * answer[1];
}

function checkFit(a, b, c, d) {
  if ((a >= c && b >= d) || (a >= d && b >= c)) return true;
  return false;
}

/*
reduce를 활용해 더 간단하게 표현 가능
직사각형이라서 가로,세로가 고정이 아니라 큰 값, 작은 값 순으로 가로, 세로로 본다고 풀면 됨

function solution(sizes) {
    const [hor, ver] = sizes.reduce(([h, v], [a, b]) => [Math.max(h, Math.max(a, b)), Math.max(v, Math.min(a, b))], [0, 0])
    return hor * ver;
}
*/
