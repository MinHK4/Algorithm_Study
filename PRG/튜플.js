// https://school.programmers.co.kr/learn/courses/30/lessons/64065
// 11min

function solution(s) {
  const sep = s
    .slice(2, -2)
    .split('},{')
    .map((val) => val.split(','))
    .sort((a, b) => a.length - b.length);

  const ans = [];
  sep.forEach((arr) => {
    arr.forEach((val) => {
      if (!ans.includes(val * 1)) ans.push(val * 1);
    });
  });

  return ans;
}
