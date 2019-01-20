#include "constante.h"


int main(int argc, char *argv[])
{

	char pseudo_nom[30];
	char password[30];

	players *head=NULL;
	SDL_Window *window=NULL;
	SDL_Renderer *renderer=NULL;
	SDL_Rect rect;
	SDL_Rect rect1;

	SDL_Rect small_rect[4][4];

	SDL_Init(SDL_INIT_VIDEO);




	

	//textinputstart
	SDL_StartTextInput();


	window=SDL_CreateWindow("window",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,largeur_window,hauteur_window,SDL_WINDOW_RESIZABLE);
	renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE);
	SDL_Surface *image=NULL;
	SDL_Surface *image1=NULL;
	SDL_Texture *texture=NULL;
	SDL_Texture *texture1=NULL;



	image=SDL_LoadBMP("src/sudoko.bmp");
	if(image==NULL){
		printf("erreur");
	}



	texture=SDL_CreateTextureFromSurface(renderer,image);
	SDL_FreeSurface(image);
	SDL_QueryTexture(texture,NULL,NULL,&rect1.w,&rect1.h);
	rect1.x=((largeur_window)-rect1.w)/2;
	rect1.y=((hauteur_window)-rect1.h)/2;
	SDL_RenderCopy(renderer,texture,NULL,&rect1);

	SDL_SetRenderDrawColor(renderer,255,255,255,255);

	
 	for(int i=0;i<=3;i++){
		for(int j=0;j<=3;j++){
			small_rect[i][j].x=404;
			small_rect[i][j].y=375;
			small_rect[i][j].w=55;
			small_rect[i][j].h=55;	
			SDL_RenderDrawRect(renderer,&small_rect[i][j]);
		}
	} 
		

	SDL_RenderPresent(renderer);



	SDL_bool keepgoing=SDL_TRUE;
	while(keepgoing){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			switch(event.type){
				case SDL_QUIT:
							keepgoing=SDL_FALSE;
							break;
				case SDL_MOUSEBUTTONDOWN:
					switch(event.button.button){
						case SDL_BUTTON_LEFT:
							rect.x=event.button.x;
							rect.y=event.button.y;
							rect.h=30;
							rect.w=30;
							SDL_SetRenderDrawColor(renderer,7,55,25,255);
							SDL_RenderFillRect(renderer,&rect);break;
							default:break;
						case SDL_BUTTON_RIGHT:
								image1=SDL_LoadBMP("src/levels.bmp");
								if(image==NULL){
									printf("erreur");
								}
								texture1=SDL_CreateTextureFromSurface(renderer,image1);
								SDL_FreeSurface(image1);
								SDL_QueryTexture(texture1,NULL,NULL,&rect1.w,&rect1.h);
								rect1.x=((largeur_window)-rect1.w)/2;
								rect1.y=((hauteur_window)-rect1.h)/2;
								SDL_RenderCopy(renderer,texture1,NULL,&rect1);
					}
				case SDL_TEXTINPUT:
									
					printf("enter your pseudonym:");
					strcpy(pseudo_nom,event.text.text);
					printf("enter your password:");
					strcpy(pseudo_nom,event.text.text);
					


				default:break; 
			}
			
		}
		SDL_RenderPresent(renderer);
	}
	//stoptextinput
	SDL_StopTextInput();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;

}




/*void red_color(SDL_Renderer *rend){
	SDL_SetRenderDrawColor(rend
,255,50,50,250);
}

void green_color(SDL_Renderer *rend){
	SDL_SetRenderDrawColor(rend
,50,250,50,250);
}

void blue_color(SDL_Renderer *rend){
	SDL_SetRenderDrawColor(rend
,50,50,250,250);
}

void some_color(SDL_Renderer *renderer){
	SDL_SetRenderDrawColor(renderer,255,150,150,250);
} */
