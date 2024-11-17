// project for student managment system in c programming By Bikram Gyawali second semester of Bca of Smc college

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student{
	int id,p,sem;
	char fname[50],a[50],f[50],lname[50] ;
}s[100];
 void space(){
	printf("\n\n\t\t\t\t\t\t\t");
}
void space1(){
	printf("\n\n\t\t\t\t");
}
void Added_Data(); //calling this function at last of the code

//Function for seeDetail
void seeDetail(){
	FILE *fp;
	fp=fopen("student.txt","r");
	struct student s1;;

	while(fread(&s1,sizeof(struct student),1,fp)==1){
	
	space(); printf("Rool-No : %d",s1.id);
	space(); printf("Name : %s %s",s1.fname,s1.lname);
	space(); printf("Faculty : %s",s1.f);
	space(); printf("Semester : %d",s1.sem);
	space(); printf("Address : %s",s1.a);
	space(); printf("Phone Number : %d",s1.p);
	space();
}
	fclose(fp);
}


//Starting Search Function
void search() {
    char opt[50], sname[50];
    int rfound = 0, sid;
    struct student s1;
    FILE *fp;

    space(); printf("Search By Id or Name : ");
    scanf("%s", opt);

    fp = fopen("student.txt", "r");
    if (fp == NULL) {
        space(); printf("No records found!");
        return;
    }

    if (strcmp(opt, "id") == 0 || strcmp(opt, "Id") == 0) {
        space(); printf("Enter the Rool-No: ");
        scanf("%d", &sid);

        while (fread(&s1, sizeof(struct student), 1, fp) == 1) {
            if (sid == s1.id) {
                space(); printf("Roll-No : %d", s1.id);
                space(); printf("Name : %s %s", s1.fname, s1.lname);
                space(); printf("Faculty : %s", s1.f);
                space(); printf("Semester : %d", s1.sem);
                space(); printf("Address : %s", s1.a);
                space(); printf("Phone Number : %d", s1.p);
                rfound = 1;
                break;
            }
        }
        if (!rfound) {
            space(); printf("No record found for Rool-No %d", sid);
            space();
        }
    } else if (strcmp(opt, "name") == 0 || strcmp(opt, "Name") == 0) {
        space(); printf("Enter the Name: ");
        scanf("%s", sname);

        while (fread(&s1, sizeof(struct student), 1, fp) == 1) {
            if (strcmp(sname, s1.fname) == 0 || strcmp(sname, s1.lname) == 0) {
                space(); printf("Roll-No : %d", s1.id);
                space(); printf("Name : %s %s", s1.fname, s1.lname);
                space(); printf("Faculty : %s", s1.f);
                space(); printf("Semester : %d", s1.sem);
                space(); printf("Address : %s", s1.a);
                space(); printf("Phone Number : %d", s1.p);
                space();
                rfound = 1;
            }
        }
        if (!rfound) {
            space(); printf("No record found for Name: %s", sname);
            space();
        }
    } else {
        space(); printf("Invalid search option! Please choose 'Rool-No' or 'Name'.");
        space();
    }

    fclose(fp);
}


//Starting Delete funciton 

void delete(){ 
	FILE *fp;
	 FILE *nfp;
 	int did,found=0;
 	char dname[50],opt[50];
 	struct student s1;	
	fp = fopen("student.txt", "r");
    if (fp == NULL) {
        space(); printf("Error opening file 'student.txt'!");
        return;
    }

    nfp = fopen("newFile.txt", "w");
    if (nfp == NULL) {
        space(); printf("Error creating temporary file!");
        fclose(fp);
        return;
    }

    space(); printf("Want to delete data by 'Id' or 'Name': ");
    scanf("%s", opt);

    // Delete data by id
    if (strcmp(opt, "id") == 0 || strcmp(opt, "Id") == 0) {
        space(); printf("Enter the Roll-No: ");
        scanf("%d", &did);
        while (fread(&s1, sizeof(struct student), 1, fp) == 1) {
            if (s1.id == did) {
                found = 1;
                space(); printf("Successfully deleted the data of Roll-No %d", did);
            } else {
                fwrite(&s1, sizeof(struct student), 1, nfp);
            }
        }
        if (!found) {
            space(); printf("No record found for Roll-No: %d", did);
        }
    } 
    // Delete data by name
    else if (strcmp(opt, "name") == 0 || strcmp(opt, "Name") == 0) {
        space(); printf("Enter the Name: ");
        scanf("%s", dname);
        while (fread(&s1, sizeof(struct student), 1, fp) == 1) {
            if (strcmp(dname, s1.fname) == 0 || strcmp(dname, s1.lname) == 0) {
                found = 1;
                space(); printf("Successfully deleted the data of %s", dname);
            } else {
                fwrite(&s1, sizeof(struct student), 1, nfp);
            }
        }
        if (!found) {
            space(); printf("No record found for Name: %s", dname);
        }
    } 
    // Invalid option
    else {
        space(); printf("Invalid search option! Please choose 'Rool-No' or 'Name'.");
        fclose(fp);
        fclose(nfp);
        remove("newFile.txt");
        return;
    }

    fclose(fp);
    fclose(nfp);
    remove("student.txt"); // Correct filename
    rename("newFile.txt", "student.txt");
    
    space();
}
//starting update function

void update(){
	FILE *fp;
	struct student s1;
	int dataFound=0,uid,recordNo=0;
	long realPostion;
	fp=fopen("student.txt","r+");
	if(fp==NULL){
	space();	printf("You havenot any file in this name");
     return;
	}
	 space(); printf("Enter the Rool-No of the student that you want to update : ");
	scanf("%d",&uid);
	while(fread(&s1,sizeof(struct student),1,fp)==1){
	
	if(uid==s1.id){
	dataFound=1;
space();	printf("The old data :");
	  space(); printf("Roll-No : %d", s1.id);
                space(); printf("Name : %s %s", s1.fname, s1.lname);
                space(); printf("Faculty : %s", s1.f);
                space(); printf("Semester : %d", s1.sem);
                space(); printf("Address : %s", s1.a);
                space(); printf("Phone Number : %d", s1.p);
                space();printf("------------------------------------------------------------------------");
			space();	printf("Now Entering the New data ........ ");
			space();	printf("Enter the semester :");
				scanf("%d",&s1.sem);
				realPostion=ftell(fp)-sizeof(struct student);
				fseek(fp,realPostion,SEEK_SET);
				
				 if (fwrite(&s1, sizeof(struct student), 1, fp) == 1) {
             space();   printf("Data updated successfully!");
            } else {
                printf("Error updating data.");
            }
			break;	
	}

	}
	if(dataFound==0){
	space();	printf("Student of Id %d not found",uid);
		
	}
fclose(fp);
}
//Stating Main Section
main(){
	int choice;
	
			//Task To be Perform
space();	printf(" Welcome to Sarswati Multiple Campus\n\n ");
do{
	loop1:
 space1();printf("----------------------------------------------------------------------------------------");
space();	printf("1.Add Students");
space();	printf("2. See All Students Details ");
space();	printf("3. Search Students");
space(); printf("4. Update Detail  ");
space();	printf("5.Delete Record");
space();	printf("6.Exist");
	
		//For Geeting the choise Form User
		
space();printf("Enter the Number to perform Task:\t");
	scanf("%d",&choice);
	
	
	switch(choice){
		
		//Starting the Cases to call the function
		case 1:
		Added_Data();
			break;
			case 2 :
		seeDetail();
			break;
			case 3 :
				search();
			break;
				case 4:
			 update();
			break;
			case 5:
                   delete();
 			break;
			case 6: 
		space();	printf("Exiting...................................");
		  space();space();printf("May this system hepl you .......");
		 space();space();
		break;
			
			default :
			space();	printf("Enter the valid Number");
				break;
				
	} 
}while(choice!=6);
	
	
} 

	//Function Call for adding data
 void Added_Data(){
 	FILE *fp;
 		struct student  s;
 		int i,n;
 			fp=fopen("student.txt","a");
 		
space();	printf("Enter the number of student that you want to keep record of: ");
	scanf("%d",&n);
	

	for(i=0;i<n;i++){
	space();printf("Roll-No for student %d: ", i + 1);
       scanf("%d", &s.id);
      space();  printf(" First Name of student %d:  ", i + 1);
      scanf("%s", s.fname);
      space();   printf(" Last Name of student %d: ", i + 1);
       scanf("%s", s.lname);
       space();  printf(" Faculty of the student %d:  ", i + 1);
        scanf("%s", s.f);
       space();  printf(" Semester of the student in number %d:  ", i + 1);
       scanf("%d", &s.sem);
       
        space(); printf("Enter the Address of student %d:  ", i + 1);
       scanf("%s", s.a);
      space();  printf("Enter Phone Number for student %d:  ", i + 1);
       scanf("%d", &s.p);
        space(); printf("Sucessfully Enter the data of %d Student",i+1);
        space();
        fwrite(&s, sizeof(struct student),1,fp);
        
      
   
 }
   fclose(fp);
}


