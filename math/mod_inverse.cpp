tuple<int, int, int> extendedGCD(int mod, int a) {
	if (!a) return {mod, 1, 0};
	auto[r, x, y] = extendedGCD(a, mod % a);
	return {r, y, x - mod / a * y};
}
int modInverse(int mod, int a) {
    auto[r, x, y] = extendedGCD(mod, a);
    if(r != 1) {
        return -1;
    }
    return ((y < 0) ? y + mod : y);
}