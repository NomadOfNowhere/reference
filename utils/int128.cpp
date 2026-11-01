// __int128 llega a ~1.7e38. No se puede usar con cin/cout ni con literales > ll
// Ojo: getchar/putchar no mezclan bien con cin/cout si se usa sync_with_stdio(false)
__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
// Para cout: convertir a string
string to_str(__int128 x) {
    if (x == 0) return "0";
    bool neg = x < 0;
    string s;
    while (x) { s += char('0' + (neg ? -(x % 10) : x % 10)); x /= 10; }
    if (neg) s += '-';
    reverse(s.begin(), s.end());
    return s;
}
bool cmp(__int128 x, __int128 y) { return x > y; }
// Multiplicar dos ll sin overflow: (__int128)a * b % mod
