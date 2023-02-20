// https://school.programmers.co.kr/learn/courses/30/lessons/12939
function solution(s) {
  return s
    .split(' ')
    .reduce(
      (acc, val) => [Math.min(acc[0], val), Math.max(acc[1], val)],
      [Infinity, -Infinity]
    )
    .join(' ');
}

// Math.min이랑 max 배열에 사용하는 방법!!
function solution(s) {
  const arr = s.split(' ');
  return Math.min(...arr) + ' ' + Math.max(...arr);
}
