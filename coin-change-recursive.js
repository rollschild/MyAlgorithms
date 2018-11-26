/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var coinChange = function(coins, amount) {
  // Now let's try recursive version..
  if (amount < 1) return 0;
  if (coins.length === 0) return -1;
  dp = new Array(amount);
  dp.fill(0);

  return check(coins, amount, dp);
};

var check = function(coins, amount, dp) {
  if (amount === 0) return 0;
  if (amount < 0) return -1;
  if (dp[amount - 1] !== 0) return dp[amount - 1];
  let min_value = amount + 1;
  coins.forEach(function(val) {
    let res = check(coins, amount - val, dp);
    if (res >= 0 && res < min_value) {
      min_value = res + 1;
    }
  });
  dp[amount - 1] = min_value > amount ? -1 : min_value;
  return dp[amount - 1];
};
