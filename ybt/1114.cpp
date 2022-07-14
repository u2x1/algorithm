#include <cstdio>
#include <climits>

int main() {
  int n;
  scanf("%d", &n);
  double max = INT_MIN, min = INT_MAX;
  int max_idx = -1, min_idx = -1;
  double arr[n], cache;
  for (int i = 0; i < n && scanf("%lf", &cache); ++i) {
    arr[i] = cache;
    if (max < cache) { max_idx = i; max = cache; }
    else if (min > cache) { min_idx = i; min = cache; }
  }

  double avg, sum = 0, max_error = -1;
  for (int i = 0; i < n; ++i) {
    if (i == max_idx || i == min_idx) { continue; }
    sum += arr[i];
  }

  avg = sum / (n-2);
  for (int i = 0; i < n; ++i) {
    if (i == max_idx || i == min_idx) { continue; }
    double error = arr[i] - avg;
    if (error < 0) { error = -error; }
    if (error > max_error) { max_error = error; }
  }

  printf("%.2f %.2f"
      , avg
      , max_error);

  return 0;
}
