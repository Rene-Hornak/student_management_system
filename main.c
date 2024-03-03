// C program for the student information management system
// able to add, find, count, delete and update student
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// variable to track number of students
int studentAmount = 0;

// struct to store the student
struct studentInfo {
	char firstName[50];
       	char lastName[50];	
	int rollNumber;
	float cgpa;
	int courseID[10];
} student[55];

void clearScreen(void) {
    printf("\033[H\033[J");  // ANSI escape code to clear the screen
    fflush(stdout);
}

void waitForAnyKey() {
    int input;
    printf("\n\nPress Any key to continue. ");
    input = getchar(); // Get the character
    while (getchar() != '\n'); // Consume additional characters in the input buffer
}

void addStudent();
void findRollNumber();
void findFirstName();
void findStudentRoll();
void studentTotal();
void deleteStudent();
void updateStudent();

//driver code
int main() 
{
	int choice, count;
	while (studentAmount = 1)
	{
		clearScreen();
		printf("\tThe Task that you want to perform\n\n");

		printf("1. Add the Student Details\n");
		printf("2. Find the Student Details by Roll number\n");
		printf("3. Find the Student Details by First name\n");
		printf("4. Find the Student Details by Course ID\n");
		printf("5. Find the Total number of Student\n");
		printf("6. Delete the Student Details by Roll number\n");
		printf("7. Update the Student Details by Roll number\n");
		printf("8. Exit\n");

		printf("\nEnter your choice to find the task: ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				addStudent();
				waitForAnyKey();
				break;

			case 2:
				findRollNumber();
				waitForAnyKey();
				break;
			
			case 3:
				findFirstName();
				waitForAnyKey();
				break;

			case 4:
				findStudentRoll();
				waitForAnyKey();
				break;

			case 5:
				studentTotal();
				waitForAnyKey();
				break;

			case 6:
				deleteStudent();
				waitForAnyKey();
				break;

			case 7:
				updateStudent();
				waitForAnyKey();
				break;

			case 8:
				exit(0);
				break;

			default:
				exit(0);
				break;
		}
	}
	
	return 0;
}

// function to add the student
void addStudent() 
{
	clearScreen();
	printf("Add the Student's Datails\n");
	printf("-------------------------\n\n");
	
	printf("Enter the first name of student: ");
	scanf("%s", student[studentAmount].firstName);

	printf("Enter the last name of student: ");
	scanf("%s", student[studentAmount].lastName);
	
	printf("Enter the roll number: ");
	scanf("%d", &student[studentAmount].rollNumber);
	
	printf("Enter the CGPA you obtained: ");
	scanf("%f", &student[studentAmount].cgpa);

	printf("Enter the course ID of each course (5): ");
	int j;
	for(j = 0; j < 5; j++){
		scanf("%d", &student[studentAmount].courseID[j]);
	}
	studentAmount++;
}

// function to find the student by the roll number
void findRollNumber() 
{
	int roll;

	clearScreen();
	printf("Enter the Roll Number of the students: ");
	scanf("%d", &roll);
	
	int j;
	for(j = 1; j <= studentAmount; j++)
	{
		if(roll == student[studentAmount].rollNumber)
		{
			printf("\n\tThe Student's Datails\n");
			printf("The First name is %s\n",
				student[studentAmount].firstName);
			printf("The Last name is %s\n",
				student[studentAmount].lastName);
			printf("The CGPA is %f\n",
				student[studentAmount].cgpa);
			printf("Enter the course ID of each course\n");

			int y;
			for(y = 0; y < 5; y++)
			{
				printf("The course ID are %d\n",
					student[studentAmount].courseID[y]);
			}
		}
		else
		{
			printf("\nThe Roll number not found\n");
		}
	}
}

// Function to find the student by the first name
void findFirstName()
{
	char name[50];
	
	clearScreen();
	printf("Enter the First Name of the student\n");
	scanf("%s", name);

	int temp = 0;
	
	int j;
	for(j = 1; j <= studentAmount; j++)
	{
		if(!strcmp(student[j].firstName, name))
		{
			printf("\tThe Student's Details\n");
			printf("The First name is %s\n",
				student[studentAmount].firstName);
			printf("The Last name is %s\n",
				student[studentAmount].lastName);
			printf("The Roll Number is %d\n",
				student[studentAmount].rollNumber);
			printf("The CGPA is %f\n",
				student[studentAmount].cgpa);
			printf("Enter the course ID of each course\n");
			
			int y;
			for(y = 0; y < 5; y++)
			{
				printf("The course ID are %d\n",
					student[studentAmount].courseID[y]);
			}
			temp++;
		}
		else
		{
			printf("The First name not found\n");
		}
	}
}

// function to find the student enrolled in a particular course
void findStudentRoll()
{
	int id;
	int temp = 0;

	clearScreen();
	printf("Enter the course ID\n");
	scanf("%d", &id);
	
	int j;
	for(j = 1; j <= studentAmount; j++)
	{
		int d;
		for(d = 0; d < 5; d++)
		{
			if(id == student[j].courseID[d])
			{				
				printf("\tThe Student's Details\n");
				printf("The First name is %s\n",
					student[studentAmount].firstName);
				printf("The Last name is %s\n",
					student[studentAmount].lastName);
				printf("The Roll Number is %d\n",
					student[studentAmount].rollNumber);
				printf("The CGPA is %f\n",
					student[studentAmount].cgpa);
			
				temp++;
				break;
			}
			else
			{
				printf("The Course ID not found\n");
			}
		}
	}
}

// function to print a total number of students
void studentTotal()
{
	clearScreen();
	printf("The total number of Student is %d\n", studentAmount);
	printf("You can have a max of 50 students, \n");
	printf("you can have %d more students\n", 50 - studentAmount);
}

// function to delete a student by the roll number
void deleteStudent()
{
	int roll;
	
	clearScreen();
	printf("Enter the Roll Number which you want to delete: ");
	scanf("%d", &roll);

	int j;
	for(j = 1; j <= studentAmount; j++)
	{
		if(roll == student[studentAmount].rollNumber)
		{
			int k;
			for(k = j; k < 49; k++)
			{
				student[k] = student[k + 1];
			}
			studentAmount--;
		}
	}

	printf("The Roll Number is removed Successfully\n");
}

// function to update a student data
void updateStudent() 
{
	long int number;
	clearScreen();
	printf("Enter the roll number to update the entry: ");
	scanf("%ld", &number);

	int x;
	for(x = 0; x < studentAmount; x++)
	{
		if(number == student[studentAmount].rollNumber)
		{
			printf(" 1. first name\n"
			   " 2. last name\n"
			   " 3. roll no.\n"
			   " 4. CGPA\n"
			   " 5. courses\n");
			int option;
			scanf("%d", &option);

			switch (option)
			{
				case 1:
					printf("Enter the NEW first name: \n");
					scanf("%s", student[studentAmount].firstName);
					break;
			
				case 2:
					printf("Enter the NEW last name: \n");
					scanf("%s", student[studentAmount].lastName);
					break;

				case 3:
					printf("Enter the NEW roll number: \n");
					scanf("%d", &student[studentAmount].rollNumber);
					break;

				case 4:
					printf("Enter the NEW CGPA: \n");
					scanf("%f", &student[studentAmount].cgpa);
					break;

				case 5:
					printf("Enter the NEW courses: \n");
					scanf("%d%d%d%d", &student[studentAmount].courseID[0],
										&student[studentAmount].courseID[1],
										&student[studentAmount].courseID[2],
										&student[studentAmount].courseID[4]);
					break;		
			}

			printf("UPDATED SUCCESSFULLY.\n");
		}		
	}
}