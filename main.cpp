#include "Ogrenci.h"
#include <list>



void showMenu() {
	cout << "* * * * * * * * * * * * * *\n";
	cout << "*                         *\n";
	cout << "*           MENU          *\n";
	cout << "*                         *\n";
	cout << "* * * * * * * * * * * * * *\n";
	cout << "1.Yeni kayit ekle \n";
	cout << "2.Tum listeyi goster \n";
	cout << "3.Ogrenci kayit sil \n";
	cout << "4.Ogrenci ara\n";
	cout << "5.Cikis\n\n ";
}

void ogrenciEkle(list<Ogrenci> *lst) {
	float id, sinavNot;
	string ad,soyad,isim;
	cout << "Lutfen ogrenci numarasini giriniz: ";
	cin >> id;
	cout << "Ogrenci adini ve soyadini giriniz: ";
	cin >> ad >> soyad;
	isim = ad + " " + soyad;
	cout << "Sinav notunu giriniz: ";
	cin >> sinavNot;
	Ogrenci ogr(id, isim, sinavNot);
	lst->push_back(ogr);
}


void showList(list<Ogrenci> * lst) {
	list<Ogrenci>::iterator itr;
	cout << endl << "- - - - - - - - - TUM OGRENCI LISTESI - - - - - - - - -\n";
	for (itr = lst->begin(); itr != lst->end(); itr++) {
		itr->bilgileriYaz();
	}
	cout << endl;
}

void ogrenciSil(list<Ogrenci> * lst) {
	int id;
	cout << "Lutfen kaydi silinecek ogrencinin okul numarasini giriniz: ";
	cin >> id;
	list<Ogrenci>::iterator itr;
	for (itr = lst->begin(); itr != lst->end(); itr++) {
		if (itr->getId() == id)
			break;
	}

	if (itr == lst->end())
		cout << "Kayit bulunamadi,Silme islemi basarisiz!";
	else
		lst->erase(itr);
}

void ogrenciAra(list<Ogrenci>*lst) {
	int id;
	cout << "Lutfen aranacak ogrencinin okul numarasini giriniz: ";
	cin >> id;
	cout << endl;
	list<Ogrenci>::iterator itr;
	for (itr = lst->begin(); itr != lst->end(); itr++) {
		if (itr->getId() == id)
			break;
	}

	if (itr == lst->end())
		cout << "Kayit bulunamadi!!\n\n";
	else {
		cout << "- - - - - - - ARADIGININIZ OGRENCININ BILGILERI- - - - - - - \n";
		itr->bilgileriYaz();
		cout << endl;
	}
}

int main() {
	list<Ogrenci>* ogrencilist = new list<Ogrenci>();

	int secim = 0;
	do{
		showMenu();
		cout << "Seciminiz: ";
		cin >> secim;
		if (secim == 1)
			ogrenciEkle(ogrencilist);
		else if (secim == 2)
			showList(ogrencilist);
		else if (secim == 3)
			ogrenciSil(ogrencilist);
		else if (secim == 4)
			ogrenciAra(ogrencilist);
		else if (secim == 5)
			break;
		else
			cout << "Hatali secim yaptiniz,Lutfen tekrar deneyiniz!";
	} while (secim != 5);
		system("cls");
	return 0;
}