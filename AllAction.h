#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int checking_login(char user[11], int *pointerofaccount);
int (*pointerofaccount);
int checking_password(char password[11], int *pointerofaccount);
int checking(char user[11]);
void newlogin();
void newpassword();
void nextline(FILE * booklist, int nbline);
int searchbook();
int checkbook(int nbline);
int action1();
int action2();
