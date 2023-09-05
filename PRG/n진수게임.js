// https://school.programmers.co.kr/learn/courses/30/lessons/17687
// 15min

function solution(n, t, m, p) {
  let fullStr = '';
  for (let i = 0; i <= t * m; i++) {
    fullStr += converter(i, n);
  }

  let ans = '';
  for (let i = 0; i < fullStr.length && ans.length < t; i++) {
    if (i % m === p - 1) ans += fullStr[i];
  }
  return ans;

  function converter(num, by) {
    if (num === 0) return '0';

    const alpha = ['A', 'B', 'C', 'D', 'E', 'F'];

    let str = [];
    while (num) {
      const left = num % by;
      str.push(left >= 10 ? alpha[left - 10] : left);
      num = Math.floor(num / by);
    }

    return str.reverse().join('');
  }
}
