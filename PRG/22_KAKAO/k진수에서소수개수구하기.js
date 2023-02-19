// https://school.programmers.co.kr/learn/courses/30/lessons/92335
// start 1808
// end 1819

function solution(n, k) {
  let str = '';
  while (n) {
    str += (n % k).toString();
    n = Math.floor(n / k);
  }
  const newNum = str.split('').reverse().join('');
  const digitList = newNum.split('0').map((val) => Number(val));

  return digitList.reduce((acc, val) => {
    if (checkPrime(val)) return acc + 1;
    return acc;
  }, 0);

  function checkPrime(num) {
    if (num <= 1) return false;

    for (let i = 2; i * i <= num; i++) {
      if (num % i === 0) return false;
    }
    return true;
  }
}
