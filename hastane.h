#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Hastane{
	protected:
		string tc, tc2;
	public:
		void Metin();
		string hastaAd, hastaSoyad,telefon,randevuTarih,bolum,doktor,saat,belirti,sigorta;
		int yas,secim,silme,fiyat;
		char cinsiyet,sart='E';
		char anamenu;
};
class Giris:public Hastane{
	public:
		Giris();	 
};
class HastaKayit:public Giris{
	public:
	void Metin();
	HastaKayit();
};
class HastaSilme:public HastaKayit{
	public:
		void Metin();
		HastaSilme();		
};
class HastaDosyaSilme:public HastaSilme{
	private:
		string yanit;
	public:
		void setYanit();
		string getYanit();
		HastaDosyaSilme();
};
class Randevu:public HastaDosyaSilme{
	public:
		void Metin();
		Randevu();
};
class Liste:public Randevu{
	protected: 
	string a;
	public:
		void Metin();
		Liste();
};
class Asi:public Liste{
	protected:
		string asiCevap;
	public:
		void Metin();
		Asi();
};
class CovidTest:public Asi{
	public:
		void Metin();
		CovidTest();
};
class TestSonuc:public CovidTest{
	public:
		int random;
		void Metin();
		TestSonuc();
};
class Fatura:public TestSonuc{
	public:
		void Metin();
		Fatura();
};
class AnaMenu:public Fatura{
	public:
		AnaMenu();		
};

