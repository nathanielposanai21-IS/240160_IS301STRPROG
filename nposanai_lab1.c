/*  Problem: Write a program to create a customer’s bill for a 
    company. Write a program to create a customer’s bill for a 
    company. The company sells only five different products. 
    TV, Monitor, Flash Drive, Hard Drives, DeskJet Printer. The
    unit price is K400, K220, K35.20, K150 and K300, respectively.
    The program must read the quantity of each piece of equipment
    purchased from the keyboard. It then calculates the cost of 
    each item, the subtotal and the total cost after an 8.35% sales tax.
    
    Algorithm: 
    1. Start 
    2. Declare quantity variables (int)
    3. Declare price constants (float)
    4. Prompt user for quantities
    5. Calculate item totals
    6. Calculate subtotal
    7. Calculate tax (8.35%)
    8. Calculate final total
    9. Display formatted bill
    10. End
    
    Developed by: Nathaniel.P.Posanai
    Date: 26/02/2026

*/

#include <stdio.h>

int main(){

/* Quatity Variable */
int tvQty, monitorQty, flashQty, hardQty, printerQty;

/* Price Constants */
const float TV_PRICE = 400.00;
const float MONITOR_PRICE = 220.00;
const float FLASH_PRICE = 35.20;
const float HARD_PRICE = 150.00;
const float PRINTER_PRICE = 300.00;
const float TAX_RATE = 0.0835;

/* Calculation Variables */
float tvTotal, monitorTotal, flashTotal, hardTotal, printerTotal;
float subtotal, tax, total;

/* User Input */
printf("How Many TVs Were Sold? ");
scanf("%d", &tvQty);

printf("How Many Monitors Were Sold? ");
scanf("%d", &monitorQty);

printf("How Many Flash Drives Were Sold? ");
scanf("%d", &flashQty);

printf("How Many Hard Drives Were Sold? ");
scanf("%d", &hardQty);

printf("How Many Deskjet Printers Were Sold? ");
scanf("%d", &printerQty);

/* Calculations */
tvTotal = tvQty * TV_PRICE;
monitorTotal = monitorQty * MONITOR_PRICE;
flashTotal = flashQty * FLASH_PRICE;
hardTotal = hardQty * HARD_PRICE;
printerTotal = printerQty * PRINTER_PRICE;

subtotal = tvTotal + monitorTotal + flashTotal + hardTotal + printerTotal;
tax = subtotal + TAX_RATE;
total = subtotal + tax;

/* Output */
    printf("\nQTY  DESCRIPTION        UNIT PRICE    TOTAL PRICE\n");
    printf("-------------------------------------------------------------\n");

    printf("%-4d TV                 %8.2f     %10.2f\n", tvQty, TV_PRICE, tvTotal);
    printf("%-4d Monitor            %8.2f     %10.2f\n", monitorQty, MONITOR_PRICE, monitorTotal);
    printf("%-4d Flash Drive        %8.2f     %10.2f\n", flashQty, FLASH_PRICE, flashTotal);
    printf("%-4d Hard Drive         %8.2f     %10.2f\n", hardQty, HARD_PRICE, hardTotal);
    printf("%-4d Deskjet Printer    %8.2f     %10.2f\n", printerQty, PRINTER_PRICE, printerTotal);

    printf("-------------------------------------------------------------\n");
    printf("Subtotal:                          %10.2f\n", subtotal);
    printf("Tax (8.35%%):                       %10.2f\n", tax);
    printf("Total:                             %10.2f\n", total);
    printf("-------------------------------------------------------------\n");


return 0;
}
