// Nama         : Isnaya Zalfa Kamila 
// NIM          : 13224028 
// Deskripsi    : Program untuk menghitung minimum steps dalam menemukan takaran yang diinginkan
// Modul        : 03 - Foundation of Algorithm

#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h> 


void minumumsteps (int ukurangelas1, int ukurangelas2, int takaran){ //[1]
// kondisi jika takaran tidak memungkinkan
    if (takaran > (ukurangelas1 > ukurangelas2 ? ukurangelas1 : ukurangelas2)){
        printf("-1"); 
        return;
    }
    else {
        int antrian[1000][3]; // kapasitas maksimal untuk menampung jumlah steps 
        int barisanawal = 0;
        int barisanakhir = 0;

        // fungsi untuk tracking nodes yang udah dikunjungin 
        bool visited [ukurangelas1+1][ukurangelas2+1]; // deklarasi array untuk tracking 
        for (int i = 0; i<= ukurangelas1; i++){
            for(int j =0; j <= ukurangelas2; j++){
                visited [i][j] = false; 
            }
        }

        // inisialisasi awal untuk kolom 
        antrian[barisanakhir][0] = 0; 
        antrian[barisanakhir][1] = 0;
        antrian[barisanakhir][2] = 0;
        barisanakhir++;

        visited [0][0] = true; // jika kolom maupun baris 0

        while (barisanawal != barisanakhir){
            int gelas1 = antrian[barisanawal][0];
            int gelas2 = antrian[barisanawal][1];
            int steps = antrian[barisanawal][2];
            barisanawal++; 

            // jika gelas 1 atau gelas 2 sama dengan takaran, maka program berhenti 
            if (gelas1 == takaran || gelas2 == takaran){
                printf("%d", steps);
                return;
            }
            // isi gelas 1 hingga max 
            if (!visited[ukurangelas1][gelas2]) {
                visited [ukurangelas1][gelas2] = true;
                antrian[barisanakhir][0] = ukurangelas1;
                antrian[barisanakhir][1] = gelas2;
                antrian[barisanakhir][2] = steps + 1;
                barisanakhir++;
            }
            // isi gelas 2 hingga max
            if (!visited[gelas1][ukurangelas2]) {
                visited[gelas1][ukurangelas2] = true;
                antrian[barisanakhir][0] = gelas1;
                antrian[barisanakhir][1] = ukurangelas2;
                antrian[barisanakhir][2] = steps + 1;
                barisanakhir++;
            }
            // gelas 1 dikosongin 
            if(!visited [0][gelas2]){
                visited [0][gelas2] = true;
                antrian[barisanakhir][0] =0;
                antrian[barisanakhir][1] = gelas2;
                antrian [barisanakhir][2] = steps +1; 
                barisanakhir ++; 
            }
            // gelas 2 dikosongin
            if (!visited [gelas1][0]){
                visited[gelas1][0] = true;
                antrian[barisanakhir][0] = gelas1;
                antrian[barisanakhir][1] = 0;
                antrian[barisanakhir][2] = steps +1; 
                barisanakhir++;
            }

            // tuang gelas 1 ke gelas 2
            int tuang1 = gelas1 < (ukurangelas2 - gelas2)? gelas1 : (ukurangelas2 - gelas2);

            if(!visited [gelas1 - tuang1][gelas2 + tuang1]){
                visited [gelas1 - tuang1][gelas2+tuang1] =true;

                antrian[barisanakhir][0] = gelas1 - tuang1;
                antrian[barisanakhir][1] = gelas2 + tuang1;
                antrian[barisanakhir][2] = steps+1;
                barisanakhir++;
            }

            // tuang gelas 2 ke gelas 1
            int tuang2 = gelas2 < (ukurangelas1 - gelas1) ? gelas2 : (ukurangelas1 - gelas1);

            if(!visited[gelas1 + tuang2][gelas2 - tuang2]){
                visited [gelas1 + tuang2][gelas2 - tuang2] = true; 

                antrian[barisanakhir][0] = gelas1 + tuang2;
                antrian[barisanakhir][1] = gelas2 -  tuang2;
                antrian[barisanakhir][2] = steps+1;
                barisanakhir++;
            }
        }

        // antrian habis dan takaran tidak ditemukan
        printf("-1");
    }
}

int main () {
    int ukurangelas1, ukurangelas2, takaran;
    scanf("%d %d %d", &ukurangelas1, &ukurangelas2, &takaran);
    minumumsteps(ukurangelas1, ukurangelas2, takaran);
    return 0; 
}

// acuan sumber dalam pembuatan kode : 
// https://www.geeksforgeeks.org/dsa/two-water-jug-puzzle/
// https://www.geeksforgeeks.org/dsa/breadth-first-search-or-bfs-for-a-graph/
