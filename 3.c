#include <stdio.h>
#include <conio.h>
#include <string.h>
#define N 10
#define SUB 5
struct student
{
    int roll;
    char name[20];
    int marks[SUB];
    int total;
    float avg;
};
void main()
{
    struct student s[N], temp;
    int i, j, sub;
    int maxMarks;
    char topName[20];
    clrscr();
   /* Input Section */
    for(i = 0; i < N; i++)
    {
        printf("\nEnter details of student %d\n", i+1);
        printf("Roll No: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf("%s", s[i].name);

        s[i].total = 0;

        for(j = 0; j < SUB; j++)
        {
            printf("Marks of Subject %d: ", j+1);
            scanf("%d", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }

        s[i].avg = s[i].total / 5.0;
    }
    clrscr();
    printf("\nRESULT SYSTEM\n");
    printf("\nRoll\tName\tTotal\tAverage\n");
    printf("-----------------------------------\n");
    for(i = 0; i < N; i++)
    {
        printf("%d\t%s\t%d\t%.2f\n",
               s[i].roll, s[i].name, s[i].total, s[i].avg);
    }
    /* Sorting for Rank (Descending Average) */
    for(i = 0; i < N-1; i++)
    {
        for(j = i+1; j < N; j++)
        {
            if(s[i].avg < s[j].avg)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    /* Display Top 3 Rankers */
    printf("\nTOP 3 RANK STUDENTS\n");
    printf("\nRank\tName\tAverage\n");
    printf("-------------------------\n");
    for(i = 0; i < 3; i++)
    {
        printf("%d\t%s\t%.2f\n", i+1, s[i].name, s[i].avg);
    }
    /* Highest Marks in Each Subject */
    printf("\nHIGHEST MARKS IN EACH SUBJECT\n");
    for(sub = 0; sub < SUB; sub++)
    {
        maxMarks = s[0].marks[sub];
        strcpy(topName, s[0].name);
        for(i = 1; i < N; i++)
        {
            if(s[i].marks[sub] > maxMarks)
            {
                maxMarks = s[i].marks[sub];
                strcpy(topName, s[i].name);
            }
        }
        printf("Subject %d: %d marks by %s\n",
               sub+1, maxMarks, topName);
    }
    getch();
}