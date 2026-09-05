#ifndef MANAGEMENT_SYSTEM_H
#define MANAGEMENT_SYSTEM_H

#include <iostream>
using namespace std;

struct Mahasiswa{
    string nama;
    string nim;
    float nilai;
};

class ManagementSystem{
	private:
        Mahasiswa mhs[100];
        int jumlah_mahasiswa = 0; // total setiap input mahasiswa
        bool ulang = true;
        string riwayat[100];
        int top = -1; // menandakan belum ada elemen dalam stack
        string antrean[100];
        int front = 0;
        int rear = -1;
    public:
    	void tunggu_enter();		
    	void tambah_antrean();		
		void layani_mahasiswa();  	
    	void tampilkan_antrean();				
    	void tambah_riwayat(string aktivitas);		
		void tampilkan_riwayat();   	
        void tambah_mahasiswa();		
		void tampilkan_semua_mahasiswa();		
		void cari_mahasiswa();	
		void urut_berdasarkan_nilai();	
          void menu();
};

#endif