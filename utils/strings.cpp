// string -> numero (lanzan excepcion si no empieza con numero)
int a = stoi("123");          // stoi("ff", nullptr, 16) en base 16
ll b = stoll("123456789012");
double c = stod("3.14");
// numero -> string
string s = to_string(42);     // to_string(3.5) da "3.500000"
// Separar por un delimitador
vector<string> split(const string& s, char d = ' ') {
    vector<string> res;
    string tok;
    stringstream ss(s);
    while (getline(ss, tok, d)) res.push_back(tok);  // "a,,b" -> {"a","","b"}
    return res;
}
// Version ll: separa y convierte cada token
vector<ll> splitll(const string& s, char d = ' ') {
    vector<ll> res;
    for (auto& t : split(s, d)) if (!t.empty()) res.push_back(stoll(t));
    return res;
}
// Leer una linea completa despues de cin >> x: cin.ignore() o cin >> ws
// getline(cin >> ws, linea);
