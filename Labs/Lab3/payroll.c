#include <stdio.h>
#include <stdlib.h>

int main() {
    // 7. Use of Variables & Data Types: Define fields for the employee data 
    char empNo[10], exempt, headerLine[100];
    int dept, hoursWorked;
    float payRate, basePay;

    // 1. File Handling (Input): Open employee.txt for reading [cite: 36, 59]
    FILE *inFile = fopen("employee.txt", "r");
    if (inFile == NULL) {
        printf("Error opening employee.txt\n"); // 8. Error Handling [cite: 38, 59]
        return 1;
    }

    // 2. File Handling (Output): Create payroll_register.txt for writing [cite: 41, 59]
    FILE *outFile = fopen("payroll_register.txt", "w");
    if (outFile == NULL) {
        printf("Error creating payroll_register.txt\n"); // 8. Error Handling [cite: 43, 59]
        fclose(inFile);
        return 1;
    }

    // 3. Data Reading and Parsing: Skip the header in the input file [cite: 47, 59]
    fgets(headerLine, sizeof(headerLine), inFile);

    // 5. Output Formatting: Write headers to the register [cite: 27, 48, 59]
    fprintf(outFile, "%-15s %-12s %-10s %-8s %-15s %-10s\n", 
            "Employee No.", "Department", "Pay Rate", "Exempt", "Hours Worked", "Base Pay");
    fprintf(outFile, "----------------------------------------------------------------------------\n");

    // 6. Looping & Control Logic: Read through the file until the end [cite: 49, 59]
    while (fscanf(inFile, "%s %d %f %c %d", empNo, &dept, &payRate, &exempt, &hoursWorked) == 5) {
        
        // 4. Base Pay Calculation: payRate * hoursWorked [cite: 33, 51, 59]
        basePay = payRate * hoursWorked;

        // a) Employee number should be left-justified (using %-15s) [cite: 28]
        fprintf(outFile, "%-15s %-12d %-10.2f %-8c %-15d %-10.2f\n", 
                empNo, dept, payRate, exempt, hoursWorked, basePay);
    }

    // Close files and finish [cite: 53, 54]
    fclose(inFile);
    fclose(outFile);

    printf("Payroll register has been created.\n"); // [cite: 55]

    return 0;
}