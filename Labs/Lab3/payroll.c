#include <stdio.h> 
#include <stdlib.h>

int main() {
    FILE *inFile, *outFile;

    char empNo[10];
    int dept, hoursWorked;
    float payRate, basePay;
    char exempt;

    // Open input file
    inFile = fopen("employee.txt", "r");
    if (inFile == NULL) {
        printf("Error opening employee.txt\n");
        return 1;
    }

    // Open output file
    outFile = fopen("payroll_register.txt", "w");
    if (outFile == NULL) {
        printf("Error creating payroll_register.txt\n");
        fclose(inFile);
        return 1;
    }

    // Skip header line
    char header[100];
    fgets(header, sizeof(header), inFile);

    // Write headers to output file
    fprintf(outFile, "%-10s %-10s %-10s %-8s %-15s %-10s\n",
            "EmpNo", "Dept", "PayRate", "Exempt", "HoursWorked", "BasePay");

    // Read data and process
    while (fscanf(inFile, "%s %d %f %c %d",
                  empNo, &dept, &payRate, &exempt, &hoursWorked) == 5) {

        basePay = payRate * hoursWorked;

        fprintf(outFile, "%-10s %-10d %-10.2f %-8c %-15d %-10.2f\n",
                empNo, dept, payRate, exempt, hoursWorked, basePay);
    }

    // Close files
    fclose(inFile);
    fclose(outFile);

    printf("Payroll register has been created.\n");

    return 0;
}