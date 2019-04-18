void detect_case_easy_save(SDL_Rect rect2,SDL_Texture *textcar,SDL_Surface *caractere,SDL_Event event,SDL_Renderer *renderer,int checktab[4][4]){
	for(int i=0;i<=3;i++){
		for(int j=0;j<=3;j++){

			if(i==0 && j==0 && checktab[i][j]==0){
				insert_car(rect2,textcar,caractere,"src/nothing2.bmp",renderer,341,212);
				
			}

			if(i==0 && j==0 && checktab[i][j]==1){
				insert_car(rect2,textcar,caractere,"src/triangle2.bmp",renderer,341,212);
				
			}	
			if(i==0 && j==0 && checktab[i][j]==2){
				insert_car(rect2,textcar,caractere,"src/cercle2.bmp",renderer,341,212);
				
			}	
			if(i==0 && j==0 && checktab[i][j]==3){
				insert_car(rect2,textcar,caractere,"src/carre2.bmp",renderer,341,212);
				
			}	
			if(i==0 && j==0 && checktab[i][j]==4){
				insert_car(rect2,textcar,caractere,"src/etoile2.bmp",renderer,341,212);
				
			}				
		
		
			if(i==0 && j==3 && checktab[i][j]==0){
				insert_car(rect2,textcar,caractere,"src/nothing3.bmp",renderer,536,212);
				
			}
		
			if(i==0 && j==3 && checktab[i][j]==1){
				insert_car(rect2,textcar,caractere,"src/triangle3.bmp",renderer,536,212);
				
			}	
			if(i==0 && j==3 && checktab[i][j]==2){
				insert_car(rect2,textcar,caractere,"src/cercle3.bmp",renderer,536,212);
				checktab[0][3]=2;
			}	
			if(i==0 && j==3 && checktab[i][j]==3){
				insert_car(rect2,textcar,caractere,"src/carre3.bmp",renderer,536,212);
				
			}	
			if(i==0 && j==3 && checktab[i][j]==4){
				insert_car(rect2,textcar,caractere,"src/etoile3.bmp",renderer,536,212);
				
			}							
		
		
				
			if(i==1 && j==2 && checktab[i][j]==0){
				insert_car(rect2,textcar,caractere,"src/nothing3.bmp",renderer,470,276);
				
			}
		
			if(i==1 && j==2 && checktab[i][j]==1){
				insert_car(rect2,textcar,caractere,"src/triangle3.bmp",renderer,470,276);
				
			}	
			if(i==1 && j==2 && checktab[i][j]==2){
				insert_car(rect2,textcar,caractere,"src/cercle3.bmp",renderer,470,276);
				
			}	
			if(i==1 && j==2 && checktab[i][j]==3){
				insert_car(rect2,textcar,caractere,"src/carre3.bmp",renderer,470,276);
				
			}	
			if(i==1 && j==2 && checktab[i][j]==4){
				insert_car(rect2,textcar,caractere,"src/etoile3.bmp",renderer,470,276);
				
			}							
		
			if(i==2 && j==0 && checktab[i][j]==0){
				insert_car(rect2,textcar,caractere,"src/nothing1.bmp",renderer,341,342);
				
			}
		
			if(i==2 && j==0 && checktab[i][j]==1){
				insert_car(rect2,textcar,caractere,"src/triangle1.bmp",renderer,341,342);
				
			}	
			if(i==2 && j==0 && checktab[i][j]==2){
				insert_car(rect2,textcar,caractere,"src/cercle1.bmp",renderer,341,342);
				
			}	
			if(i==2 && j==0 && checktab[i][j]==3){
				insert_car(rect2,textcar,caractere,"src/carre1.bmp",renderer,341,342);
				
			}	
			if(i==2 && j==0 && checktab[i][j]==4){
				insert_car(rect2,textcar,caractere,"src/etoile1.bmp",renderer,341,342);
				
			}							
		
		
			if(i==2 && j==2 && checktab[i][j]==0){
				insert_car(rect2,textcar,caractere,"src/nothing4.bmp",renderer,470,342);
				
			}

			if(i==2 && j==2 && checktab[i][j]==1){
				insert_car(rect2,textcar,caractere,"src/triangle4.bmp",renderer,470,342);
				
			}	
			if(i==2 && j==2 && checktab[i][j]==2){
				insert_car(rect2,textcar,caractere,"src/cercle4.bmp",renderer,470,342);
				

			}	
			if(i==2 && j==2 && checktab[i][j]==3){
				insert_car(rect2,textcar,caractere,"src/carre4.bmp",renderer,470,342);
				
			}	
			if(i==2 && j==2 && checktab[i][j]==4){
				insert_car(rect2,textcar,caractere,"src/etoile4.bmp",renderer,470,342);
				
			}								
		
		
			if(i==3 && j==1 && checktab[i][j]==0){
				insert_car(rect2,textcar,caractere,"src/nothing1.bmp",renderer,404,410);
				
			}
		
			if(i==3 && j==1 && checktab[i][j]==1){
				insert_car(rect2,textcar,caractere,"src/triangle1.bmp",renderer,404,410);
				
			}	
			if(i==3 && j==1 && checktab[i][j]==2){
				insert_car(rect2,textcar,caractere,"src/cercle1.bmp",renderer,404,410);
				
			}	
			if(i==3 && j==1 && checktab[i][j]==3){
				insert_car(rect2,textcar,caractere,"src/carre1.bmp",renderer,404,410);
				
			}		
			if(i==3 && j==1 && checktab[i][j]==4){
				insert_car(rect2,textcar,caractere,"src/etoile1.bmp",renderer,404,410);
				
			}							
		
			if(i==3 && j==3 && checktab[i][j]==0){
				insert_car(rect2,textcar,caractere,"src/nothing4.bmp",renderer,536,410);
				
			}

			if(i==3 && j==3 && checktab[i][j]==1){
				insert_car(rect2,textcar,caractere,"src/triangle4.bmp",renderer,536,410);
				

			}	
			if(i==3 && j==3 && checktab[i][j]==2){
				insert_car(rect2,textcar,caractere,"src/cercle4.bmp",renderer,536,410);
				
			}	
			if(i==3 && j==3 && checktab[i][j]==3){
				insert_car(rect2,textcar,caractere,"src/carre4.bmp",renderer,536,410);
				
			}	
			if(i==3 && j==3 && checktab[i][j]==4){
				insert_car(rect2,textcar,caractere,"src/etoile4.bmp",renderer,536,410);
				
			}						
	
	}
		}
}