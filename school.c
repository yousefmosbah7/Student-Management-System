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
sint32 std_count=0;
void add_std(struct Student* students) {
        printf("Enter information for student number (%d):\n", std_count+1);
        printf("\nFirst name: ");
        scanf("%s",students[std_count].first_name);
        printf("\nLast name: ");
        scanf(" %s",students[std_count].last_name);
        students[std_count].roll_num=std_count+1;
        printf("\nEnter only 2 of these courses (English,Geography,Art,Design,Science,History,Maths) to be registered in\n\n");
        printf("Enter course number one: ");
        scanf("%s",&students[std_count].arr_str[0]);
        printf("\nEnter course number two: ");
        scanf("%s",&students[std_count].arr_str[1]);
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
        students[i-1]=students[i];
    }
    std_count--;
}
void update_std(struct Student* students,sint32 number,sint32 opt){
    if(opt==1){
        printf("Enter new first name: ");
        scanf("%s",students[number-1].first_name);
    }else if(opt==2){
        printf("Enter new last name: ");
        scanf("%s",students[number-1].last_name);
    }else if(opt==3){
        printf("Enter your new roll number: ");
        scanf("%d",students[number-1].roll_num);
    }else if(opt==4){
        printf("Enter your first new course: ");
        scanf("%s",&students[number-1].arr_str[0]);
        printf("Enter your second new course: ");
        scanf("%s",&students[number-1].arr_str[1]);
        printf("\n\n");
        }else if(opt==5){
        printf("Enter your new age: ");
        scanf("%d",students[number-1].age);
    }else if(opt==6){
        printf("Enter your new age: ");
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
int main() {
sint32 std_num;
struct Student students[100];
printf("\n*********Welcome to GLORY school*********\n\n");
sint32 option;
do{
printf("1 - Add student\n\n");
printf("2 - List of student\n\n");
printf("3 - Find student by his roll number\n\n");
printf("4 - Find student by his first name\n\n");
printf("5 - Find student numbers\n\n");
printf("6 - Delete student\n\n");
printf("7 - Update student\n\n");
printf("8 - List of student registered in a course\n\n");
printf("9 - Quite\n\n");
printf("Choose between options: ");
while (scanf("%d", &option) != 1) {
while (getchar() != '\n');
printf("\nInvalid input. Please enter an integer: ");
}
printf("\n");
if(option==1){
    add_std(students);
}else if (option==2){
    if(std_count==0){
        printf("-------------------------\n");
        printf("There is no students yet\n");
        printf("-------------------------\n\n");
    }else{
    print_stds(students,std_count);
    }
}else if(option==3){
    if(std_count==0){
        printf("-------------------------\n");
        printf("There is no students yet\n");
        printf("-------------------------\n\n");
    }else{
    sint32 num;
    printf("\nEnter student roll number: ");
    scanf("%d",&num);
    find_roll(students,num-1);
    }
}else if(option==4){
    if(std_count==0){
        printf("-------------------------\n");
        printf("There is no students yet\n");
        printf("-------------------------\n\n");
    }else{
    uint8 array[20];
    printf("\nEnter student first name: ");
    scanf("%s",array);
    find_first(students,array);
    }
}else if(option==5){
    printf("\n-------------------------------------\n\n");
    printf("Number of students : %d\n",std_count);
    printf("\n-------------------------------------\n\n");
}else if(option==6){
    if(std_count==0){
        printf("-------------------------\n");
        printf("There is no students yet\n");
        printf("-------------------------\n\n");
    }else{
    sint32 num;
    printf("\nEnter student roll number you want to delete: ");
    scanf("%d",&num);
    delete_std(students,num);
    }
}else if(option==7){
    if(std_count==0){
        printf("-------------------------\n");
        printf("There is no students yet\n");
        printf("-------------------------\n\n");
    }else{
    printf("\nEnter roll number of student you want to update: ");
    sint32 number;
    while (scanf("%d", &number) != 1) {
    while (getchar() != '\n');
    printf("\nInvalid input. Please enter an integer: ");
    }    printf("\n\nUpdating options:\n\n");
    printf("1 - Update first name\n\n");
    printf("2 - Update last name\n\n");
    printf("3 - Update roll number\n\n");
    printf("4 - Update courses\n\n");
    printf("5 - Update age\n\n");
    printf("6 - Update gender\n\n");
    sint32 opt;
    printf("Choose between updating option: ");
    while (scanf("%d", &opt) != 1) {
    while (getchar() != '\n');
    printf("\nInvalid input. Please enter an integer: ");
    }    printf("\n");
    if(opt==1){
        update_std(students,number,1);
    }else if(opt==2){
        update_std(students,number,2);
    }else if(opt==3){
        update_std(students,number,3);
    }else if(opt==4){
        update_std(students,number,4);
    }else if(opt==5){
        update_std(students,number,5);
    }else if(opt==6){
        update_std(students,number,6);
    }
}
}else if(option==8){
    if(std_count==0){
        printf("-------------------------\n");
        printf("There is no students yet\n");
        printf("-------------------------\n\n");
    }else{
        uint8 *arr[10];
        printf("Enter the course you want to know students number registered in: ");
        scanf("%s",&arr);
        course_num(students,arr);
    }
}
}
while(option!=9);
printf("Thank you for visiting our site\n");
}
