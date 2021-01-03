#include<stdio.h>
#include<windows.h>
#include<stdbool.h>
#include<math.h>

int I[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
int matrisCarpim[3][3];
int m1[3][3];
int m2[3][3];
int m1Kare[3][3];
int m2Kare[3][3];
int mToplama[3][3];//m1 +m2 sonuç
int mCikarma[3][3];
int m1Result[3][3];//m1 matrisinin sabit sayi ile çarpiminin sonucu 
int m2Result[3][3];//m2 matrisinin sabit sayi ile çarpiminin sonucu
//---------------------------------------------------------------arayuz bolumu
void gotoxy(short x, short y) {
	HANDLE hConsoleOutput;
	COORD Cursor_Pos = {x-1, y-1};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_Pos);
}

//-----------------------------------------------------------------------

void box(int x,int y)
{
	gotoxy(x,y);
	printf("%c",176);
}
void cerceve()
{
	int i=0;
	int j=0;
	for (i;i<110;i++)
	{
		box(i,j);
	}
	for(j;j<50;j++)
	{
		box(i+1,j);
	}
	for(i;i>0;i--)
	{
		box(i,j);
	}
	for(i=0;i<50;i++){
		box(65,i);
	}
}
void matrisYaz(int x,int y){
		//matris 1
	gotoxy(x,y-1);printf("A. MATRIS");
	gotoxy(x,y);printf(" __________");
	gotoxy(x,y+1);printf("|___|___|___|");
	gotoxy(x,y+2);printf("|___|___|___|");
	gotoxy(x,y+3);printf("|___|___|___|");
		//matris 2
	gotoxy(x+15,y-1);printf("B. MATRIS");
	gotoxy(x+15,y);printf(" __________");
	gotoxy(x+15,y+1);printf("|___|___|___|");
	gotoxy(x+15,y+2);printf("|___|___|___|");
	gotoxy(x+15,y+3);printf("|___|___|___|");
		//result Matris

	gotoxy(x+40,y);printf(" ____________");
	gotoxy(x+40,y+1);printf("|___|___|___|");
	gotoxy(x+40,y+2);printf("|___|___|___|");
	gotoxy(x+40,y+3);printf("|___|___|___|");

		//matris 1 kullanýcýdan alýmý
	gotoxy(x+1,y+1);scanf("%d",&m1[0][0]);
	gotoxy(x+5,y+1);scanf("%d",&m1[0][1]);
	gotoxy(x+9,y+1);scanf("%d",&m1[0][2]);	
	gotoxy(x+1,y+2);scanf("%d",&m1[1][0]);
	gotoxy(x+5,y+2);scanf("%d",&m1[1][1]);
	gotoxy(x+9,y+2);scanf("%d",&m1[1][2]);	
	gotoxy(x+1,y+3);scanf("%d",&m1[2][0]);
	gotoxy(x+5,y+3);scanf("%d",&m1[2][1]);
	gotoxy(x+9,y+3);scanf("%d",&m1[2][2]);
		//matris 2 kullanýcýdan alýmý
	gotoxy(x+16,y+1);scanf("%d",&m2[0][0]);
	gotoxy(x+20,y+1);scanf("%d",&m2[0][1]);
	gotoxy(x+24,y+1);scanf("%d",&m2[0][2]);	
	gotoxy(x+16,y+2);scanf("%d",&m2[1][0]);
	gotoxy(x+20,y+2);scanf("%d",&m2[1][1]);
	gotoxy(x+24,y+2);scanf("%d",&m2[1][2]);	
	gotoxy(x+16,y+3);scanf("%d",&m2[2][0]);
	gotoxy(x+20,y+3);scanf("%d",&m2[2][1]);
	gotoxy(x+24,y+3);scanf("%d",&m2[2][2]);
	
}
void topla(){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			mToplama[i][j] = m1[i][j] + m2[i][j];
		}
	}
}

void cikar(){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			mCikarma[i][j] = m1[i][j] - m2[i][j];
		}
	}
}

void carp(){
	int k,i,j;
	for(i=0; i<3; i++){
        for(j=0; j<3; j++){            
            for(k=0; k<3; k++){
                matrisCarpim[i][j] += m1[i][k] * m2[k][j];
                m1Kare[i][j] +=m1[i][k] * m1[k][j];
            	m2Kare[i][j] +=m2[i][k] * m2[k][j];
			}
        }
    }
}

void sabitleCarp(int sabit){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			m1Result[i][j] = m1[i][j] * sabit;
			m2Result[i][j] = m2[i][j] * sabit;
		}
	}
}

int det3(int m00,int m01,int m02,int m10,int m11,int m12,int m20,int m21,int m22){
	//determinant..................(sorunsuz)
	int t1,t2;
	int x[3];
	int y[3];
	x[0]=m00*m11*m22; 
	x[1]=m10*m21*m02; 
	x[2]=m20*m01*m12; 
		
	y[0]=m02*m11*m20; 
	y[1]=m12*m21*m00; 
	y[2]=m22*m01*m10; 
	
	t1=x[0]+x[1]+x[2];// printf("t1: %d\n",t1);
	t2=y[0]+y[1]+y[2];// printf("t2: %d\n",t2);
	return (t1-t2);
}

//---------------------involitif tespit---------------------------
bool isInvolutif(){
	int i,j;
	carp();
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(m1Kare[i][j] != I[i][j]){
				return 0;
			}
		}
	}
	return 1;
}
//-------------------------------------ek matris bulumu------------------------------------------------------------

int det2(int x,int y,int z,int t){
	int result;
	result = (x*t) - (y*z);
	return result;
}

int kofactorDizisi[4];
int kofactor(int x,int y){
	int i,j,sayac=0;

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(x==i || y==j)
				continue;
			kofactorDizisi[sayac] = m1[i][j];
			sayac++;
		}
	}
}

float ekMatris[3][3];//son hali
int metrix[3][3]; //kofactör iþlemi için kullanýlacak
void EK(){//kofaktör iþleminin devamý 
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			kofactor(i,j);
			metrix[i][j] = (int)(pow((-1.0),(i+j))*(det2(kofactorDizisi[0],kofactorDizisi[1],kofactorDizisi[2],kofactorDizisi[3])));//tranpozu alýnacak.........
		}
	}
	// transpoz iþlemi
		for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			ekMatris[j][i] = (float)(metrix[i][j]);
		}
	}
}

float mT[3][3]; // ters matris

void tersMatris(){
	int i,j;
	EK();
	float h = (float)(det3(m1[0][0],m1[0][1],m1[0][2],m1[1][0],m1[1][1],m1[1][2],m1[2][0],m1[2][1],m1[2][2]));
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			mT[i][j] = (1.0)/h *ekMatris[i][j];
	    	}
    	}
   }

void toplamYaz(int x,int y){ //matris yaz fonksiyonundaki x y kullanilacak
	gotoxy(x+44,y-1);printf("A + B");
	gotoxy(x+41,y+1);printf("%d",mToplama[0][0]);
	gotoxy(x+45,y+1);printf("%d",mToplama[0][1]);
	gotoxy(x+49,y+1);printf("%d",mToplama[0][2]);
	gotoxy(x+41,y+2);printf("%d",mToplama[1][0]);
	gotoxy(x+45,y+2);printf("%d",mToplama[1][1]);
	gotoxy(x+49,y+2);printf("%d",mToplama[1][2]);
	gotoxy(x+41,y+3);printf("%d",mToplama[2][0]);
	gotoxy(x+45,y+3);printf("%d",mToplama[2][1]);
	gotoxy(x+49,y+3);printf("%d",mToplama[2][2]);	
}
void farkYaz(int x,int y){ //matris yaz fonksiyonundaki x y kullanilacak
	gotoxy(x+44,y-1);printf("A - B");
	gotoxy(x+41,y+1);printf("%d",mCikarma[0][0]);
	gotoxy(x+45,y+1);printf("%d",mCikarma[0][1]);
	gotoxy(x+49,y+1);printf("%d",mCikarma[0][2]);
	gotoxy(x+41,y+2);printf("%d",mCikarma[1][0]);
	gotoxy(x+45,y+2);printf("%d",mCikarma[1][1]);
	gotoxy(x+49,y+2);printf("%d",mCikarma[1][2]);
	gotoxy(x+41,y+3);printf("%d",mCikarma[2][0]);
	gotoxy(x+45,y+3);printf("%d",mCikarma[2][1]);
	gotoxy(x+49,y+3);printf("%d",mCikarma[2][2]);	
}
void carpimYaz(int x,int y){ //matris yaz fonksiyonundaki x y kullanilacak
	gotoxy(x+44,y-1);printf("A * B");
	gotoxy(x+41,y+1);printf("%d",matrisCarpim[0][0]);
	gotoxy(x+45,y+1);printf("%d",matrisCarpim[0][1]);
	gotoxy(x+49,y+1);printf("%d",matrisCarpim[0][2]);
	gotoxy(x+41,y+2);printf("%d",matrisCarpim[1][0]);
	gotoxy(x+45,y+2);printf("%d",matrisCarpim[1][1]);
	gotoxy(x+49,y+2);printf("%d",matrisCarpim[1][2]);
	gotoxy(x+41,y+3);printf("%d",matrisCarpim[2][0]);
	gotoxy(x+45,y+3);printf("%d",matrisCarpim[2][1]);
	gotoxy(x+49,y+3);printf("%d",matrisCarpim[2][2]);	
}
void matrisinTersi(int x,int y){ //matris yaz fonksiyonundaki x y kullanilacak
	gotoxy(x+10,y+13);printf("A nin tersi");
	gotoxy(x+10,y+14); printf("|%f  %f  %f|",mT[0][0],mT[0][1],mT[0][2]);
	gotoxy(x+10,y+15); printf("|%f  %f  %f|",mT[1][0],mT[1][1],mT[1][2]);
	gotoxy(x+10,y+16); printf("|%f  %f  %f|",mT[2][0],mT[2][1],mT[2][2]);
	
}

void toolBar(int x,int y){
	gotoxy(x,y);printf("DOGRUSAL CEBIR ODEVI");
	gotoxy(x+1,y+3);printf("");
	gotoxy(x+1,y+6);printf("1. A + B ");
	gotoxy(x+1,y+9);printf("2. A - B ");
	gotoxy(x+1,y+12);printf("3. A * B");
	gotoxy(x+1,y+15);printf("4. A nin tersi");
	gotoxy(x+1,y+18);printf("5. det(A)");
	gotoxy(x+1,y+21);printf("6. Involutiflik kontrolu (A)");
	gotoxy(x+1,y+23);printf("7. programý kapat");
	gotoxy(x+1,y+24);printf("Yalnizca 1 - 7 arasinda bir deger girin.");
}

int main(){
	system("color 0D");
	int tus;
	int secenekX=83;
	int secenekY=6;
	cerceve();
	MessageBox(NULL,"A VE B MATRISLERINI SIRASIYLA GIRIN!","UYARI!",MB_OK);
	matrisYaz(2,3);
	toolBar(67,3);
	tpzB:
	scanf("%d",&tus);
	switch(tus){
		case 1: topla();toplamYaz(2,3);break;
		case 2: cikar();farkYaz(2,3);break;
		case 3: carp();carpimYaz(2,3);break;
		case 4: tersMatris();matrisinTersi(2,3);
			
			break; 
		case 5: gotoxy(2,10); printf("\nA matrisinin determinanti = %d\n",det3(m1[0][0],m1[0][1],m1[0][2],m1[1][0],m1[1][1],m1[1][2],m1[2][0],m1[2][1],m1[2][2]));
				break;	
		case 6: if(isInvolutif() == 1){
				gotoxy(2,10);printf("A matrisi involutif matristir.");
			}
			else 
				printf("A matrisi involutif matris degildir.");
			break;
		case 7: return 0;
		default:{
			printf("Yalnis sayi girdiniz. Lutfen tekrar deneyiniz.");
			goto tpzB;
			break;
		}
}
	getch();
	MessageBox(NULL,"sistem yeniden baslatilacak","islemler sona ermistir",MB_OK);
	system("CLS");
	return main();
}
