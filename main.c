#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int score = 0;
int level = 1;

void tampilanAwal();
void tampilkanMenu();
void lanjutkanPermainan();
void keluarPermainan();
void restartPermainan();
void benar();
void salah();
void gameover();
void pertanyaan1();
void pertanyaan2();
void pertanyaan3();
void pertanyaan4();
void pertanyaan5();
void pertanyaan6();
void pertanyaan7();

int main (int banyakArgumen, char *argumen[]) {
    tampilanAwal();

    if (banyakArgumen != 3) {
        printf("Harus Terdapat 3 ARGUMEN Saat Menjalankan Program!\n");
        printf("Cara Penggunaan : ./main Username Password!\n");
        return 1;
    }

    FILE *fpw = fopen("database/login.bin","wb");
    if (fpw == NULL) {
        printf("GAGAL Membuka File!");
        return EXIT_FAILURE;
    }

    char username[50], password[50];

    printf("Masukkan Username :");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';
    
    printf("Masukkan Password :");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    strcat(username, "@");
    strcat(username, password);

    fwrite(username, sizeof(char), sizeof(username)/sizeof(char), fpw);

    fclose(fpw);

    FILE *fpr = fopen("database/login.bin", "rb");

    if (fpr == NULL) {
        printf("GAGAL Membuka File!");
        return EXIT_FAILURE;
    }

    fread(username, sizeof(char), sizeof(username)/sizeof(char), fpr);

    fclose(fpr);
    char *string[3];
    char user[50], pass[50];
    int ctrl = 0;

    string[0] = strtok(username, "@");
    while(string[ctrl++] != NULL) {
        string[ctrl] = strtok(NULL, "@");
    }

    strcpy(user, string[0]);
    strcpy(pass, string[1]);

    printf("=============================================\n");
    printf("=         Registrasi Anda Berhasil          =\n");
    printf("=============================================\n");
    printf("=  Silahkan Login untuk Memulai Permainan!  =\n");
    printf("=============================================\n");
    printf("=       Tekan ENTER untuk Melanjutkan       =\n");
    printf("=============================================");
    getchar();

    char userLog[20], passLog[20];
    printf("Masukkan Username :");
    fgets(userLog, sizeof(userLog), stdin);

    printf("Masukkan Password :");
    fgets(passLog, sizeof(passLog), stdin);

    char userLogin[10], passLogin[10];
    strcpy(userLogin, argumen[1]);
    strcpy(passLogin, argumen[2]);

    if((strcmp(userLogin, user)) == 0 && (strcmp(passLogin, pass) == 0)) {
        printf("\n\n=============================================\n");    
        printf("=        SELAMAT ANDA BERHASIL LOGIN!       =\n");
        printf("=============================================\n");
        printf("=  Tekan ENTER Untuk Melanjutkan Permainan  =\n");
        printf("=============================================\n");
        getchar();
        tampilkanMenu();
    } else {
        printf("=============================================\n");    
        printf("=             ANDA GAGAL LOGIN!             =\n");
        printf("=============================================\n");
    }

    return 0;
}

void tampilanAwal() {
    printf("============================================\n");
    printf("=                                          =\n");
    printf("=             SELAMAT DATANG               =\n");
    printf("=                                          =\n");
    printf("============================================\n");
    printf("=      WHO WANTS TO BE A MILLIONAIRE       =\n");
    printf("============================================\n");
    printf("=                                          =\n");
    printf("= Tekan ENTER Untuk Melanjutkan Registrasi =\n");
    printf("=                                          =\n");
    printf("============================================");
    getchar();
}

void tampilkanMenu() {
    printf("=============================================\n");
    printf("=              🎮 MENU UTAMA 🎮            =\n");
    printf("=============================================\n");
    printf("=  1️⃣  Lanjutkan Permainan                  =\n");
    printf("=  2️⃣  Keluar dari Permainan                =\n");
    printf("=  3️⃣  Restart Permainan                    =\n");
    printf("=============================================\n");
    printf("🌟 SKOR ANDA Saat Ini: %d\n", score);
    printf("=============================================\n");
    printf("👉 Pilih Opsi Anda (1/2/3): ");
    int pilihan;
    scanf("%d", &pilihan);
    getchar(); 
        switch (pilihan) {
            case 1:
                lanjutkanPermainan();
                break;
            case 2:
                keluarPermainan();
                break;
            case 3:
                restartPermainan();
                break;
            default:
                printf("❌ Pilihan Tidak Valid. Silakan Coba Lagi!\n");
        }

}

void lanjutkanPermainan() {
    printf("\n=============================================\n");
    printf("=       Anda Memilih untuk Melanjutkan!     =\n");
    printf("=============================================\n");
    switch (level) {
        case 1:
            pertanyaan1();
            break;
        case 2:
            pertanyaan2();
            break;
        case 3:
            pertanyaan3();
            break;
        case 4:
            pertanyaan4();
            break;
        case 5:
            pertanyaan5();
            break;
        case 6:
            pertanyaan6();
            break;
        case 7:
            pertanyaan7();
            break;
        default:
            printf("âŒ Pertanyaan untuk Level %d BELUM TERSEDIA!\n", level);
    }
}
    
void keluarPermainan() {
    printf("\n=============================================\n");
    printf("=       Terima Kasih Telah Bermain!         =\n");
    printf("=============================================\n");
    printf("ðŸ‘‹ Sampai Jumpa Lagi!\n");
}

void restartPermainan() {
    printf("\n=============================================\n");
    printf("=       Permainan Telah di-Restart!         =\n");
    printf("=============================================\n");
    score = 0; 
    level = 1;
    printf("ðŸŒŸ Skor Anda Sekarang: %d\n", score);
    getchar();
    pertanyaan1();
}

void benar () {
    printf("============================================\n");
    printf("=         Selamat, Jawaban Anda Benar      =\n");
    printf("============================================\n");
    score += 100;
    printf("🌟 Skor Anda Sekarang: %d", score);
    getchar();
}

void salah() {
    printf("============================================\n");
    printf("=         Waduh, Jawaban Anda SALAH        =\n");
    printf("============================================\n");
    printf("🌟 Skor Total Anda : %d\n", score);
    printf("============================================\n\n");
}

void gameover() {
    printf("============================================\n");
    printf("=                 GAME OVER                =\n");
    printf("============================================\n");
    printf("=        Terima Kasih Telah Bermain!       =\n");
    printf("============================================\n");
}

void pertanyaan1() {
    printf("1. Apa Warna Lidah Jerapah?\n");
    printf("a. PINK\tb. BIRU TUA\nc. HIJAU\td. KUNING\n");
    printf("Masukkan Jawaban Anda: ");
    char answer;
    scanf(" %c", &answer);
    if (answer == 'b' || answer == 'B') {
        level++;
        benar();
        getchar();
        tampilkanMenu();
    } else {
        salah();
        getchar();
        gameover();
    }
}

void pertanyaan2() {
    printf("2. Negara Mana yang Tidak Memiliki Ular Sama Sekali?\n");
    printf("a. MEKSIKO\tb.  ISLANDIA\nc. BRAZIL\td. KANADA\n");
    printf("Masukkan Jawaban Anda: ");
    char answer;
    scanf(" %c", &answer);
    getchar(); 
    if (answer == 'b' || answer == 'B') {
        level++;
        benar();
        getchar();
        tampilkanMenu();
    } else {
        salah();
        getchar();
        gameover();
    }
}

 void pertanyaan3() {
    printf("3. Di Negara Manakah, Sapi Dianggap Sebagai Hewan Suci?\n");
    printf("a. JEPANG\tb. AUSTRALIA\nc. INDONESIA\td. INDIA\n");
    printf("Masukkan Jawaban Anda: ");
    char answer;
    scanf(" %c", &answer);
    getchar(); 
    if (answer == 'd' || answer == 'D') {
        level++;
        benar();
        getchar();
        tampilkanMenu();
    } else {
        salah();
        getchar();
        gameover();
    }
}

 void pertanyaan4() {
    printf("4. Hewan Apa yang Dikenal Sebagai Predator Terbesar di Lautan?\n");
    printf("a. PAUS PEMBUNUH\tb.  HIU PUTIH BESAR\nc. UBUR-UBUR RAKSASA\td. ANEMON LAUT\n");
    printf("Masukkan Jawaban Anda: ");
    char answer;
    scanf(" %c", &answer);
    getchar(); 
    if (answer == 'a' || answer == 'A') {
        level++;
        benar();
        getchar();
        tampilkanMenu();
    } else {
        salah();
        getchar();
        gameover();
    }
}

void pertanyaan5() {
    printf("5. Hewan Apa yang Menghasilkan Tinta Sebagai Mekanisme Pertahanan?\n");
    printf("a. NYAMUK\tb. AYAM\nc. UDANG\td. CUMI-CUMI\n");
    printf("Masukkan Jawaban Anda: ");
    char answer;
    scanf(" %c", &answer);
    getchar(); 
    if (answer == 'd' || answer == 'D') {
        level++;
        benar();
        getchar();
        tampilkanMenu();
    } else {
        salah();
        getchar();
        gameover();
    }
} 
    
void pertanyaan6() {
    printf("6. Apa Nama Serangga yang Bisa Bertahan Hidup di Bawah Air Selama Berminggu-minggu??\n");
    printf("a. CAPUNG\tb.  KEPIK\nc. WATER BEETLE\td. BELALANG\n");
    printf("Masukkan Jawaban Anda: ");
    char answer;
    scanf(" %c", &answer);
    getchar(); 
    if (answer == 'c' || answer == 'C') {
        level++;
        benar();
        getchar();
        tampilkanMenu();
    } else {
        salah();
        getchar();
        gameover();
    }
}
        
void pertanyaan7() {
    printf("Hewan Apa yang Memiliki Jantung Terbesar di Dunia?\n");
    printf("a. GAJAH\tb. PAUS BIRU\nc. HIU\td. BADAK\n");
    printf("Masukkan Jawaban Anda: ");
    char answer;
    scanf(" %c", &answer);
    if (answer == 'b' || answer == 'B') {
        level++;
        benar();
        getchar();
        tampilkanMenu();
    } else {
        salah();
        getchar();
        gameover();
    }
}



