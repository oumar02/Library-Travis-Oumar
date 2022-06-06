#include"AllAction.h"

int main(){
	int choice1=0;
	int choice2=0;
	FILE* account = NULL;
	account = fopen("Account.txt","r");
	do{
		printf("--------------------------------------\n      Application CY-biblioTECH\n--------------------------------------\n");
		printf("1. Se connecter.\n2. Nouvel utilisateur ?\n3. Quitter.\n");
		scanf("%d", &choice1);
	}while(choice1 != 1 && choice1 != 2 && choice1 != 3);
	if(choice1==1){
		if(action1(account)==1){
			printf("Bienvenue dans l'application !\n");
			do{
				printf("--------------------------------------\n--------------------------------------\n");
				printf("1. Emprunter un livre.\n2. Quitter ?\n");
				scanf("%d", &choice1);
			}while(choice1 != 1 && choice1 != 2);
			
			if (choice1==1){
				int res=0;
				res=searchbook();
				checkbook(res);
				fclose(account);
			}
			else{
				printf("Au revoir!\n");
				fclose(account);
				fclose(account);
				return 0;
			}
		}
	}
	if(choice1==2){
		if(action2(account)==1){
			printf("Relancez l'application pour vous connecter !\n");
			fclose(account);
		return 0;
		}
	}
	if(choice1==3){
		printf("Au revoir!\n");
		fclose(account);
		return 0;
	}

}
