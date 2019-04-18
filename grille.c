int largeur;
int hauteur;
int i,j;
SDL_Rect small_rect[4][4];
void grille(SDL_Renderer *renderer){
	for(i=0;i<=3;i++){
		for(j=0;j<=3;j++){
			small_rect[i][j].x=341+largeur;
			small_rect[i][j].y=212+hauteur;
			small_rect[i][j].w=64;
			small_rect[i][j].h=64;	
			largeur+=64;
			
		}
		largeur=0;
		hauteur+=64;
	}
}