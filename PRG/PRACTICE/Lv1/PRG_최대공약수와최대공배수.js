// https://school.programmers.co.kr/learn/courses/30/lessons/12940

function solution(n, m) {
  const gcdVal = gcd(n, m);
  return [gcdVal, (n * m) / gcdVal];

  function gcd(a, b) {
    if (b === 0) return a;
    return gcd(b, a % b);
  }
}
