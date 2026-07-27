// #include <stdbool.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

/* struct Date{
    int day;
    char month[20];
    int year;
};

struct Habit{
    int id;
    char name[50];
    bool completeToday;
    struct Date date;
};

int main(){
    char answer[100];
    printf("Type what you want:\n");
    fgets(answer,100,stdin);
    printf("You typed: %s\n",answer);
    return 0; */

/*     struct Habit habitS[2];
    habitS[0].id = 1;
    strcpy(habitS[0].name, "Playing Basktball");
    habitS[0].completeToday = false;
    habitS[0].date.day = 25;
    strcpy(habitS[0].date.month, "May");
    habitS[0].date.year = 1995;

    habitS[1].id = 2;
    strcpy(habitS[1].name, "Watching matrix");
    habitS[1].completeToday = true;
    habitS[1].date.day = 12;
    strcpy(habitS[1].date.month, "February");
    habitS[1].date.year = 1998;

    for (int i = 0; i<2; i++){
        printf("Id: %d\n", habitS[i].id);
        printf("Name: %s\n",habitS[i].name);
        printf("Is it completed: %d\n",habitS[i].completeToday);
        printf("Date: %d\n", habitS[i].date.day);
        printf("Month: %s\n", habitS[i].date.month);
        printf("Date: %d\n", habitS[i].date.year);
    }
return 0;
} */

// compiling with/without gcc -Werror -Wall -Wextra -fsanitize = address -g
/*int main(void) {
  // printf("My name is c3m4 \n");
  char buffer[5];
  int index = 100000000; // more then 100 000 000  is out of bound and fsanitize
                         // wont allow it to compile
  buffer[index] = 'A';
  printf("%c\n", buffer[index]);
  return 0;
}*/
//------------------------------------------------------------------

// int main() {
//   FILE *ptr = fopen("test.txt", "r");
//
//   if (ptr == NULL) {
//     printf("%s", "error occured when creating file ");
//     exit(1);
//   }
//
//   //  char buff[100];
//   fseek(ptr, 0, SEEK_END);
//   printf("%s %ld\n", "Position in the file: ", ftell(ptr));
//
//   long filePosition = ftell(ptr);
//
//   for (long i = filePosition - 1; i >= 0; i--) {
//     fseek(ptr, i, SEEK_SET);
//     printf("%c", fgetc(ptr));
//   }
//   printf("\n");
//
//   fclose(ptr);
//
//   return 0;
// }

//-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

// Memory Peek
// #include <arpa/inet.h> // htons, htonl
// #include <stdio.h>
// int main() {
//   uint16_t host_num = 0x1234;
//   unsigned char *host_ptr = (unsigned char *)&host_num;
//   printf("Host memory (Little Endian x86): %02X %02X\n", host_ptr[0],
//          host_ptr[1]);
//
//   // convert
//   uint16_t net_num = htons(host_num);
//
//   // Network side
//
//   unsigned char *net_ptr = (unsigned char *)&net_num;
//   printf("Network Byte Order (Big Endian): %02X %02X\n", net_ptr[0],
//          net_ptr[1]);
// }
//---------------------------------------------------------------------------------------
// You have a 16-bit integer in your code: uint16_t x = 0x1A2B;
// Your computer is Little Endian (Intel/AMD).
// Question: What exact hexadecimal number will htons(x) return?
// (Show your work: what are the bytes before and after?)
//
// #include <arpa/inet.h>
// #include <stdint.h>
// #include <stdio.h>
//
// int main() {
//   uint16_t x = 0x1A2B;
//   unsigned char *host_ptr = (unsigned char *)&x;
//   printf("Little Endian format: %02X %02X\n", host_ptr[0], host_ptr[1]);
//
//   uint16_t net_num = htons(x);
//   unsigned char *host_num = (unsigned char *)&net_num;
//
//   printf("Big Endian format: %02X %02X\n", host_num[0], host_num[1]);
//
//   return 0;
// }
//-------------------------------------------------------------------------
// You are writing a UDP server. Your code receives a network packet.
// You look at the raw bytes of the UDP source port (which are the very first 2
// bytes of the UDP header) and you see this in memory: Byte 0: 0x04 , Byte 1:
// 0x00 (This 04 00 was sent over the network).
//
// Question: When you convert these 2 bytes into a local uint16_t using ntohs()
// for your code to read, what decimal number will your program see?

// #include <arpa/inet.h>
// #include <stdint.h>
// #include <stdio.h>
//
// int main() {
//   unsigned char buffer[2] = {0x04, 0x00};
//   uint16_t raw_network = *(uint16_t *)buffer;
//
//   printf("Network format: %02X %02X\n", buffer[0], buffer[1]);
//
//   unsigned char *network_byte = (unsigned char *)&raw_network;
//   uint16_t host_num = ntohs(raw_network);
//   unsigned char *host_ptr = (unsigned char *)&host_num;
//
//   printf("Host format: %02X %02X\n", host_ptr[0], host_ptr[1]);
//
//   printf("decimal format: %u\n", host_num);
//
//   return 0;
// }
// -----------------------------------------------------------------------------

// #include <arpa/inet.h>
// #include <stdint.h>
// #include <stdio.h>
//
// int main() {
//   unsigned char buffer[6] = {0x04, 0x00, 0xAC, 0x10, 0x00, 0x02};
//
//   uint16_t raw_port = *(uint16_t *)buffer;
//
//   uint16_t host_port = ntohs(raw_port);
//   unsigned char *network_port = (unsigned char *)&host_port;
//   printf("Port: %02X %02X\n", network_port[0], network_port[1]);
//
//   uint32_t raw_ip = *(uint32_t *)(buffer + 2);
//   uint32_t host_ip = ntohl(raw_ip);
//   unsigned char *network_ip = (unsigned char *)&host_ip;
//   printf("Ip format: %u. %u. %u. %u.\n", network_ip[0], network_ip[1],
//          network_ip[2], network_ip[3]);
//
//   return 0;
// }
// --------------------------------------------------------------------------------
// rerun basic C syntax, pointers, structs, memory
// 1-------------------------------------------------------------------------------------
// Write a C program that takes a floating-point number (a decimal number,
// like 3.14159) from the user and prints it, formatted to display with only two
// decimal places.
// int main(void) {
//   float x;
//   printf("enter the float number:\n");
//   scanf("%f", &x);
//   printf("%.2f\n", x);
//
//   return 0;
// }

// 2-------------------------------------------------------------------------------------
// Write a C program that prompts the user to enter two separate integers,
// calculates their sum, and then prints the result.

// int main() {
//   printf("enter 2 numbers to add:\n");
//   int x, y;
//   scanf("%d %d", &x, &y);
//   int z = x + y;
//   printf("%d\n", z);
//   return 0;
// }

// 3-------------------------------------------------------------------------------------
// Write a C program that calculates and prints the sum, difference, product,
// and quotient (division) of two integers

// int main() {
//   int x, y;
//   scanf("%d %d", &x, &y);
//   printf("addition:%d\n", x + y);
//   printf("difference:%d\n", x - y);
//
//   printf("sum:%d\n", x * y);
//   printf("division:%d\n", x / y);
//   return 0;
// }

// 4-------------------------------------------------------------------------------------
// Write a C program to read two integer values, A and B,
// and then swap their contents so that A holds the original value of B,
// and B holds the original value of A. Use a third, temporary variable.

// int main() {
//   int a, b, c;
//   scanf("%d %d", &a, &b);
//   c = a;
//   a = b;
//   b = c;
//   printf("order of a:%d of b:%d\n", a, b);
//   return 0;
// }

// 5-------------------------------------------------------------------------------------
// Write a C program swap two integer values, A and B,
// without using a third temporary variable

// int main() {
//   int a, b;
//   scanf("%d %d", &a, &b);
//   a ^= b;
//   b ^= a;
//   a ^= b;
//
//   printf("%d %d\n", a, b);
//   return 0;
// }
// 6------------------------------------------------------------------------------------
// Write a C program to print the first 10 natural numbers (1 to 10)
// in ascending order using a for loop

// int main() {
//   for (int x = 10; x > 0; x--) {
//     printf("%d ", x);
//   }
//   return 0;
// }
// while loop
// int main() {
//   int x = 10;
//   while (x > 0) {
//     x--;
//     printf("%d ", x);
//   }
//   return 0;
// }

// 7------------------------------------------------------------------------------------
// Write a C program to print odd numbers between 1 and 20
// using a do...while loop.

// int main() {
//   int i = 1;
//   do {
//     printf("%d ", i);
//     i++;
//   } while (i < 21);
//   return 0;
// }

// 8------------------------------------------------------------------------------------
// Create a simple menu-driven program that displays options
//(“1. Greet”, “2. Say Goodbye”, “3. Exit”). Use a do-while loop and
// a switch statement to repeatedly show the menu and process the user’s
// choice until they select the ‘Exit’ option.

// int main(void) {
//   int menu;
//   do {
//     if (scanf("%d", &menu) != 1) {
//       while (getchar() != '\n') {
//       }
//       printf("Invalid input!!!\n");
//       continue;
//     }
//     switch (menu) {
//     case 1:
//       printf("Greet\n");
//       break;
//
//     case 2:
//       printf("Say Goodbye\n");
//       break;
//
//     case 3:
//       printf("Exit\n");
//       return 0;
//
//     default:
//       printf("choose between 1, 2 and 3!\n");
//       break;
//     }
//   } while (1);
//   return 0;
// }

// 9------------------------------------------------------------------------------------
// Write a C program to calculate the factorial of a given non-negative integer
// N. (The factorial of N is the product of all positive integers less than or
// equal to N, denoted N!).
// int main(void) {
//   int x;
//   long long factorial = 1;
//
//   printf("enter an integer to calcutate its factorial: \n");
//   if (scanf("%d", &x) != 1) {
//     printf("error needs an integer\n");
//     return 1;
//   }
//   if (x < 0) {
//     // x *= -1;
//     printf("Error: factorial is not defined for negative numbers.\n");
//     return -1;
//   }
//   printf("you entered %d\n", x);
//
//   for (int y = 2; y <= x; y++) {
//     factorial *= y;
//   }
//   printf("%lld is the factorial of %d\n", factorial, x);
//   return 0;
// }

// 10------------------------------------------------------------------------------------
// Write a C program to counts the total number of digits in a given number.

// int main(void) {
//   int x, y = 0;
//   scanf("%d", &x);
//
//   while (x != 0) {
//     x /= 10;
//     y++;
//   }
//   printf("%d\n", y);
//   return 0;
// }

// 11------------------------------------------------------------------------------------
// Write a C program to check if a given integer is a palindrome
//(reads the same forwards and backward, e.g., 121,3553).

// int main(void) {
//   char x[100];
//
//   if (fgets(x, sizeof(x), stdin) == NULL) {
//     perror("fgets");
//     return 1;
//   }
//   // here we yoink the new line
//   size_t pos = (strcspn(x, "\n"));
//   if (x[pos] == '\n') {
//     x[pos] = '\0';
//   }
//   // here we yoink the extra buffer that we dont need
//   else {
//     int c;
//     while ((c = getchar()) != '\n' && c != EOF)
//       ;
//   }
//
//   size_t len = strlen(x);
//
//   for (int i = len - 1; i >= 0; i--) {
//     printf("%c", x[i]);
//   }
//   printf("\n");
//   return 0;
// }

// 12------------------------------------------------------------------------------------
// Write a C program to print all odd numbers between 1 and N using a single for
// loop and use the continue keyword to skip the even numbers.

// int main(void) {
//   int N = 20;
//
//   for (int x = 1; x <= N; x++) {
//     if (x % 2 == 0) {
//       continue;
//     } else {
//       printf("%d\n", x);
//     }
//   }
//   return 0;
// }

// 13------------------------------------------------------------------------------------
// Write a C program to print the first N terms of the Fibonacci series.
//(The series starts with 0, 1 and each subsequent number is the sum of the two
// preceding ones: 0,1,1,2,3,5,8,…).

// int main(void) {
//   int n = 8;
//   int d1 = 0;
//   int d2 = 1;
//   int d3 = d1 + d2;
//
//   printf("%d %d %d", d1, d2, d3);
//
//   for (int i = 3; i < n; i++) {
//     d1 = d2;
//     d2 = d3;
//     d3 = d1 + d2;
//     printf(" %d", d3);
//   }
//   printf("\n");
//
//   return 0;
// }
//
// //
// 14------------------------------------------------------------------------------------
// Write a C program that uses nested for-loops to print a solid rectangle
// pattern of asterisks (*) with 3 rows and 3 columns
// nested loop
// int main(void) {
//   for (int i = 1; i <= 3; i++) {
//     for (int j = 1; j <= 3; j++) {
//       printf("(%d %d)", i, j);
//     }
//     printf("\n");
//   }
//   return 0;
// }
// 14

// int main() {
//   for (int i = 1; i <= 3; i++) {
//     for (int j = 1; j <= 3; j++) {
//       printf("*");
//     }
//     printf("\n");
//   }
//   return 0;
// }

// 15------------------------------------------------------------------------------------
// Write a C program that prompts the user to enter 5 integer values,
// stores them in an array, and then prints all the stored elements.

// int main() {
//   int x[5];
//   printf("Enter 5 integer values\n");
//   int i;
//   for (i = 0; i < 5; i++) {
//     scanf("%d", &x[i]);
//   }
//   printf("the elements stored are: %d %d %d %d %d\n", x[0], x[1], x[2], x[3],
//          x[4]);
//
//   return 0;
// }

// 16------------------------------------------------------------------------------------
// Write a C program to calculate and print the sum of all elements in
// a pre-initialized integer array of size 5

int main(void) {
  int arr[5] = {10, 5, 20, 15, 30};

  int sum = 0;

  int len = (sizeof arr / sizeof arr[0]);
  for (int i = 0; i < len; i++) {
    sum += arr[i];
  }
  printf("%d\n", sum);
  return 0;
}
