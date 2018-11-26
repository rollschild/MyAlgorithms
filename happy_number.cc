class Solution {
 public:
  int square_sum(int n) {
    int sum = 0;
    while (n) {
      sum += (n % 10) * (n % 10);
      n /= 10;
    }
    return sum;
  }
  bool isHappy(int n) {
    int less = n;
    int more = n;
    do {
      less = square_sum(less);
      more = square_sum(more);
      more = square_sum(more);
    } while (less != more);
    return less == 1;
  }
};
