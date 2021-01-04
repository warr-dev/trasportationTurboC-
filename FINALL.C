#include <stdio.h>
#include <conio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int chose(char choices[][30],int numchoices);
char name[30],contact[14];
void gen(int l,int d,int c,int m);
void summ(int l,int d,int c,int m);
int ex=-1;
int hw[]={0,19,38,43,63,72,91,97,104,117,125,138,162,175};//puerto to place
int inside[]={0,0,13,0,4,6,5,10,0,12,9,14,0,0};//place to intersection
int choose();
char str[][30]={"Puerto Galera","San Teodoro(Poblacion)","Baco","Calapan","Naujan","Victoria","Soccoro","Pola","Pinamalayan","Gloria","Bansud","Bongabong","Roxas","Mansalay"};
char cars[][30]={"motor (35 PHP/km) ","suv (45 PHP/km)"};
float carrate[]={35,45};
char modes[][30]={"cash","online"};
int main() {
//	char car[15];
	char response;
	int loc,drop,car,mode;
	printf("***************************************\n");
	printf("\t\tEnter Details\n");
	printf("Name:");
	scanf("%s",&name);
	printf("Contact No:");
	scanf("%s",&contact);
	printf("\n\tPlease Select Location\n");
	loc=choose();
	printf("\n\tPlease Select Drop off\n");
	drop=choose();
	printf("\n\tPlease Select Vehicle type\n");
	car=chose(cars,2);
	printf("\n\tPlease Select Mode of Payment\n");
	mode=chose(modes,2);
	summ(loc,drop,car,mode);
	gen(loc,drop,car,mode);
	getch();
	return 0;
}
int choose(){
	int numchoices,choice,i;
	numchoices = sizeof(str)/sizeof(str[0]);

	printf("****************************************\n");
	for(i=0;i<numchoices;i++){
		if(ex!=i)
		printf("(%d) %s\n",i,str[i]);
	}
	printf("****************************************\n");
	choosing:
	printf("Choice: ");
	scanf(" %d",&choice);
	if(choice==ex||choice<0||choice>=numchoices){
		printf("invalid selection.. try again...\n");
		goto choosing;
	}
	ex=choice;
	printf("You have chosen %s\n\n",str[choice]);
	return choice;
}

int chose(char choices[][30],int numchoices){
	int choice,i;
	printf("****************************************\n");
	for(i=0;i<numchoices;i++){
		printf("(%d) %s\n",i,choices[i]);
	}
	printf("****************************************\n");
	printf("Choice: ");
	scanf(" %d",&choice);
	printf("You have chosen %s\n\n",choices[choice]);
	return choice;
}
void summ(int l, int d, int c, int m){

	printf("**************************************************************\n");
	printf("\t\t\tSummary.........\n");
	printf("**************************************************************\n");
	printf("  Name: %s\n",name);
	printf("  Contact Number: %s\n",contact);
	printf("  Vehicle: %s\n",cars[c]);
	printf("  From: %s\n",str[l]);
	printf("  To: %s\n",str[d]);
	printf("  Payment Method: %s\n",modes[m]);
}
	void gen(int l, int d, int c, int m){

	float payment,mult;
	printf("**************************************************************\n");
	printf("\t\t\tGenerating receipt.........\n");
	printf("**************************************************************\n");
	printf("  Name: %s\n",name);
	printf("  Contact Number: %s\n\n\n",contact);
	printf("  Vehicle: %s\n",cars[c]);
	printf("  From: %s\n",str[l]);
	printf("  To: %s\n",str[d]);
	payment=inside[l]+inside[d];
	if(hw[l]>hw[d])
		payment+=hw[l]-hw[d];
	else
		payment+=hw[d]-hw[l];
	printf("  Distance: %4.2f KM\n",payment);
	printf("  Fair per km: %4.2f PHP\n\n\n",carrate[c]);
	payment*=carrate[c];
	printf("  Payment: %4.2f PHP\n",payment);
	printf("  Payment Method: %s\n",modes[m]);
	printf("**************************************************************\n");
	printf("********************thank you*********************************\n\n");
}
