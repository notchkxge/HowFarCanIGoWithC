#include <stdbool.h>
#include <stdio.h>
#include <string.h>

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
int main(void) {
  // printf("My name is c3m4 \n");
  char buffer[5];
  int index = 100000000; // more then 100 000 000  is out of bound and fsanitize
                         // wont allow it to compile
  buffer[index] = 'A';
  printf("%c\n", buffer[index]);
  return 0;
}
