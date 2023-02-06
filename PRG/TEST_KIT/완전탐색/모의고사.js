// https://school.programmers.co.kr/learn/courses/30/lessons/42840?language=javascript

function solution(answers) {
  const ex2 = [2, 1, 2, 3, 2, 4, 2, 5];
  const ex3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];

  const count1 = answers.reduce(
    (acc, val, idx) => ((idx % 5) + 1 === val ? acc + 1 : acc),
    0
  );
  const count2 = answers.reduce(
    (acc, val, idx) => (ex2[idx % 8] === val ? acc + 1 : acc),
    0
  );
  const count3 = answers.reduce(
    (acc, val, idx) => (ex3[idx % 10] === val ? acc + 1 : acc),
    0
  );

  const maxCnt = Math.max(count1, count2, count3);

  return [count1, count2, count3]
    .map((val, idx) => (val === maxCnt ? idx + 1 : -1))
    .filter((val) => val > 0);
}
