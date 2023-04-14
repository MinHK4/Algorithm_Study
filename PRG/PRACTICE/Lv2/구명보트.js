// https://school.programmers.co.kr/learn/courses/30/lessons/42885
// JS에서 숫자 정렬 할 때는 꼭 a-b 식 넣어줘야 함!!!!

function solution(people, limit) {
  people.sort((a, b) => a - b);

  let i = 0,
    j = people.length - 1;
  for (; i < j; j--) {
    if (people[i] + people[j] <= limit) i++;
  }

  return people.length - i;
}
