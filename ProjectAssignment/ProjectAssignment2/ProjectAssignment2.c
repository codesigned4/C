#include <stdio.h>
#include <stdlib.h>

int comparision(char *p1,int size,char *p2){
	int i;
	for(i=0;i<size;i++){
		if (p1[i]!=p2[i])
			return 0;
	}
	return 1;	
}


int main(){


int satir,sutun,i,j,m;

int row=0,column=0;
char tipi[6]="basla";
char end[4]="end";
scanf(" %d %d",&satir,&sutun);
++sutun;
char *dizi[satir];
for(i=0;i<satir;i++){
	dizi[i]=(char*)malloc(sutun*sizeof(char));
}	
int oduller[satir][sutun];
int odul_puani;
int toplam_odulu=0;
char move;
for(i=0;i<satir;i++){//tum diziye boş karakter atadım
	for(j=0;j<sutun;j++){
		dizi[i][j]=' ';
	}
}


for(i=0;i<satir;i++){
	for(j=0;j<sutun-1;j++){
		if(i==0||i==satir-1){//ilk ve son satır için
			dizi[i][j]='*';			
			dizi[i][sutun-1]='\n';//son sutunlara \n koymak için sutun degerini verilen sutun değerinden 1 fazla aldım
			continue;
		}
		if(j==0||j==sutun-2){//ilk ve son satır haricinde satır başını ve sonunudaki birer yıldızları basmak için
			dizi[i][j]='*';
		if(j==sutun-2)
				dizi[i][j+1]='\n';
		}	
		if(j>0&&j<sutun-2)//satır aralarındaki boşlukları basmak için
			dizi[i][j]=' ';
	
	}
}

int start_x,start_y;
int bosluk_x,bosluk_y;
while(1){
	odul_puani=0;
	scanf("%s",&tipi[0]);
	if(comparision(tipi,3,end)==1)
		break;
	scanf("%d %d",&row,&column);
	
	if(tipi[0]=='s'){
		start_x=row;
		start_y=column;
		dizi[row][column]='O';
	}
	if(tipi[0]=='f'){
		bosluk_x=row;
		bosluk_y=column;
		dizi[row][column]=' ';
	}
	if(tipi[0]=='b')
		dizi[row][column]='*';
	
	if(tipi[0]=='$'){
		scanf("%d",&odul_puani);
		oduller[row][column]=odul_puani;
		dizi[row][column]='$';
	}
	if(tipi[0]=='X')
		dizi[row][column]='X';	
}

for(i=0;i<satir;i++){
	for(j=0;j<sutun;j++){
		printf("%c",dizi[i][j]);
	}
}	
printf("\n");

int karsilasma=0;
int quit=0;
int kazandi=0;
while((scanf(" %c",&move))!=EOF){
	
	switch(move){
		case 'q'://eger kullanıcı q ya basarsa quit degerini 1 arttıyorum,switch case yapısından break ile çıkıyorum
			++quit;
			printf("YOU COULD NOT REACH THE FINAL POSITION :(\nGAME IS OVER!\n");
			break;
		case 'd':
			if(dizi[start_x+1][start_y]=='X'){
				printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
				++karsilasma;
				break;
				}
			if(dizi[start_x+1][start_y]=='*')
				printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
		
			if(dizi[start_x+1][start_y]==' '||dizi[start_x+1][start_y]=='$'){
				if(dizi[start_x+1][start_y]=='$'){
					printf("YOU GOT %d $.\n",oduller[start_x+1][start_y]);
					odul_puani+=oduller[start_x+1][start_y];	
				}
				dizi[start_x][start_y]=' ';
				dizi[++start_x][start_y]='O';
			}
			if(dizi[bosluk_x][bosluk_y]==dizi[start_x][start_y]){
				printf("CONGRATS! YOU GOT %d BONUS:)\n",odul_puani);
				++kazandi;
				break;
			}
			for(i=0;i<satir;i++){
				for(j=0;j<sutun;j++){
					printf("%c",dizi[i][j]);
				}
			}
			printf("\n");
			break;
		
		
		case 'r':
			if(dizi[start_x][start_y+1]=='X'){
				printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
				++karsilasma;
				break;
				}
			if(dizi[start_x][start_y+1]=='*')
				printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");			
			
			if(dizi[start_x][start_y+1]==' '||dizi[start_x][start_y+1]=='$'){
				if(dizi[start_x][start_y+1]=='$'){
					printf("YOU GOT %d $.\n",oduller[start_x][start_y+1]);
					odul_puani+=oduller[start_x][start_y+1];	
				}
			
				dizi[start_x][start_y]=' ';
				dizi[start_x][++start_y]='O';
			}
			if(dizi[bosluk_x][bosluk_y]==dizi[start_x][start_y]){
				printf("CONGRATS! YOU GOT %d BONUS:)\n",odul_puani);
				++kazandi;
				break;
			}
			for(i=0;i<satir;i++){
				for(j=0;j<sutun;j++){
					printf("%c",dizi[i][j]);
				}
			}
			printf("\n");
			break;
			
		
		case 'u':
			if(dizi[start_x-1][start_y]=='X'){
				printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
				++karsilasma;
				break;
				}
			if(dizi[start_x-1][start_y]=='*')
				printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
			
			if(dizi[start_x-1][start_y]==' '||dizi[start_x-1][start_y]=='$'){
				if(dizi[start_x-1][start_y]=='$'){
					printf("YOU GOT %d $.\n",oduller[start_x-1][start_y]);
					odul_puani+=oduller[start_x-1][start_y];	
				}
			
				dizi[start_x][start_y]=' ';
				dizi[--start_x][start_y]='O';
			}
			if(dizi[bosluk_x][bosluk_y]==dizi[start_x][start_y]){
				printf("CONGRATS! YOU GOT %d BONUS:)\n",odul_puani);
				++kazandi;
				break;
			}
			for(i=0;i<satir;i++){
				for(j=0;j<sutun;j++){
					printf("%c",dizi[i][j]);
				}
			}	
			printf("\n");
			break;
			
		
		case 'l':
			if(dizi[start_x][start_y-1]=='X'){
				printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
				++karsilasma;
				break;
				}
			if(dizi[start_x][start_y-1]=='*')
				printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
			
			if(dizi[start_x][start_y-1]==' '||dizi[start_x][start_y-1]=='$'){
				if(dizi[start_x][start_y-1]=='$'){
					printf("YOU GOT %d $.\n",oduller[start_x][start_y-1]);
					odul_puani+=oduller[start_x][start_y-1];	
				}
				dizi[start_x][start_y]=' ';
				dizi[start_x][--start_y]='O';
			}
			if(dizi[bosluk_x][bosluk_y]==dizi[start_x][start_y]){
				printf("CONGRATS! YOU GOT %d BONUS:)\n",odul_puani);
				++kazandi;
				break;
			}
			for(i=0;i<satir;i++){
				for(j=0;j<sutun;j++){
					printf("%c",dizi[i][j]);
				}
			}
			printf("\n");
			break;
	
	}
	

	if(karsilasma==1||quit==1||kazandi==1)//her döngüde quit yapılmışmı veya düşmanla karşılaşılmış mı diye kontrol ediyorum
	break;//düşmanla karşılaşma kontrolunu her seferinde r,u,d,l ile yapıyorum ve eğer bir sefer bile karşılaştıysam break ile switch case den çıkıyorum,buradaki if ile de o kontorlu yapıyorum eger bir sefer bile karsılastıysam direkt olarak döngüden de çıkıyorum.
}

		
	
	if(karsilasma==1||quit==1){//enemyle karsilasti veya quite basıldı final state basıyoruz
		for(i=0;i<satir;i++){
			for(j=0;j<sutun;j++){
				printf("%c",dizi[i][j]);
			}
		}
		printf("\n");
		return 0;
	}
	if(kazandi==1){
		for(i=0;i<satir;i++){
			for(j=0;j<sutun;j++){
				printf("%c",dizi[i][j]);
			}
		}
		printf("\n");
	
	}
	else{
		printf("YOU COULD NOT REACH THE FINAL POSITION :(\nGAME IS OVER!\n");
		for(i=0;i<satir;i++){
			for(j=0;j<sutun;j++){
				printf("%c",dizi[i][j]);
			}
		}
		printf("\n");
	}





return 0;
}
