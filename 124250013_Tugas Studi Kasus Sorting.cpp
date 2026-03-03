#include <iostream>
using namespace std;

void tampilData(string namaMhs[], int size);
void bubbleSort(string namaMhs[], int size);
void quickSort(string namaMhs[], int awal, int akhir);

int main()
{
	int n = 4, opsi, num = 1;
	string namaMhs[n];
	bool sorting = false;
	
	cout << "Selamat datang di program Sorting!" << endl;
	cout << "Silakan input nama: " << endl;
	for (int i = 0; i < n; i++) {
		cout << num << ". ";
		getline(cin, namaMhs[i]);
		num++;
	}
	cout << "\nList nama sebelum disorting: " << endl; 
	tampilData(namaMhs, n);
	
	while (!sorting) {		
		cout << "\nPilih opsi sorting di bawah ini:" << endl;
		cout << "1. Bubble Sort" << endl;
		cout << "2. Quick Sort" << endl;
		char pilihan;
		cout << ">> ";
		cin >> opsi;
		switch (opsi) {
			case 1:
				bubbleSort(namaMhs, n);
					
				cout << "\nList nama setelah disorting (Bubble Sort): " << endl; 
				tampilData(namaMhs, n);
					
				cout << "Ingin mengganti sorting? (Y/N) : ";
				cin >> pilihan;				
				if (toupper(pilihan == 'y')) {						
					sorting = false;
				}
				else if (toupper(pilihan == 'n')) {					
					sorting = true;
				}
					
				break;
			case 2:									
				quickSort(namaMhs, 0, n-1);
					
				cout << "\nList nama setelah disorting (Quick Sort): " << endl; 
				tampilData(namaMhs, n);
										
				cout << "Ingin mengganti sorting? (Y/N) : ";
				cin >> pilihan;				
				if (toupper(pilihan == 'y')) {						
					sorting = false;
				}
				else if (toupper(pilihan == 'n')) {					
					sorting = true;
				}					
				break;
			default:
				cout << "Input salah, silakan ulang" << endl;
		}
	}
	cout << "\nTerima kasih telah menggunakan program ini!" << endl;
}

void tampilData(string namaMhs[], int size) {
	int num = 1;
	for (int i = 0; i < size; i++) {
		cout << num << ". ";
		cout << namaMhs[i] << endl;
		num++;
	}
}

void bubbleSort(string namaMhs[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (namaMhs[j] > namaMhs[j + 1]) {       
				swap(namaMhs[j], namaMhs[j + 1]);
			}
		}
	}
}

void quickSort(string namaMhs[], int awal, int akhir) {
    int low = awal, high = akhir;
    string pivot = namaMhs[(awal + akhir) / 2];

    do {
        while (namaMhs[low] < pivot)
            low++;
        while (namaMhs[high] > pivot)
            high--;

        if (low <= high) {
            swap(namaMhs[low], namaMhs[high]);
            low++;
            high--;
        }
        
    } while (low <= high);

    if (awal < high)
        quickSort(namaMhs, awal, high);

    if (low < akhir)
        quickSort(namaMhs, low, akhir);
}

