
void go_to_next_page(char *destination,SDL_Surface *image1,SDL_Renderer *renderer,SDL_Rect rect1,SDL_Texture *texture1){
image1=SDL_LoadBMP(destination);
if(image1==NULL){
	printf("erreur");
}

texture1=SDL_CreateTextureFromSurface(renderer,image1);
SDL_FreeSurface(image1);
SDL_QueryTexture(texture1,NULL,NULL,&rect1.w,&rect1.h);
rect1.x=((largeur_window)-rect1.w)/2;
rect1.y=((hauteur_window)-rect1.h)/2;
SDL_RenderCopy(renderer,texture1,NULL,&rect1);

}