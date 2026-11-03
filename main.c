#include <stdio.h>
#include <string.h>

/*customer properties*/

#define MAXRECORDS 100
#define CUSTOMERNAMELEN 30
#define PHONENUMBERLEN 15

struct Customer {
	char customername[CUSTOMERNAMELEN];
	char phonenumber[PHONENUMBERLEN];
	float planusage;
	float bill;
};

struct Customer customers[MAXRECORDS];


void add_record();
void view_records();
void modify_record();
void view_payment();
void delete_record();

char user_choice;
int numcustomers = 0;

int main() {
	printf("What would you like to do? 
		1. add a record 
		2. view a record 
		3. modify a record 
		4. view a payment 
		5. delete a record 
		6. exit \n");
	scanf("%c", &user_choice);

	switch (user_choice) {
	case '1':
		add_record();
		break;

	case '2':
		view_records();
		break;

	case '3':
		modify_record();
		break;

	case '4':
		view_payment();
		break;

	case '5':
		delete_record();
		break;

	case '6':
		return 0;
	}

	return 0;
}

void add_record() {
	if (numcustomers < MAXRECORDS) {
		printf("Enter Customer Name:\n ");
		scanf("%s", customers[numcustomers].customername);
		printf("Enter customer phone number: \n");
		scanf("%s", customers[numcustomers].phonenumber);
		printf("Enter customer usage:\n");
		scanf("%f", &customer[numcustomers].planusage);

		customers[numcustomers].bill = customers[numcustomers].planusage * 0.1;
		numcustomers++;

		printf("Successfully added customer record.\n");

	else printf("You have hit the customer records limit.");

	}
}