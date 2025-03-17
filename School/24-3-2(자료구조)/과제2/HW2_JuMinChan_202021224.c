#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare Structures of Customer
typedef struct {
    // Customer Name (Maximum length of 20)
    char name[21];
    // Customer Type (C: Consumer, S: Seller)
    char type;
    // Customer Phone (Optionally, specify a maximum length of 100)
    char phone[101];
    // Customer amount based on purpose (Union inside of Structure)
    union {
        int personal;
        int reselling;
    } amount;
} Customer;

// Declare the prototype of a function
void addCustomer(Customer* customers, int* size, Customer customer);
void printConsumer(Customer* customers, int size);
void printSeller(Customer* customers, int size);

// Main Function
int main() {
    // Customers Initialization
    int size = 0;
    Customer* customers = (Customer*)malloc(size*sizeof(Customer));

    // Customer variables to be entered
    Customer customer;

    printf("Please enter your customer information (<Name> <Customer Type> <Phone Number> <Amount>):\n");
    while (1) {
        // Enter Customer Name and break if "--"
        scanf("%s", customer.name);
        if (strcmp(customer.name, "--") == 0) break;

        // Enter Customer Type, Customer Phone
        scanf(" %c %s", &customer.type, customer.phone);

        // Enter the Customer Amount according to the Customer Type
        if (customer.type == 'C') scanf(" %d", &customer.amount.personal);
        if (customer.type == 'S') scanf(" %d", &customer.amount.reselling);
        
        // Insert customer into customer array
        addCustomer(customers, &size, customer);
    }

    printf("\n");
    
    // Print the maximum minimum amount and average for consumers and sellers, respectively
    printConsumer(customers, size);
    printSeller(customers, size);

    // Free the dynamically allocated memory
    free(customers);

    return 0;
}

// Add Customer Function
void addCustomer(Customer* customers, int* size, Customer customer) {
    // Increase the size of the customer array by one
    customers = (Customer*)realloc(customers,(*size+1)*sizeof(Customer));

    // Add a new customer at the end of the customer array
    customers[*size] = customer;

    // Size Update
    (*size)++;
}

// Print Consumer Function
void printConsumer(Customer* customers, int size) {
    // Declare the variable for which the mean is to be obtained
    float sum = 0;
    int num = 0;

    // Declare the consumer to store the minimum, maximum amount
    Customer minConsumer;
    Customer maxConsumer;
    minConsumer.type = 'N';
    maxConsumer.type = 'N';

    // Calculate only customers with type 'C' 
    for (int i=0; i < size; i++) {
        if (customers[i].type == 'C') {
            // Calculate the variable to obtain the mean
            sum  = (float) customers[i].amount.personal + sum;
            num++;
            
            // Change if the consumer's amount is less than the current minimum consumer's amount
            if (minConsumer.type == 'N') minConsumer = customers[i];
            if (minConsumer.amount.personal > customers[i].amount.personal) minConsumer = customers[i];

            // Change if the consumer's amount is greater than the current maximum consumer's amount
            if (maxConsumer.type == 'N') maxConsumer = customers[i];
            if (maxConsumer.amount.personal < customers[i].amount.personal) maxConsumer = customers[i];
        }
    }

    // Print the name and amount of lowest and highest consumers and the average of consumers.
    printf("Lowest consumer: %s %d\n", minConsumer.name, minConsumer.amount.personal);
    printf("Highest consumer: %s %d\n", maxConsumer.name, maxConsumer.amount.personal);
    printf("Average consumer amount: %.2f\n", sum/num);
}

// Print Seller Function
void printSeller(Customer* customers, int size) {
    // Declare the variable for which the mean is to be obtained
    float sum = 0;
    int num = 0;

    // Declare the seller to store the minimum, maximum amount
    Customer minSeller;
    Customer maxSeller;
    minSeller.type = 'N';
    maxSeller.type = 'N';

    // Calculate only customers with type 'S' 
    for (int i=0; i < size; i++) {
        if (customers[i].type == 'S') {
            // Calculate the variable to obtain the mean
            sum  = (float) customers[i].amount.reselling + sum;
            num++;

            // Change if the seller's amount is less than the current minimum seller's amount
            if (minSeller.type == 'N') minSeller = customers[i];
            if (minSeller.amount.reselling > customers[i].amount.reselling) minSeller = customers[i];

            // Change if the seller's amount is greater than the current maximum seller's amount
            if (maxSeller.type == 'N') maxSeller = customers[i];
            if (maxSeller.amount.reselling < customers[i].amount.reselling) maxSeller = customers[i];
        }
    }

    // Print the name and amount of lowest and highest sellers and the average of sellers.
    printf("Lowest seller: %s %d\n", minSeller.name, minSeller.amount.reselling);
    printf("Highest seller: %s %d\n", maxSeller.name, maxSeller.amount.reselling);
    printf("Average seller amount: %.2f\n", sum/num);
}