#include"AllAction.h"

int checking_login(FILE* account, char user[11], int *pointerofaccount){			//Une fonction pour vérifier si le nom d'utilisateur et correct.
	
	char check[11], line[11];
	char next;
	int i, numberofaccount=0, j=0, meter=0, k=0;

	rewind(account);
	
	do{										//On compte le nombre de comptes éxistants.
		k = fgetc(account);
		if(k == '\n') numberofaccount++;
		}
		while(k != EOF);
		
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
		
		if(supr_return != NULL){						//On supprime les retour à la ligne inutiles.
			*supr_return = 0;
		}
		
		*pointerofaccount +=2;
		
		if (strcmp(user, line)==0){						//On compare si le nom d'utilisateur donné est identique à celui d'une personne déjà inscrite pour le refusé.
			printf("Nom d'utilisateur correct !\n");

			return 0;
		}
		
		*pointerofaccount ++;
		
	}
	
	printf("Nom d'utilisateur incorrecte !!!\n");
	printf("L'application a fermé !\nReconnectez-vous plus tard !\n");

	return 1;
}

int checking_password ( FILE * account, char password[11], int *pointerofaccount){			//Une fonction pour savoir si le mot de passe correspond au nom d'utilisateur.
	
	char line[11];
	char next;
	int i, j, meter=0;


	fgets(line, 10, account);
	
	
	/*for(i=0; i<*pointerofaccount; i++){					//Une boucle pour vérifier le mot de passe valide.
		fgets(line, 10, account);
		line[strlen(line)-1]=' ';
		printf("%s\n", line);
		
	}*/
		
	if (strcmp(password, line)==0){						//On compare si le mot de passe donné est identique à celui de la personne déjà inscrite pour le refusé ou pas.
			printf("Mot de passe correcte !\n");
			fclose(account);
			return 0;
			}

	printf("Mot de passe incorrecte !!!\n");
	printf("L'application a fermé !\nReconnectez-vous plus tard !\n");
	
	return 1;

}


int checking(FILE * account, char user[11]){

	char check[11], line[11];							//Une fonction qui vérifie si le nom d'utilisateur est disponible.
	char next;
	int i, numberofaccount=0, j, meter=0;
	rewind(account);
	
	do{										//On compte le nombre de comptes éxistants.
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
		
		if(supr_return != NULL){						//On supprime les retour à la ligne inutiles.
		*supr_return = 0;
		}
		
	if (strcmp(user, line)==0){							//On compare si le nom d'utilisateur donné est identique à celui d'une personne déjà inscrite pour le refusé.
			printf("Un autre utilisateur possède déjà ce nom !!!\n");
			
			return 1;
			}
			
	}
	
	printf("Login disponible !\n");
	
	return 0;
}


void newlogin(FILE * account){

	char newlogin[11];								//Une fonction pour créer un nouveau nom d'utilisateur et l'inscrire dans la liste des comptes.
	char next[]="\n";
	int identity;
	rewind(account);
											//On demande un nom avec plus de 0 caractère et moins de 10 caractères sinon on redemande.
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
}


void newpassword(FILE * account){								//On fais une même fonction mais pour le mot de passe et pas besoin de vérifier s'il est déjà utilisé.

	char newpassword[11];
	char next[]="\n";
	rewind(account);
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


int searchbook(){
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
	gets(searchbook);
	rewind(booklist);
	
	for(i=0; i<=(numberofbook*2)-2; i++){
		fgets(findbook, 999, booklist);
		Nbook=Nbook+1;
		
		while(next!='\n'){
			next=fgetc(booklist);
		}
		
		fseek(booklist, 0, SEEK_CUR);
		char *supr_return;
		supr_return = strpbrk(findbook, "\n");
		
		if(supr_return != NULL){
		*supr_return = 0;
		}
		
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

int checkbook(int nbline){
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



int action1(FILE * account){										//Permet le lancement du système de connexion.
	int numberofaccount=0;
	int *pointerofaccount=&numberofaccount;
	char user[11], password[11];
	rewind(account);

	do {
	 	printf("Nom d'utilisateur:\n");
		scanf("%s", user);
	 }while(checking_login(account, user, pointerofaccount)==1);
	
	do {
		printf("Mot de passe:\n");
		scanf("%s", password);
	}while(checking_password(account, password, pointerofaccount)==1);
	
	printf("Bienvenue dans l'application!\n");
	return 1;
	
}

int action2(FILE * account){										//Permet de faire la création d'un compte.
	int numberofaccount=0;
	int *pointerofaccount=&numberofaccount;
	char user[11], password[11];

	
	newlogin();
	
	newpassword();
		
	printf("Compte créé!!!\n");

	return 1;
}

