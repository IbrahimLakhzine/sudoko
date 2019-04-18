typedef struct {
	char Pseudo_Name[30];
	char Password[30];
	int player_Score;  
}info_players;


typedef struct players{
	info_players *info;
	struct players *next;
}players;

typedef players* listeplayer;

listeplayer head= NULL;

info_players* create_info_player(char *Password,char *Pseudo_Name){

	info_players *new_info=(info_players *)malloc(sizeof(info_players));
	strcpy(new_info->Pseudo_Name,Pseudo_Name);
	strcpy(new_info->Password,Password);
	new_info->player_Score=0;
	return new_info;
}

listeplayer create_player(info_players *new_info){
	players *new_player=(players *)malloc(sizeof(players));
	new_player->info=new_info;
	new_player->next=NULL;
	return new_player;
}

	


int  check_player(char *pseudo_nom,char *password){
	FILE *file_to_stock_players=NULL;
	file_to_stock_players=fopen("C:/Users/LAKHZINE/Desktop/sudoko/src/save_player.txt","r");
	char *searched_name=(char *)malloc(30*sizeof(char));
	char *searched_password=(char *)malloc(30*sizeof(char));;
	int flag1=0;
	while(fgetc(file_to_stock_players)!=EOF){
		
		if(strcmp(searched_name,pseudo_nom)==0 && strcmp(searched_password,password)==0){
			flag1=1;
			break;
		}
		else{ 
			fscanf(file_to_stock_players,"%s %s",searched_name,searched_password);
			}		
	}
	fclose(file_to_stock_players);
	return flag1;
}





void stock_player(char *pseudo_nom,char *password){
	FILE *file_to_stock_players=NULL;
	file_to_stock_players=fopen("C:/Users/LAKHZINE/Desktop/sudoko/src/save_player.txt","a");
	fprintf(file_to_stock_players," %s %s\n",pseudo_nom,password);
	fclose(file_to_stock_players);
}

void stock_gamestatut(int gamestatut){
	FILE *file_to_stock_gamestatut=NULL;
	file_to_stock_gamestatut=fopen("C:/Users/LAKHZINE/Desktop/sudoko/src/save_statut.txt","a");
	fprintf(file_to_stock_gamestatut,"%d\n",gamestatut);
	fclose(file_to_stock_gamestatut);
}

void stock_grille(int game_matrix[4][4]){
	FILE *file_to_stock_grille=NULL;
	file_to_stock_grille=fopen("C:/Users/LAKHZINE/Desktop/sudoko/src/save_grille.txt","a");
	
	for(int i=0;i<=3;i++){
		for(int j=0;j<=3;j++){
			fprintf(file_to_stock_grille,"%d",game_matrix[i][j]);
		}
	}
		
	
	fclose(file_to_stock_grille);
}





int load_player(char *pseudo_nom){
	FILE *file_to_stock_players=NULL;
	int i=0;
	file_to_stock_players=fopen("C:/Users/LAKHZINE/Desktop/sudoko/src/save_player.txt","r");
	char *searched_name=(char *)malloc(30*sizeof(char));
	char *searched_password=(char *)malloc(30*sizeof(char));
	while(strcmp(searched_name,pseudo_nom)!=0){
		fscanf(file_to_stock_players,"%s %s",searched_name,searched_password);
		i++;
	}
	
	fclose(file_to_stock_players);
	return i; 
}





void load_grille(int game_matrix[4][4],int ligne_num){
	int compt=0;
	char chaine[30];
	int a=0;
	int nbr;
	FILE *file_to_stock_grille=NULL;
	file_to_stock_grille=fopen("C:/Users/LAKHZINE/Desktop/sudoko/src/save_grille.txt","r");
	while(compt!=ligne_num){

		fgets(chaine,17,file_to_stock_grille);
		
		compt++;
		
	}

	
		
	
	for(int i=0;i<=3;i++){
		for(int j=0;j<=3;j++){
			game_matrix[i][j]=(-48+(int)chaine[a]);
			a++;
		}
	}
	
	fclose(file_to_stock_grille);
}




int load_gamestatut(int line){
	int gamestatut,i=0;
	FILE *file_to_stock_gamestatut=NULL;
	file_to_stock_gamestatut=fopen("C:/Users/LAKHZINE/Desktop/sudoko/src/save_statut.txt","r");
	while(i!=line){
		fscanf(file_to_stock_gamestatut,"%d",&gamestatut);
		i++;
	}	
	fclose(file_to_stock_gamestatut);
	return gamestatut;	
}






void check_player_and_deliver_point(listeplayer head,char *pseudo_nom,int point){
	listeplayer pt=head;
	while(pt!=NULL){
		
		if(strcmp(pt->info->Pseudo_Name,pseudo_nom)==0){
			pt->info->player_Score=point;
			break;
		}
		pt=pt->next;
					
	}
	
}