#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define NAME_LENGTH 15

typedef struct employee
{
    int id;
    char name[NAME_LENGTH];
} EMP;

EMP emp[MAX];
int a[MAX];

int create(int num)
{
    return num % MAX;
}

void getEmp(int key)
{
    printf("Enter the employee id :");
    scanf("%d", &emp[key].id);
    getchar();
    printf("Enter the employee name :");
    fgets(emp[key].name, NAME_LENGTH, stdin);
    a[key] = 1;
    display();
}

void display()
{
    int choice;
    printf("\n1.display all\n2.filtered display\n");
    printf("Enter your choice :");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("the hash table is :\n");
        printf("\nHTkey\tEmpId\tEmpName\n");
        for (int i = 0; i < MAX; i++)
        {
            printf("%d\t%d\t%s\n", i, emp[i].id, emp[i].name);
        }
    }
    else if (choice == 2)
    {
        printf("the hash table is :\n");
        printf("\nHTkey\tEmpId\tEmpName\n");
        for (int i = 0; i < MAX; i++)
        {
            if (a[i] != -1)
            {
                printf("%d\t%d\t%s\n", i, emp[i].id, emp[i].name);
            }
        }
    }
}

void linearProbing(int key)
{
    int flag = 0;
    int count = 0;

    if (a[key] != -1)
    {
        getEmp(key);
        return;
    }

    for (int i = 0; i < MAX; i++)
    {
        if (a[i] != -1)
        {
            count++;
        }
    }

    if (count == MAX)
    {
        printf("Error: Hash table is full!\n");
        exit(1);
    }

    // linear probing
    for (int i = key; i < MAX; i++)
    {
        if (a[i] == -1)
        {
            getEmp(i);
            break;
        }
    }

    for (int i = 0; i < key; i++)
    {
        if (a[i] == -1)
        {
            getEmp(i);
            break;
        }
    }
}
int main()
{
    int data, key;
    char choice;
    for (int i = 0; i < MAX; i++)
    {
        a[i] = -1;
    }

    do
    {
        printf("enter the data :");
        scanf("%d", &data);
        key = create(data);
        linearProbing(key);
        printf("Do you want to continue! (y/n):");
        scanf("%c", &choice);
        if (choice == 'n')
        {
            break;
        }
    } while (1);

    return 0;
}