#include <stdio.h>
#include "STD_TYPES.h"
struct Student {
    uint8 first_name[30];
    uint8 last_name[30];
    sint32 roll_num;
    uint8 *arr_str[2];
    sint32 age;
    uint8 gender;
};
extern sint32 std_count;
void add_std(struct Student* students){
        printf("Enter information for student number (%d):\n", std_count+1);
        do{
        printf("\nFirst name: ");
        scanf("%s",students[std_count].first_name);
        if(!Isalpha(students[std_count].first_name)){
        printf("\n\"First name must be string\"\n");
        }
        }
        while(Isalpha(students[std_count].first_name)!=1);
        do{
        printf("\nLast name: ");
        scanf("%s",students[std_count].last_name);
        if(!Isalpha(students[std_count].last_name)){
        printf("\n\"Last name must be string\"\n");
        }
        }
        while(Isalpha(students[std_count].last_name)!=1);
        students[std_count].roll_num=std_count+1;
        printf("\nEnter only 2 of these courses (English,Geography,Art,Design,Science,History,Maths) to be registered in\n\n");
        do{
        printf("Enter course number one: ");
        scanf("%s",&students[std_count].arr_str[0]);
        if(!Isalpha(&students[std_count].arr_str[0])){
        printf("\n\"Course must be string\"\n\n");
        }
        }
        while(Isalpha(&students[std_count].arr_str[0])!=1);
        do{
        printf("\nEnter course number two: ");
        scanf("%s",&students[std_count].arr_str[1]);
        if(!Isalpha(&students[std_count].arr_str[1])){
        printf("\n\"Course must be string\"\n\n");
        }
        }
        while(Isalpha(&students[std_count].arr_str[1])!=1);
        printf("\nAge: ");
        while (scanf("%d",&(students[std_count].age)) != 1) {
        while (getchar() != '\n');
        printf("\nInvalid input. Age must be an integer: ");
        }
        printf("\nGender(F/M): ");
        scanf(" %c",&students[std_count].gender);
        std_count++;
        printf("\n");
        printf("*************************************************\n\n");
}
void print_stds(struct Student* students, sint32 count) {
    for (sint32 i = 0; i < count; i++) {
        printf("\n-------------------------------------\n");
        printf("information for student number (%d):\n",i+1);
        printf("-------------------------------------\n\n");
        printf("First name: %s\n",students[i].first_name);
        printf("Last name: %s\n",students[i].last_name);
        printf("Roll number: %d\n",students[i].roll_num);
        printf("Courses: %s,%s\n",&students[i].arr_str[0],&students[i].arr_str[1]);
        printf("Age: %d\n",students[i].age);
        printf("Gender: %c\n",students[i].gender);
        printf("-------------------------------------\n");
        printf("\n");
    }
}
void find_roll(struct Student* students,sint32 count){
        //count received 0 for roll=1
        //count=0 for roll=1
        //std_count=1
        if(count+1>std_count||count+1<0){
            printf("\n-----------------------------------------------");
            printf("\nThere isn't a student with this roll number\n");
            printf("-----------------------------------------------\n\n");
        }else{
        printf("\n-------------------------------------\n\n");
        printf("First name: %s\n",students[count].first_name);
        printf("Last name: %s\n",students[count].last_name);
        printf("Roll number: %d\n",students[count].roll_num);
        printf("Courses: %s,%s\n",&students[count].arr_str[0],&students[count].arr_str[1]);
        printf("Age: %d\n",students[count].age);
        printf("Gender: %c\n",students[count].gender);
        printf("\n-------------------------------------\n");
        }
}
void find_first(struct Student* students,uint8 arr[]){
    sint32 flag=0;
    for(sint32 i=0;i<std_count;i++){
        if(!(strcmp(arr,students[i].first_name))){
        flag=1;
        printf("\n-------------------------------------\n\n");
        printf("First name: %s\n",students[i].first_name);
        printf("Last name: %s\n",students[i].last_name);
        printf("Roll number: %d\n",students[i].roll_num);
        printf("Courses: %s,%s\n",&students[i].arr_str[0],&students[i].arr_str[1]);
        printf("Age: %d\n",students[i].age);
        printf("Gender: %c\n",students[i].gender);
        printf("\n-------------------------------------\n");
        }
    }
    if(flag==0){
        printf("\n-----------------------------------------------");
        printf("\nThere isn't a student with this first name\n");
        printf("-----------------------------------------------\n\n");    }
}
void delete_std(struct Student* students,sint32 count){
    for(sint32 i=count;i<std_count;i++){
        students[i-1].age=students[i].age;
        students[i-1].gender=students[i].gender;
        students[i-1].arr_str[0]=students[i].arr_str[0];
        students[i-1].arr_str[1]=students[i].arr_str[1];
        students[i-1].first_name[30]=students[i].first_name[30];
        students[i-1].last_name[30]=students[i].last_name[30];
    }
    std_count--;
}
void update_std(struct Student* students,sint32 number,sint32 opt){
    if(opt==1){
        do{
        printf("\nEnter new first name: ");
        scanf("%s",students[number-1].first_name);
        if(!Isalpha(students[number-1].first_name)){
        printf("\n\"First name must be string\"\n");
        }
        }
        while(Isalpha(students[number-1].first_name)!=1);
        printf("\n");
    }else if(opt==2){
        do{
        printf("\nEnter new last name: ");
        scanf("%s",students[number-1].last_name);
        if(!Isalpha(students[number-1].last_name)){
        printf("\n\"Last name must be string\"\n");
        }
        }
        while(Isalpha(students[number-1].last_name)!=1);
        printf("\n");
    }else if(opt==3){
        printf("Enter your new roll number: ");
        scanf("%d",students[number-1].roll_num);
        printf("\n");
    }else if(opt==4){
        printf("Enter your first new course: ");
        scanf("%s",&students[number-1].arr_str[0]);
        printf("Enter your second new course: ");
        scanf("%s",&students[number-1].arr_str[1]);
        printf("\n\n");
        }else if(opt==5){
        printf("Enter your new age: ");
        scanf("%d",students[number-1].age);
        printf("\n");
    }else if(opt==6){
        printf("Enter your new gender: ");
        printf("\n");
        scanf("%c",&students[number-1].gender);
    }
}
void course_num(struct Student *students,uint8 *ptr){
    sint32 x=1;
    sint32 flag=0;
    for(sint32 i=0;i<std_count;i++){
        if((!(strcmp(ptr,&students[i].arr_str[0])))||(!(strcmp(ptr,&students[i].arr_str[1])))){
            flag=1;
            printf("\n[%d] - %s %s\n",x,students[i].first_name,students[i].last_name);
            x++;
        }
    }
    printf("\n");
    if(flag==0){
        printf("---------------------------------------------------\n");
        printf("No students are registered in this course till now\n");
        printf("---------------------------------------------------\n\n");
    }
}
