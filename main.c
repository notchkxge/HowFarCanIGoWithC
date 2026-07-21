// #include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
// #include <string.h>

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
#include <arpa/inet.h> // htons, htonl
#include <stdio.h>
int main() {
  uint16_t host_num = -0x1234;
  unsigned char *host_ptr = (unsigned char *)&host_num;
  printf("Host memory (Little Endian x86): %02X %02X\n", host_ptr[0],
         host_ptr[1]);

  // convert
  uint16_t net_num = htons(host_num);

  // Network side

  unsigned char *net_ptr = (unsigned char *)&net_num;
  printf("Network Byte Order (Big Endian): %02X %02X\n", net_ptr[0],
         net_ptr[1]);
}
