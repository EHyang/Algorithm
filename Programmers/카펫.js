/**
 * 문제 - https://school.programmers.co.kr/learn/courses/30/lessons/42842
 * 
 * 매우 쉬운 완전탐색문제.
 * 
 * x,y를 입력받아서 총 격자의 수를 카운팅 한뒤
 * Yellow의 갯수를 비교하는 방식으로 진행하였다.
 * 
 * 문제의 조건에 맞게 x >= y 인 값을 찾아 진행하였다.
 * 
테스트 1 〉	통과 (0.08ms, 33.5MB)
테스트 2 〉	통과 (0.17ms, 33.5MB)
테스트 3 〉	통과 (6.46ms, 36.7MB)
테스트 4 〉	통과 (0.29ms, 33.5MB)
테스트 5 〉	통과 (0.40ms, 33.4MB)
테스트 6 〉	통과 (3.63ms, 36.6MB)
테스트 7 〉	통과 (7.17ms, 36.4MB)
테스트 8 〉	통과 (6.17ms, 36.4MB)
테스트 9 〉	통과 (7.51ms, 36.6MB)
테스트 10 〉	통과 (7.72ms, 36.6MB)
테스트 11 〉	통과 (0.08ms, 33.5MB)
테스트 12 〉	통과 (0.08ms, 33.4MB)
테스트 13 〉	통과 (0.16ms, 33.6MB)
 */

const divisor = (n) => {
  const res = [];
  let div = 1;

  while (div <= n) {
    if (n % div === 0) {
      res.push([div, n / div]);
    }
    div++;
  }

  return [... new Set(res)];
}

const solution = (brown, yellow) => {
  const answer = [];
  const area = brown + yellow;

  const pair = divisor(area);

  while (pair.length > 0) {
    const [x, y] = pair.shift();

    if (x <= 2 || y <= 2) continue;

    const yellowArea = (x - 2) * (y - 2);

    if (yellowArea === yellow && x >= y) {
      answer.push(x, y);
      break;
    }
  }

  return answer;
}



console.log(solution(24, 24))
