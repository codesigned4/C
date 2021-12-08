#include <stdio.h>
#include <stdlib.h>

int my_strcmp(char *a, char *b)
{
  return (*a == *b && *b == '\0')? 0 : (*a == *b)? my_strcmp(++a, ++b): 1;
} 
void copyString(char* t, char* s)
{
    while (*t++ = *s++)
        ;
}
struct Flights{
	int flightnumber;
	char departureCity[20];
	char arrivalCity[20];
	char departureDay[20];
	char departureTime[20];
	char arrivalDay[20];
	char arrivalTime[20];
	struct Flights* next;
};

struct Flights * addFlight(int flightnumber,char *departureCity,char *arrivalCity,char *departureDay,char *departureTime,char *arrivalDay,char *arrivalTime){

	struct Flights* newFlights;
	newFlights=(struct Flights*)malloc(sizeof(struct Flights));
	if(!newFlights) return NULL;
	
	newFlights->flightnumber=flightnumber;
	copyString(newFlights->departureCity,departureCity);
	copyString(newFlights->arrivalCity,arrivalCity);
	copyString(newFlights->departureDay,departureDay);		
	copyString(newFlights->departureTime,departureTime);	
	copyString(newFlights->arrivalDay,arrivalDay);
	copyString(newFlights->arrivalTime,arrivalTime);
	newFlights->next=NULL;	
	
	return newFlights;
}

void printFlight(struct Flights *p){
	
	while(p!=NULL){
		printf("%d %s %s %s %s %s %s\n",p->flightnumber,p->departureCity,p->arrivalCity,p->departureDay,p->departureTime,p->arrivalDay,p->arrivalTime);
		p=p->next;
	}
}

int searchDeparture(struct Flights *p,char *departureCity){
	int control=0;
	while(p!=NULL){
		if((my_strcmp(p->departureCity,departureCity))==0){
printf("%d %s %s %s %s %s %s\n",p->flightnumber,p->departureCity,p->arrivalCity,p->departureDay,p->departureTime,p->arrivalDay,p->arrivalTime);
			++control;
		}
	
		p=p->next;
	}
	if(control==0)
		return 0;//fail
	return 1;//success	
}

int searchFlightNumber(struct Flights * p,int number){//query by number
	int control=0;
	while(p!=NULL){
		if((p->flightnumber)==number){
			printf("%d %s %s %s %s %s %s\n",p->flightnumber,p->departureCity,p->arrivalCity,p->departureDay,p->departureTime,p->arrivalDay,p->arrivalTime);
			++control;
		}
		p=p->next;
	}
	if(control==0)//fail
		return 0;
	return 1;//success
}



int searchArrival(struct Flights *p,char *arrivalCitySearch){
	int count=0;
	while(p!=NULL){
		if((my_strcmp(p->arrivalCity,arrivalCitySearch))==0){
printf("%d %s %s %s %s %s %s\n",p->flightnumber,p->departureCity,p->arrivalCity,p->departureDay,p->departureTime,p->arrivalDay,p->arrivalTime);
			++count;
		}
	
		p=p->next;
	}
	if(count==0)
		return 0;//fail
	return 1;//success
}

struct Passengers{
 	int PflightNumber;
	char PfirstName[20];
	char PlastName[20];
	char PdepartureCity[20];
	char ParrivalCity[20];
	char PdepartureDay[20];
	struct Passengers* next;
};

struct Passengers *addPassenger(char *PfirstName,char *PlastName,char *PdepartureCity,char *ParrivalCity,char *PdepartureDay){
	struct Passengers *newPassenger;
	newPassenger=(struct Passengers *)malloc(sizeof(struct Passengers));
	if(!newPassenger) return NULL;
	copyString(newPassenger->PfirstName,PfirstName);
	copyString(newPassenger->PlastName,PlastName);
	copyString(newPassenger->PdepartureCity,PdepartureCity);
	copyString(newPassenger->ParrivalCity,ParrivalCity);
	copyString(newPassenger->PdepartureDay,PdepartureDay);
	return newPassenger;		
}

void printPassanger(struct Passengers* p){
	while(p!=NULL){
	printf("%d %s %s %s %s %s\n",p->PflightNumber,p->PfirstName,p->PlastName,p->PdepartureCity,p->ParrivalCity,p->PdepartureDay);
p=p->next;
	}
}

void printNumbers(struct Passengers* p,struct Flights* f,int flightnumber){
	int count=0;
        struct Passengers* last=p;
	while(p!=NULL){
		if(p->PflightNumber==flightnumber){ 
			++count;
		}
		p=p->next;
	}
	
	while(f!=NULL){
		if(f->flightnumber==flightnumber){
			break;
		}
		f=f->next;
	}	
	printf("%d %s %s %s %s %s %s %d\n",f->flightnumber,f->departureCity,f->arrivalCity,f->departureDay,f->departureTime,f->arrivalDay,f->arrivalTime,count);
}

void printWhichPassenger(struct Passengers *p,struct Flights *f,int flightnumber){
int count=0;
	struct Passengers* again=p;
	while(p!=NULL){
		if(p->PflightNumber==flightnumber){ 
			++count;
		}
		p=p->next;
	}

	while(f!=NULL){
		if(f->flightnumber==flightnumber){
			break;
		}
	
		f=f->next;
	}	
	printf("%d %s %s %s %s %s %s %d\n",f->flightnumber,f->departureCity,f->arrivalCity,f->departureDay,f->departureTime,f->arrivalDay,f->arrivalTime,count);
	
	while(again!=NULL){
		if(again->PflightNumber==flightnumber){ 
			printf("%s %s\n",again->PfirstName,again->PlastName);
		}

		again=again->next;
	}
}

void printResult(struct Passengers *p,struct Flights *f,char *name,char *surname){ 
	int compareName=1;
	int compareSurname=1;
	int ucusId;
	while(p!=NULL){//yolcuyu buluyoruz
		compareName=my_strcmp(p->PfirstName,name);
		compareSurname=my_strcmp(p->PlastName,surname);
		if(compareName==0&&compareSurname==0){//we found the wanted person and now we can print it to the screen
			ucusId=p->PflightNumber;
			break;
		}
		p=p->next;
	}
	
	while(f!=NULL){//finding flight

		if(f->flightnumber==ucusId){//we found the wanted flight and now we can print it to the screen
			printf("%s %s %d %s %s %s %s %s %s\n",p->PfirstName,p->PlastName,f->flightnumber,f->departureCity,f->arrivalCity,f->departureDay,f->departureTime,f->arrivalDay,f->arrivalTime);
		}
		f=f->next;
	}
}

int printNoReservations(struct Passengers* p){
	int count=0;
	int count2=0;
	int counter=0;
	struct Passengers* m=p;
	
	while(m!=NULL){
		if(m->PflightNumber==0){
			++count2;
		}
		m=m->next;
	}
	
	while(p!=NULL){
		if(p->PflightNumber==0){
			printf("%s %s %s %s %s %s\n",p->PfirstName,p->PlastName,p->PdepartureCity,p->ParrivalCity,p->PdepartureDay,"No reservation");
			++count;
			++counter;
			if(counter!=count2)
				printf("\n");
		}
		p=p->next;
	}
	if(count!=0)
		return 1;
	return 0;	
}

void addId(struct Passengers* p,struct Flights*f,char *PdepartureCity,char *ParrivalCity,char *PdepartureDay){
	int depCity=1,arCity=1,arDay=1;
	while(f!=NULL){
		
		depCity=my_strcmp(f->departureCity,PdepartureCity);
		arCity=my_strcmp(f->arrivalCity,ParrivalCity);	
		arDay=my_strcmp(f->departureDay,PdepartureDay);
		if(depCity==0&&arCity==0&&arDay==0){p->PflightNumber=f->flightnumber;}
		f=f->next;
	}
}

int main(){

int numberOfFlights=0,i=0,numberOfPassengers=0,j=0;
int flightnumber;
char departureCity[20],arrivalCity[20],departureDay[20],departureTime[20],arrivalDay[20],arrivalTime[20];
struct Flights *HEAD;
struct Flights *TAIL;
struct Flights *prev;

struct Passengers *HEAD2;
struct Passengers *TAIL2;
struct Passengers *prev2;

scanf("%d",&numberOfFlights);
scanf("%d%s%s%s%s%s%s",&flightnumber,departureCity,arrivalCity,departureDay,departureTime,arrivalDay,arrivalTime);

	HEAD=addFlight(flightnumber,departureCity,arrivalCity,departureDay,departureTime,arrivalDay,arrivalTime);
	prev=HEAD;
	++i;
while(i<numberOfFlights){
	scanf("%d",&flightnumber);
	scanf("%s",departureCity);
	scanf("%s",arrivalCity);
	scanf("%s",departureDay);
	scanf("%s",departureTime);
	scanf("%s",arrivalDay);
	scanf("%s",arrivalTime);
	TAIL=addFlight(flightnumber,departureCity,arrivalCity,departureDay,departureTime,arrivalDay,arrivalTime);			
	prev->next=TAIL;
	prev=TAIL;
	++i;
}

char PfirstName[20],PlastName[20],PdepartureCity[20],ParrivalCity[20],PdepartureDay[20];

scanf("%d",&numberOfPassengers);
scanf("%s%s%s%s%s",PfirstName,PlastName,PdepartureCity,ParrivalCity,PdepartureDay);
	
	HEAD2=addPassenger(PfirstName,PlastName,PdepartureCity,ParrivalCity,PdepartureDay);
	prev2=HEAD2;
	++j;
addId(HEAD2,HEAD,PdepartureCity,ParrivalCity,PdepartureDay);//Thanks to PdepartureCity,ParrivalCity,PdepartureDay, I find which passengers are traveling and transfer their flight IDs to that passenger.

while(j<numberOfPassengers){
	scanf("%s",PfirstName);
	scanf("%s",PlastName);
	scanf("%s",PdepartureCity);
	scanf("%s",ParrivalCity);
	scanf("%s",PdepartureDay);

	TAIL2=addPassenger(PfirstName,PlastName,PdepartureCity,ParrivalCity,PdepartureDay);			
	addId(TAIL2,HEAD,PdepartureCity,ParrivalCity,PdepartureDay);
	prev2->next=TAIL2;
	prev2=TAIL2;
	++j;
}	

int no_reservation=printNoReservations(HEAD2);
int no_reservation1=0;

int m=0,flightId=0;
char select[10],category[20],departureCitySearch[20],arrivalCitySearch[20],name[20],surname[20];//which one search,print,printwP,printR

	while(1){
		
		if(no_reservation==0){
		no_reservation++;
		}
		else{printf("\n");}
		
		
		scanf("%s",select);
		int END=my_strcmp(select,"END");
		
		if(END==0)
			break;
		
		int search=my_strcmp(select,"search");
		int print=my_strcmp(select,"print");
		int printwP=my_strcmp(select,"printwP");
		int printR=my_strcmp(select,"printR");
		
		if(search==0){
			
			scanf("%s",category);
			int flightNumber=my_strcmp(category,"flightNumber");
			int departure =my_strcmp(category,"departure");
			int arrival=my_strcmp(category,"arrival");

				if(search==0&&flightNumber==0){
					int successSearch;
					scanf("%d",&flightId);
					successSearch=searchFlightNumber(HEAD,flightId);
					if(successSearch==0){
					printf("%s %d\n","No flight with number",flightId);			
				
					}
				}
				
				
				if(search==0&&departure==0){
					int success;
					scanf("%s",departureCitySearch);
					success=searchDeparture(HEAD,departureCitySearch);
					if(success==0){
						printf("%s %s\n","No departure city",departureCitySearch);			
					}
				}
				
				if(search==0&&arrival==0){
					int successArrival;
					scanf("%s",arrivalCitySearch);
					successArrival=searchArrival(HEAD,arrivalCitySearch);
					if(successArrival==0)			
						printf("%s %s\n","No arrival city",arrivalCitySearch);
				}	
		}		
		
		if(print==0){
			
			scanf("%d",&flightId);
			printNumbers(HEAD2,HEAD,flightId);//How many flights are there with the given flight id
		}		
			
		if(printwP==0){
			scanf("%d",&flightId);
			printWhichPassenger(HEAD2,HEAD,flightId);//which passengers with their flight id
 
		}	
		
		if(printR==0){
			scanf("%s",name);
			scanf("%s",surname);
			printResult(HEAD2,HEAD,name,surname);//Prints the passenger first name, last name and his/her flight information
		}

	}	


return 0;
}









