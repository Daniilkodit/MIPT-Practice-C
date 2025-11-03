void matrix_product(unsigned (*A)[N], unsigned (*B)[N], unsigned (*C)[N], unsigned m) {
    unsigned temp[N][N] = {0};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                temp[i][j] = (temp[i][j] + (A[i][k] % m) * (B[k][j] % m)) % m;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = temp[i][j];
        }
    }
}

void powNxN(unsigned (*A)[N], unsigned k, unsigned m) {
    unsigned B[N][N];
    for (int i = 0; i < N; i++) {
        result[i][i] = 1;
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = A[i][j] % m;
        }
    }
    
    while (k > 0) {
        if (k % 2 == 1) {
            matrix_product(result, B, result, m);
        }
        matrix_product(B, B, B, m);
        k /= 2;
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = result[i][j];
        }
    }
}
