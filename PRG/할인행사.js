// https://school.programmers.co.kr/learn/courses/30/lessons/131127
// 15 min

function solution(want, number, discount) {
  const totalNum = number.reduce((a, b) => a + b);

  let ans = 0;
  for (let i = 0; i + totalNum <= discount.length; i++) {
    const part = discount.slice(i, i + totalNum);

    const count = want.map((wnt) => {
      let cnt = 0;
      part.forEach((val) => (cnt += val === wnt ? 1 : 0));

      return cnt;
    });

    ans += count.every((val, idx) => val === number[idx]) ? 1 : 0;
  }

  return ans;
}
