// https://school.programmers.co.kr/learn/courses/30/lessons/147355

function solution(t, p) {
  const num = Number(p);
  const len = p.length;

  let ans = 0;
  for (let i = 0; i <= t.length - len; i++) {
    const str = t.substr(i, len);

    if (Number(str) <= num) ans++;
  }

  return ans;
}
