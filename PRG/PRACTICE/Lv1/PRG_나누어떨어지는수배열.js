// https://school.programmers.co.kr/learn/courses/30/lessons/12910

function solution(arr, divisor) {
  const ans = arr.filter((val) => val % divisor === 0);

  return ans.length ? ans.sort((a, b) => a - b) : [-1];
}
