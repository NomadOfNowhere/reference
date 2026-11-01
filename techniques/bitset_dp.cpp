// DP booleana con bitset 
// (subset sum / mochila 0-1 de alcanzabilidad)
// O(n * N / 64)
// N la maxima suma alcanzable (el maximo de una pila)
const int N=1e5;
vector<int> nums;
bitset<N> dp(){
    // Antes era bool dp[pos][cant]
    bitset<N> dp;
    // Equivale a no poner nada
    dp[0]=1;
    // Cada numero se pone o no se pone dentro de la pila
    for(auto it:nums)dp|=dp<<it;
    // dp[s]=1 si la suma s se puede formar
    return dp;
}
