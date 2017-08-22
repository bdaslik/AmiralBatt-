//AmiralBatti v1.7
//Sakarya Üniversitesi Teknoloji Fakültesi Bilgisayar Mühendisliði
//II. Dönem Proje Ödevi
//Bervan Daþlýk
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
	cout<<"Oyununuzu kaydetmek için bir isim giriniz :";gets_s(tempisim);	//Her Kaydý Farklý bir metin dosyasýna kaydeder
	strcat_s(oyun_ismi,"kayitli_oyunlar\\");
	strcat_s(oyun_ismi,tempisim);				//String ekleme iþlemi ile dosya yolu kaydedilir..
	strcat_s(oyun_ismi,".txt");

	FILE *dosyaPtr;
	dosyaPtr=fopen(oyun_ismi,"w");
	if(dosyaPtr==NULL)
		cout<<"Dosya Açýlamadý\n";
	else{
		fprintf(dosyaPtr,"%d\n",amiral_sayac_o);		//Amiral Gemilerinin Sayaçlarýný Dosyaya kaydeder..
		fprintf(dosyaPtr,"%d\n",amiral_sayac_p);
		for(int i=0;i<10;i++){							//Oyun Tahtalarýný Dosyaya Sýralý bir þekilde Kaydeder..
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

		for(int i=0;i<10;i++){				//Oyuncu Gemilerinin x,y koordinatlarýnýn tümünü kaydeder..
			for(int j=0;j<gemiuzunluk[i];j++){
				fprintf(dosyaPtr,"%d,%d;",*(gemi_x_oy[i]+j),*(gemi_y_oy[i]+j));
			}
			fprintf(dosyaPtr,"\n");
		}


		for(int i=0;i<10;i++){				//Bilgisayar Gemilerinin x,y koordinatlarýnýn tümünü kaydeder..
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
	cout<<"Kayýtlý oyun ismi giriniz :";gets_s(tempisim);
	strcat_s(oyun_ismi,"kayitli_oyunlar\\");
	strcat_s(oyun_ismi,tempisim);
	strcat_s(oyun_ismi,".txt");

	FILE *dosyaPtr;
	dosyaPtr=fopen(oyun_ismi,"r");
	if(dosyaPtr==NULL){
		cout<<"Dosya açýlamadý tekrar giriþ yapýnýz\n";		// Yanlýþ giriþ durumunda recursive fonksiyonla tekrar giriþ ister..
		_getch();
		oyun_yukle();
	}
	else{
		fscanf(dosyaPtr,"%d\n",&amiral_sayac_o);	//Amiral Gemisi Sayaçlarýný dosyadan çeker
		fscanf(dosyaPtr,"%d\n",&amiral_sayac_p);

		for(int i=0;i<10;i++){				//Oyun Tahtalarýný Dosyadan Çekip Dizilere yerleþtirir
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

		for(int i=0;i<10;i++){			//Oyuncu Gemi Koordinatlarýný Çeker(Puanlama için Gerekli)
			for(int j=0;j<gemiuzunluk[i];j++){
				fscanf(dosyaPtr,"%d,%d;",&*(gemi_x_oy[i]+j),&*(gemi_y_oy[i]+j));
			}
			fscanf(dosyaPtr,"\n");
		}


		for(int i=0;i<10;i++){			//Bilgisayar Gemi Koordinatlarýný Çeker(Puanlama için Gerekli)
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
		cout<<"\tOyuncunun Tahtasý\t\t\t\tBilgisayarýn Tahtasý\n";

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

	//Oyun Tahtasýný Sýfýrlamak için
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			tahta[i][j]='.';
	// Gemilerin Yerleþtirilmesi
	for(int i=0;i<10;i++){		//Gemiyi Yatay yada Dikey Yerleþimini rastgele belirler...
		z=rand()%2;
	if(z==0)					//Yatay Yerleþim
		{
			while(true){
			x=rand()%(11-gemiuzunluk[i]);
			y=rand()%10;
			for(int j=0;j<gemiuzunluk[i];j++){		//Girilen Koordinatlarýn Boþ olduðunu kontrol eder
				if(tahta[x+j][y]!='.')
					test=0;
			}
			if(test==1)
				break;
			test=1;
			}
			for(int k=0;k<gemiuzunluk[i];k++){   	//Gemiyi Yerleþtirir..
				tahta[x][y]=gemisembol[i];
				*(gemi_x[i]+k)=x;*(gemi_y[i]+k)=y;
				x++;
			}
		}
		if(z==1)			//Dikey Yerleþim...
		{
			while(true){
			x=rand()%10;
			y=rand()%(11-gemiuzunluk[i]);
			for(int j=0;j<gemiuzunluk[i];j++){		//Girilen Koordinatlarýn Boþ olduðunu kontrol eder
				if(tahta[x][y+j]!='.')
					test=0;
			}
			if(test==1)
				break;
			test=1;
			}
			for(int k=0;k<gemiuzunluk[i];k++){		//Gemiyi Yerleþtirir..
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

	//Oyun Tahtasýný Sýfýrlamak için
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			tahta[i][j]='.';
	// Gemilerin Yerleþtirilmesi
	for(int i=0;i<10;i++){		//Gemiyi Yatay yada Dikey Yerleþimini rastgele belirler...
		z=rand()%2;
	if(z==0)					//Yatay Yerleþim
		{
			while(true){
			x=rand()%(11-gemiuzunluk[i]);
			y=rand()%10;
			for(int j=0;j<gemiuzunluk[i];j++){		//Girilen Koordinatlarýn Boþ olduðunu kontrol eder
				if(tahta[x+j][y]!='.')
					test=0;
			}
			if(test==1)
				break;
			test=1;
			}
			for(int k=0;k<gemiuzunluk[i];k++){   	//Gemiyi Yerleþtirir..
				tahta[x][y]=gemisembol[i];
				*(gemi_x[i]+k)=x;*(gemi_y[i]+k)=y;
				x++;
			}
		}
		if(z==1)			//Dikey Yerleþim...
		{
			while(true){
			x=rand()%10;
			y=rand()%(11-gemiuzunluk[i]);
			for(int j=0;j<gemiuzunluk[i];j++){		//Girilen Koordinatlarýn Boþ olduðunu kontrol eder
				if(tahta[x][y+j]!='.')
					test=0;
			}
			if(test==1)
				break;
			test=1;
			}
			for(int k=0;k<gemiuzunluk[i];k++){		//Gemiyi Yerleþtirir..
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
	koordinatChar[uzunluk]='!';		//Taramayý Durdurma komutu(Koordinat giriþinin sonuna ekler)
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
		if(k==0){		//Tek basamaklýysa koordinatý ptr aracýlýðýyla diziye atar..
			*(sayiDizisi+j)=gecici[0]-49;
			j++;
			i++; // virgül atlatma
			}
		else if(k==1){		//Çift basamaklýysa koordinatý ptr aracýlýðýyla diziye atar..
			ciftsayi=(gecici[0]-48)*10+(gecici[1]-48)*10;
			if(ciftsayi==10){
				*(sayiDizisi+j)=ciftsayi-1;
				j++;
				i++; // virgül atlatma
			}
			else{	 //sayýnýn 10'dan buyuk olmasý durumunda fonksiyonu durdurur..
				return 0;
				}
			}
			
		else		//3 veya daha fazla basamak giriþinde fonksiyonu durdurur..
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
	char gemi_ismi[10][10]={"Amiral","Destroyer","Destroyer","Firkateyn","Firkateyn","Firkateyn","Hücum Bot","Hücum Bot","Hücum Bot","Hücum Bot"};
	char gemi_simge[11]={"ADDFFFHHHH"};


	//Oyun Tahtasýný Sýfýrlamak için

	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			oyuncu_tahta[i][j]='.';

	char koordinat_giris[15]={};
	int test,girisuzunlugu,koordinatlar[4];
	int *koordinatPtr=koordinatlar;


	//Gemileri yerleþtirme...

	for(int gemi_sirasi=0;gemi_sirasi<10;gemi_sirasi++){
		while(true){
			test=1;
				system("cls");
				tahtaGoster(oyuncu_tahta);
				cout<<"Gemileri Yerleþtiriniz..."<<endl;
				cout<<"Örnek : 1,1-1,"<<gemi_uzunluk[gemi_sirasi]<<" (Ýlk ve Son Noktalarýný Giriniz)"<<endl;
				cout<<"\n-------------------------------------------------\n";
				cout<<gemi_ismi[gemi_sirasi]<<" Gemisini Yerleþtiriniz:";
				gets_s(koordinat_giris);

				if(koordinat_giris[0]=='\0')
					continue;
				girisuzunlugu=strlen(koordinat_giris);
				test=karakter_engelle(girisuzunlugu,koordinat_giris);  //Sayýlar ',' ve '-' dýþýnda karakter giriþini engeller...
				if(test==0){
					system("cls");
					cout<<"Hatalý giriþ yapýldý tekrar deneyiniz..\n";
					continue;
				}
				test=koordinat_ayikla(koordinat_giris,koordinatPtr);		//Girilen Koordinatý ',' ve '-' ayýklayýp diziye parçalar..
																			//koordinatlar[] dizisindeki deðerler sýrasýyla --> x1,y1,x2,y2 þeklinde ayýklanýr ;)
				
				if(koordinatlar[0]<0 || koordinatlar[1]<0 || koordinatlar[2]<0 || koordinatlar[3]<0 || test==0  || test==2 ){    
					system("CLS");								//Koordinatlarýn 1-10 arasýnda giriþini saðlar..
					cout<<"Hatalý giriþ yapýldý tekrar deneyiniz..\n";
					continue;
				}												


				//Geminin Dikey yerleþme durumu
				if(koordinatlar[0]==koordinatlar[2]){
					if(koordinatlar[3]-koordinatlar[1]!=(gemi_uzunluk[gemi_sirasi]-1)){
						system("CLS");
						cout<<"Hatalý giriþ yapýldý tekrar deneyiniz..\n";
						continue;
					}
						test=koordinat_kontroly(oyuncu_tahta,koordinatlar[0],koordinatlar[1],gemi_uzunluk[gemi_sirasi]);		//Girilen Koordinatlarýn boþ olup olmadýðýna bakar..
						if(test==0){
							system("CLS");
							cout<<"Girilen Koordinatta Yerleþtirilmiþ gemi var!!!\nYeni koordinat giriniz..\n";
							continue;
					}

					//Tahtaya gemiyi yerleþtirir.
					for(int i=0;i<gemi_uzunluk[gemi_sirasi];i++){
						oyuncu_tahta[koordinatlar[0]][koordinatlar[1]+i]=gemi_simge[gemi_sirasi];
						*(gemi_x[gemi_sirasi]+i)=koordinatlar[0];*(gemi_y[gemi_sirasi]+i)=koordinatlar[1]+i;
					}
					system("CLS");break;
				}


				//Geminin Yatay Yerleþme Durumu
				if(koordinatlar[1]==koordinatlar[3]){
					if(koordinatlar[2]-koordinatlar[0]!=(gemi_uzunluk[gemi_sirasi]-1)){
						system("CLS");
						cout<<"Hatalý giriþ yapýldý tekrar deneyiniz..\n";
						continue;
					}

					test=koordinat_kontrolx(oyuncu_tahta,koordinatlar[0],koordinatlar[1],gemi_uzunluk[gemi_sirasi]);			//Girilen Koordinatlarýn boþ olup olmadýðýna bakar..
					
					if(test==0){
						system("CLS");
						cout<<"Girilen Koordinatta Yerleþtirilmiþ gemi var!!!\nYeni koordinat giriniz..\n";
						continue;
					}

					//Tahtaya Gemiyi Yerleþtirir..

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
		if((atisgiris[i]<=47 || atisgiris[i]>=58) && atisgiris[i]!=',')  //Sayý ve virgül dýþýndaki karakterleri engeller
			return 0;
		if(atisgiris[i]==',')  //Virgül adetini Sayar
			sayac++;
		
	}
	if(sayac!=1) //1'den Fazla virgülde hata verdirir..
		return 0;
	if(atisgiris[0]<'0' || atisgiris[0]>'9' || atisgiris[uzunluk-1]<'0' || atisgiris[uzunluk-1]>'9')    //Ýlk ve Son Karakterin Sayý Olmasýný saðlar
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
		if(amiral_sayac_p==6){		//Bilgisayarýn amiralý batýrmasý þartý...
			system("mode con cols=100 lines=70 ");		//Konsol boyutunu ayarlar
			cout<<"\n-----  Amiral Geminiz Battý Oyunu Bilgisayar Kazandý!!!  ----\n";
			winlose=0;
			break;
		}

		cout<<endl;
		cift_tahta_goster(atis_oy_tahta,atis_pc_tahta);
		cout<<"Oyununuzu Kaydetmek için CTRL+F6 kombinasyonunu kullanýnýz \nRakip gemileri görmek için CTRL+F5 kombinasyonunu kullanýnýz \n\nAtýþlar x,y koordinat giriþi girilerek yapýlýr.\nÖrn:3,5\n----------------------------------------\nKoordinat Giriniz:";	
		while(1){
			 if ((GetAsyncKeyState(VK_CONTROL)) && (GetAsyncKeyState(VK_F5)))	//CTRL+F5 Basýlýrsa Bilgisayar Tahtasýný gösterir..
			 {
				system("cls");
				cout<<"\tRakip Oyun Tahtasý\n";
				tahtaGoster(pc_tahta);
				system("pause");
				system("cls");
				ctrlkont=true;
				break;
				
			 }
			 else if ((GetAsyncKeyState(VK_CONTROL)) && (GetAsyncKeyState(VK_F6)))	//CTRL+F6 Basýlýrsa Oyunu Kaydetme Fonksiyonuna geçer
			 {
				oyun_kayit();
				oyunkayit_kontrol=true;
				ctrlkont=false;
				winlose=3;				//Burdaki dönüþ deðeri oyunun kaydedildigini main fonksiyonuna aktarmak içindir..
				break;
				
			 }
			 else if(_kbhit())	//Ctrl+F5 dýþýnda bir tuþa basýlýrsa atýþ giriþi alýnýr..
			 {
				 gets_s(atis_giris);
				 ctrlkont=false;
				 break;
			 }
		
		}
		if(ctrlkont){		//Ctrl+F5 kombinasyonu yapýldýysa baþa alýr ekranda tahta görüntüsü saðlar..
			continue;
		}
		if(oyunkayit_kontrol){  //Oyun Kaydedildikten Sonra Döngüyü durdurup oyunu bitirir..
			break;
		}

		kontrol=atis_hata_ayiklama(atis_giris);		//Atýþ Koordinatlarýnýn hatalarýný kontrol eder..
		if(kontrol==0){
			system("CLS");
			cout<<"Hatalý Koordinat Giriþi Yeniden Atýþ Yapýnýz..\n";
			continue;
		}

		kontrol=koordinat_ayikla(atis_giris,atisPtr);	//Atýþ Koordinatlarýný Ayýklayýp sayýlarýn 1-10 arasý girilmesini saðlar..
		if(atis_xy[0]<0 || atis_xy[1]<0 || kontrol==0 ){
			system("CLS");
			cout<<"1-10 Arasý Sayý Giriniz..\n";
			continue;
		}
		if(atis_pc_tahta[atis_xy[0]][atis_xy[1]]=='X' || atis_pc_tahta[atis_xy[0]][atis_xy[1]]=='O'){	//Koordinata daha önce atýþ yapýlmýþmý kontrolü yapar..
			system("cls");
			cout<<"Bu koordinatlara daha önce atýþ yapýldý!!\n";
			continue;
		}
		system("cls");
		if(pc_tahta[atis_xy[0]][atis_xy[1]]!='.'){		//Atýþ yapýlan yerde gemi varmý?
			if(pc_tahta[atis_xy[0]][atis_xy[1]]=='A')	//Varsa Amiral mi? Amiralse sayacý artýrýp oyunu sonlandýrýr..
				amiral_sayac_o++;
			atis_pc_tahta[atis_xy[0]][atis_xy[1]]='O';	//Diðer gemilerse atýþ tahtasýný iþaretler...
			cout<<"Ýsabetli Atýþ..\n";
		}
		else{
			atis_pc_tahta[atis_xy[0]][atis_xy[1]]='X';	//Atýþ karavana ise iþaretleme yapýlýr..
			cout<<"Karavana..\n";
		}
		if(amiral_sayac_o==6){							//Amiral sayacý tüm kareleri vurdurdugunda þartý saðlar ve oyunu durdurur..
			system("mode con cols=100 lines=70 ");		//Konsol boyutunu ayarlar
			cout<<"\n-----  Amiral Gemisi Batýrýldý Oyunu Kazandýnýz!!!  ----\n";
			winlose=1;
			break;
		}
		while(true){				//Bilgisayarýn Atýþý 
			atis_xy[0]=rand()%10;			//Rastgele Koordinat seçimi yapar..
			atis_xy[1]=rand()%10;
			if(atis_oy_tahta[atis_xy[0]][atis_xy[1]]!='X' && atis_oy_tahta[atis_xy[0]][atis_xy[1]]!='O')
				break;
		}


		if(sag){		//Ýsabet olmasý durumunda sýrasýyla sað sol üst ve alt taraflara bakar..
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
	cout<<"Oyuncu Puaný\t :"<<p1<<endl;
	cout<<"Rakibin Puaný\t :"<<p2<<endl<<endl;

	return p1;

}

void son_durum()
{
	
	cift_tahta_goster(oyuncu_tahta,pc_tahta);
	cout<<"\n-----------------------------------------------------------------------------------------\n\t\t\t\tAtýþ Yapýlan Yerler\n";
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
		cout<<"Dosya Açýlamadý\n";
	else{
		while(!feof(dosyaPtr)){
				fscanf(dosyaPtr,"%[^;];%d;%d;%d;%d\n",isimler[veri_adet],&puanlar[veri_adet],&batan_gemiler[veri_adet],&isabetler[veri_adet],&toplam_hamleler[veri_adet]);
				veri_adet++;
		}
		fclose(dosyaPtr);
		
		}

	if(puan>puanlar[4] && winlose==1){
		cout<<"Yüksek skor yapýldý.."<<endl;
		cout<<"Kayit için isim giriniz :";gets_s(isim);
		puanlar[5]=puan;
		batan_gemiler[5]=*batangemi;
		isabetler[5]=*isabet;
		toplam_hamleler[5]=*toplam_hamle;
		strcpy_s(isimler[5],isim);
		FILE *dosyaPtr;
		dosyaPtr=fopen("HighScore.csv","w");
		if(dosyaPtr==NULL)
			cout<<"Dosya Açýlamadý\n";
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
		cout<<"Skorunuz Kaydedilmiþtir\nAtýþlara Devam..\n";
	}

		
}

void puanlari_goster()
{
	char isimler[5][50];
	int puanlar[6]={0},batan_gemiler[6]={0},isabetler[6]={0},toplam_hamleler[6]={0};
	int veri_adet=0;
	FILE *dosyaPtr;
	dosyaPtr=fopen("HighScore.csv","r");
	cout<<"\n\t\t\tAmiral Battý Yüksek Puanlar\n\n\n";
	cout<<"-----------------------------------------------------------------------------\n\n";
	cout<<"   Ýsim\t\tSkorlar\t  Toplam Atýþ\tÝsabetli Atýþ\tBatýrýlan Gemi Sayýsý\n";
	cout<<" ---------\t-------\t  -----------\t-------------\t--------------------\n";
	if(dosyaPtr==NULL)
		cout<<"Dosya Açýlamadý\n";
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

	for(int i=0;i<10;i++){			//Atýþ Tahtalarýný Sýfýrlar...
		for(int j=0;j<10;j++){
			atis_oy_tahta[i][j]='.';
			atis_pc_tahta[i][j]='.';
		}
	}

	while((secim!='1' && secim !='2' && secim!='4' && secim!='5') || secim=='3' ){

		system("mode con cols=60 lines=15 ");		//Konsol boyutunu ayarlar

		cout<<"Amiral Battý v1.7\t\t\t\tCreated B1"<<endl<<endl;
		cout<<"\t                  Menü"<<endl;
		cout<<"\t---------------------------------------"<<endl;
		cout<<"\t|                                     |"<<endl;
		cout<<"\t|   1-)Gemileri Manuel Yerleþtir      |"<<endl;
		cout<<"\t|   2-)Gemileri Otomatik Yerleþtir    |"<<endl;
		cout<<"\t|   3-)Yüksek Skorlarý Görüntüle      |"<<endl;
		cout<<"\t|   4-)Kaydedilmiþ Oyundan Devam et   |"<<endl;
		cout<<"\t|   5-)Çýkýþ                          |"<<endl;
		cout<<"\t|                                     |"<<endl;
		cout<<"\t---------------------------------------"<<endl<<endl;
		cout<<"Seçiminiz :";
		secim=_getch();
		system("cls");

		if(secim!='1' && secim!='2' && secim!='3' && secim!='4' && secim!='5')
			cout<<"Menü giriþini hatalý yaptýnýz. Lütfen seçenek numarasýný tekrar giriniz"<<endl;

		if(secim=='3'){
			system("mode con cols=80 lines=17 ");		//Konsol boyutunu sabitlemek için...
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
		cout<<"Oyununuz baþarýyla yüklendi.."<<endl;
	}

	if(secim=='1'){
		system("mode con cols=50 lines=30 ");		//Konsol boyutunu ayarlar
		Manuel_TahtaDoldur(oyuncu_tahta);
		system("mode con cols=95 lines=40 ");		//Konsol boyutunu ayarlar
		Oto_TahtaDoldur(pc_tahta);
		cout<<"Gemiler Baþarýyla Yerleþtirildi. Oyuna Baþlayabiliriz Artýk...\n";
	}

	if(secim=='2'){
		system("mode con cols=95 lines=40 ");		//Konsol boyutunu ayarlar
		Oto_TahtaDoldur2(oyuncu_tahta);
		Oto_TahtaDoldur(pc_tahta);
		cout<<"Gemiler Bilgisayar Tarafýndan Rastgele Yerleþtirildi.. Oyun Baþlasýn...\n";
	}
	
	return 0;
}

int main()
{
	HWND consoleWindow = GetConsoleWindow();									//Console Ekranýnýn Baþlangýç Pozisyonunu ayarlar..
	SetWindowPos( consoleWindow, 0, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER );

	srand(time(NULL));
	setlocale(0,"tr");
	system("color 1F");				//Açýlýþta Renk Temasý Belirler..

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
			cout<<"\nOyununuz Baþarýyla Kaydedilmiþtir..\nTekrar görüþmek üzere hoþçakal :*\n\n";
			system("pause");
			break;
		}
		
		puan=Puanlama(Ptr_batan_gemi,Ptr_isabet,Ptr_toplam_hamle);
		son_durum();
		puan_kaydi(puan,Ptr_isabet,Ptr_toplam_hamle,Ptr_batan_gemi,winlose);

		cout<<"Çýkýþ için 'h' tuþuna basýnýz..\nTekrar oynamak için bir tuþa basýnýz..";

		tekrar_secim=_getch();

		if(tekrar_secim=='h')
			break;

		system("cls");
		_flushall();
	}
	return 0;
}
