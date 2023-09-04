// https://school.programmers.co.kr/learn/courses/30/lessons/12949
// 13 min

function solution(arr1, arr2) {
  const r1 = arr1.length;
  const c1 = arr1[0].length;
  const r2 = arr2.length;
  const c2 = arr2[0].length;

  const ans = Array.from(Array(r1), () => new Array(c2));
  for (let i = 0; i < r1; i++) {
    for (let j = 0; j < c2; j++) {
      let temp = 0;
      for (let k = 0; k < c1; k++) {
        temp += arr1[i][k] * arr2[k][j];
      }
      ans[i][j] = temp;
    }
  }

  return ans;
}
