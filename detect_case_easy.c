void detect_case_easy(SDL_Rect rect2,SDL_Texture *textcar,SDL_Surface *caractere,SDL_Event event,int choice,SDL_Renderer *renderer,int checktab[4][4]){
	if(event.button.x>=341 && event.button.x<=404 && event.button.y<=276 && event.button.y>=212){
		if(choice==1){
			insert_car(rect2,textcar,caractere,"src/triangle2.bmp",renderer,341,212);
			checktab[0][0]=1;
		}	
		if(choice==2){
			insert_car(rect2,textcar,caractere,"src/cercle2.bmp",renderer,341,212);
			checktab[0][0]=2;
		}	
		if(choice==3){
			insert_car(rect2,textcar,caractere,"src/carre2.bmp",renderer,341,212);
			checktab[0][0]=3;
		}	
		if(choice==4){
			insert_car(rect2,textcar,caractere,"src/etoile2.bmp",renderer,341,212);
			checktab[0][0]=4;
		}				
	}
	
	
	if(event.button.x>=536 && event.button.x<=600 && event.button.y<=276 && event.button.y>=212){
		if(choice==1){
			insert_car(rect2,textcar,caractere,"src/triangle3.bmp",renderer,536,212);
			checktab[0][3]=1;
		}	
		if(choice==2){
			insert_car(rect2,textcar,caractere,"src/cercle3.bmp",renderer,536,212);
			checktab[0][3]=2;
		}	
		if(choice==3){
			insert_car(rect2,textcar,caractere,"src/carre3.bmp",renderer,536,212);
			checktab[0][3]=3;
		}	
		if(choice==4){
			insert_car(rect2,textcar,caractere,"src/etoile3.bmp",renderer,536,212);
			checktab[0][3]=4;
		}							
	}
	
			
	
	if(event.button.x>=470 && event.button.x<=536 && event.button.y<=342 && event.button.y>=276){
		if(choice==1){
			insert_car(rect2,textcar,caractere,"src/triangle3.bmp",renderer,470,276);
			checktab[1][2]=1;
		}	
		if(choice==2){
			insert_car(rect2,textcar,caractere,"src/cercle3.bmp",renderer,470,276);
			checktab[1][2]=2;
		}	
		if(choice==3){
			insert_car(rect2,textcar,caractere,"src/carre3.bmp",renderer,470,276);
			checktab[1][2]=3;
		}	
		if(choice==4){
			insert_car(rect2,textcar,caractere,"src/etoile3.bmp",renderer,470,276);
			checktab[1][2]=4;
		}							
	}
	
	if(event.button.x>=341 && event.button.x<=404 && event.button.y<=410 && event.button.y>=342){
		if(choice==1){
			insert_car(rect2,textcar,caractere,"src/triangle1.bmp",renderer,341,342);
			checktab[2][0]=1;
		}	
		if(choice==2){
			insert_car(rect2,textcar,caractere,"src/cercle1.bmp",renderer,341,342);
			checktab[2][0]=2;
		}	
		if(choice==3){
			insert_car(rect2,textcar,caractere,"src/carre1.bmp",renderer,341,342);
			checktab[2][0]=3;
		}	
		if(choice==4){
			insert_car(rect2,textcar,caractere,"src/etoile1.bmp",renderer,341,342);
			checktab[2][0]=4;
		}							
	}
	
	if(event.button.x>=470 && event.button.x<=536 && event.button.y<=410 && event.button.y>=342){
		if(choice==1){
			insert_car(rect2,textcar,caractere,"src/triangle4.bmp",renderer,470,342);
			checktab[2][2]=1;
		}	
		if(choice==2){
			insert_car(rect2,textcar,caractere,"src/cercle4.bmp",renderer,470,342);
			checktab[2][2]=2;

		}	
		if(choice==3){
			insert_car(rect2,textcar,caractere,"src/carre4.bmp",renderer,470,342);
			checktab[2][2]=3;
		}	
		if(choice==4){
			insert_car(rect2,textcar,caractere,"src/etoile4.bmp",renderer,470,342);
			checktab[2][2]=4;
		}								
	}
	
	
	if(event.button.x>=404 && event.button.x<=470 && event.button.y<=471 && event.button.y>=410){
		if(choice==1){
			insert_car(rect2,textcar,caractere,"src/triangle1.bmp",renderer,404,410);
			checktab[3][1]=1;
		}	
		if(choice==2){
			insert_car(rect2,textcar,caractere,"src/cercle1.bmp",renderer,404,410);
			checktab[3][1]=2;
		}	
		if(choice==3){
			insert_car(rect2,textcar,caractere,"src/carre1.bmp",renderer,404,410);
			checktab[3][1]=3;
		}		
		if(choice==4){
			insert_car(rect2,textcar,caractere,"src/etoile1.bmp",renderer,404,410);
			checktab[3][1]=4;
		}							
	}
	
	if(event.button.x>=536 && event.button.x<=600 && event.button.y<=471 && event.button.y>=410){
		if(choice==1){
			insert_car(rect2,textcar,caractere,"src/triangle4.bmp",renderer,536,410);
			checktab[3][3]=1;
		}	
		if(choice==2){
			insert_car(rect2,textcar,caractere,"src/cercle4.bmp",renderer,536,410);
			checktab[3][3]=2;
		}	
		if(choice==3){
			insert_car(rect2,textcar,caractere,"src/carre4.bmp",renderer,536,410);
			checktab[3][3]=3;
		}	
		if(choice==4){
			insert_car(rect2,textcar,caractere,"src/etoile4.bmp",renderer,536,410);
			checktab[3][3]=4;
		}							
	}

}