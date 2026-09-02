#include <iostream>
using namespace std;

struct Pasien{
	string nama;
	string nomor_pasien;
	string keluhan;
};

class HospitalQueueSystem{
	private:
		Pasien ps[100];
		int front = 0;
		int rear = -1;
	public:
		
		void tunggu_enter(){
			cout << "\nTekan ENTER untuk kembali ke menu..."	;
			cin.ignore();
			cin.get();
		}
		
		void tambah_pasien(){
			if (rear >= 99){
				cout << "\nAntrean penuh!!\n";
				tunggu_enter();
				return;
			}
			
			rear++; // agar rear bertambah ke index 0 dan seterusnya
			
			cout << "\nMasukkan Nama Pasien  : ";
			cin.ignore();
			getline(cin, ps[rear].nama);
			
			cout << "Masukkan Nomor Pasien   : ";
			cin >> ps[rear].nomor_pasien;
			
			cout << "Masukkan Keluhan Pasien : ";
			cin.ignore();
			getline(cin, ps[rear].keluhan);
			
			cout << "\nPasien berhasil ditambahkan ke antrean!!\n";
			tunggu_enter();
		}
		
		void layani_pasien(){
			if(front > rear){
				cout << "\nAntrean masih kosong\n";
				tunggu_enter();
				return;
			}
			
			cout << "\nSedang melayani : " << ps[front].nama << endl;
			
			front++;
			tunggu_enter();
		}
		
		void tampilkan_antrean(){
			if(front > rear){
				cout << "\nAntrean masih kosong\n";
				tunggu_enter();
				return;
			}
			
			int nomor = 1;
			cout << "\n--------------------------------\n";
			for(int i = front; i <= rear; i++){
				cout << "Antrean ke-" << nomor << " : \n\n";
				cout << "Nama Pasien   : " << ps[i].nama << endl;
				cout << "Nomor Pasien  : " << ps[i].nomor_pasien << endl;
				cout << "Keluhan Pasien: " << ps[i].keluhan << endl;
				cout << "--------------------------------\n";
				nomor++;
			}
			tunggu_enter();
		}
		
		void menu(){
			bool ulang = true;
			int pilih;
			do{
				system("cls");
				
				cout << "===========================\n"
					 << "   HOSPITAL QUEUE SYSTEM  \n"
					 << "===========================\n"
					 << "1. Tambah Pasien\n"
					 << "2. Layani Pasien\n"
					 << "3. Lihat Antrean\n"
					 << "0. Keluar\n\n"
					 
					 << "Pilih menu (0-3) : ";
				cin >> pilih;
				
				switch(pilih){
					case 1:
						tambah_pasien();
						break;
					
					case 2:
						layani_pasien();
						break;
						
					case 3:
						tampilkan_antrean();
						break;
					case 0:
						ulang = false;
						break;
					default:
						cout << "\nError input tidak valid!!\n";
						tunggu_enter();
				}
			}while(ulang);
			cout << "\nProgram berakhir, Terima kasih\n";
		}
};

int main(){
	HospitalQueueSystem hqs;
	
	hqs.menu();
	return 0;
}
