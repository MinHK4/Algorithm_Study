// https://school.programmers.co.kr/learn/courses/30/lessons/118667

function solution(queue1, queue2) {
  let answer = 0;

  let sum1 = queue1.reduce((a, b) => a + b);
  let sum2 = queue2.reduce((a, b) => a + b);
  const target = (sum1 + sum2) / 2;

  // 예외 처리 : 총합이 홀수이거나 한 숫자가 너무 큰 경우
  if (
    (sum1 + sum2) % 2 ||
    queue1.some((val) => val > target) ||
    queue2.some((val) => val > target)
  )
    return -1;

  // target이 원소로 있는 경우
  if (queue1.includes(target)) {
    const idx = queue1.indexOf(target);
    if (idx === queue1.length - 1) return idx;
    return (idx + 1) * 2 - 1 + queue2.length;
  }
  if (queue2.includes(target)) {
    const idx = queue2.indexOf(target);
    if (idx === queue2.length - 1) return idx;
    return (idx + 1) * 2 - 1 + queue1.length;
  }

  const newQ = [...queue1, ...queue2];
  let idx1 = 0;
  let idx2 = queue1.length;
  while (sum1 !== target) {
    if (sum1 > sum2) {
      const temp = newQ[idx1];
      sum1 -= temp;
      sum2 += temp;
      idx1 = (idx1 + 1) % (queue1.length + queue2.length);
    } else if (sum1 < sum2) {
      const temp = newQ[idx2];
      sum1 += temp;
      sum2 -= temp;
      idx2 = (idx2 + 1) % (queue1.length + queue2.length);
    }
    answer++;

    // 예외처리 : 이론 검증은 안 되지만 결국 연속합이기 때문에 한 반퀴 이상 돌려도 의미가 없음
    if (answer > queue1.length + queue2.length) return -1;
  }

  return answer;
}
