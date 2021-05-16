#include <stdio.h>

int myAtoi(char* str)
{

    float res = 0.0;
 
    for (int i = 0; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';
 
    return res;
}


int main(){

float toplam_tutar=0.0;
float total_tutar=0.0;
float fiyatlar[11]={5,7,9,50,25,2.5,4.2,1.1,1.9,2.3};
char hangisinden[10];
char kac_tane[10];
printf("****************Online Shopping*****************\n1- Apple	5$\n2- Orange	7$\n3- Tomate	9$\n4- Meat   	50$\n5- Chicken	25$\n6- Milk   	2.5$\n7- Yoghurt	4.2$\n8- Egg   	1.1$\n9- Lemonate	1.9$\n10-Coke  	2.3$\n************************************************\n");

	while(1){

	scanf("%s",&hangisinden[0]);
	scanf("%s",&kac_tane[0]);

		if(hangisinden[0]=='0'){
			if(kac_tane[0]=='y'){
				printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): Are you sure (y/n) : y\n");
				printf("Have a good day...\n");	
			break;
			}
			if(kac_tane[0]=='n'){
				printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): Are you sure (y/n) : n\n");			
			}
		}

		


	int hangisindenn=0;
	if (hangisinden[0]=='-'){
		hangisindenn=myAtoi(hangisinden+(hangisinden[1]-hangisinden[0]))-1;
	}
	else{
	hangisindenn=myAtoi(hangisinden)-1;
	}
	
	float kactanee=myAtoi(kac_tane);
	
	
	if(hangisinden[0]=='-'&&hangisinden[1]=='1'){
		printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): -1\n");
		printf("Your total price is %.2f$. ",total_tutar);
		float butce=(float)myAtoi(kac_tane);
		float butce2=0;
		while(1){

			printf("How much money you enter: %.2f$\n",butce);

			if(butce>=total_tutar){
				printf("Total price has been paid. Your remaining money %.2f$. \n",butce-total_tutar);
				total_tutar=total_tutar-butce;				
				break;			
			}
			
			if (butce<total_tutar){
				printf("Your money is not enough. You must add %.2f$ for total price. ",total_tutar-butce);
				total_tutar=total_tutar-butce;
				scanf("%f",&butce2);
				butce=butce2;			
			}
				
		}
		printf("Have a good day...\n");	
		break;
	}
                         	

	if (hangisindenn==0){	
	toplam_tutar=fiyatlar[hangisindenn]*kactanee;
	total_tutar+=toplam_tutar;	
	printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): %.2f kg Apple: %.2f$\n",kactanee,toplam_tutar);
	}
	if (hangisindenn==1){	
	toplam_tutar=fiyatlar[hangisindenn]*kactanee;
	total_tutar+=toplam_tutar;	
	printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): %.2f kg Orange: %.2f$\n",kactanee,toplam_tutar);		
	}

	if (hangisindenn==2){	
	toplam_tutar=fiyatlar[hangisindenn]*kactanee;
	total_tutar+=toplam_tutar;	
	printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): %.2f kg Tomate: %.2f$\n",kactanee,toplam_tutar);
	}

	if (hangisindenn==3){	
	toplam_tutar=fiyatlar[hangisindenn]*kactanee;
	total_tutar+=toplam_tutar;
	printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): %.2f kg Meat: %.2f$\n",kactanee,toplam_tutar);
	}


	if (hangisindenn==4){	
	toplam_tutar=fiyatlar[hangisindenn]*kactanee;
	total_tutar+=toplam_tutar;
	printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): %.2f kg Chicken: %.2f$\n",kactanee,toplam_tutar);
	}

	if (hangisindenn==5){	
	toplam_tutar=fiyatlar[hangisindenn]*kactanee;
	total_tutar+=toplam_tutar;
	printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): %.2f lt Milk: %.2f$\n",kactanee,toplam_tutar);
	}

	if (hangisindenn==6){	
	toplam_tutar=fiyatlar[hangisindenn]*kactanee;
	total_tutar+=toplam_tutar;
	printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): %.2f kg Yoghurt: %.2f$\n",kactanee,toplam_tutar);
	}

	if (hangisindenn==7){	
	toplam_tutar=fiyatlar[hangisindenn]*kactanee;
	total_tutar+=toplam_tutar;
	printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): %.2f kg Egg: %.2f$\n",kactanee,toplam_tutar);
	}

	if (hangisindenn==8){	
	toplam_tutar=fiyatlar[hangisindenn]*kactanee;
	total_tutar+=toplam_tutar;
	printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): %.2f lt Lemonate: %.2f$\n",kactanee,toplam_tutar);
	}

	if (hangisindenn==9){	
	toplam_tutar=fiyatlar[hangisindenn]*kactanee;
	total_tutar+=toplam_tutar;
	printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): %.2f lt Coke: %.2f$\n",kactanee,toplam_tutar);
	}


	
	}
	


return 0;
}





