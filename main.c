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
        printf("Harus terdapat 3 Argumen saat menjalankan program!\n");
        printf("Cara penggunaan : ./main Username Password!\n");
        return 1;
    }

    FILE *fpw = fopen("database/login.bin","wb");
    if (fpw == NULL) {
        printf("gagal membuka file!");
        return EXIT_FAILURE;
    }

    char username[50],password[50];

    printf("Masukkan Username :");
    fgets(username,sizeof(username),stdin);
    username[strcspn(username, "\n")] = '\0';
    
    printf("Masukkan Password :");
    fgets(password,sizeof(password),stdin);
    password[strcspn(password, "\n")] = '\0';

    strcat(username, "@");
    strcat(username,password);

    fwrite(username,sizeof(char),sizeof(username)/sizeof(char),fpw);

    fclose(fpw);

    FILE *fpr = fopen("database/login.bin","rb");

    if (fpr == NULL) {
        printf("gagal membuka file!");
        return EXIT_FAILURE;
    }

    fread(username,sizeof(char),sizeof(username)/sizeof(char),fpr);

    fclose(fpr);
    char *string[3];
    char user[50], pass[50];
    int ctrl = 0;

    string[0] = strtok(username,"@");
    while(string[ctrl++] != NULL) {
        string[ctrl] = strtok(NULL,"@");
    }

    strcpy(user, string[0]);
    strcpy(pass, string[1]);

    printf("=============================================\n");
    printf("=         Registrasi Anda Berhasil          =\n");
    printf("=============================================\n");
    printf("=  Silahkan Login Untuk Memulai Permainan!   =\n");
    printf("=============================================\n");
    printf("=       Tekan ENTER Untuk Melanjutkan       =\n");
    printf("=============================================");
    getchar();

    char userLog[20], passLog[20];
    printf("Masukkan Username :");
    fgets(userLog, sizeof(userLog), stdin);

    printf("Masukkan Password :");
    fgets(passLog, sizeof(passLog), stdin);

    char userLogin[10], passLogin[10];
    strcpy(userLogin,argumen[1]);
    strcpy(passLogin,argumen[2]);

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
    printf("🌟 Skor Anda Saat Ini: %d\n", score);
    printf("=============================================\n");
    printf("👉 Pilih opsi Anda (1/2/3): ");
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
                printf("❌ Pilihan tidak valid. Silakan coba lagi!\n");
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
    printf("=         Selamat Jawaban Anda Benar       =\n");
    printf("============================================\n");
    score += 100;
    printf("🌟 Skor Anda Sekarang: %d", score);
    getchar();
}

void salah() {
    printf("============================================\n");
    printf("=            Jawaban Anda SALAH!           =\n");
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
    printf("a. Pink\tb. Biru tua\nc. Hijau\td. Kuning\n");
    printf("Masukkan jawaban Anda: ");
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
    printf("2. Negara mana yang tidak memiliki ular sama sekali?\n");
    printf("a. Norwegia\tb.  Islandia\nc. Finlandia\td. Kanada\n");
    printf("Masukkan jawaban Anda: ");
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
    printf("3. Hewan apa yang bisa menggulung tubuhnya menjadi bola?\n");
    printf("a. Landak\tb. Trenggiling\nc. Siput\td. armadillo\n");
    printf("masukan jawaban anda: ");
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

 void pertanyaan4() {
    printf("4. Hewan apa yang dikenal sebagai predator terbesar di lautan?\n");
    printf("a. Paus pembunuh\tb.  Hiu putih besar\nc. Ubur-ubur raksasa\td. Anemon Laut\n");
    printf("Masukkan jawaban Anda: ");
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
    printf("5. Hewan apa yang menghasilkan tinta sebagai mekanisme pertahanan?\n");
    printf("a. Cumi-cumi\tb. Ayam\nc. Udang\td. Ikan pari\n");
    printf("masukan jawaban anda: ");
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
    
void pertanyaan6() {
    printf("6. Apa nama serangga yang bisa bertahan hidup di bawah air selama berminggu-minggu??\n");
    printf("a. Capung\tb.  Kepik\nc. Water Beetle\td. Belalang\n");
    printf("Masukkan jawaban Anda: ");
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
    printf("Hewan apa yang memiliki jantung terbesar di dunia?\n");
    printf("a. Gajah\tb. Paus biru\nc. Hiu\td. Badak\n");
    printf("Masukkan jawaban Anda: ");
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



