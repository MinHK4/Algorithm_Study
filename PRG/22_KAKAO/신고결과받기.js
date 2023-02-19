// https://school.programmers.co.kr/learn/courses/30/lessons/92334
// start 1747
// end 1808

function solution(id_list, report, k) {
  const nameMap = new Map();
  id_list.forEach((id, idx) => {
    nameMap.set(id, idx);
  });

  const countList = Array(id_list.length).fill(0);
  const reportList = Array(id_list.length)
    .fill()
    .map(() => []);
  report.forEach((r) => {
    const [a, b] = r.split(' ');
    if (!reportList[nameMap.get(b)].includes(nameMap.get(a))) {
      countList[nameMap.get(b)] += 1;
      reportList[nameMap.get(b)].push(nameMap.get(a));
    }
  });

  const answer = Array(id_list.length).fill(0);
  countList.forEach((val, idx) => {
    if (val >= k) {
      reportList[idx].forEach((val) => answer[val]++);
    }
  });
  return answer;
}
