#include <stdio.h>



int my_strcmp(const char *a, const char *b)
{
    while (*a && *a == *b) { ++a; ++b; }
    return (int)(unsigned char)(*a) - (int)(unsigned char)(*b);
}




int main(){
	
	char end[4]="END";
	int i=0;
	int j=0;
	int point[30];
	int index=0;
	char dictionary[20][30];
	char search[20][30];

	int karsilastirma=0;
	
	while(1){
		scanf("%s",&dictionary[i][j]);

		scanf("%d",&point[index]);
			index++;
				if(my_strcmp(end, dictionary[i])==0)
					break;
				
		++i;
	}	

	i=0;
	while(scanf("%s",&search[i][j])!=EOF){
	++i;
	}

	while(j<i){
		
		while(karsilastirma<index){
			if(my_strcmp(search[j],dictionary[karsilastirma])==0){
					printf("%s %d\n",search[j],point[karsilastirma]);
				}
		
			karsilastirma++;	
		}
		karsilastirma=0;
		++j;
	}



return 0;
}
