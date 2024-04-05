#include "Ogrenci.h"

Ogrenci::Ogrenci(int _id, string _ad, int _sinavNot) {
	id = _id;
	ad = _ad;
	sinavNot = _sinavNot;
}

void Ogrenci::setId(int _id) {
	id = _id;
}

int Ogrenci::getId() {
	return id;
}

void Ogrenci::setAd(string _ad) {
	ad = _ad;
}

string Ogrenci::getAd() {
	return ad;
}

void Ogrenci::setsinavNot(int _sinavNot) {
	sinavNot = _sinavNot;
}

int Ogrenci::getsinavNot() {
	return sinavNot;
}

void Ogrenci::bilgileriYaz() {
	cout << "Ogrenci Numarasi:" << id << "       Ad Soyad:" << ad << "       " << "Sinav Notu:" << sinavNot << endl;
}