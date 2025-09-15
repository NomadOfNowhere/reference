// If we only need to get the final result, we can increase l and r+1
// to simulate range update and use a prefix sum to get the answer.
diff[l] += k;
diff[r+1] -= k;

// If we have initial values, we need to subtract the previous values:
diff[i] -= values[i - 1];