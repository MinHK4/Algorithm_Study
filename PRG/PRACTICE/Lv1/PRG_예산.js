// https://school.programmers.co.kr/learn/courses/30/lessons/12982

function solution(d, budget) {
  d.sort((a, b) => a - b);

  return d.reduce(
    (acc, val) => {
      if (acc[0] + val <= budget) return [acc[0] + val, acc[1] + 1];
      return acc;
    },
    [0, 0]
  )[1];
}
