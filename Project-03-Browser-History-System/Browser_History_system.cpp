#include <iostream>
using namespace std;

struct Halaman{
	string judul;
	string url;
};

class BrowserHistorySystem{
	private:
		Halaman hal[100];
		int top = -1;
		
	public:
		
		void tunggu_enter(){
			cout << "\nTekan ENTER untuk kembali ke menu...";
			cin.ignore();
			cin.get();
		}
		
		void tambah_halaman(){
			if(top >= 99){
				cout << "\nHalaman penuh!!\n";
				tunggu_enter();
				return;
			}
			
			top++;
			
			cout << "\nMasukkan Judul : ";
			cin.ignore();
			getline(cin, hal[top].judul);
			
			cout << "Masukkan URL   : ";
			cin >> hal[top].url;
			
			cout << "\nHalaman berhasil ditambahkan!!\n";
			tunggu_enter();
		}
		
		void kembali_halaman(){
			if(top == -1){
				cout << "\nTidak ada halaman untuk dikembalikan\n";
				tunggu_enter();
				return;
			}
			
			cout << "\nKeluar dari halaman : " << hal[top].judul << endl;
			
			top--;
			tunggu_enter();
		}
		
		void lihat_halaman_terakhir(){
			if(top == -1){
				cout << "\nTidak ada halaman untuk dilihat\n";
				tunggu_enter();
				return;
			}
			
			cout << "\nHalaman terakhir : " << hal[top].judul << endl;
			
			tunggu_enter();
		}
		
		void tampilkan_seluruh_halaman(){
			if(top == -1){
				cout << "\nTidak ada halaman untuk ditampilkan\n";
				tunggu_enter();
				return;
			}
			
			int nomor = 1;
			for(int i = top; i >= 0; i--){
				cout << nomor << ". " << hal[i].judul << endl;
				nomor++;
			}
			
			tunggu_enter();
		}
		
		void menu(){
			bool ulang = true;
			int pilih;
			
			do{
				system("cls");
				
				cout << "============================\n"
					 << "   BROWSER HISTORY SYSTEM\n"
					 << "============================\n"
					 << "1. Tambah Halaman\n"
					 << "2. Kembali ke Halaman Sebelumnya\n"
					 << "3. Lihat Halaman Terakhir\n"
					 << "4. Tampilkan Seluruh Riwayat\n"
					 << "0. Keluar\n\n"
					 << "pilih menu (0-4) : ";
				cin >> pilih;
				
				switch(pilih){
					case 1:
						tambah_halaman();
						break;
					
					case 2:
						kembali_halaman();
						break;
					
					case 3:
						lihat_halaman_terakhir();
						break;
					
					case 4:
						tampilkan_seluruh_halaman();
						break;
					
					case 0:
						ulang = false;
						break;
					
					default:
						cout << "\nError input tidak valid\n";
						tunggu_enter();
						break;
				}
			}while(ulang);
			cout << "\nProgram selesai, Terima Kasih\n";
		}
};

int main(){
	BrowserHistorySystem bhs;
	
	bhs.menu();
	return 0;
}
