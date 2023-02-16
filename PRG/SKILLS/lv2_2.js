function solution(queue1, queue2) {
  const queue = [...queue1, ...queue2];
  if (queue.reduce((a, b) => a + b) % 2) return -1;

  let sum1 = queue1.reduce((a, b) => a + b);
  let sum2 = queue2.reduce((a, b) => a + b);
  let cnt = 0,
    idx1 = 0,
    idx2 = queue1.length;
  while (sum1 != sum2) {
    if (cnt > queue.length + 1) return -1;

    if (sum1 < sum2) {
      sum2 -= queue[idx2];
      sum1 += queue[idx2];
      idx2 = (idx2 + 1) % queue.length;
    } else if (sum1 > sum2) {
      sum1 -= queue[idx1];
      sum2 += queue[idx1];
      idx1 = (idx1 + 1) % queue.length;
    }
    cnt++;
  }
  return cnt;
}
