 void top_scores(players *head,int Tab_score_ordred[10]){
		listeplayer pt=head;
		int b=0;
		int i=0;
		int j=0;
		int *Tab_score;
		char **tab_name_player=(char **)malloc(10*sizeof(char *));
		for(int s=0;s<=9;s++){
			tab_name_player[s]=(char *)malloc(30*sizeof(char));
			
		}
		int a;
		while (pt !=NULL){
			Tab_score=(int *)malloc(sizeof(int));
			*(Tab_score+i)=pt->info->player_Score;
			pt=pt->next;
			i++;
		}
		//on doit trier le tableau
		int ordre=0;
		while(ordre==0){
			ordre=1;
			for(int j=0;j<=i-2;j++){
				if(*(Tab_score+j)<*(Tab_score+j+1)){
				a=*(Tab_score+j);
				*(Tab_score+j)=*(Tab_score+j+1);
				*(Tab_score+j+1)=a;
				ordre=0;
		 
			}
		}	
			for(int k=0;k<=h;k++){
				Tab_score_ordred[k]=*(Tab_score+k);
			}	

		/*pt=head;		
		while(pt!=NULL){
			if(Tab_score_ordred[b]==pt->info->player_Score){
				strcpy(tab_name_player[b],pt->info->Pseudo_Name);
								b++;
			}
			pt=pt->next;
				
		}*/
		
	}


	
}


void stock_top_players(int Tab_score_ordred[10]){
	FILE *file_to_stock=NULL;
	int h=0;
	file_to_stock=fopen("C:/Users/LAKHZINE/Desktop/sudoko/src/save_top_players.txt","r");
	while(h<10){
		for(int i=0;i<=h;i++){
			fprintf(file_to_stock,"%d\n",Tab_score_ordred[i]);	
		
		}
	}	
		
	fclose(file_to_stock);

}