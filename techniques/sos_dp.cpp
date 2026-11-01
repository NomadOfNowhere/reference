// SOS DP (Sum Over Subsets). O(N * 2^N)
// N el numero maximo de bits y M = 2^N - 1 el maximo numero
const ll N=20,M=(1<<N)-1;
ll reps[M+1];
// Se tiene que mirar como un trie para entender las secuencias o cambiarlas
void dp(){
    for (int i=0; i<N; i++) {
        for (int x=0; x<=M; x++) {
            if (x & (1 << i)) { reps[x] += reps[x ^ (1 << i)]; }
        }
    }
    // La respuesta esta en reps[x]
}
