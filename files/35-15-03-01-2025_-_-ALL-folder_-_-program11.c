#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct employee
{
    int id;
    char name[20];
} EMP;
EMP emp[MAX_SIZE];
int avail[MAX_SIZE];

int create_key(int num)
{
    return num % MAX_SIZE;
}

void get_emp(int key)
{
    printf("Enter the employee id :");
    scanf("%d", &emp[key].id);
    printf("Emter the employee name :");
    getchar();
    fgets(emp[key].name, 15, stdin);
}

void display()
{
    printf("\n1.Display All\n2.Filtered Display\n");
    printf("Enter your choice :");
    int choice;
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("The Complete hash table is :\n");
        printf("HTkey\tEmpId\tEmpName\n");
        for (int i = 0; i < MAX_SIZE; i++)
        {
            printf("%d\t%d\t%s\n", i, emp[i].id, emp[i].name);
        }
    }
    else if (choice == 2)
    {
        printf("The Filtered hash table is :\n");
        printf("HTkey\tEmpId\tEmpName\n");
        for (int i = 0; i < MAX_SIZE; i++)
        {
            if (avail[i] != -1)
            {
                printf("%d\t%d\t%s\n", i, emp[i].id, emp[i].name);
            }
        }
    }
}

void linear_probing(int key, int num)
{
    int count = 0;
    int flag = 0;
    if (avail[key] == -1)
    {
        avail[key] = 1;
        get_emp(key);
    }
    else
    {
        printf("Collision Detected!\n");
        // counting number of elements in Hash Table
        for (int i = 0; i < MAX_SIZE; i++)
        {
            if (avail[i] == -1)
            {
                count++;
            }
        }

        // if there is no empty place in Hash Table
        if (count == 0)
        {
            printf("Error: Hash Table is full!\n");
            return;
        }

        // if Hash Table is not full
        for (int i = key; i < MAX_SIZE; i++)
        {
            if (avail[i] == -1)
            {
                avail[i] = 1;
                get_emp(i);
                flag = 1;
                break;
            }
        }

        if (flag != 1)
        {
            for (int i = 0; i < key; i++)
            {
                if (avail[i] == -1)
                {
                    avail[i] = 1;
                    get_emp(i);
                }
            }
        }
    }
}

int main()
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        avail[i] = -1;
    }

    int num, key, ans;
    do
    {
        printf("Enter any number :");
        scanf("%d", &num);
        key = create_key(num);
        linear_probing(key, num);

        printf("Do you wish to continue? (0/1) :");
        scanf("%d", &ans);
    } while (ans);

    display();
}