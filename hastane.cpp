#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "hastane.h"

using namespace std;

void Hastane::Metin(){
	cout << "\t\tPICAKCI HASTANESINE HOSGELDINIZ!" << endl;
}
Giris::Giris(){
		cout << "---------------------------------------------------------------" << endl;
		cout << "1-Hasta Kayit\n2-Hasta Silme\n3-Hasta Listesi\n4-Randevu Alma\n5-Covid-19 Asisi\n6-Covid-19 Test Yaptirma\n7-Covid-19 Test Sonucu Ogrenme\n8-Fatura\n9-Hasta Kayit Dosyasini Silme(Dikkat Tum Hastalarin Listesini Temizler!)" << endl;
		cout << "Lutfen Yapilacak Islemi Numaralandirma Yoluyla Seciniz: ";
		cin >> secim;
		cout << "\n---------------------------------------------------------------\n" << endl;	
}
void HastaKayit::Metin(){
	cout << "\t\tHASTA KAYIT MENUSU" << endl;
}
HastaKayit::HastaKayit(){
	switch(secim){
	case 1:
		Metin();
		do{
		ofstream dosya;
		dosya.open("list.txt",ios::app);
		cout << "Hasta Adi = ";
		cin >> hastaAd;
		cout << "Hasta Soyadi = ";
		cin >> hastaSoyad;
		cout << "Hasta T.C Kimlik Numarasi = ";
		cin >> tc;
		cout << "Hasta Yasi = ";
		cin >> yas;
		cout << "Cinsiyet (E/K) = ";
		cin >> cinsiyet;
		cout << "Hasta Iletisim Bilgileri = ";
		cin >> telefon;
		dosya << hastaAd << " " << hastaSoyad << " " << tc << " " << yas << " " << cinsiyet << " " << telefon << endl;
		cout << "Baska bir kayit yapacak misiniz?(E/H)" << endl;
		cin >> sart;
		dosya.close();
		}
		while(sart=='E');
		cout << "Hasta kaydi tamamlandi!" << endl;
		break;
		}
}
void HastaSilme::Metin(){
	cout << "\t\tHASTA SILME MENUSU" << endl;
}
HastaSilme::HastaSilme(){
	switch(secim){
				case 2:
					Metin();
					cout << endl;
					while (sart='E'){
			string dizi[] = {"1-Onur Picakci","\n2-Osman Bulut","\n3-Sema Polat","\n4-Leyla Aslan","\n5-Ali Atilgan\n","6-Zeki Yoruk\n","7-Eslem Kocak\n","8-Beyza Onaran\n","9-Yusuf Bucak"};
			for(int a=0;a<9;a++){
				cout << dizi[a];
			}
			cout << "\nSilmek istediginiz hastanin numarasini giriniz:";
			cin >> silme;
			cout << endl;
			for(int i=0;i<1;i++){
				cout << dizi[silme-1] << " hastasi sistemden silindi...";
				
			}	
			cout << "\nBaska bir silme islemi yapmak ister misiniz?(E/H)" << endl;
			cin >> sart;	
		if(sart == 'E' ||sart == 'e'){		
		}
		else{
			break;
			}
		}
			}
}
void HastaDosyaSilme::setYanit(){
	string answer;
	yanit = answer;
}
string HastaDosyaSilme::getYanit(){
	return yanit;
}
HastaDosyaSilme::HastaDosyaSilme(){
	switch(secim){
		case 9:	
			cout << "Silmek istediginize emin misiniz?(Evet/Hayir): ";
			cin >> yanit;
			if(yanit == "Evet" || yanit == "evet"){
			silme = remove("list.txt");
			if(silme==0){
				cout << "Dosya silindi";
			}
			else{
				cout << "Dosya silinmedi";
					}
				}
			
			break;
		}
}
void Randevu::Metin(){
	cout << "\t\tRANDEVU MENUSU\n" << endl;
}
Randevu::Randevu(){
	switch(secim){
				case 4:	
				Metin();
				cout << "Randevu alacaginiz hastanin TC kimlik numarasini giriniz = ";
				cin >> tc2;
				ifstream randevu("list.txt"); 
 				while(!randevu.eof()){
 					randevu >> hastaAd >> hastaSoyad >> tc >> yas >> cinsiyet >> telefon;
 					if(tc2==tc){
 						cout << "Adi = " << hastaAd << endl; 
 						cout << "Soyadi = " << hastaSoyad <<endl;
						cout << "TC no = " << tc << endl;  
 						cout << "Yasi = " << yas << endl; 
 						cout << "Cinsiyeti = " << cinsiyet << endl; 
 						cout << "Telefonu = " << telefon << endl; 
 						
						cout << "Randevu almak istiyor mu? (E/H)"<<endl; 
 						cin >> sart; 
 						if(sart == 'e' || sart == 'E'){
 							randevu.close();
 							ofstream randevuYaz;
 							randevuYaz.open("Randevu.txt",ios::app);
 							cout << "-------Hastane Bolumleri--------\n\n1-Agiz\n2-Dahiliye\n3-Cildiye\n4-Dermatoloji\n5-Uroloji\n6-Kardiyoloji\n7-Noroloji\n8-Ortopedi\n9-Psikoloji\n" << endl;
 							cout << "Bolum = ";
 							cin >> bolum;
 							if(bolum=="agiz" || bolum=="dahiliye" || bolum=="Agiz" || bolum=="Dahiliye"){
 								fiyat = 100;			
							 }
							 if(bolum=="cildiye" || bolum=="dermatoloji" || bolum=="uroloji" || bolum=="Cildiye" || bolum=="Dermatoloji" || bolum=="Uroloji"){
 								fiyat = 150;
							 }
							 if(bolum=="kardiyoloji" || bolum=="noroloji" || bolum=="ortopedi" || bolum=="psikoloji" || bolum=="Kardiyoloji" || bolum=="Noroloji" || bolum=="Ortopedi" || bolum=="Psikoloji"){
 								fiyat = 250;
							 }
 							cout << "Randevu Tarihi = ";
 							cin >> randevuTarih;
 							cout << "Randevu Saati = ";
 							cin >> saat;
 							cout << "Muayene Ucreti = " << fiyat << endl;
 							cout << "Randevunuz olusturulmustur.\n\n-------Randevu Bilgileri-------\n\n";
 							cout << "Bolum = " << bolum << "\nRandevu Tarih = " << randevuTarih << "\nRandevu Saati = " << saat << "\nMuayene Ucreti = " << fiyat << endl;  
 							cout << " " << endl;
 							randevuYaz << tc <<" "<< randevuTarih<<" " << saat << " "<< bolum <<" "<< fiyat << endl;
 							randevuYaz.close();
						 }
						 else {
						 	break;
						 }
						 break;
					 }
				 }
				 if(tc2!=tc){
				 		cout << "\nGirdiginiz tc kimlik numaralari uyusmadi.\nLutfen tekrar deneyiniz...\n" << endl;
					 }	
					 break;
			}
}
void Liste::Metin(){
	cout << "\t\tHASTA LISTESI\n" << endl;
}
Liste::Liste(){
	switch(secim){
				case 3:
					Metin();
					ifstream listOku("list.txt",ios::in);
					if(listOku.is_open()){
						while(getline(listOku,a)){
							cout << a << endl;
						}
					}
					listOku.close();
				break;
			}
}
void Asi::Metin(){
	cout << "\t\tASI MENUSU\n" << endl;
}
Asi::Asi(){
	switch(secim){
			case 5:
				Metin();
					cout << "Asi randevusu alacaginiz kisinin kimlik numarasini giriniz : ";
					cin >> tc2;
					ifstream asi("list.txt");
					while(!asi.eof()){
						asi >> hastaAd >> hastaSoyad >> tc >> yas >> cinsiyet >> telefon;
						if(tc2==tc){
							int asisec;
							cout << "Adi = " << hastaAd << endl; 
 							cout << "Soyadi = " << hastaSoyad << endl;
							cout << "TC no = " << tc << endl;  
 							cout << "Yasi = " << yas << endl; 
 							cout << "Cinsiyeti = " << cinsiyet << endl; 
 							cout << "Telefonu = " << telefon << endl; 
 							cout << "\n--------------------------\n";
 							cout << "1-Turkovac\n2-Biontech\n3-Sinovac"	<< endl;
 							cout << tc <<" kimlik numarali hastamiz " << hastaAd <<" "<< hastaSoyad << " lutfen hangi asiyi olmak istediginizi seciniz:(1/2/3) ";
 							cin >> asisec;
 							if(asisec == 1){
 								cout << "Asi olmak istediginize dair sozlesmeyi onayliyor musunuz?(Onayliyorum/Onaylamiyorum): ";
 								cin >> asiCevap;
 								if(asiCevap == "Onayliyorum")
 								cout << "Onayiniz alindi. Turkovac asisi icin 1 numarali asi odamiza geciniz..." << endl;
							 }
						 	if(asisec == 2){
						 		cout << "Asi olmak istediginize dair sozlesmeyi onayliyor musunuz?(Onayliyorum/Onaylamiyorum): ";
 								cin >> asiCevap;
 								if(asiCevap == "Onayliyorum")
 								cout << "Onayiniz alindi. Biontech asisi icin 2 numarali asi odamiza geciniz..." << endl;
							 }
						 	if(asisec == 3){
						 		cout << "Asi olmak istediginize dair sozlesmeyi onayliyor musunuz?(Onayliyorum/Onaylamiyorum): ";
 								cin >> asiCevap;
 								if(asiCevap == "Onayliyorum")
 								cout << "Onayiniz alindi. Sinovac asisi icin 3 numarali asi odamiza geciniz..." << endl;
							 }
						 break;		
					}		
				}
				asi.close();
		break;
				
		}
}
void CovidTest::Metin(){
	cout << "\t\tCOVID-19 TESTI\n" << endl;
}
CovidTest::CovidTest(){
	switch(secim){
				case 6: 
				Metin();
					cout << "Covid-19 testi yaptiracaginiz kisinin kimlik numarasini giriniz : ";
					cin >> tc2;
					ifstream test("list.txt");
					while(!test.eof()){
						test >> hastaAd >> hastaSoyad >> tc >> yas >> cinsiyet >> telefon;
						if(tc2==tc){
							cout << " " << endl;
 							cout << "Sayin " << hastaAd << " " << hastaSoyad <<" lutfen belirtinizi giriniz (Oksurek/Ates/Agri/Halsizlik/Tat/Koku): ";
 							cin >> belirti;
 							if(belirti == "Oksurek" || belirti == "Ates" || belirti == "Agri" || belirti == "Halsizlik" || belirti == "Tat" || belirti == "Koku"){
 								test.close();
 								ofstream testYap;
 								testYap.open("covidtest.txt",ios::app);
 								cout << "Covid-19 testinizi yaptirdiniz. Test sonuclarinizin cikmasi ortalama 8 saattir. Gecmis olsun..." << endl;
 								testYap << tc << " " << hastaAd << " " << hastaSoyad << " " << belirti << " "<< endl;
 								testYap.close();
							 }
							 break;
 						}
 					}
 				break;
			}
}
void TestSonuc::Metin(){
	cout << "\t\tTEST SONUC MENUSU\n" << endl;
}
TestSonuc::TestSonuc(){
	switch(secim){
				case 7: 
				Metin();
				srand(time(NULL));
				cout << "Covid-19 test sonucu icin kimlik numarasi giriniz : ";
					cin >> tc2;
					cout << " " << endl;
					ifstream sonuc("covidtest.txt");
					while(!sonuc.eof()){
						sonuc >> tc >> hastaAd >> hastaSoyad >> belirti;
						if(tc2==tc){
 							random = rand () % 2;
 							if(random==0)
 							cout << tc << " kimlik numarali hasta " << hastaAd << " " <<  hastaSoyad <<" Covid-19 test sonucu = Negatif" << endl;
 							if(random==1)
								cout << tc << " kimlik numarali hasta " << hastaAd << " " <<  hastaSoyad << " Covid-19 test sonucu = Pozitif" << endl;
								cout << "7 Gunluk izolasyona alindiniz. Lutfen kendinizi eve kapatip ekiplerimizin sizinle iletisim kurmasini bekleyiniz... " << endl;
							 break;
 						}
 					}
 				sonuc.close();
 			break;			
		}
}
void Fatura::Metin(){
	cout << "\t\tFATURA\n" << endl;
}
Fatura::Fatura(){
	switch(secim){
				case 8:
					Metin();
					cout << "Faturasini almak istediginiz kisinin kimlik numarasini giriniz : ";
					cin >> tc2;
					ifstream fatura("Randevu.txt");
					while(!fatura.eof()){
						fatura >> tc >>	randevuTarih >> saat >> bolum >> fiyat;
						if(tc2==tc){
							cout << "Tc = " << tc << endl;
							cout << "Randevu alinan bolum =  " << bolum << endl;
							cout << "Sigortaniz var mi?(Evet/Hayir): ";
							cin >> sigorta;
							if(sigorta == "Evet" || sigorta == "evet"){
							cout << "\nSigortanizdan dolayi yapilan %80 indirimle odemeniz gereken tutar = " << fiyat - (fiyat*80/100) << " TL" << endl;
							}
							else{
								cout << "Odemeniz gereken tutar = " << fiyat << " TL"<< endl;
							}	
							break;
 						}
 					}
				break;	
			}
}
AnaMenu::AnaMenu(){
	for(int i=0;i<5;i++){
					cout << "\nAna Menuye donmek ister misiniz? (E/H): ";
					cin >> anamenu;
					cout << "\n\n\n" << endl;
					if(anamenu=='E' || anamenu=='e'){
						Hastane a;
						a.Metin();
						Fatura();
						i=0;
					}
					else{
						cout << "\n\nOtomasyon kapatildi!" << endl;
						break;
					}
				}
}


