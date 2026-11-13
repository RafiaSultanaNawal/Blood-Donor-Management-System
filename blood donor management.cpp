#include <stdio.h>


int main()

{

    char name[20];

    char phone[15];

    int group;

    int search;

    int choice;

    int found;


    FILE *file;


    while(1)

    {

        printf("\n===== Blood Donor Management System =====\n");

        printf("1. Add Donor\n");

        printf("2. Search Donor by Blood Group\n");

        printf("3. Show All Donors\n");

        printf("4. Exit\n");


        printf("Enter choice: ");

        scanf("%d", &choice);


        /* Add Donor */

        if(choice == 1)

        {

            file = fopen("donors.txt", "a");


            if(file == NULL)

            {

                printf("File Error!\n");

                return 1;

            }


            printf("\nBlood Group Number:\n");

            printf("1 = A+\n");

            printf("2 = A-\n");

            printf("3 = B+\n");

            printf("4 = B-\n");

            printf("5 = AB+\n");

            printf("6 = AB-\n");

            printf("7 = O+\n");

            printf("8 = O-\n");


            printf("Enter Blood Group Number: ");

            scanf("%d", &group);


            if(group < 1 || group > 8)

            {

                printf("Invalid Blood Group Number!\n");

                fclose(file);

                continue;

            }


            printf("Name: ");

            scanf("%s", name);


            printf("Phone Number: ");

            scanf("%s", phone);


            fprintf(file, "%s %d %s\n", name, group, phone);


            fclose(file);


            printf("Donor saved successfully!\n");

        }


        /* Search Donor by Blood Group */

        else if(choice == 2)

        {

            file = fopen("donors.txt", "r");


            if(file == NULL)

            {

                printf("No donor data found!\n");

                continue;

            }


            printf("\nBlood Group Number:\n");

            printf("1 = A+\n");

            printf("2 = A-\n");

            printf("3 = B+\n");

            printf("4 = B-\n");

            printf("5 = AB+\n");

            printf("6 = AB-\n");

            printf("7 = O+\n");

            printf("8 = O-\n");


            printf("Enter Blood Group Number: ");

            scanf("%d", &search);


            found = 0;


            while(fscanf(file, "%s %d %s",

                         name, &group, phone) != EOF)

            {

                if(group == search)

                {

                    printf("\nDonor Found!\n");

                    printf("Name: %s\n", name);

                    printf("Phone: %s\n", phone);


                    found = 1;

                }

            }


            if(found == 0)

            {

                printf("\nNo donor found for this blood group.\n");

            }


            fclose(file);

        }


        /* Show All Donors */

        else if(choice == 3)

        {

            file = fopen("donors.txt", "r");


            if(file == NULL)

            {

                printf("No donor data found!\n");

                continue;

            }


            printf("\n===== All Donors =====\n");


            while(fscanf(file, "%s %d %s",

                         name, &group, phone) != EOF)

            {

                printf("Name: %s | Blood Group: %d | Phone: %s\n",

                       name, group, phone);

            }


            fclose(file);

        }


        /* Exit */

        else if(choice == 4)

        {

            printf("Program ended.\n");

            break;

        }


        else

        {

            printf("Invalid choice!\n");

        }

    }


    return 0;

}

