//AmiralBatti v1.7
//Sakarya �niversitesi Teknoloji Fak�ltesi Bilgisayar M�hendisli�i
//II. D�nem Proje �devi
//Bervan Da�l�k
//B130910021

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <clocale>
#include <time.h>
#include <Windows.h>


using namespace std;

char oyuncu_tahta[10][10],pc_tahta[10][10],atis_oy_tahta[10][10],atis_pc_tahta[10][10];
int amiral_sayac_o,amiral_sayac_p;

struct Gemi
{
	int x[6],y[6];
}A_O,D1_O,D2_O,F1_O,F2_O,F3_O,H1_O,H2_O,H3_O,H4_O,A_P,D1_P,D2_P,F1_P,F2_P,F3_P,H1_P,H2_P,H3_P,H4_P;

void oyun_kayit(){
	system("cls");

	int gemiuzunluk[10] ={6,4,4,3,3,3,2,2,2,2};
	int *gemi_x_pc[10] ={A_P.x,D1_P.x,D2_P.x,F1_P.x,F2_P.x,F3_P.x,H1_P.x,H2_P.x,H3_P.x,H4_P.x};
	int *gemi_y_pc[10] ={A_P.y,D1_P.y,D2_P.y,F1_P.y,F2_P.y,F3_P.y,H1_P.y,H2_P.y,H3_P.y,H4_P.y};
	int *gemi_x_oy[10] ={A_O.x,D1_O.x,D2_O.x,F1_O.x,F2_O.x,F3_O.x,H1_O.x,H2_O.x,H3_O.x,H4_O.x};
	int *gemi_y_oy[10] ={A_O.y,D1_O.y,D2_O.y,F1_O.y,F2_O.y,F3_O.y,H1_O.y,H2_O.y,H3_O.y,H4_O.y};
	char oyun_ismi[50]={NULL},tempisim[20];
	cout<<"Oyununuzu kaydetmek i�in bir isim giriniz :";gets_s(tempisim);	//Her Kayd� Farkl� bir metin dosyas�na kaydeder
	strcat_s(oyun_ismi,"kayitli_oyunlar\\");
	strcat_s(oyun_ismi,tempisim);				//String ekleme i�lemi ile dosya yolu kaydedilir..
	strcat_s(oyun_ismi,".txt");

	FILE *dosyaPtr;
	dosyaPtr=fopen(oyun_ismi,"w");
	if(dosyaPtr==NULL)
		cout<<"Dosya A��lamad�\n";
	else{
		fprintf(dosyaPtr,"%d\n",amiral_sayac_o);		//Amiral Gemilerinin Saya�lar�n� Dosyaya kaydeder..
		fprintf(dosyaPtr,"%d\n",amiral_sayac_p);
		for(int i=0;i<10;i++){							//Oyun Tahtalar�n� Dosyaya S�ral� bir �ekilde Kaydeder..
			for(int j=0;j<10;j++)
				fprintf(dosyaPtr,"%c",oyuncu_tahta[i][j]);
			fprintf(dosyaPtr,"\n");
		}
		fprintf(dosyaPtr,"\n");
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++)
				fprintf(dosyaPtr,"%c",pc_tahta[i][j]);
			fprintf(dosyaPtr,"\n");
		}
		fprintf(dosyaPtr,"\n");
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++)
				fprintf(dosyaPtr,"%c",atis_oy_tahta[i][j]);
			fprintf(dosyaPtr,"\n");
		}
		fprintf(dosyaPtr,"\n");
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++)
				fprintf(dosyaPtr,"%c",atis_pc_tahta[i][j]);
			fprintf(dosyaPtr,"\n");
		}

		for(int i=0;i<10;i++){				//Oyuncu Gemilerinin x,y koordinatlar�n�n t�m�n� kaydeder..
			for(int j=0;j<gemiuzunluk[i];j++){
				fprintf(dosyaPtr,"%d,%d;",*(gemi_x_oy[i]+j),*(gemi_y_oy[i]+j));
			}
			fprintf(dosyaPtr,"\n");
		}


		for(int i=0;i<10;i++){				//Bilgisayar Gemilerinin x,y koordinatlar�n�n t�m�n� kaydeder..
			for(int j=0;j<gemiuzunluk[i];j++){
				fprintf(dosyaPtr,"%d,%d;",*(gemi_x_pc[i]+j),*(gemi_y_pc[i]+j));
			}
			fprintf(dosyaPtr,"\n");
		}


		}
	fclose(dosyaPtr);
}

void oyun_yukle(){

	system("cls");

	int gemiuzunluk[10] ={6,4,4,3,3,3,2,2,2,2};
	int *gemi_x_pc[10] ={A_P.x,D1_P.x,D2_P.x,F1_P.x,F2_P.x,F3_P.x,H1_P.x,H2_P.x,H3_P.x,H4_P.x};
	int *gemi_y_pc[10] ={A_P.y,D1_P.y,D2_P.y,F1_P.y,F2_P.y,F3_P.y,H1_P.y,H2_P.y,H3_P.y,H4_P.y};
	int *gemi_x_oy[10] ={A_O.x,D1_O.x,D2_O.x,F1_O.x,F2_O.x,F3_O.x,H1_O.x,H2_O.x,H3_O.x,H4_O.x};
	int *gemi_y_oy[10] ={A_O.y,D1_O.y,D2_O.y,F1_O.y,F2_O.y,F3_O.y,H1_O.y,H2_O.y,H3_O.y,H4_O.y};
	char oyun_ismi[50]={NULL},tempisim[20],deneme;
	cout<<"Kay�tl� oyun ismi giriniz :";gets_s(tempisim);
	strcat_s(oyun_ismi,"kayitli_oyunlar\\");
	strcat_s(oyun_ismi,tempisim);
	strcat_s(oyun_ismi,".txt");

	FILE *dosyaPtr;
	dosyaPtr=fopen(oyun_ismi,"r");
	if(dosyaPtr==NULL){
		cout<<"Dosya a��lamad� tekrar giri� yap�n�z\n";		// Yanl�� giri� durumunda recursive fonksiyonla tekrar giri� ister..
		_getch();
		oyun_yukle();
	}
	else{
		fscanf(dosyaPtr,"%d\n",&amiral_sayac_o);	//Amiral Gemisi Saya�lar�n� dosyadan �eker
		fscanf(dosyaPtr,"%d\n",&amiral_sayac_p);

		for(int i=0;i<10;i++){				//Oyun Tahtalar�n� Dosyadan �ekip Dizilere yerle�tirir
			for(int j=0;j<10;j++)
				fscanf(dosyaPtr,"%c",&oyuncu_tahta[i][j]);
			fscanf(dosyaPtr,"\n");
		}
		fscanf(dosyaPtr,"\n");

		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++)
				fscanf(dosyaPtr,"%c",&pc_tahta[i][j]);
			fscanf(dosyaPtr,"\n");
		}
		fscanf(dosyaPtr,"\n");

		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++)
				fscanf(dosyaPtr,"%c",&atis_oy_tahta[i][j]);
			fscanf(dosyaPtr,"\n");
		}
		fscanf(dosyaPtr,"\n");

		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++)
				fscanf(dosyaPtr,"%c",&atis_pc_tahta[i][j]);
			fscanf(dosyaPtr,"\n");
		}

		for(int i=0;i<10;i++){			//Oyuncu Gemi Koordinatlar�n� �eker(Puanlama i�in Gerekli)
			for(int j=0;j<gemiuzunluk[i];j++){
				fscanf(dosyaPtr,"%d,%d;",&*(gemi_x_oy[i]+j),&*(gemi_y_oy[i]+j));
			}
			fscanf(dosyaPtr,"\n");
		}


		for(int i=0;i<10;i++){			//Bilgisayar Gemi Koordinatlar�n� �eker(Puanlama i�in Gerekli)
			for(int j=0;j<gemiuzunluk[i];j++){
				fscanf(dosyaPtr,"%d,%d;",&*(gemi_x_pc[i]+j),&*(gemi_y_pc[i]+j));
			}
			fscanf(dosyaPtr,"\n");
		}

	}

}

void tahtaGoster(char tahta[10][10])
{
	for(int i=9;i>=0;i--){
		if(i==9)
			cout<<i+1<<" ";
		else
			cout<<i+1<<"  ";
		for(int j=0;j<10;j++){
			
			cout<<tahta[j][i]<<"   ";
		}
		cout<<endl<<endl;
	}
	cout<<"   ";
	for(int i=1;i<11;i++)
		cout<<i<<"   ";
	cout<<endl<<endl;

}

void cift_tahta_goster(char tahta_o[10][10],char tahta_p[10][10])
{
		cout<<"\tOyuncunun Tahtas�\t\t\t\tBilgisayar�n Tahtas�\n";

	for(int i=9;i>=0;i--){
		if(i==9)
			cout<<i+1<<" ";
		else
			cout<<i+1<<"  ";
		for(int j=0;j<10;j++){
			
			cout<<tahta_o[j][i]<<"   ";
		}
		cout<<"    ";
		
		if(i==9)
			cout<<i+1<<" ";
		else
			cout<<i+1<<"  ";
		for(int j=0;j<10;j++){
			cout<<tahta_p[j][i]<<"   ";
		}
		cout<<endl<<endl;
	}
	cout<<"   ";
	for(int i=1;i<11;i++)
		cout<<i<<"   ";
	cout<<"      ";
	for(int i=1;i<11;i++)
		cout<<i<<"   ";
	cout<<endl<<endl;
}

int koordinat_kontroly(char tahta[10][10],int x1,int y1,int gemiuzunlugu)

{
	int test=1;
	for(int j=0;j<gemiuzunlugu;j++){
		if(tahta[x1][y1+j]!='.')
			test=0;
	}
	return test;
}

int koordinat_kontrolx(char tahta[10][10],int x1,int y1,int gemiuzunlugu)

{
	int test=1;
	for(int j=0;j<gemiuzunlugu;j++){
		if(tahta[x1+j][y1]!='.')
			test=0;
	}
	return test;
}

void Oto_TahtaDoldur(char tahta[10][10])
{
	int x,y,z,test=1;
	int gemiuzunluk[10] ={6,4,4,3,3,3,2,2,2,2};
	char gemisembol[10] ={'A','D','D','F','F','F','H','H','H','H'};
	int *gemi_x[10] ={A_P.x,D1_P.x,D2_P.x,F1_P.x,F2_P.x,F3_P.x,H1_P.x,H2_P.x,H3_P.x,H4_P.x};
	int *gemi_y[10] ={A_P.y,D1_P.y,D2_P.y,F1_P.y,F2_P.y,F3_P.y,H1_P.y,H2_P.y,H3_P.y,H4_P.y};

	//Oyun Tahtas�n� S�f�rlamak i�in
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			tahta[i][j]='.';
	// Gemilerin Yerle�tirilmesi
	for(int i=0;i<10;i++){		//Gemiyi Yatay yada Dikey Yerle�imini rastgele belirler...
		z=rand()%2;
	if(z==0)					//Yatay Yerle�im
		{
			while(true){
			x=rand()%(11-gemiuzunluk[i]);
			y=rand()%10;
			for(int j=0;j<gemiuzunluk[i];j++){		//Girilen Koordinatlar�n Bo� oldu�unu kontrol eder
				if(tahta[x+j][y]!='.')
					test=0;
			}
			if(test==1)
				break;
			test=1;
			}
			for(int k=0;k<gemiuzunluk[i];k++){   	//Gemiyi Yerle�tirir..
				tahta[x][y]=gemisembol[i];
				*(gemi_x[i]+k)=x;*(gemi_y[i]+k)=y;
				x++;
			}
		}
		if(z==1)			//Dikey Yerle�im...
		{
			while(true){
			x=rand()%10;
			y=rand()%(11-gemiuzunluk[i]);
			for(int j=0;j<gemiuzunluk[i];j++){		//Girilen Koordinatlar�n Bo� oldu�unu kontrol eder
				if(tahta[x][y+j]!='.')
					test=0;
			}
			if(test==1)
				break;
			test=1;
			}
			for(int k=0;k<gemiuzunluk[i];k++){		//Gemiyi Yerle�tirir..
				tahta[x][y]=gemisembol[i];
				*(gemi_x[i]+k)=x;*(gemi_y[i]+k)=y;
				y++;
			}
		}


	}

}

void Oto_TahtaDoldur2(char tahta[10][10])
{
	int x,y,z,test=1;
	int gemiuzunluk[10] ={6,4,4,3,3,3,2,2,2,2};
	char gemisembol[10] ={'A','D','D','F','F','F','H','H','H','H'};
	int *gemi_x[10] ={A_O.x,D1_O.x,D2_O.x,F1_O.x,F2_O.x,F3_O.x,H1_O.x,H2_O.x,H3_O.x,H4_O.x};
	int *gemi_y[10] ={A_O.y,D1_O.y,D2_O.y,F1_O.y,F2_O.y,F3_O.y,H1_O.y,H2_O.y,H3_O.y,H4_O.y};

	//Oyun Tahtas�n� S�f�rlamak i�in
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			tahta[i][j]='.';
	// Gemilerin Yerle�tirilmesi
	for(int i=0;i<10;i++){		//Gemiyi Yatay yada Dikey Yerle�imini rastgele belirler...
		z=rand()%2;
	if(z==0)					//Yatay Yerle�im
		{
			while(true){
			x=rand()%(11-gemiuzunluk[i]);
			y=rand()%10;
			for(int j=0;j<gemiuzunluk[i];j++){		//Girilen Koordinatlar�n Bo� oldu�unu kontrol eder
				if(tahta[x+j][y]!='.')
					test=0;
			}
			if(test==1)
				break;
			test=1;
			}
			for(int k=0;k<gemiuzunluk[i];k++){   	//Gemiyi Yerle�tirir..
				tahta[x][y]=gemisembol[i];
				*(gemi_x[i]+k)=x;*(gemi_y[i]+k)=y;
				x++;
			}
		}
		if(z==1)			//Dikey Yerle�im...
		{
			while(true){
			x=rand()%10;
			y=rand()%(11-gemiuzunluk[i]);
			for(int j=0;j<gemiuzunluk[i];j++){		//Girilen Koordinatlar�n Bo� oldu�unu kontrol eder
				if(tahta[x][y+j]!='.')
					test=0;
			}
			if(test==1)
				break;
			test=1;
			}
			for(int k=0;k<gemiuzunluk[i];k++){		//Gemiyi Yerle�tirir..
				tahta[x][y]=gemisembol[i];
				*(gemi_x[i]+k)=x;*(gemi_y[i]+k)=y;
				y++;
			}
		}


	}

}

int koordinat_ayikla(char koordinatChar[],int *sayiDizisi){
	int j=0,ciftsayi,uzunluk;
	char gecici[4];
	uzunluk=strlen(koordinatChar);
	koordinatChar[uzunluk]='!';		//Taramay� Durdurma komutu(Koordinat giri�inin sonuna ekler)
	for(int i=0; i<uzunluk ; i++){
		
		bool kontrol=true;
		int k=0;
		do { 
			
			gecici[k]=koordinatChar[i];
			if(koordinatChar[i+1]=='!')
				break;
			if(koordinatChar[i+1]==',' || koordinatChar[i+1]=='-' ){
				kontrol=false;
			}
			else{
				i++;
				k++;
			}
		}while(kontrol);
		if(k==0){		//Tek basamakl�ysa koordinat� ptr arac�l���yla diziye atar..
			*(sayiDizisi+j)=gecici[0]-49;
			j++;
			i++; // virg�l atlatma
			}
		else if(k==1){		//�ift basamakl�ysa koordinat� ptr arac�l���yla diziye atar..
			ciftsayi=(gecici[0]-48)*10+(gecici[1]-48)*10;
			if(ciftsayi==10){
				*(sayiDizisi+j)=ciftsayi-1;
				j++;
				i++; // virg�l atlatma
			}
			else{	 //say�n�n 10'dan buyuk olmas� durumunda fonksiyonu durdurur..
				return 0;
				}
			}
			
		else		//3 veya daha fazla basamak giri�inde fonksiyonu durdurur..
			return 0;
		
			
	}
	if(j!=4)
		return 2;
	if(*sayiDizisi!=*(sayiDizisi+2) && *(sayiDizisi+1)!=*(sayiDizisi+3))
		return 2;
	koordinatChar[uzunluk]=NULL;
	return 1;
}

int karakter_engelle(int girisuzunlugu,char koordinat_giris[])
{
	int test=0;
	for(int b=0;b<girisuzunlugu;b++){
			if(koordinat_giris[b]>47 && koordinat_giris[b]<58 || koordinat_giris[b]==',' || koordinat_giris[b]=='-')
				test=1;
			else 
				test=0;
		}
	return test;
}

void Manuel_TahtaDoldur(char oyuncu_tahta[10][10])
{
	int *gemi_x[10] ={A_O.x,D1_O.x,D2_O.x,F1_O.x,F2_O.x,F3_O.x,H1_O.x,H2_O.x,H3_O.x,H4_O.x};
	int *gemi_y[10] ={A_O.y,D1_O.y,D2_O.y,F1_O.y,F2_O.y,F3_O.y,H1_O.y,H2_O.y,H3_O.y,H4_O.y};
	int gemi_uzunluk[10]={6,4,4,3,3,3,2,2,2,2};
	char gemi_ismi[10][10]={"Amiral","Destroyer","Destroyer","Firkateyn","Firkateyn","Firkateyn","H�cum Bot","H�cum Bot","H�cum Bot","H�cum Bot"};
	char gemi_simge[11]={"ADDFFFHHHH"};


	//Oyun Tahtas�n� S�f�rlamak i�in

	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			oyuncu_tahta[i][j]='.';

	char koordinat_giris[15]={};
	int test,girisuzunlugu,koordinatlar[4];
	int *koordinatPtr=koordinatlar;


	//Gemileri yerle�tirme...

	for(int gemi_sirasi=0;gemi_sirasi<10;gemi_sirasi++){
		while(true){
			test=1;
				system("cls");
				tahtaGoster(oyuncu_tahta);
				cout<<"Gemileri Yerle�tiriniz..."<<endl;
				cout<<"�rnek : 1,1-1,"<<gemi_uzunluk[gemi_sirasi]<<" (�lk ve Son Noktalar�n� Giriniz)"<<endl;
				cout<<"\n-------------------------------------------------\n";
				cout<<gemi_ismi[gemi_sirasi]<<" Gemisini Yerle�tiriniz:";
				gets_s(koordinat_giris);

				if(koordinat_giris[0]=='\0')
					continue;
				girisuzunlugu=strlen(koordinat_giris);
				test=karakter_engelle(girisuzunlugu,koordinat_giris);  //Say�lar ',' ve '-' d���nda karakter giri�ini engeller...
				if(test==0){
					system("cls");
					cout<<"Hatal� giri� yap�ld� tekrar deneyiniz..\n";
					continue;
				}
				test=koordinat_ayikla(koordinat_giris,koordinatPtr);		//Girilen Koordinat� ',' ve '-' ay�klay�p diziye par�alar..
																			//koordinatlar[] dizisindeki de�erler s�ras�yla --> x1,y1,x2,y2 �eklinde ay�klan�r ;)
				
				if(koordinatlar[0]<0 || koordinatlar[1]<0 || koordinatlar[2]<0 || koordinatlar[3]<0 || test==0  || test==2 ){    
					system("CLS");								//Koordinatlar�n 1-10 aras�nda giri�ini sa�lar..
					cout<<"Hatal� giri� yap�ld� tekrar deneyiniz..\n";
					continue;
				}												


				//Geminin Dikey yerle�me durumu
				if(koordinatlar[0]==koordinatlar[2]){
					if(koordinatlar[3]-koordinatlar[1]!=(gemi_uzunluk[gemi_sirasi]-1)){
						system("CLS");
						cout<<"Hatal� giri� yap�ld� tekrar deneyiniz..\n";
						continue;
					}
						test=koordinat_kontroly(oyuncu_tahta,koordinatlar[0],koordinatlar[1],gemi_uzunluk[gemi_sirasi]);		//Girilen Koordinatlar�n bo� olup olmad���na bakar..
						if(test==0){
							system("CLS");
							cout<<"Girilen Koordinatta Yerle�tirilmi� gemi var!!!\nYeni koordinat giriniz..\n";
							continue;
					}

					//Tahtaya gemiyi yerle�tirir.
					for(int i=0;i<gemi_uzunluk[gemi_sirasi];i++){
						oyuncu_tahta[koordinatlar[0]][koordinatlar[1]+i]=gemi_simge[gemi_sirasi];
						*(gemi_x[gemi_sirasi]+i)=koordinatlar[0];*(gemi_y[gemi_sirasi]+i)=koordinatlar[1]+i;
					}
					system("CLS");break;
				}


				//Geminin Yatay Yerle�me Durumu
				if(koordinatlar[1]==koordinatlar[3]){
					if(koordinatlar[2]-koordinatlar[0]!=(gemi_uzunluk[gemi_sirasi]-1)){
						system("CLS");
						cout<<"Hatal� giri� yap�ld� tekrar deneyiniz..\n";
						continue;
					}

					test=koordinat_kontrolx(oyuncu_tahta,koordinatlar[0],koordinatlar[1],gemi_uzunluk[gemi_sirasi]);			//Girilen Koordinatlar�n bo� olup olmad���na bakar..
					
					if(test==0){
						system("CLS");
						cout<<"Girilen Koordinatta Yerle�tirilmi� gemi var!!!\nYeni koordinat giriniz..\n";
						continue;
					}

					//Tahtaya Gemiyi Yerle�tirir..

					for(int i=0;i<gemi_uzunluk[gemi_sirasi];i++){
						oyuncu_tahta[koordinatlar[0]+i][koordinatlar[1]]=gemi_simge[gemi_sirasi];
						*(gemi_x[gemi_sirasi]+i)=koordinatlar[0]+i;*(gemi_y[gemi_sirasi]+i)=koordinatlar[1];
					}
				}
						system("cls");break;
		
		}
	}
}

int atis_hata_ayiklama(char atisgiris[])
{
	int uzunluk,sayac=0;
	uzunluk=strlen(atisgiris);
	for(int i=0;i<uzunluk;i++){
		if((atisgiris[i]<=47 || atisgiris[i]>=58) && atisgiris[i]!=',')  //Say� ve virg�l d���ndaki karakterleri engeller
			return 0;
		if(atisgiris[i]==',')  //Virg�l adetini Sayar
			sayac++;
		
	}
	if(sayac!=1) //1'den Fazla virg�lde hata verdirir..
		return 0;
	if(atisgiris[0]<'0' || atisgiris[0]>'9' || atisgiris[uzunluk-1]<'0' || atisgiris[uzunluk-1]>'9')    //�lk ve Son Karakterin Say� Olmas�n� sa�lar
		return 0;

	return 1;
}

int Game_Start()
{
	int koor_tut[2],winlose;
	bool sag=false,sol=false,ust=false,alt=false,ctrlkont,oyunkayit_kontrol=false;
	
	while(true){
		
		char atis_giris[10]={NULL};
		int atis_xy[2],kontrol=1;
		int *atisPtr=atis_xy;
		if(amiral_sayac_p==6){		//Bilgisayar�n amiral� bat�rmas� �art�...
			system("mode con cols=100 lines=70 ");		//Konsol boyutunu ayarlar
			cout<<"\n-----  Amiral Geminiz Batt� Oyunu Bilgisayar Kazand�!!!  ----\n";
			winlose=0;
			break;
		}

		cout<<endl;
		cift_tahta_goster(atis_oy_tahta,atis_pc_tahta);
		cout<<"Oyununuzu Kaydetmek i�in CTRL+F6 kombinasyonunu kullan�n�z \nRakip gemileri g�rmek i�in CTRL+F5 kombinasyonunu kullan�n�z \n\nAt��lar x,y koordinat giri�i girilerek yap�l�r.\n�rn:3,5\n----------------------------------------\nKoordinat Giriniz:";	
		while(1){
			 if ((GetAsyncKeyState(VK_CONTROL)) && (GetAsyncKeyState(VK_F5)))	//CTRL+F5 Bas�l�rsa Bilgisayar Tahtas�n� g�sterir..
			 {
				system("cls");
				cout<<"\tRakip Oyun Tahtas�\n";
				tahtaGoster(pc_tahta);
				system("pause");
				system("cls");
				ctrlkont=true;
				break;
				
			 }
			 else if ((GetAsyncKeyState(VK_CONTROL)) && (GetAsyncKeyState(VK_F6)))	//CTRL+F6 Bas�l�rsa Oyunu Kaydetme Fonksiyonuna ge�er
			 {
				oyun_kayit();
				oyunkayit_kontrol=true;
				ctrlkont=false;
				winlose=3;				//Burdaki d�n�� de�eri oyunun kaydedildigini main fonksiyonuna aktarmak i�indir..
				break;
				
			 }
			 else if(_kbhit())	//Ctrl+F5 d���nda bir tu�a bas�l�rsa at�� giri�i al�n�r..
			 {
				 gets_s(atis_giris);
				 ctrlkont=false;
				 break;
			 }
		
		}
		if(ctrlkont){		//Ctrl+F5 kombinasyonu yap�ld�ysa ba�a al�r ekranda tahta g�r�nt�s� sa�lar..
			continue;
		}
		if(oyunkayit_kontrol){  //Oyun Kaydedildikten Sonra D�ng�y� durdurup oyunu bitirir..
			break;
		}

		kontrol=atis_hata_ayiklama(atis_giris);		//At�� Koordinatlar�n�n hatalar�n� kontrol eder..
		if(kontrol==0){
			system("CLS");
			cout<<"Hatal� Koordinat Giri�i Yeniden At�� Yap�n�z..\n";
			continue;
		}

		kontrol=koordinat_ayikla(atis_giris,atisPtr);	//At�� Koordinatlar�n� Ay�klay�p say�lar�n 1-10 aras� girilmesini sa�lar..
		if(atis_xy[0]<0 || atis_xy[1]<0 || kontrol==0 ){
			system("CLS");
			cout<<"1-10 Aras� Say� Giriniz..\n";
			continue;
		}
		if(atis_pc_tahta[atis_xy[0]][atis_xy[1]]=='X' || atis_pc_tahta[atis_xy[0]][atis_xy[1]]=='O'){	//Koordinata daha �nce at�� yap�lm��m� kontrol� yapar..
			system("cls");
			cout<<"Bu koordinatlara daha �nce at�� yap�ld�!!\n";
			continue;
		}
		system("cls");
		if(pc_tahta[atis_xy[0]][atis_xy[1]]!='.'){		//At�� yap�lan yerde gemi varm�?
			if(pc_tahta[atis_xy[0]][atis_xy[1]]=='A')	//Varsa Amiral mi? Amiralse sayac� art�r�p oyunu sonland�r�r..
				amiral_sayac_o++;
			atis_pc_tahta[atis_xy[0]][atis_xy[1]]='O';	//Di�er gemilerse at�� tahtas�n� i�aretler...
			cout<<"�sabetli At��..\n";
		}
		else{
			atis_pc_tahta[atis_xy[0]][atis_xy[1]]='X';	//At�� karavana ise i�aretleme yap�l�r..
			cout<<"Karavana..\n";
		}
		if(amiral_sayac_o==6){							//Amiral sayac� t�m kareleri vurdurdugunda �art� sa�lar ve oyunu durdurur..
			system("mode con cols=100 lines=70 ");		//Konsol boyutunu ayarlar
			cout<<"\n-----  Amiral Gemisi Bat�r�ld� Oyunu Kazand�n�z!!!  ----\n";
			winlose=1;
			break;
		}
		while(true){				//Bilgisayar�n At��� 
			atis_xy[0]=rand()%10;			//Rastgele Koordinat se�imi yapar..
			atis_xy[1]=rand()%10;
			if(atis_oy_tahta[atis_xy[0]][atis_xy[1]]!='X' && atis_oy_tahta[atis_xy[0]][atis_xy[1]]!='O')
				break;
		}


		if(sag){		//�sabet olmas� durumunda s�ras�yla sa� sol �st ve alt taraflara bakar..
			koor_tut[0]++;
			if(koor_tut[0]>9)
				sag=false;
			if(oyuncu_tahta[koor_tut[0]][koor_tut[1]]!='.'){
				if(oyuncu_tahta[koor_tut[0]][koor_tut[1]]=='A')
						amiral_sayac_p++;
				atis_oy_tahta[koor_tut[0]][koor_tut[1]]='O';
				alt=false;ust=false;
			}
			else{
				atis_oy_tahta[koor_tut[0]][koor_tut[1]]='X';
				sag=false;
			}
			continue;
		}


		if(sol){
			if(koor_tut[0]<0)
				sol=false;
			while(true){
				if(atis_oy_tahta[koor_tut[0]][koor_tut[1]]=='X' || atis_oy_tahta[koor_tut[0]][koor_tut[1]]=='O'){
					koor_tut[0]--;
					continue;
				}
				break;
			}
			if(oyuncu_tahta[koor_tut[0]][koor_tut[1]]!='.'){
				if(oyuncu_tahta[koor_tut[0]][koor_tut[1]]=='A')
						amiral_sayac_p++;
				atis_oy_tahta[koor_tut[0]][koor_tut[1]]='O';
				koor_tut[0]--;
				alt=false;ust=false;
			}
			else{
				atis_oy_tahta[koor_tut[0]][koor_tut[1]]='X';
				sol=false;
				koor_tut[0]++;
			}
			continue;
		}


		if(ust){
			if(koor_tut[1]>9)
				ust=false;
			koor_tut[1]++;
			if(oyuncu_tahta[koor_tut[0]][koor_tut[1]]!='.'){
				if(oyuncu_tahta[koor_tut[0]][koor_tut[1]]=='A')
						amiral_sayac_p++;
				atis_oy_tahta[koor_tut[0]][koor_tut[1]]='O';
			}
			else{
				atis_oy_tahta[koor_tut[0]][koor_tut[1]]='X';
				ust=false;
			}
			continue;
		}


		if(alt){
			if(koor_tut[1]<0)
				alt=false;
			while(true){
				if(atis_oy_tahta[koor_tut[0]][koor_tut[1]]=='X' || atis_oy_tahta[koor_tut[0]][koor_tut[1]]=='O'){
					koor_tut[1]--;
					continue;
				}
				break;
			}
			if(oyuncu_tahta[koor_tut[0]][koor_tut[1]]!='.'){
				if(oyuncu_tahta[koor_tut[0]][koor_tut[1]]=='A')
						amiral_sayac_p++;
				atis_oy_tahta[koor_tut[0]][koor_tut[1]]='O';
				koor_tut[1]--;
			}
			else{
				atis_oy_tahta[koor_tut[0]][koor_tut[1]]='X';
				alt=false;
			}
			continue;
		}

		if(oyuncu_tahta[atis_xy[0]][atis_xy[1]]!='.'){
			if(oyuncu_tahta[atis_xy[0]][atis_xy[1]]=='A')
					amiral_sayac_p++;
			atis_oy_tahta[atis_xy[0]][atis_xy[1]]='O';
			sag=true;sol=true;ust=true;alt=true;
			koor_tut[0]=atis_xy[0];koor_tut[1]=atis_xy[1];
		}
		else
			atis_oy_tahta[atis_xy[0]][atis_xy[1]]='X';

		

	}
	return winlose;
}

int Puanlama(int *batangemi,int *isabet,int *toplam_hamle)
{

	int sayac=0,p1=0,p2=0;
	int gemiuzunluk[9] ={4,4,3,3,3,2,2,2,2};
	int *gemi_x_pc[9] ={D1_P.x,D2_P.x,F1_P.x,F2_P.x,F3_P.x,H1_P.x,H2_P.x,H3_P.x,H4_P.x};
	int *gemi_y_pc[9] ={D1_P.y,D2_P.y,F1_P.y,F2_P.y,F3_P.y,H1_P.y,H2_P.y,H3_P.y,H4_P.y};
	int *gemi_x_oy[9] ={D1_O.x,D2_O.x,F1_O.x,F2_O.x,F3_O.x,H1_O.x,H2_O.x,H3_O.x,H4_O.x};
	int *gemi_y_oy[9] ={D1_O.y,D2_O.y,F1_O.y,F2_O.y,F3_O.y,H1_O.y,H2_O.y,H3_O.y,H4_O.y};
	
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++){
			if(atis_pc_tahta[i][j]=='X'||atis_pc_tahta[i][j]=='O')
				(*toplam_hamle)++;
			if(atis_pc_tahta[i][j]=='O')
				(*isabet)++;

		}


	for(int i=0;i<9;i++){
		sayac=0;
		for(int j=0;j<gemiuzunluk[i];j++){
			if(atis_pc_tahta[*(gemi_x_pc[i]+j)][*(gemi_y_pc[i]+j)]=='O')
				sayac++;
			
		}
		if(sayac==gemiuzunluk[i]){
			p1 = p1 + sayac;
			(*batangemi)++;
		}
	}

	for(int i=0;i<9;i++){
		sayac=0;
		for(int j=0;j<gemiuzunluk[i];j++){
			if(atis_oy_tahta[*(gemi_x_oy[i]+j)][*(gemi_y_oy[i]+j)]=='O')
				sayac++;
		}
		if(sayac==gemiuzunluk[i])
			p2 = p2 + sayac;
		
	}
	cout<<"Oyuncu Puan�\t :"<<p1<<endl;
	cout<<"Rakibin Puan�\t :"<<p2<<endl<<endl;

	return p1;

}

void son_durum()
{
	
	cift_tahta_goster(oyuncu_tahta,pc_tahta);
	cout<<"\n-----------------------------------------------------------------------------------------\n\t\t\t\tAt�� Yap�lan Yerler\n";
	cift_tahta_goster(atis_oy_tahta,atis_pc_tahta);
}

void puan_kaydi(int puan,int *isabet,int *toplam_hamle,int *batangemi,int winlose)
{
	char isimler[6][50],isim[50],tempisim[50];
	int puanlar[6]={0},batan_gemiler[6]={0},isabetler[6]={0},toplam_hamleler[6]={0},temp;
	int veri_adet=0;
	FILE *dosyaPtr;
	dosyaPtr=fopen("HighScore.csv","r");
	if(dosyaPtr==NULL)
		cout<<"Dosya A��lamad�\n";
	else{
		while(!feof(dosyaPtr)){
				fscanf(dosyaPtr,"%[^;];%d;%d;%d;%d\n",isimler[veri_adet],&puanlar[veri_adet],&batan_gemiler[veri_adet],&isabetler[veri_adet],&toplam_hamleler[veri_adet]);
				veri_adet++;
		}
		fclose(dosyaPtr);
		
		}

	if(puan>puanlar[4] && winlose==1){
		cout<<"Y�ksek skor yap�ld�.."<<endl;
		cout<<"Kayit i�in isim giriniz :";gets_s(isim);
		puanlar[5]=puan;
		batan_gemiler[5]=*batangemi;
		isabetler[5]=*isabet;
		toplam_hamleler[5]=*toplam_hamle;
		strcpy_s(isimler[5],isim);
		FILE *dosyaPtr;
		dosyaPtr=fopen("HighScore.csv","w");
		if(dosyaPtr==NULL)
			cout<<"Dosya A��lamad�\n";
		else{
			for(int j=0;j<6;j++){
				for(int k=0;k<j;k++){
					if(puanlar[j]>puanlar[k]){
						temp=puanlar[j];
						puanlar[j]=puanlar[k];
						puanlar[k]=temp;
						temp=isabetler[j];
						isabetler[j]=isabetler[k];
						isabetler[k]=temp;
						temp=toplam_hamleler[j];
						toplam_hamleler[j]=toplam_hamleler[k];
						toplam_hamleler[k]=temp;
						temp=batan_gemiler[j];
						batan_gemiler[j]=batan_gemiler[k];
						batan_gemiler[k]=temp;
						strcpy_s(tempisim,isimler[j]);
						strcpy_s(isimler[j],isimler[k]);
						strcpy_s(isimler[k],tempisim);
					}
				}
		}
			for(int i=0;i<5;i++){
				fprintf(dosyaPtr,"%s;%d;%d;%d;%d\n",isimler[i],puanlar[i],batan_gemiler[i],isabetler[i],toplam_hamleler[i]);
			}
			
			fclose(dosyaPtr);
		
		}
		cout<<"Skorunuz Kaydedilmi�tir\nAt��lara Devam..\n";
	}

		
}

void puanlari_goster()
{
	char isimler[5][50];
	int puanlar[6]={0},batan_gemiler[6]={0},isabetler[6]={0},toplam_hamleler[6]={0};
	int veri_adet=0;
	FILE *dosyaPtr;
	dosyaPtr=fopen("HighScore.csv","r");
	cout<<"\n\t\t\tAmiral Batt� Y�ksek Puanlar\n\n\n";
	cout<<"-----------------------------------------------------------------------------\n\n";
	cout<<"   �sim\t\tSkorlar\t  Toplam At��\t�sabetli At��\tBat�r�lan Gemi Say�s�\n";
	cout<<" ---------\t-------\t  -----------\t-------------\t--------------------\n";
	if(dosyaPtr==NULL)
		cout<<"Dosya A��lamad�\n";
	else{
		while(!feof(dosyaPtr)){
				fscanf(dosyaPtr,"%[^;];%d;%d;%d;%d\n",isimler[veri_adet],&puanlar[veri_adet],&batan_gemiler[veri_adet],&isabetler[veri_adet],&toplam_hamleler[veri_adet]);
				if(strlen(isimler[veri_adet])>4)
					cout<<veri_adet+1<<"-)"<<isimler[veri_adet]<<"\t  "<<puanlar[veri_adet]<<"\t     "<<toplam_hamleler[veri_adet]<<"\t\t   "<<isabetler[veri_adet]<<"\t\t   "<<batan_gemiler[veri_adet]<<" Adet\n";
				else if(strlen(isimler[veri_adet])<=4)
					cout<<veri_adet+1<<"-)"<<isimler[veri_adet]<<"\t\t  "<<puanlar[veri_adet]<<"\t     "<<toplam_hamleler[veri_adet]<<"\t\t   "<<isabetler[veri_adet]<<"\t\t   "<<batan_gemiler[veri_adet]<<" Adet\n";
				veri_adet++;
		}
		fclose(dosyaPtr);
		cout<<"\n----------------------------------------------------------------------------\n";
		}
}

int menu()
{
	
	char secim=NULL,koseler[4]={218,191,192,217};

	for(int i=0;i<10;i++){			//At�� Tahtalar�n� S�f�rlar...
		for(int j=0;j<10;j++){
			atis_oy_tahta[i][j]='.';
			atis_pc_tahta[i][j]='.';
		}
	}

	while((secim!='1' && secim !='2' && secim!='4' && secim!='5') || secim=='3' ){

		system("mode con cols=60 lines=15 ");		//Konsol boyutunu ayarlar

		cout<<"Amiral Batt� v1.7\t\t\t\tCreated B1"<<endl<<endl;
		cout<<"\t                  Men�"<<endl;
		cout<<"\t---------------------------------------"<<endl;
		cout<<"\t|                                     |"<<endl;
		cout<<"\t|   1-)Gemileri Manuel Yerle�tir      |"<<endl;
		cout<<"\t|   2-)Gemileri Otomatik Yerle�tir    |"<<endl;
		cout<<"\t|   3-)Y�ksek Skorlar� G�r�nt�le      |"<<endl;
		cout<<"\t|   4-)Kaydedilmi� Oyundan Devam et   |"<<endl;
		cout<<"\t|   5-)��k��                          |"<<endl;
		cout<<"\t|                                     |"<<endl;
		cout<<"\t---------------------------------------"<<endl<<endl;
		cout<<"Se�iminiz :";
		secim=_getch();
		system("cls");

		if(secim!='1' && secim!='2' && secim!='3' && secim!='4' && secim!='5')
			cout<<"Men� giri�ini hatal� yapt�n�z. L�tfen se�enek numaras�n� tekrar giriniz"<<endl;

		if(secim=='3'){
			system("mode con cols=80 lines=17 ");		//Konsol boyutunu sabitlemek i�in...
			puanlari_goster();
			system("pause");
			system("cls");
		}

		_flushall();

	}

	if(secim=='5')
		return 1;

	if(secim=='4'){
		oyun_yukle();
		system("cls");
		cout<<"Oyununuz ba�ar�yla y�klendi.."<<endl;
	}

	if(secim=='1'){
		system("mode con cols=50 lines=30 ");		//Konsol boyutunu ayarlar
		Manuel_TahtaDoldur(oyuncu_tahta);
		system("mode con cols=95 lines=40 ");		//Konsol boyutunu ayarlar
		Oto_TahtaDoldur(pc_tahta);
		cout<<"Gemiler Ba�ar�yla Yerle�tirildi. Oyuna Ba�layabiliriz Art�k...\n";
	}

	if(secim=='2'){
		system("mode con cols=95 lines=40 ");		//Konsol boyutunu ayarlar
		Oto_TahtaDoldur2(oyuncu_tahta);
		Oto_TahtaDoldur(pc_tahta);
		cout<<"Gemiler Bilgisayar Taraf�ndan Rastgele Yerle�tirildi.. Oyun Ba�las�n...\n";
	}
	
	return 0;
}

int main()
{
	HWND consoleWindow = GetConsoleWindow();									//Console Ekran�n�n Ba�lang�� Pozisyonunu ayarlar..
	SetWindowPos( consoleWindow, 0, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER );

	srand(time(NULL));
	setlocale(0,"tr");
	system("color 1F");				//A��l��ta Renk Temas� Belirler..

	char tekrar_secim,secim,cikis;
	int puan,batan_gemi,isabet,toplam_hamle,winlose;
	int *Ptr_batan_gemi=&batan_gemi,*Ptr_isabet=&isabet,*Ptr_toplam_hamle=&toplam_hamle;


	while(true){

		amiral_sayac_o=0;
		amiral_sayac_p=0;
		batan_gemi=0;
		isabet=0;
		toplam_hamle=0;
		cikis=menu();

		if(cikis)
			break;

		_flushall();
		winlose=Game_Start();

		if(winlose==3){
			cout<<"\nOyununuz Ba�ar�yla Kaydedilmi�tir..\nTekrar g�r��mek �zere ho��akal :*\n\n";
			system("pause");
			break;
		}
		
		puan=Puanlama(Ptr_batan_gemi,Ptr_isabet,Ptr_toplam_hamle);
		son_durum();
		puan_kaydi(puan,Ptr_isabet,Ptr_toplam_hamle,Ptr_batan_gemi,winlose);

		cout<<"��k�� i�in 'h' tu�una bas�n�z..\nTekrar oynamak i�in bir tu�a bas�n�z..";

		tekrar_secim=_getch();

		if(tekrar_secim=='h')
			break;

		system("cls");
		_flushall();
	}
	return 0;
}
