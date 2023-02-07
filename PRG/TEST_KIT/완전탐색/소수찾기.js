// https://school.programmers.co.kr/learn/courses/30/lessons/42839

function solution(numbers) {
  const primeSet = new Set();

  for (let i = 1; i <= numbers.length; i++)
    makeAllCombiByLimit(i, numbers.split(''), [], 0);

  // 특정 길이만큼의 조합 찾아주기
  function makeAllCombiByLimit(limit, numbers, combi, curIdx) {
    if (combi.length === limit) {
      console.log(combi);
      checkAllPermutePrime(combi, [], []);
      return;
    }

    for (let i = curIdx; i < numbers.length; i++) {
      makeAllCombiByLimit(limit, numbers, [...combi, numbers[i]], i + 1);
      makeAllCombiByLimit(limit, numbers, [...combi], i + 1);
    }
  }

  // 해당 길이의 모든 순열 만들어서 소수인지 판별하기
  function checkAllPermutePrime(combi, visited, curNum) {
    if (combi.length === curNum.length) {
      const temp = Number(curNum.join(''));
      if (checkPrime(temp)) {
        primeSet.add(temp);
      }
      return;
    }

    for (let i = 0; i < combi.length; i++) {
      if (!visited.includes(i)) {
        checkAllPermutePrime(combi, [...visited, i], [...curNum, combi[i]]);
      }
    }
  }

  // 소수 판정해주기
  function checkPrime(num) {
    if (num <= 1) return false;

    let flag = true;

    for (let i = 2; i * i <= num; i++) {
      if (num % i === 0) {
        flag = false;
        break;
      }
    }

    return flag;
  }

  return primeSet.size;
}
