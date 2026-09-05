#include "ManagementSystem.h"

void ManagementSystem::tunggu_enter(){
    cout << "\nTekan ENTER untuk kembali ke menu...";
    cin.ignore();
    cin.get();
}

void ManagementSystem::tambah_antrean(){ // Enqueue
    string nama;
    
    if(rear >= 99){
        cout <<"\nAntrean penuh!!\n";
        tunggu_enter();
        return;
    }
    
    cout << "\nMasukkan nama mahasiswa : ";
    cin.ignore();
    getline(cin, nama);
    
    rear++;
    antrean[rear] = nama;
    
    cout << "\nBerhasil ditambahkan ke antrean!!\n";
    tunggu_enter();
}

void ManagementSystem::layani_mahasiswa(){ // Dequeue
    if (front > rear){ // cek bahwa antrean kosong atu tidak
        cout << "\nAntrean kosong!!\n";
    }else{
        cout << "\nsedang melayani : " << antrean[front];
        front++;
    }
    
    tunggu_enter();
}

void ManagementSystem::tampilkan_antrean(){ // Display Queue
    cout << "\n=== TAMPILKAN ANTREAN ===\n";
    if(front > rear){
        cout << "\nAntrean kosong!!\n";
    }else{
        cout << endl;
        for (int i = front; i <= rear; i++){
            if (i == rear){
                cout << antrean[i];
            }else{
                cout << antrean[i] << ", ";
            }
        }
        cout << endl;
    }
    
    tunggu_enter();
}

void ManagementSystem::tambah_riwayat(string aktivitas){
    if (top >= 99){
        return;
    }
    
    top++;
    riwayat[top] = aktivitas;
}

void ManagementSystem::tampilkan_riwayat(){ // berdasarkan terbaru 
    cout << "\n=== RIWAYAT AKTIVITAS ===\n";
    
    if(top == -1){
        cout << "\nBelum ada aktivitas.\n";
    }else{
        int nomor = 1; // untuk penomoran saja
        
        for(int i = top; i >= 0; i--){
            cout << endl << nomor <<". " << riwayat[i] << endl;
            nomor++;
        }
    }
    
    tunggu_enter();
}

void ManagementSystem::tambah_mahasiswa(){
    cin.ignore();
    cout << "Masukkan Nama  : ";
    getline(cin, mhs[jumlah_mahasiswa].nama);
    cout << "Masukkan NIM   : ";
    cin >> mhs[jumlah_mahasiswa].nim;
    cout << "Masukkan Nilai : ";
    cin >> mhs[jumlah_mahasiswa].nilai;
    
    tambah_riwayat("Tambah mahasiswa: " + mhs[jumlah_mahasiswa].nama);
    
    jumlah_mahasiswa++;  // menambahkan setiap ruang array untuk input
    
    cout << "\nData berhasil ditambahkan!!\n";
    tunggu_enter();
}

void ManagementSystem::tampilkan_semua_mahasiswa(){
    cout << "============================\n"
            << "       DATA MAHASISWA \n"
            << "============================\n";
    for (int i = 0; i < jumlah_mahasiswa; i++){
        cout << "\nData ke-" << i+1 << endl;
        cout << "Nama  : " << mhs[i].nama << endl;
        cout << "NIM   : " << mhs[i].nim << endl;
        cout << "Nilai : " << mhs[i].nilai << endl;
    }
    tunggu_enter();
}

void ManagementSystem::cari_mahasiswa(){
    string nimCari;
    bool ditemukan = false;

    cout << "Masukkan NIM yang ingin dicari : ";
    cin >> nimCari;

    for(int i = 0; i < jumlah_mahasiswa; i++){
        if(nimCari == mhs[i].nim){
            cout << "\nData ditemukan!\n";
            cout << "\nNama  : " << mhs[i].nama << endl;
            cout << "NIM   : " << mhs[i].nim << endl;
            cout << "Nilai : " << mhs[i].nilai << endl;

            ditemukan = true;
            break;
        }
    }

    if(!ditemukan){
        cout << "\nData mahasiswa tidak ditemukan!\n";
    }

    tambah_riwayat("Cari mahasiswa dengan NIM : " + nimCari);

    tunggu_enter();
}

void ManagementSystem::urut_berdasarkan_nilai(){
    for(int i = 0; i < jumlah_mahasiswa - 1; i++){
        int max = i;

        for(int j = i + 1; j < jumlah_mahasiswa; j++){
            if(mhs[j].nilai > mhs[max].nilai){
                max = j;
            }
        }

        if(max != i){
            Mahasiswa temp = mhs[i];
            mhs[i] = mhs[max];
            mhs[max] = temp;
        }
    }

    tambah_riwayat("Mengurutkan mahasiswa berdasarkan nilai");

    cout << "\nData berhasil diurutkan berdasarkan nilai terbesar!!\n";

    tunggu_enter();
}

void ManagementSystem::menu(){
    do{
        system("cls");
        
        int pilih;
        cout << "==========================\n"
                << " STUDENT MANAGEMENT SYSTEM\n"
                << "==========================\n"
                << "1. Tambah Mahasiswa\n"
                << "2. Tampilkan Semua Mahasiswa\n"
                << "3. Cari Mahasiswa\n"
                << "4. Urutkan Mahasiswa berdasarkan Nilai\n"
                << "5. Lihat Riwayat Aktivitas\n"
                << "6. Tambah ke Antrean\n"
                << "7. Layani Mahasiswa\n"
                << "8. Lihat Antrean\n"
                << "0. Keluar\n\n"
                << "Pilih menu (0-8): ";
        cin >> pilih;

        switch(pilih){
            case 1:
                if (jumlah_mahasiswa >= 100){
                    cout << "\nKapasitas mahasiswa sudah penuh\n";
                }else{
                    tambah_mahasiswa();
                }
                break;
                
            case 2:
                if (jumlah_mahasiswa == 0){ // cek apakah sudah ada data belum
                    cout << "\nMaaf data masih kosong!!\n";
                    tunggu_enter();
                }else{
                    tampilkan_semua_mahasiswa();
                }
                break;
                
            case 3:
                if (jumlah_mahasiswa == 0){ // cek apakah sudah ada data belum
                    cout << "\nMaaf data masih kosong!!\n";
                    tunggu_enter();
                }else{
                    cari_mahasiswa();
                }
                break;
                
            case 4:
                if (jumlah_mahasiswa == 0){ // cek apakah sudah ada data belum
                    cout << "\nMaaf data masih kosong!!\n";
                    tunggu_enter();
                }else{
                    urut_berdasarkan_nilai();
                }
                break;
                
            case 5:
                tampilkan_riwayat();
                break;
                
            case 6:
                tambah_antrean();
                break;
                
            case 7:
                layani_mahasiswa();
                break;
                
            case 8:
                tampilkan_antrean();
                break;
            
            case 0:
                ulang = false;
                break;
                
            default:
                cout << "\nError, input tidak valid\n";
                tunggu_enter();
                break;
        }
        
    }while(ulang);
    
    cout << "\nTerima kasih\n";
}