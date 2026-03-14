#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cstring>
using namespace std;

void lihatKatalog();
void bubbleSort();
void quickSort(int awal, int akhir);
void linearSearch();
void binarySearch();
void tambahFilm();

struct dataFilm {
	char name[100];
	double price;
	int year;
	double rating;
};
int jumlahData = 0;
dataFilm netfilm[99];

int main() {
	int pilih;
	bool memilih = false;
	char menu;
	
	// Membaca jumlah data film untuk dijadikan batas perulangan pada setiap fungsi
	FILE *fcount; 
	fcount = fopen("jumlahdata.txt", "r");
	if (fcount == NULL) {
		cout << "Error opening file" << endl;
		exit(1);
	}
	fscanf(fcount, "%d", &jumlahData);
	fclose(fcount);
	
	// Menu dashboard
	while (!memilih) {
		bool lanjut = false;
		cout << left << setw(12) << "" << "NETFILM SYSTEM - DASHBOARD" << endl;
		cout << left << setw(5) << "" << setfill('=') << setw(40) << "" << setfill(' ') << endl;
		cout << left << setw(5) << "" << "[1] Lihat Katalog Film" << endl;
		cout << left << setw(5) << "" << "[2] Urutkan Rating (Quick Sort)" << endl;
		cout << left << setw(5) << "" << "[3] Urutkan Abjad (Bubble Sort)" << endl;
		cout << left << setw(5) << "" << "[4] Cari Film (Sequential Search)" << endl;
		cout << left << setw(5) << "" << "[5] Cari Film (Binary Search)" << endl;
		cout << left << setw(5) << "" << "[6] Tambah Film Baru" << endl;
		cout << left << setw(5) << "" << "[0] Keluar dan Simpan" << endl;
		cout << left << setw(5) << "" << setfill('=') << setw(40) << "" << setfill(' ') << endl;
		cout << endl;
		cout << left << setw(5) << "" << "Pilih Menu: ";
		cin >> pilih;
		
		switch (pilih) {
			case 1: 
				lihatKatalog();
				cout << "\nIngin melanjutkan program? (Y/N) : ";
				while (!lanjut) {
					cin >> menu;				
					if (toupper(menu) == 'Y') {						
						system("cls");
						lanjut = true;
						memilih = false;
					}
					else if (toupper(menu) == 'N') {
						cout << "Terima kasih telah menggunakan program ini.";					
						lanjut = true;
						memilih = true;
					}
					else {
						cout << "Input tidak valid, silakan ulang.";
						cout << "\nPilih: ";
					}
				}
				break;
			case 2:
				quickSort(0, jumlahData - 1);
				cout << "\nIngin melanjutkan program? (Y/N) : ";
				while (!lanjut) {
					cin >> menu;				
					if (toupper(menu) == 'Y') {						
						system("cls");
						lanjut = true;
						memilih = false;
					}
					else if (toupper(menu) == 'N') {
						cout << "Terima kasih telah menggunakan program ini.";					
						lanjut = true;
						memilih = true;
					}
					else {
						cout << "Input tidak valid, silakan ulang.";
						cout << "\nPilih: ";
					}
				}
				break;
			case 3:
				bubbleSort();
				cout << "\nIngin melanjutkan program? (Y/N) : ";
				while (!lanjut) {
					cin >> menu;				
					if (toupper(menu) == 'Y') {						
						system("cls");
						lanjut = true;
						memilih = false;
					}
					else if (toupper(menu) == 'N') {
						cout << "Terima kasih telah menggunakan program ini.";					
						lanjut = true;
						memilih = true;
					}
					else {
						cout << "Input tidak valid, silakan ulang.";
						cout << "\nPilih: ";
					}
				}
				break;
			case 4:
				linearSearch();
				cout << "\nIngin melanjutkan program? (Y/N) : ";
				while (!lanjut) {
					cin >> menu;				
					if (toupper(menu) == 'Y') {						
						system("cls");
						lanjut = true;
						memilih = false;
					}
					else if (toupper(menu) == 'N') {
						cout << "Terima kasih telah menggunakan program ini.";					
						lanjut = true;
						memilih = true;
					}
					else {
						cout << "Input tidak valid, silakan ulang.";
						cout << "\nPilih: ";
					}
				}
				break;
			case 5:
				binarySearch();
				cout << "\nIngin melanjutkan program? (Y/N) : ";
				while (!lanjut) {
					cin >> menu;				
					if (toupper(menu) == 'Y') {						
						system("cls");
						lanjut = true;
						memilih = false;
					}
					else if (toupper(menu) == 'N') {
						cout << "Terima kasih telah menggunakan program ini.";					
						lanjut = true;
						memilih = true;
					}
					else {
						cout << "Input tidak valid, silakan ulang.";
						cout << "\nPilih: ";
					}
				}
				break;
			case 6:
				tambahFilm();
				cout << "\nIngin melanjutkan program? (Y/N) : ";
				while (!lanjut) {
					cin >> menu;				
					if (toupper(menu) == 'Y') {						
						system("cls");
						lanjut = true;
						memilih = false;
					}
					else if (toupper(menu) == 'N') {
						cout << "Terima kasih telah menggunakan program ini.";					
						lanjut = true;
						memilih = true;
					}
					else {
						cout << "Input tidak valid, silakan ulang.";
						cout << "\nPilih: ";
					}
				}
				break;
			case 0:
				memilih = true;
				cout << "\n[ THANK YOU ] Data berhasil disinkronkan ke netfilm_db.txt" << endl;
				break;
			default:
				system("cls");
		}
	}
	
}

void lihatKatalog() {
	int i = 0, id = 1;
	// Membuka file data film.
	FILE *fptr;
	fptr = fopen ("netfilm_db.txt","r");
	if (fptr == NULL){
	  cout << "\nData masih kosong, silakan input terlebih dahulu." << endl;
	  return;
	}
	
	while (fscanf(fptr, " %[^;];%lf;%d;%lf\n", netfilm[i].name, &netfilm[i].price,&netfilm[i].year, &netfilm[i].rating) != EOF) {
		i++;
	}
	
	// Menampilkan data film dari file.
	cout << "\nN E T F I L M  C O N T E N T  K A T A L O G" << endl;
	cout << setfill('-') << setw(72) << "" << setfill(' ') << endl;
	cout << setw(6) << " ID " << setw(24) << " JUDUL FILM " << setw(16) << " LISENSI " << setw(16) << " TAHUN " << setw(16) << " RATING " << endl;
	cout << setfill('-') << setw(72) << "" << setfill(' ') << endl;
	
	for(int j = 0; j < jumlahData; j++) {
		cout << "[" << id++ << "]" << setw(3)  << " ";
		cout << setw(24) << netfilm[j].name << " ";
		cout << setw(15) << netfilm[j].price << " ";
		cout << setw(16) << netfilm[j].year << " ";
		cout << setw(15) << netfilm[j].rating << " ";
		cout << endl;
	}
	cout << setfill('-') << setw(72) << "" << setfill(' ') << endl;

	fclose(fptr);
}

void quickSort(int awal, int akhir) {
	
	int id = 1;
	
	// Membuka dan membaca seluruh data film dari dalam file.
	if (awal == 0 && akhir == jumlahData - 1) {
		FILE *fptr;
		fptr = fopen ("netfilm_db.txt","r");
		if (fptr == NULL){
		  cout << "\nData masih kosong, silakan input terlebih dahulu" << endl;
		  return;
		}

		int i = 0;
		while (fscanf(fptr, " %[^;];%lf;%d;%lf\n", netfilm[i].name, &netfilm[i].price,&netfilm[i].year, &netfilm[i].rating) != EOF) {
			i++;
		}
		fclose(fptr);
	}
	
	// Sorting
	int low = awal, high = akhir;
    double pivot = netfilm[(awal + akhir) / 2].rating;
	
    do {
        while (netfilm[low].rating > pivot)
            low++;
        while (netfilm[high].rating < pivot)
            high--;

        if (low <= high) {
            swap(netfilm[low], netfilm[high]);
            low++;
            high--;
        }
        
    } while (low <= high);

    if (awal < high)
        quickSort(awal, high);
	
    if (low < akhir)
        quickSort(low, akhir);
	
    // Data yang sudah disorting.
    if (awal == 0 && akhir == jumlahData - 1) {
		cout << "\nN E T F I L M  C O N T E N T  K A T A L O G" << endl;
		cout << setfill('-') << setw(72) << "" << setfill(' ') << endl;
		cout << setw(6) << " ID " << setw(24) << " JUDUL FILM " << setw(16) << " LISENSI " << setw(16) << " TAHUN " << setw(16) << " RATING " << endl;
		cout << setfill('-') << setw(72) << "" << setfill(' ') << endl;
		
		for(int j = 0; j < jumlahData; j++) {
			cout << "[" << id++ << "]" << setw(3)  << " ";
			cout << setw(24) << netfilm[j].name << " ";
			cout << setw(15) << netfilm[j].price << " ";
			cout << setw(16) << netfilm[j].year << " ";
			cout << setw(15) << netfilm[j].rating << " ";
			cout << endl;
		}
		cout << setfill('-') << setw(72) << "" << setfill(' ') << endl;
		cout << "[!] Katalog berhasil diurutkan sesuai rating tertinggi." << endl;
	}
}

void bubbleSort() {
	int i = 0, id = 1;
     
    // Membuka file data film
	FILE *fptr;
	fptr = fopen ("netfilm_db.txt","r");
	
	if (fptr == NULL){
	  cout << "\nData masih kosong, silakan input terlebih dahulu" << endl;
	  return;
	}
	
	//Membaca data film awal hingga akhir
	while (fscanf(fptr, " %[^;];%lf;%d;%lf\n", netfilm[i].name, &netfilm[i].price,&netfilm[i].year, &netfilm[i].rating) != EOF) {
		i++;
	}
	
	// Sorting
	for (int i = 0; i < jumlahData - 1; i++) {
		for (int j = 0; j < jumlahData - 1 - i; j++) {
			if (strncmp(netfilm[j].name, netfilm[j+1].name, 5) > 0) {       
				swap(netfilm[j], netfilm[j + 1]);
			}
		}
	}
	
	// Data yang sudah disorting
	cout << "\nN E T F I L M  C O N T E N T  K A T A L O G" << endl;
	cout << setfill('-') << setw(72) << "" << setfill(' ') << endl;
	cout << setw(6) << " ID " << setw(24) << " JUDUL FILM " << setw(16) << " LISENSI " << setw(16) << " TAHUN " << setw(16) << " RATING " << endl;
	cout << setfill('-') << setw(72) << "" << setfill(' ') << endl;
	
	for(int j = 0; j < i; j++) {
		cout << "[" << id++ << "]" << setw(3)  << " ";
		cout << setw(24) << netfilm[j].name << " ";
		cout << setw(15) << netfilm[j].price << " ";
		cout << setw(16) << netfilm[j].year << " ";
		cout << setw(15) << netfilm[j].rating << " ";
		cout << endl;
	}
	cout << setfill('-') << setw(72) << "" << setfill(' ') << endl;
	cout << "[!] Katalog berhasil diurutkan sesuai abjad (A-Z)" << endl;
	fclose(fptr);
}

void linearSearch() {
	char keyword[100];
	int i = 0, j = 0;
	bool found = false;
	
	if (jumlahData < 30) { // Syarat untuk melakukan linear search
		// Membuka file data film
		FILE *fptr;
		fptr =  fopen("netfilm_db.txt", "r");
		if (fptr == NULL) {
			cout << "\nData masih kosong, silakan input terlebih dahulu" << endl;
			return;
		}
		//Membaca data film awal hingga akhir
		while (fscanf(fptr, " %[^;];%lf;%d;%lf\n", netfilm[i].name, &netfilm[i].price,&netfilm[i].year, &netfilm[i].rating) != EOF) {
			i++;
		}
		
		cout << "\nKeyword judul: ";
		cin.ignore();
		cin.getline(keyword, 100);
		
		while (j < jumlahData && !found) {
			if (strncmp(netfilm[j].name, keyword, 100) == 0) {
				found = true;
				break;
			}
			j++;
		}
			
		if (found) {
			cout << "[ FOUND ] " << netfilm[j].name << " (" << netfilm[j].year << ")" << endl; 
		}
		else {
			cout << "[ NOT FOUND ]" << endl;
		}
		fclose(fptr);
	}
	else {
		cout << "\nData terlalu banyak, silakan gunakan binary search." << endl;
	}
}

void binarySearch() {
	char keyword[100];
	int i = 0, awal, tengah, akhir;
	bool found = false;
	
	if (jumlahData >= 30) { // Syarat untuk melakukan binary search
		// Membuka file data film
		FILE *fptr;
		fptr =  fopen("netfilm_db.txt", "r");
		if (fptr == NULL) {
			cout << "\nData masih kosong, silakan input terlebih dahulu" << endl;
			return;
		}
		//Membaca data film awal hingga akhir
		while (fscanf(fptr, " %[^;];%lf;%d;%lf\n", netfilm[i].name, &netfilm[i].price,&netfilm[i].year, &netfilm[i].rating) != EOF) {
			i++;
		}
		
		// Sorting data sebelum melakukan binary search
		for (int i = 0; i < jumlahData - 1; i++) {
			for (int j = 0; j < jumlahData - 1 - i; j++) {
				if (strncmp(netfilm[j].name, netfilm[j+1].name, 5) > 0) {       
					swap(netfilm[j], netfilm[j + 1]);
				}
			}
		}
		
		cout << "\nKeyword judul: ";
		cin.ignore();
		cin.getline(keyword, 100);
		
		awal = 0;
		akhir = jumlahData - 1;
		
		
		while (!found && awal <= akhir) {
			tengah = (awal + akhir) / 2;
			if (strncmp(netfilm[tengah].name, keyword, 100) == 0) {
				found = true;
			} 
			else if (strncmp(keyword, netfilm[tengah].name, 100) < 0) {
				akhir = tengah - 1;
			} 
			else if (strncmp(keyword, netfilm[tengah].name, 100) > 0) {
				awal = tengah + 1;
			}
		}
		if (found) {
			cout << "[ FOUND ] " << netfilm[tengah].name << " (" << netfilm[tengah].year << ")" << endl; 
		}
		else {
			cout << "[ NOT FOUND ]" << endl;
		}
		fclose(fptr);
	}
	else {
		cout << "\nJumlah data tidak memenuhi syarat, silakan untuk dapat menggunakan linear search." << endl;
	}
}

void tambahFilm() {
	int i = 0;
	FILE *fptr;
	fptr = fopen ("netfilm_db.txt","a"); //File untuk struct data film 
	FILE *fcount;
	fcount = fopen("jumlahdata.txt", "w"); //File untuk jumlah data atau total array film
	if (fptr == NULL){
	  cout << "Error opening file." << endl;
	  exit (1);
	}
	
	//Input data film
	cout << "\nInput Judul : ";
	cin.ignore();
	cin.getline(netfilm[i].name, 100);
	cout << "Input Harga : ";
	cin >> netfilm[i].price;
	cout << "Input Tahun : ";
	cin >> netfilm[i].year;
	cout << "Input Rating: ";
	cin >> netfilm[i].rating;
	cin.ignore();
	fprintf(fptr, "%s;%.0lf;%d;%.1lf\n", netfilm[i].name, netfilm[i].price, netfilm[i].year, netfilm[i].rating);
	i++;
	
	//Menyimpan jumlah data atau total array film ke dalam file
	jumlahData++;
	fprintf(fcount, "%d", jumlahData); 
	
	cout << "[ SUCCESS ] Data berhasil disinkronkan ke netfilm_db.txt" << endl;
	cout << "[ SUCCESS ] Film ditambahkan." << endl;
	fclose(fptr);
}


