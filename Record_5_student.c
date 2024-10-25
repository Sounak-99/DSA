#include<stdio.h>
#include<string.h>

struct student
{
    char name[50];
    int roll;
    float marks[10];
    float total;
};

int main()
{
   struct student students[5];
    int i,j;
    
    for(i = 0; i < 5; i++)
    {
        printf("\nEnter the student Data %d", i+1);
        printf("\nEnter the name: ");
        fflush(stdin);
        scanf("%[^\n]s", students[i].name);
        fflush(stdin);
        printf("Enter the roll: ");
        scanf("%d", &students[i].roll);
        students[i].total = 0;

         
        for(j = 0; j < 3; j++)
        {
          printf("Marks in subject %d: ", j+1);
          scanf("%f", &students[i].marks[j]);
          students[i].total += students[i].marks[j];
        }

        printf("\n");
    }


    printf("\nStudent details: ");
    for(i = 0; i < 5; i++)
    {
        printf("\nName: %s", students[i].name);
        printf("\nRoll number: %d", students[i].roll);
        printf("\nMarks %.2f, %.2f, %.2f\n", students[i].marks[0], students[i].marks[1], students[i].marks[2]);
        printf("\nTotal: %.2f", students[i].total);
        printf("\n");
    }    

    return 0;
}