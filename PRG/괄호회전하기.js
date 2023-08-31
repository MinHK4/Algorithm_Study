// https://school.programmers.co.kr/learn/courses/30/lessons/76502#

function solution(s) {
  if (s.size % 2) return 0;

  let ans = 0;
  for (let i = 0; i < s.length; i++) {
    if (isRight(s)) ans++;

    s = s.substr(1) + s[0];
  }

  return ans;

  function isRight(str) {
    const open = '({[';
    const close = ')}]';

    const stck = [];
    for (let s of str) {
      if (open.includes(s)) stck.push(s);
      else {
        if (stck.length < 1) return false;

        const last = stck.pop();
        if (open.indexOf(last) !== close.indexOf(s)) return false;
      }
    }

    if (stck.length) return false;
    return true;
  }
}
