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
void record_editor();
void view_payment();
void delete_record();

char user_choice;
int numcustomers = 0;

int main() {
	printf("What would you like to do? 1. add a record 2. view a record 3. modify a record 4. view a payment 5. delete a record 6. exit \n");
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
		scanf("%f", &customers[numcustomers].planusage);

		customers[numcustomers].bill = customers[numcustomers].planusage * 0.1;
		numcustomers++;

		printf("Successfully added customer record.\n");
	}
	else printf("You have hit the customer records limit.");
}

void view_records() {
	for (int i = 0; i < numcustomers; i++) {
		printf("Customer Name: %s\n ", customers[i].customername);
		printf("Customer phone number: %s\n ", customers[i].phonenumber);
		printf("Customer Usage: %.2f\n", customers[i].planusage);
		printf("Customer Bill: %.2f\n", customers[i].bill);
		printf("-----------------------\n");
	}

	printf("Records successfully listed.");
}

void modify_record() {
	char user_number[PHONENUMBERLEN];
	int user_found = 0;

	printf("What record would you like to modify? Enter Customer phone number:\n");
	scanf("%s", user_number);

	for (int i = 0; i < numcustomers; i++) {
		if (strcmp(user_number, customers[i].phonenumber) == 0) {
			printf("Record found!");
			user_found = 1;
			record_editor(i);
			break;
		}
	}

	if (user_found == 0)
		printf("Record was not found.\n");

}

void record_editor(int index) {
	int editor_choice;
	printf("What would you like to modify in this record? 1. Customer name 2. Phone number\n");
	scanf("%d", &editor_choice);

	if (editor_choice == 1) {
		char new_name[CUSTOMERNAMELEN];

		printf("Enter new customer name:\n");
		scanf("%s", new_name);

		strcpy(customers[index].customername, new_name);
	}
	else if (editor_choice == 2) {
		char new_phonenumber[PHONENUMBERLEN];

		printf("Enter new phone number:\n");
		scanf("%s", new_phonenumber);

		strcpy(customers[index].phonenumber, new_phonenumber);
	}
	else printf("Invalid Choice.\n");
}

void view_payment(){
	char user_number[PHONENUMBERLEN];
	int user_found = 0;

	printf("Enter a phone number: ");
	scanf("%s", user_number);

	for (int i = 0; i < numcustomers; i++){
		if (strcmp(user_number, customers[i].phonenumber) == 0){
			printf("Total Usage: %f\n", customers[i].planusage);
			printf("Bill: %f\n", customers[i].bill);
			user_found = 1;
			break;
		}
	}

	if (user_found == 0)
		printf("User not found.\n");

} 