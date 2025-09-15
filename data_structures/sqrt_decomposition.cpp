struct SQ{
    int n, b;
    vector<int> values, blocks;
    SQ(int _n) : n(_n), values(_n) {
        b = (int)sqrt(n) + 1;
        blocks = vector<int> (b);
    }
    // Basic update / query
    void operation(int l, int r, int k) {
        int bl = l/b, br = r/b;
        // operation lies in same block
        if(bl == br) {
            for(int i=l; i<=r; i++) {
                blocks[bl] -= values[i];
                values[i] += k;
                blocks[bl] += values[i];
            }
        }
        // operation on different blocks
        else {
            for(int i=l; i<(bl+1)*b; i++) {
                blocks[bl] -= values[i];
                values[i] += k;
                blocks[bl] += values[i];
            }
            for(int i=br*b; i<=r; i++) {
                blocks[br] -= values[i];
                values[i] += k;
                blocks[br] += values[i];
            }
            for(int i=(bl+1)*b; i<br; i++) {
                blocks[i] += k * b;
            }
        }
    }
};