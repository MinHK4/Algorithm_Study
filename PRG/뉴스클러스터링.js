// https://school.programmers.co.kr/learn/courses/30/lessons/17677
// 40 min

function solution(str1, str2) {
  str1 = str1.toLowerCase();
  str2 = str2.toLowerCase();

  const twoWord1 = makeTwoWordList(str1).sort();
  const twoWord2 = makeTwoWordList(str2).sort();

  return Math.floor(jackard(twoWord1, twoWord2) * 65536);

  // 자카드 유사도
  function jackard(arr1, arr2) {
    if (arr1.length === 0 && arr2.length === 0) return 1;

    const cntMap1 = new Map();
    const cntMap2 = new Map();

    arr1.forEach((val) => {
      if (!cntMap1.has(val)) {
        cntMap1.set(val, 0);
      }
      cntMap1.set(val, cntMap1.get(val) + 1);
    });
    arr2.forEach((val) => {
      if (!cntMap2.has(val)) {
        cntMap2.set(val, 0);
      }
      cntMap2.set(val, cntMap2.get(val) + 1);
    });

    const setList1 = [...new Set(arr1)];
    const setList2 = [...new Set(arr2)];
    const unionList = [...new Set([...arr1, ...arr2])];

    // 교집합 수 구하기
    let interCnt = 0;
    setList1.forEach((val) => {
      if (setList2.includes(val)) {
        interCnt += Math.min(cntMap1.get(val), cntMap2.get(val));
      }
    });

    // 합집합 수 구하기
    let unionCnt = 0;
    unionList.forEach((val) => {
      unionCnt += Math.max(cntMap1.get(val) || 0, cntMap2.get(val) || 0);
    });

    return interCnt / unionCnt;
  }

  function makeTwoWordList(str) {
    const ret = [];
    const regEx = /^[a-z]+$/;

    for (let i = 0; i + 1 < str.length; i++) {
      let temp = str.substr(i, 2);
      if (regEx.test(temp)) ret.push(temp);
    }

    return ret;
  }
}
