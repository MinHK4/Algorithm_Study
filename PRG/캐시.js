// https://school.programmers.co.kr/learn/courses/30/lessons/17680
// 10min

function solution(cacheSize, cities) {
  let cache = [];
  let ans = 0;
  cities.forEach((city) => {
    city = city.toLowerCase();

    // cache hit
    if (cache.includes(city)) {
      ans++;
      cache = cache.filter((val) => val !== city);
      cache.push(city);
    }

    // cache miss
    else {
      ans += 5;
      cache.push(city);
      if (cache.length > cacheSize) {
        cache = cache.slice(1);
      }
    }
  });

  return ans;
}
