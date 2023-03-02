// https://school.programmers.co.kr/learn/courses/30/lessons/12911

function solution(n) {
  const target = numToBin1Cnt(n);
  for (let i = n + 1; ; i++) {
    if (target === numToBin1Cnt(i)) return i;
  }

  function numToBin1Cnt(num) {
    return num
      .toString(2)
      .split('')
      .reduce((acc, val) => (val === '1' ? acc + 1 : acc));
  }
}
