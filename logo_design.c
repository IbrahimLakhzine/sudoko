void affichage_texte(){
	SDL_Surface *text=NULL;

	TTF_Font *police=NULL;

	if(TTF_Init()==-1) {
    	SDL_Log("%s",TTF_GetError());
    	exit(1);
	}
	police=TTF_OpenFont("IndieFlower.ttf",50);


	positiontxt.x=315;
	positiontxt.y=283;
	text=TTF_RenderText_Blended(police,"you can enter");
	SDL_BlitSurface(texte,NULL,image,&positiontxt);
							


	




	TTF_Quit()



}