#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int action1(FILE * account);
int action2(FILE * account);
int checking_login(FILE* account, char user[11], int *pointerofaccount);
int checking_password ( FILE * account, char password[11], int *pointerofaccount);
int checking(FILE * account, char user[11]);
void newlogin(FILE * account);
void newpassword(FILE * account);
void nextline(FILE * booklist, int nbline);
int searchbook();
int checkbook(int nbline);
