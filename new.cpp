#include<stdio.h>
#include<string.h>
#include<windows.h>

char *List_Hari(int sisa){
	static char hari[100];
	if(sisa==0)strcpy(hari,"Monday");
	if(sisa==1)strcpy(hari,"Tuesday");
	if(sisa==2)strcpy(hari,"Wednesday");
	if(sisa==3)strcpy(hari,"Thursday");
	if(sisa==4)strcpy(hari,"Friday");
	if(sisa==5)strcpy(hari,"Saturday");
	if(sisa==6)strcpy(hari,"Sunday");
	return(hari);
}

char *List_Weton(int sisa){
	static char weton[100];
	if(sisa==0)strcpy(weton,"Legi");
	if(sisa==1)strcpy(weton,"Pahing");
	if(sisa==2)strcpy(weton,"Pon");
	if(sisa==3)strcpy(weton,"Wage");
	if(sisa==4)strcpy(weton,"kliwon");
	return(weton);
}

char *List_Zodiak(int zum){
	static char zodiak[100];
	if(zum>=109&&zum<134)strcpy(zodiak,"Aries");
	if(zum>=134&&zum<171)strcpy(zodiak,"Taurus");
	if(zum>=171&&zum<202)strcpy(zodiak,"Gemini");
	if(zum>=202&&zum<222)strcpy(zodiak,"Cancer");
	if(zum>=222&&zum<259)strcpy(zodiak,"Leo");
	if(zum>=259&&zum<304)strcpy(zodiak,"Virgo");
	if(zum>=304&&zum<327)strcpy(zodiak,"Libra");
	if(zum>=327&&zum<334)strcpy(zodiak,"Scorpio");
	if(zum>=334&&zum<353)strcpy(zodiak,"Ophiuchus");
	if(zum>=353||zum<19)strcpy(zodiak,"Sagitarius");
	if(zum>=19&&zum<47)strcpy(zodiak,"Capricorn");
	if(zum>=47&&zum<71)strcpy(zodiak,"Aquarius");
	if(zum>=71&&zum<109)strcpy(zodiak,"Pisces");
	return(zodiak);
}

char *List_Shio(int sisa){
	static char shio[100];
	if(sisa==0)strcpy(shio,"Monkey");
	if(sisa==1)strcpy(shio,"Rooster");
	if(sisa==2)strcpy(shio,"Dog");
	if(sisa==3)strcpy(shio,"Pig");
	if(sisa==4)strcpy(shio,"Rat");
	if(sisa==5)strcpy(shio,"Ox");
	if(sisa==6)strcpy(shio,"Tiger");
	if(sisa==7)strcpy(shio,"Rabbit");
	if(sisa==8)strcpy(shio,"Dragon");
	if(sisa==9)strcpy(shio,"Snake");
	if(sisa==10)strcpy(shio,"Horse");
	if(sisa==11)strcpy(shio,"Goat");
	return(shio);
}

int Hitung(int bulan,int j,int tahun,int tanggal){
	int F=0,total,k;
	if(bulan>2){
		if(tahun%4==0)F=1;
		else F=2;
	}
	k=bulan/2;
	if(bulan>8&&bulan%2==1)k++;
	total=30*(bulan-1)+tanggal-F+k+j;
	return total;
}

int Shio(int tahun){
	int total;
	total=tahun%12;
	return total;	
}

int Zodiak(int tanggal,int bulan){
	int j=0,tahun=0,total;
	total=Hitung(bulan,j,tahun,tanggal);
	return total;	
}

int Hari(int tanggal,int bulan,int tahun){
	int total,j,i,sisa;
	i=(tahun-1)%28;
	j=i/4+i-2;
	total=Hitung(bulan,j,tahun,tanggal);
	sisa=total%7;
	return sisa;
}

int Weton(int tanggal,int bulan,int tahun){
	int total,j,sisa;
	j=((tahun-1)%20)/4;
	total=Hitung(bulan,j,tahun,tanggal);
	sisa=total%5;
	return sisa;
}

int main(){
	int tanggal,bulan,tahun,sisa;
	char hari[100],cont;
	start:system("cls");
	puts("Birth Date Calculation Program");
	puts("Complete the following data!");
	printf("Date   :");scanf("%d",&tanggal);
	printf("Month  :");scanf("%d",&bulan);
	printf("Year   :");scanf("%d",&tahun);
	puts("####################################");
	sisa=Hari(tanggal,bulan,tahun);
	printf("Day    :");puts(List_Hari(sisa));
	sisa=Weton(tanggal,bulan,tahun);
	printf("Weton  :");puts(List_Weton(sisa));
	sisa=Zodiak(tanggal,bulan);
	printf("Zodiac :");puts(List_Zodiak(sisa));
	sisa=Shio(tahun);
	printf("Shio   :");puts(List_Shio(sisa));
	puts("####################################");
	puts("press enter to repeat");
	cont=getchar();
	if((cont=getchar())=='\n')goto start;
}
