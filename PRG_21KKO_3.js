// 배열 내에서 더 큰 숫자의 개수를 알기 위해 BNSCH 이용한 lowerBound
function lowerBound(arr, key){    
  let start = 0
  let end = arr.length
  
  while(start < end){
      let mid = Math.floor((start+end)/2)
      if(arr[mid] >= key)
          end = mid
      else
          start = mid + 1
  }
  return start
}

// 문자들의 배열로 주어진 길이의 단어 조합 만들어주기
function getCombi(arr, num){
  const results = []
  if(num === 1)
      return arr.map(el => [el])
  
  arr.forEach((fixed, idx, org) => {
      const rest = org.slice(idx+1)
      const combi = getCombi(rest, num-1)
      const attached = combi.map(el => [fixed, ...el])
      results.push(...attached)
  })
  return results
}

function solution(info, query) {
  var answer = [];
  
  var dataTable = {'' : []}
  for(i of info){
      const keyList = []
      const infoData = i.split(" ")
      
      // 1개 조합부터 4개조합까지 다 만들어주기
      for(let num=1; num<=4; num++){   
          getCombi(infoData.slice(0,-1), num).forEach(el =>{
              keyList.push(el.join(''))
          })
      }
      
      // 모든 단어조합을 key로 배열 만들고 포함되는 것에 value 다 넣어주기
      for(const key of keyList){
          if(!(key in dataTable))
              dataTable[key] = new Array()
          dataTable[key].push(Number(infoData[4]))
      }
      dataTable[''].push(Number(infoData[4]))
  }
  
  // 쿼리마다 해당하는 배열 찾아서 그 안에서 더 큰 값 찾아주기
  for(q of query){
      const condition = q.split(" ")
      const target = [(condition[0] + condition[2] + condition[4] + condition[6]).replace(/-/g, ''), Number(condition[7])]
      
      // 해당 배열 안에서 더 큰 수의 개수 찾기 위해서 lowerBound 활용
      if(target[0] in dataTable){   
          const arr = dataTable[target[0]].sort(function(a, b){return a-b})
          answer.push(arr.length - lowerBound(arr, target[1]))
      }
      else
          answer.push(0)
  }
  return answer;
}
/*
info가 최대 5*10^4 query가 최대 10*5이기 때문에
그대로 돌려버리면 10^9이상 연산하기 때문에 시간초과 발생함

info에서 주어진 조합이 4가지 종류 각각 조합하는 거기 떄문에 4C1 + 4C2 +4C3 + 4C4로 15개정도라서
여기서 모든 조합들로 배열 만들어주고 모든 값 저장해주어야 함

그러고 나서 쿼리에서는 각 쿼리당 해당하는 배열 바로 찾아서 그 안에 있는 숫자들만 비교해서 카운트해주기

----

추가로 lowerBound까지 활용해서 이상의 수 찾아줄 때 효율성 높이기
*/