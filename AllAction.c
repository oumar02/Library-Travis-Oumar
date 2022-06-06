#include"AllAction.h"

int checking_login(char user[11], int *pointerofaccount){				//A function to check if the username is correct.
	
	char check[11], line[11];
	char next;
	int i, numberofaccount=0, j=0, meter=0, k=0;
	FILE* account = NULL;
	account = fopen("Account.txt","r");
	rewind(account);
	
	do{										//The number of existing accounts is counted.
		k = fgetc(account);
		if(k == '\n') numberofaccount++;
		}
		while(k != EOF);
		
	numberofaccount=numberofaccount/3;
	
	rewind(account);
	
	for(i=0; i<=numberofaccount-1; i++){						//A loop "to" check one by one the usernames already used.
		fgets(line, 10, account);

		
		
		while(meter<2){							//A "while" to take into account only usernames and not passwords.
			next=fgetc(account);
			if(next=='\n'){
				meter++;
			}
		}
		
		meter=0;
		fseek(account, 0, SEEK_CUR);
		char *supr_return;
		supr_return = strpbrk(line, "\n");
		
		if(supr_return != NULL){						//Unnecessary line breaks are removed.
			*supr_return = 0;
		}
		
		*pointerofaccount +=2;
		
		if (strcmp(user, line)==0){					//A comparison is made if the given username is the same as the username of a person already registered to refuse it.
			printf("Nom d'utilisateur correct !\n");
			fclose(account);

			return 0;
		}
		
		*pointerofaccount ++;
		
	}
	
	printf("Nom d'utilisateur incorrecte !!!\n");
	printf("L'application a fermé !\nReconnectez-vous plus tard !\n");
	fclose(account);
	return 1;
}

int checking_password(char password[11], int *pointerofaccount){			//A function to find out if the password matches the username.
	
	char line[11];
	char next;
	int i, j, meter=0;


	FILE* account = NULL;
	account = fopen("Account.txt","r");
	rewind(account);
	printf("%d\n", (*pointerofaccount));
	
	for(i=0; i<=(*pointerofaccount)-1; i++){					//A "for" loop to check the valid password.
		fgets(line, 10, account);
		line[strlen(line)-1]='\0';;
		printf("%s\n", line);
		
	}
		
	if (strcmp(password, line)==0){			//A comparison is made to see if the password given is the same as the password of the person already registered to refuse it or not.
			printf("Mot de passe correcte !\n");
			fclose(account);
			return 0;
			}

	printf("Mot de passe incorrecte !!!\n");
	printf("L'application a fermé !\nReconnectez-vous plus tard !\n");
	fclose(account);
	return 1;

}


int checking(char user[11]){

	char check[11], line[11];							//A function that checks if the username is available.
	char next;
	int i, numberofaccount=0, j, meter=0;
	FILE* account = NULL;
	account = fopen("Account.txt","r");
	
	do{										//The number of existing accounts is counted.
		i = fgetc(account);
		
		if(i == '\n') numberofaccount++;
		}
		while(i != EOF);
		
	numberofaccount=numberofaccount/3;
	rewind(account);
	
	for(i=0; i<=numberofaccount-1; i++){						//Une boucle pour vérifier un par un les nom d'utilisateur déjà utilisés.
		fgets(line, 10, account);
		
		while(meter<2){							//Un while pour prendre en compte que les nom d'utilisateur et pas les mots de passe.
			next=fgetc(account);
			if(next=='\n'){
				meter++;
				}
		}
		
		meter=0;
		fseek(account, 0, SEEK_CUR);
		char *supr_return;							
		supr_return = strpbrk(line, "\n");
		
		if(supr_return != NULL){						//Unnecessary line breaks are removed.
		*supr_return = 0;
		}
		
	if (strcmp(user, line)==0){						//A comparison is made if the given username is the same as the username of a person already registered to refuse it.
			printf("Un autre utilisateur possède déjà ce nom !!!\n");
			fclose(account);
			return 1;
			}
			
	}
	
	printf("Login disponible !\n");
	fclose(account);
	return 0;
}


void newlogin(){

	char newlogin[11];								//A function to create a new user name and enter it in the list of accounts.
	char next[]="\n";
	int identity;
	FILE* account=NULL;
	account = fopen("Account.txt","a");
											//A name with more than 0 characters and less than 10 characters is requested, otherwise it is requested again.
	printf("Nom d'utilisateur: (10 charactères autorisés)\n!!!! Les autres caractères ne seront pas pris en compte !!!!\n");
	scanf("%10s", newlogin);

	
	while (checking(newlogin)==1){
	
		do {
			printf("Erreur!!!!\nEssayez encore une fois !\n");
			scanf("%10s", newlogin);
		}while (strlen(newlogin)>10 || strlen(newlogin)==0);
		
	}
	
	fputs(newlogin, account);
	fputs(next, account);
	fclose(account);
}


void newpassword(){									//We do the same function but for the password and no need to check if it is already used.

	char newpassword[11];
	char next[]="\n";
	FILE* account=NULL;
	account = fopen("Account.txt", "a");
	printf("Mot de passe: (10 charactères autorisés)\n!!!! Les autres caractères ne seront pas pris en compte !!!!\n");
	scanf("%s", newpassword);
	fputs(newpassword, account);
	fputs(next, account);
	fputs(next, account);
	fclose(account);
}


void nextline(FILE * booklist, int nbline){
	int i=0;
	char car;
	while(i<nbline){
		car=fgetc(booklist);
		if(car=='\n'){
			i++;
		}
	}	
}


int searchbook(){									//A search function for the requested book.
	int numberofbook=0, j, i;
	char searchbook[999];
	char findbook[999];
	int Nbook=2;
	char c;
	char next;
	FILE* booklist=NULL;
	booklist=fopen("BookList.txt", "r");
	printf("Voici la liste de livres disponibles dans notre bibliothéque :\n");
	
	do{
		j = fgetc(booklist);
		if(j == '\n'){ numberofbook++;}
		}while(j != EOF);
		
	numberofbook=numberofbook/2;
	printf("%d\n", numberofbook);
	rewind(booklist);
	
	while((c=fgetc(booklist))!=EOF){
		printf("%c",c);
	}
	
	printf("Quel livre voulez-vous emprunter ?		(Vous devez l'écrire correctement dans son ensemble avec le(s) auteur(s) !\n");
	//gets(searchbook); //Cette fonction n'existe plus dans stdio.h
	do{
		fgets(searchbook,999,stdin);
	}while(strlen(searchbook)==1);
	rewind(booklist);
	
	for(i=0; i<=(numberofbook*2)-2; i++){
		fgets(findbook, 999, booklist);
		Nbook=Nbook+1;
		
		while(next!='\n'){
			next=fgetc(booklist);
		}
		
		fseek(booklist, 0, SEEK_CUR);
		char *supr_return;
		/*supr_return = strpbrk(findbook, "\n");
		
		if(supr_return != NULL){
		*supr_return = 0;
		}*/ //Plus besoin de ça en utilisant fgets pour récupérer searchbook
		
		if (strcmp(searchbook, findbook)==0){
			printf("Livre trouvé !!!\n");
			fclose(booklist);
			return Nbook;
		}
			
	}
	
	printf("Ce livre n'existe pas ou vous l'avez mal écrit !\n");
	fclose(booklist);
	return 0;
}

int checkbook(int nbline){								//A function to borrow a book.
	int i, j, numberofbook=0;
	char next;
	char letter;
	char available;
	char free='0';
	FILE* booklist=NULL;
	booklist=fopen("BookList.txt", "r+");
	rewind(booklist);

	nextline(booklist, nbline);
	fseek(booklist, -2, SEEK_CUR);
	available=fgetc(booklist);
	printf("%c\n%c", available, free);
	if(available == free){
		printf("Le livre n'est pas empruté !\nVous avez emprunter le livre !\n");
			fseek(booklist, -1, SEEK_CUR);
			fprintf(booklist, "1");
			fclose(booklist);
			return 0;
		}
		
	else{
		printf("Le livre est déjà emprunté !\n");
		fclose(booklist);
		return 0;
	}
	
	}



int action1(){										//Allows the connection system to be launched.
	int numberofaccount=0;
	int *pointerofaccount=&numberofaccount;
	char user[11], password[11];

	do {
	 	printf("Nom d'utilisateur:\n");
		scanf("%s", user);
	 }while(checking_login(user, pointerofaccount)==1);
	
	do {
		printf("Mot de passe:\n");
		scanf("%s", password);
	}while(checking_password(password, pointerofaccount)==1);
	
	printf("Bienvenue dans l'application!\n");
	return 1;
	
}

int action2(){										//Allows you to create an account.
	int numberofaccount=0;
	int *pointerofaccount=&numberofaccount;
	char user[11], password[11];
	
	newlogin();
	
	newpassword();
		
	printf("Compte créé!!!\n");
	return 1;
}

