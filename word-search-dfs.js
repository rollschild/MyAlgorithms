/*
 * Word search
 * DFS method..
 */
let exist = function(board, word) {
  if (board.length === 0) return false;
  if (word.length === 0) return false;

  let size = word.length;
  let rowUpper = board.length;
  let colUpper = board[0].length;

  for (let i = 0; i < rowUpper; ++i) {
    for (let j = 0; j < colUpper; ++j) {
      if (dfs(board, i, j, rowUpper, colUpper, word, 0, size)) return true;
    }
  }
  return false;
};

let dfs = function(board, row, col, rowUpper, colUpper, word, pos, size) {
  if (pos == size) return true;
  if (row >= rowUpper || col >= colUpper || row < 0 || col < 0) return false;
  let c = word[pos];
  if (board[row][col] !== c) return false;

  board[row][col] = '*';

  let check =
    dfs(board, row + 1, col, rowUpper, colUpper, word, pos + 1, size) ||
    dfs(board, row, col + 1, rowUpper, colUpper, word, pos + 1, size) ||
    dfs(board, row - 1, col, rowUpper, colUpper, word, pos + 1, size) ||
    dfs(board, row, col - 1, rowUpper, colUpper, word, pos + 1, size);

  board[row][col] = c;
  return check;
};

module.exports = exist;
