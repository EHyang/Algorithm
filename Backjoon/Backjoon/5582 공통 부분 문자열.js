const path = process.platform === 'linux' ? '/dev/stdin' : 'bj-input.txt';

let [first, second] = require('fs')
  .readFileSync(path)
  .toString()
  .trim()
  .split('\n');

const solution = (first, second) => {
  const firL = first.length, secL = second.length;

  const lcs = Array.from(Array(firL + 1), () => Array(secL + 1).fill(0));
  let answer = 0;

  for (let i = 1; i <= firL; i++) {
    for (let j = 1; j <= secL; j++) {
      if (first[i - 1] === second[j - 1]) {
        lcs[i][j] = lcs[i - 1][j - 1] + 1;
        answer = Math.max(answer, lcs[i][j]);
      }
    }
  }

  return answer;
}

const answer = solution(first, second);
console.log(answer);