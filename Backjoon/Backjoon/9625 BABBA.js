const path = process.platform === 'linux' ? '/dev/stdin' : 'bj-input.txt';

let [n, ...inputs] = require('fs')
  .readFileSync(path)
  .toString()
  .trim()
  .split('\n');

const N = +n;

const solution = (N) => {
  const A = [0], B = [1];

  for (let i = 1; i < N; i++) {
    A[i] = B[i - 1];
    B[i] = A[i - 1] + B[i - 1];
  }

  return `${A[N - 1]} ${B[N - 1]}`;
}

const answer = solution(N);
console.log(answer)