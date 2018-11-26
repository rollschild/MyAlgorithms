/*
 * Couring sort..
 * O(n + k)
 * k is the range
 */
let range = 255;

let coutingSort = function(arr) {
  let count = new Array(range);
  count.fill(0);
  let output = new Array(arr.length);
  output.fill(0);

  arr.forEach(function(val) {
    ++count[val];
  });

  for (let j = 1; j < range; ++j) {
    count[j] += count[j - 1];
  }

  arr.forEach(function(val) {
    output[count[val] - 1] = val;
    --count[val];
  })

  return output;
};

console.log(coutingSort([12, 1, 5, 4, 4, 0, 3, 9, 3, 4]));
