#include <stdio.h>
#include "STD_TYPES.h"
#include "functions.h"
struct Student {
    uint8 first_name[30];
    uint8 last_name[30];
    sint32 roll_num;
    uint8 *arr_str[2];
    sint32 age;
    uint8 gender;
};
sint32 std_count=0;
sint32 Isalpha(const uint8 *arr){
    sint32 flag;
for(sint32 i=0 ; arr[i] ; i++){
    if(!isalpha(arr[i])||arr[i]==' '){
        flag= 0;
        break;//not string
    }else{
    flag=1;
    }
}
return flag;
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
    printf("Enter student roll number you want to delete: ");
    scanf("%d",&num);
    printf("\n");
    delete_std(students,num);
    printf("Student with roll number %d is deleted\n\n",num);
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
