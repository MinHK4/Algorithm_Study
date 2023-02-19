// https://school.programmers.co.kr/learn/courses/30/lessons/92341
// start 1819
// end 1847

function solution(fees, records) {
  const recordMap = {};
  records.forEach((record) => {
    const [time, car, info] = record.split(' ');
    if (!recordMap.hasOwnProperty(car)) recordMap[car] = [];
    recordMap[car].push(time);
  });

  const answer = [];
  for (car in recordMap) {
    if (recordMap[car].length % 2) recordMap[car].push('23:59');
    const accTime = recordMap[car].reduce((acc, val, idx, arr) => {
      if (idx % 2) return acc + getTimeDiff(val, arr[idx - 1]);
      return acc;
    }, 0);
    answer.push([car, timeToFee(accTime)]);
  }

  return answer.sort((a, b) => a[0] - b[0]).map((val) => val[1]);

  function getTimeDiff(end, start) {
    return strToTime(end) - strToTime(start);
  }

  function strToTime(str) {
    return str
      .split(':')
      .reduce((acc, val, idx) => acc + Number(val) * (idx === 0 ? 60 : 1), 0);
  }

  function timeToFee(time) {
    if (time <= fees[0]) return fees[1];
    return fees[1] + Math.ceil((time - fees[0]) / fees[2]) * fees[3];
  }
}
