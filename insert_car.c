void insert_car(SDL_Rect recta2,SDL_Texture *textcara,SDL_Surface *caracter,char *dest_car,SDL_Renderer *rend,int i,int j){
	caracter=SDL_LoadBMP(dest_car);
	textcara=SDL_CreateTextureFromSurface(rend,caracter);
	SDL_FreeSurface(caracter);
	SDL_QueryTexture(textcara,NULL,NULL,&recta2.w,&recta2.h);
	recta2.x=i+3;
	recta2.y=j+2;
	SDL_RenderCopy(rend,textcara,NULL,&recta2);
}	