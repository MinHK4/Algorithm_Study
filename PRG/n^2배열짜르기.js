// https://school.programmers.co.kr/learn/courses/30/lessons/87390
// 15 min

function solution(n, left, right) {
  const answer = [];
  
  for(let i=left; i<=right; i++){
      const div = Math.floor(i / n);
      const ret = i % n;
      
      if(ret <= div) answer.push(div+1);
      else answer.push(ret+1);
  }
  
  return answer;
}