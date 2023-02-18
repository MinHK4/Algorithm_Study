// https://school.programmers.co.kr/learn/courses/30/lessons/76501

function solution(absolutes, signs) {
  return absolutes.reduce(
    (acc, val, idx) => (signs[idx] ? acc + val : acc - val),
    0
  );
}
