char pseudo_nom[30];
char password[30];
void login(){
	SDL_Event event;
	printf("enter your pseudonym:");
	strcpy(pseudo_nom,event.text.text);
	printf("enter your password:");
	strcpy(password,event.text.text);
	printf("%s",password);
}