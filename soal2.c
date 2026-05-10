#include <stdio.h>

int adj_mat[1000][1000];
int state[1000]; // 0: unvisited, 1: visiting, 2: visited
int n, m;

// Fungsi DFS untuk mengecek apakah ada siklus
int has_cycle(int u) {
    state[u] = 1; // Tandai sedang dikunjungi (masuk di recursion stack)
    
    for (int v = 0; v < n; v++) {
        if (adj_mat[u][v] == 1) {
            // Jika menemukan simpul yang juga sedang dikunjungi (back edge), berarti ada siklus
            if (state[v] == 1) {
                return 1; 
            }
            // Jika simpul belum dikunjungi, lanjutkan DFS ke simpul tersebut
            if (state[v] == 0 && has_cycle(v)) {
                return 1;
            }
        }
    }
    
    state[u] = 2; // Tandai sudah selesai dikunjungi
    return 0;
}

int main() {
    // Membaca jumlah misi (N) dan dependensi (M)
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Inisialisasi awal matrix
    for(int i = 0; i < n; i++) {
        state[i] = 0;
        for(int j = 0; j < n; j++) {
            adj_mat[i][j] = 0;
        }
    }

    // Membaca dependensi
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        // a bergantung pada b, jadi logikanya misi b harus selesai sebelum a.
        // Dapat dimodelkan sebagai edge berarah b -> a
        adj_mat[b][a] = 1;
    }

    int cycle_detected = 0;
    
    // Periksa siklus untuk setiap simpul yang belum dikunjungi
    for (int i = 0; i < n; i++) {
        if (state[i] == 0) {
            if (has_cycle(i)) {
                cycle_detected = 1;
                break;
            }
        }
    }

    // Cetak hasil sesuai output format
    if (cycle_detected) {
        printf("TIDAK​ BISA\n");
    } else {
        printf("BISA​\n");
    }
// 
    return 0;
}
