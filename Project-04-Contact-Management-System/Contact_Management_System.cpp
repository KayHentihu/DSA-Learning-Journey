#include <iostream>
using namespace std;

struct Node{
	string nama;
	string nomor_telepon;
	
	Node* next; // pointer ke Node berikutnya
};

class ContactManagementSystem{
	private:
		Node* head;
		
	public:
		ContactManagementSystem(){
			head = nullptr; // head belum menunjuk ke Node mana pun
		}
		
		void tunggu_enter(){
			cout << "\nTekan ENTER untuk kembali ke menu..."	;
			cin.ignore();
			cin.get();
		}
		
		void tambah_kontak(){
			Node* kontak_baru;
			
			kontak_baru = new Node;
			
			cout << "\nMasukkan Nama : ";
			cin.ignore();
			getline(cin, kontak_baru->nama);
			cout << "Masukkan Nomor Telepon : ";
			cin >> kontak_baru->nomor_telepon;
			
			if (head == nullptr){
				kontak_baru->next = nullptr;
				head = kontak_baru;
			}else{
				Node* temp = head;
				
				while(temp->next != nullptr){
					temp = temp->next;	
				}
				
				kontak_baru->next = nullptr;
				temp->next = kontak_baru;
			}
			
			cout << "\nKontak baru berhasil ditambahkan!!\n";
			tunggu_enter();
		}
		
		void tampilkan_kontak(){
			if (head == nullptr){
				cout << "\nTidak ada kontak yang bisa ditampilkan\n";
				tunggu_enter();
				return;
			}
			
			Node* temp = head;
			while(temp != nullptr){
				cout << "\nNama Kontak   : " << temp->nama << endl;
				cout << "Nomor Telepon : " << temp->nomor_telepon << endl;
				
				temp = temp->next;
			}
			
			tunggu_enter();
		}
		
		void cari_kontak(){
			string cari;
			
			if (head == nullptr){
				cout << "\nTidak ada kontak yang bisa dicari\n";
				tunggu_enter();
				return;
			}
			
			cout << "\nMasukkan nama yang dicari : ";
			cin.ignore();
			getline(cin, cari);
			
			Node* temp = head;
			bool ditemukan = false;
			
			while(temp != nullptr){
				if (temp->nama == cari){
					cout << "\nKontak ditemukan!!\n";
					cout << "Nama Kontak   : " << temp->nama << endl;
					cout << "Nomor Telepon : " << temp->nomor_telepon << endl;
					ditemukan = true;
					break;
				}else{
					temp = temp->next;
				}
			}
			
			if(!ditemukan){
				cout << "\nKontak tidak ditemukan!!\n";
			}
			tunggu_enter();
		}
		
		void hapus_kontak(){
			if(head == nullptr){
				cout << "\nTidak ada kontak yang bisa dihapus\n";
				tunggu_enter();
				return;
			}
			
			string hapus_nama;
			
			cout << "\nMasukkan nama kontak yang ingin dihapus : ";
			cin.ignore();
			getline(cin, hapus_nama);
			
			Node* temp = head;
			Node* sebelumnya = nullptr;
			bool ditemukan = false;
			
			while(temp != nullptr){
				if(temp->nama == hapus_nama){
					if(temp == head){
						head = temp->next;
					}else{
						sebelumnya->next = temp->next;
					}
					ditemukan = true;
					delete temp;
					break;
				}else{
					sebelumnya = temp;
					temp = temp->next;
				}
			}
			
			if(!ditemukan){
				cout << "\nKontak tidak ditemukan!!\n";
			}else{
				cout << "\nKontak berhasil dihapus!!\n";
			}
			
			tunggu_enter();
		}
		
		void menu(){
			bool ulang = true;
			int pilih;
			
			do{
				system("cls");
				cout << "==================================\n"
					 << "    CONTACT MANAGEMENT SYSTEM\n"
					 << "==================================\n"
					 << "1. Tambah Kontak\n"
					 << "2. Tampilkan Semua Kontak\n"
					 << "3. Cari Kontak\n"
					 << "4. Hapus Kontak\n"
					 << "0. Keluar\n\n"
					 << "Pilih menu (0-4) : ";
				cin >> pilih;
				
				switch(pilih){
					case 1:
						tambah_kontak();
						break;
					
					case 2:
						tampilkan_kontak();
						break;
					
					case 3:
						cari_kontak();
						break;
					
					case 4:
						hapus_kontak();
						break;
					
					case 0:
						ulang = false;
						break;
					
					default:
						cout << "\nError input tidak valid!!\n";
						tunggu_enter();
						break;
				}
			}while(ulang);
			cout << "\nProgram selesai, Terima kasih!!\n";
		}
};

int main(){
	ContactManagementSystem cms;
	
	cms.menu();
	return 0;
}
