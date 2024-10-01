// project for student managment system in c programming By Bikram Gyawali second semester of Bca of Smc college

#include <stdio.h>

struct student{
	int r,p;
	char fn[50],ln[50],a[50] ;
}s[100];
void Added_Data();
void Search_Data(int);
main(){
	int choice ;
			//Task To be Perform
	printf(" \n\n\n %35s Welcome to Sarswati Multiple Campus \n\n\n","");
	printf("1.\tAdd\n\n");
	printf("2. \tSearch By Rool_No\n\n");
	printf("3. \tSee All Student Details \n\n");
	printf("4.\tExist\n\n");
	
		//For Geeting the choise Form User
		
	printf("Enter the Number to perform Task:\t \n");
	scanf("%d",&choice);
	
	
	switch(choice){
		case 1:
		Added_Data();
			break;
			case2 :
			Searh_Data();
			break;
			case 3 :
				printf("TEst1");
			break;
			case 4:
				printf("Existing...............");
				printf("\n\nMay this help you to keep records properly");
			break;
			default :
				printf("Enter the valid Number");
				break;
				
	}
	
	
} 

   		//Function Call for adding data
 void Added_Data(){
 		int i,id,n;
	printf("Enter the number of student that you want to keep record of: ");
	scanf("%d",&n);
	
	
	for(i=0;i<n;i++){
		 printf("\nEnter Roll-No for student %d: \n ", i + 1);
        scanf("%d", &s[i].r);
        printf("\nEnter the first Name of student %d: \n ", i + 1);
        scanf("%s", s[i].fn);
        printf("\nEnter the last Name of student %d: \n", i + 1);
        scanf("%s", s[i].ln);
         printf("\nEnter the Address of student %d: \n ", i + 1);
        scanf("%s", &s[i].a);
        printf("\nEnter Phone Number for student %d: \n ", i + 1);
        scanf("%d", &s[i].p);
//        Search_Data(n,s[i].r);
 }
}
// Calling Search Function
void Search_Data(int n){
	int f=0,id,i;
	printf("Enter the Rool Nuber : \t");
	scanf("%d",&id);
	//searching Data
	
	for (i=0;i<n;i++){
		if(id==s[i].r){
			printf("Data Founded : \n");
			printf("%d",s[i].r);
			f=1;
			break;
		}
		if(!f){
			printf("Data Not Found");
		}
	}
}

