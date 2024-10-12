#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi untuk menghapus karakter newline (\n) dari input pengguna
void clearNewline(char str[]) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Fungsi untuk memvalidasi input pilihan tipe kamar
int validasiTipeKamar(int pilihan) {
    return pilihan >= 1 && pilihan <= 5;
}

// Fungsi untuk menampilkan header form
void tampilkanHeader() {
    printf("\n=================================\n");
    printf("   Form Pemesanan Vila Filya\n");
    printf("=================================\n\n");
}

// Fungsi untuk menampilkan ringkasan pembayaran
void ringkasanPembayaran(const char *metodePembayaran, int totalBiaya) {
    printf("\n=================================\n");
    printf("      Ringkasan Pembayaran\n");
    printf("=================================\n");
    printf("Metode Pembayaran: %s\n", metodePembayaran);
    printf("Total Biaya: Rp %d\n", totalBiaya);
    printf("=================================\n");
}

// Fungsi untuk pilihan transfer bank
void pilihBankTransfer() {
    printf("\n=================================\n");
    printf("      Pilihan Transfer Bank\n");
    printf("=================================\n");
    printf("1. Bank Mandiri  - No. Rek: 123-456-7890\n");
    printf("2. BRI           - No. Rek: 987-654-3210\n");
    printf("3. BCA           - No. Rek: 123-987-6540\n");
    printf("4. BNI           - No. Rek: 456-123-7890\n");
    printf("5. BTN           - No. Rek: 789-654-1230\n");
    printf("6. BSI           - No. Rek: 321-654-9870\n");
    printf("7. Bank Indonesia - No. Rek: 654-987-3210\n");
    int pilihanBank;
    printf("\nMasukkan nomor bank yang ingin digunakan (1-7): ");
    while (scanf("%d", &pilihanBank) != 1 || pilihanBank < 1 || pilihanBank > 7) {
        printf("Pilihan tidak valid! Masukkan ulang: ");
        while (getchar() != '\n');
    }
    printf("\nSilakan transfer ke rekening yang dipilih.\n");
    printf("Tolong selesaikan pembayaran tiket booking kamar villa dalam waktu 2 jam.\n");
}

// Fungsi untuk pilihan e-wallet
void pilihEWallet() {
    printf("\n=================================\n");
    printf("         Pilihan E-Wallet\n");
    printf("=================================\n");
    printf("1. Dana       - No. E-Wallet: 0808-1234-5678\n");
    printf("2. ShopeePay  - No. E-Wallet: 0812-3456-7890\n");
    printf("3. OVO        - No. E-Wallet: 0811-1234-5678\n");
    printf("4. GoPay      - No. E-Wallet: 0813-4567-7890\n");
    printf("5. LinkAja    - No. E-Wallet: 0819-1234-5678\n");
    int pilihanEWallet;
    printf("\nMasukkan nomor E-Wallet yang ingin digunakan (1-5): ");
    while (scanf("%d", &pilihanEWallet) != 1 || pilihanEWallet < 1 || pilihanEWallet > 5) {
        printf("Pilihan tidak valid! Masukkan ulang: ");
        while (getchar() != '\n');
    }
    printf("\nSilakan lakukan pembayaran ke nomor E-Wallet yang dipilih.\n");
}

// Fungsi untuk pilihan kartu kredit
void pilihKartuKredit() {
    printf("\n=================================\n");
    printf("       Pilihan Kartu Kredit\n");
    printf("=================================\n");
    printf("1. Bank Mandiri  - No. Kartu: 1234-5678-9012-3456\n");
    printf("2. BRI           - No. Kartu: 9876-5432-1098-7654\n");
    printf("3. BCA           - No. Kartu: 5678-9012-3456-7890\n");
    printf("4. BNI           - No. Kartu: 3456-7890-1234-5678\n");
    printf("5. BTN           - No. Kartu: 7890-1234-5678-9012\n");
    printf("6. BSI           - No. Kartu: 6543-2198-7654-3210\n");
    printf("7. Bank Indonesia - No. Kartu: 4321-0987-6543-2109\n");
    int pilihanKartuKredit;
    char pin[5];
    printf("\nMasukkan nomor bank kartu kredit yang ingin digunakan (1-7): ");
    while (scanf("%d", &pilihanKartuKredit) != 1 || pilihanKartuKredit < 1 || pilihanKartuKredit > 7) {
        printf("Pilihan tidak valid! Masukkan ulang: ");
        while (getchar() != '\n');
    }
    // Meminta PIN untuk kartu kredit
    printf("Masukkan PIN kartu kredit Anda (4 digit): ");
    scanf("%s", pin);
    printf("\nPembayaran kartu kredit berhasil dilakukan dengan nomor kartu yang dipilih.\n");
}

// Fungsi untuk mengecek status pembayaran
void cekStatusPembayaran() {
    printf("\n=================================\n");
    printf("       Cek Status Pembayaran\n");
    printf("=================================\n");
    // Misalkan status pembayaran
    printf("Status pembayaran: Sukses (silakan cek bukti pembayaran Anda)\n");
}

int main() {
    char nama[50], email[50], tipeKamar[50], metodePembayaran[30];
    int jumlahOrang, pilihanKamar, totalBiaya;
    char tanggalMenginap[20];
    int pilihanMenu;

    do {
        tampilkanHeader();

        // Input nama pemesan
        printf("Masukkan Nama Pemesan: ");
        fgets(nama, sizeof(nama), stdin);
        clearNewline(nama);  // Menghapus newline

        // Input email pemesan
        printf("Masukkan Email Pemesan: ");
        fgets(email, sizeof(email), stdin);
        clearNewline(email);  // Menghapus newline

        // Input tanggal menginap
        printf("Masukkan Tanggal Menginap (dd-mm-yyyy): ");
        fgets(tanggalMenginap, sizeof(tanggalMenginap), stdin);
        clearNewline(tanggalMenginap);  // Menghapus newline

        // Input jumlah orang
        printf("Masukkan Jumlah Orang: ");
        while (scanf("%d", &jumlahOrang) != 1 || jumlahOrang <= 0) {
            printf("Jumlah orang tidak valid! Masukkan ulang: ");
            while (getchar() != '\n');
        }

        // Menampilkan pilihan tipe kamar
        printf("\nPilih Tipe Kamar:\n");
        printf("1. Filya Garden (Villa Kebun/Taman) - Rp 1,500,000 per malam\n");
        printf("2. Filya Bliss (Villa Spa/Wellness) - Rp 2,000,000 per malam\n");
        printf("3. Filya Grove (Villa Hutan) - Rp 1,800,000 per malam\n");
        printf("4. Filya Hills (Villa Pegunungan/Bukit) - Rp 2,500,000 per malam\n");
        printf("5. Filya Breeze (Villa Pantai) - Rp 2,200,000 per malam\n");

        // Input tipe kamar dengan validasi
        printf("\nMasukkan nomor tipe kamar (1-5): ");
        while (scanf("%d", &pilihanKamar) != 1 || !validasiTipeKamar(pilihanKamar)) {
            printf("Pilihan tidak valid! Masukkan ulang: ");
            while (getchar() != '\n');  // Membersihkan buffer input
        }

        // Menentukan harga berdasarkan pilihan kamar
        switch(pilihanKamar) {
            case 1:
                strcpy(tipeKamar, "Filya Garden (Villa Kebun/Taman)");
                totalBiaya = 1500000;
                break;
            case 2:
                strcpy(tipeKamar, "Filya Bliss (Villa Spa/Wellness)");
                totalBiaya = 2000000;
                break;
            case 3:
                strcpy(tipeKamar, "Filya Grove (Villa Hutan)");
                totalBiaya = 1800000;
                break;
            case 4:
                strcpy(tipeKamar, "Filya Hills (Villa Pegunungan/Bukit)");
                totalBiaya = 2500000;
                break;
            case 5:
                strcpy(tipeKamar, "Filya Breeze (Villa Pantai)");
                totalBiaya = 2200000;
                break;
        }

        // Menampilkan ringkasan pemesanan
        printf("\n=================================\n");
        printf("        Ringkasan Pemesanan\n");
        printf("=================================\n");
        printf("Nama Pemesan   : %s\n", nama);
        printf("Email          : %s\n", email);
        printf("Tanggal Menginap: %s\n", tanggalMenginap);
        printf("Jumlah Orang   : %d\n", jumlahOrang);
        printf("Tipe Kamar     : %s\n", tipeKamar);
        printf("=================================\n");

        // Pilih metode pembayaran
        printf("\nPilih Metode Pembayaran:\n");
        printf("1. Transfer Bank\n");
        printf("2. Kartu Kredit\n");
        printf("3. E-Wallet\n");
        printf("4. Konfirmasi via WhatsApp (Pembayaran VIA Offline)\n");

        int pilihanPembayaran;
        printf("\nMasukkan nomor metode pembayaran (1-4): ");
        while (scanf("%d", &pilihanPembayaran) != 1 || pilihanPembayaran < 1 || pilihanPembayaran > 4) {
            printf("Pilihan tidak valid! Masukkan ulang: ");
            while (getchar() != '\n');
        }

        // Memilih metode pembayaran
        switch(pilihanPembayaran) {
            case 1:
                strcpy(metodePembayaran, "Transfer Bank");
                ringkasanPembayaran(metodePembayaran, totalBiaya);
                pilihBankTransfer();
                break;
            case 2:
                strcpy(metodePembayaran, "Kartu Kredit");
                ringkasanPembayaran(metodePembayaran, totalBiaya);
                pilihKartuKredit();
                break;
            case 3:
                strcpy(metodePembayaran, "E-Wallet");
                ringkasanPembayaran(metodePembayaran, totalBiaya);
                pilihEWallet();
                break;
            case 4:
                printf("\nSilakan kirim pesan berikut ke WhatsApp:\n");
                printf("Halo, saya ingin melakukan booking kamar secara offline dengan detail berikut:\n");
                printf("Nama Pemesan   : %s\n", nama);
                printf("Email          : %s\n", email);
                printf("Tanggal Menginap: %s\n", tanggalMenginap);
                printf("Jumlah Orang   : %d\n", jumlahOrang);
                printf("Tipe Kamar     : %s\n", tipeKamar);
                printf("Terima kasih!\n");
                printf("\nTerima kasih atas pemesanan Anda! Konfirmasi akan dikirim melalui WhatsApp.\n");
                printf("Silakan cek WhatsApp Anda untuk informasi lebih lanjut.\n");
                return 0; // Mengakhiri program setelah konfirmasi
        }

        // Menanyakan apakah pengguna ingin memeriksa status pembayaran atau kembali ke halaman beranda
        printf("\n=================================\n");
        printf("Apakah Anda ingin:\n");
        printf("1. Cek Status Pembayaran\n");
        printf("2. Kembali ke Halaman Beranda\n");
        printf("Masukkan pilihan (1-2): ");
        while (scanf("%d", &pilihanMenu) != 1 || (pilihanMenu < 1 || pilihanMenu > 2)) {
            printf("Pilihan tidak valid! Masukkan ulang: ");
            while (getchar() != '\n');
        }

        if (pilihanMenu == 1) {
            cekStatusPembayaran();
        }

    } while (pilihanMenu != 2);  

    return 0;
}