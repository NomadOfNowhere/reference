// Secure random seed
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Generate values using distribution
uniform_int_distribution<int> dist(0, N);       // [0, N]
randval = dist(rng);