#include "constante.h"
int main(int argc, char *argv[])
{
	info_players* new_info=NULL;
	int i=0;
	int line=0;
	int Top_score[10];

	char **name_top_players=(char **)malloc(10*sizeof(char *));
	for(int s=0;s<=9;s++){
		name_top_players[s]=(char *)malloc(30*sizeof(char));
			
	}
	


	int checktab_easy[4][4]={{0,4,2,0},{1,2,0,3},{0,3,0,4},{4,0,3,0}};
	int checktab_medium[4][4]={{0,0,0,1},{0,1,4,0},{0,2,3,0},{3,0,0,0}};
	int checktab_hard[4][4]={{1,0,4,0},{0,0,0,0},{0,0,0,0},{0,1,0,2}};
	int choice=0;
	int flag=1;
	int len_pass=0; //la longeur du password qui incremente a chaque appuye
	int len_pseu=0 ; //la longeur du pseudonym qui incremente a chaque appuye
	int tab_len[2]={len_pseu,len_pass};  
	int gamestatut;
	char pseudo_nom[30]="";
	char password[30]="";
	char *tab_pseu_pass[2]={pseudo_nom,password};


	SDL_Surface *caractere=NULL;	
	SDL_Texture *textcar=NULL;
	SDL_Rect rect2;

	
	SDL_Window *window=NULL;
	SDL_Renderer *renderer=NULL;
	SDL_Rect rect;
	SDL_Rect rect1;

	SDL_Rect small_rect[4][4];

	SDL_Init(SDL_INIT_VIDEO);


	printf("pseudonym:");

	//textinputstart
	SDL_StartTextInput();

	window=SDL_CreateWindow("window",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,largeur_window,hauteur_window,SDL_WINDOW_RESIZABLE);
	renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE);
	SDL_Surface *image=NULL;
	SDL_Texture *texture=NULL;

	


	image=SDL_LoadBMP("src/login.bmp");
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
							//gotomenupage
							if(flag==1){
								//done
								if(event.button.x>=775 && event.button.x<=880 && event.button.y<=583 && event.button.y>=545 && event.button.x>=705){
									if(check_player(pseudo_nom,password)==1){
                						go_to_next_page("src/menu.bmp",image,renderer,rect1,texture);
										flag=2;
                					}
                					else if(check_player(pseudo_nom,password)==0){
                						new_info=create_info_player(password,pseudo_nom);
                						head=create_player(new_info);
                						stock_player(pseudo_nom,password);
                						go_to_next_page("src/menu.bmp",image,renderer,rect1,texture);
										flag=2;	
         								 
                					}
                				
									
								}	
							}	
							else if(flag==2){
								if(event.button.x>=705 && event.button.x<=880 && event.button.y<=532 && event.button.y>=335){
									go_to_next_page("src/levels.bmp",image,renderer,rect1,texture);
									flag=4;
								}	
								//log out
								if(event.button.x>=24 && event.button.x<=214 && event.button.y<=530 && event.button.y>=343){
									go_to_next_page("src/login.bmp",image,renderer,rect1,texture);
									printf("\npseudonym:");
									i=0;
									flag=1;
									strcpy(tab_pseu_pass[0]," ");
									strcpy(tab_pseu_pass[1]," ");
									tab_len[0]=0;
									tab_len[1]=0;

								}
								if(event.button.x>=463 && event.button.x<=690 && event.button.y<=523 && event.button.y>=316){
									go_to_next_page("src/Top_score.bmp",image,renderer,rect1,texture);	
									flag=3;
								}
								//load
								if(event.button.x>=253 && event.button.x<=439 && event.button.y<=530 && event.button.y>=343){
									line=load_player(pseudo_nom);
									
									if(load_gamestatut(line)==1){
										load_grille(checktab_easy,line);
										go_to_next_page("src/game_easy.bmp",image,renderer,rect1,texture);
										detect_case_easy_save(rect2,textcar,caractere,event,renderer,checktab_easy);
										flag=5;		
										
									}
									else if(load_gamestatut(line)==2){
										load_grille(checktab_medium,line);
										go_to_next_page("src/game_medium.bmp",image,renderer,rect1,texture);
										detect_case_medium_save(rect2,textcar,caractere,event,renderer,checktab_medium);
										
										flag=5;
										
										
									}
									else if(load_gamestatut(line)==3){
										load_grille(checktab_hard,line);
										go_to_next_page("src/game_hard.bmp",image,renderer,rect1,texture);
										detect_case_hard_save(rect2,textcar,caractere,event,renderer,checktab_hard);
										flag=5;
										
									}

									
								}	
									
							}
							else if(flag==3){
								if(event.button.x>=826 && event.button.x<=865 && event.button.y<=581 && event.button.y>=544){
									go_to_next_page("src/menu.bmp",image,renderer,rect1,texture);
									flag=2;
								}
							}
							else if(flag==4){
								if(event.button.x>=463 && event.button.x<=671 && event.button.y<=262 && event.button.y>=206){
									go_to_next_page("src/game_easy.bmp",image,renderer,rect1,texture);
									gamestatut=1;
									stock_gamestatut(1);
									flag=5;
								
								}
								if(event.button.x>=535 && event.button.x<=729 && event.button.y<=352 && event.button.y>=300){
									go_to_next_page("src/game_medium.bmp",image,renderer,rect1,texture);
									gamestatut=2;
									stock_gamestatut(2);
									flag=5;
									
								}
								if(event.button.x>=633 && event.button.x<=819 && event.button.y<=452 && event.button.y>=388){
									go_to_next_page("src/game_hard.bmp",image,renderer,rect1,texture);
									gamestatut=3;
									stock_gamestatut(3);
									flag=5;
								
								}
							}
							//save
							else if(flag==5){
								if(event.button.x>=842 && event.button.x<=882 && event.button.y<=578 && event.button.y>=538){
									if((load_gamestatut(line)==1 || gamestatut==1) && !(load_gamestatut(line)==2 || gamestatut==2) && !(load_gamestatut(line)==3 || gamestatut==3)){
										stock_grille(checktab_easy);
										checktab_easy[0][0]=0;
										checktab_easy[0][1]=4;
										checktab_easy[0][2]=2;
										checktab_easy[0][3]=0;
										checktab_easy[1][0]=1;
										checktab_easy[1][1]=2;
										checktab_easy[1][2]=0;
										checktab_easy[1][3]=3;
										checktab_easy[2][0]=0;
										checktab_easy[2][1]=3;
										checktab_easy[2][2]=0;
										checktab_easy[2][3]=4;
										checktab_easy[3][0]=4;
										checktab_easy[3][1]=0;
										checktab_easy[3][2]=3;
										checktab_easy[3][3]=0;
										
									
										
									}
									if((load_gamestatut(line)==2 || gamestatut==2)){	
										stock_grille(checktab_medium);
										checktab_medium[0][0]=0;
										checktab_medium[0][1]=0;
										checktab_medium[0][2]=0;
										checktab_medium[0][3]=1;
										checktab_medium[1][0]=0;
										checktab_medium[1][1]=1;
										checktab_medium[1][2]=4;
										checktab_medium[1][3]=0;
										checktab_medium[2][0]=0;
										checktab_medium[2][1]=2;
										checktab_medium[2][2]=3;
										checktab_medium[2][3]=0;
										checktab_medium[3][0]=3;
										checktab_medium[3][1]=0;
										checktab_medium[3][2]=0;
										checktab_medium[3][3]=0;
										
									
										
									}
									if((load_gamestatut(line)==3 || gamestatut==3)){
										stock_grille(checktab_hard);
										checktab_hard[0][0]=1;
										checktab_hard[0][1]=0;
										checktab_hard[0][2]=4;
										checktab_hard[0][3]=0;
										checktab_hard[1][0]=0;
										checktab_hard[1][1]=0;
										checktab_hard[1][2]=0;
										checktab_hard[1][3]=0;
										checktab_hard[2][0]=0;
										checktab_hard[2][1]=0;
										checktab_hard[2][2]=0;
										checktab_hard[2][3]=0;
										checktab_hard[3][0]=0;
										checktab_hard[3][1]=1;
										checktab_hard[3][2]=0;
										checktab_hard[3][3]=2;
										

									}
									flag=5;
									//ttf game saved 5 sec

								}
								if(event.button.x>=41 && event.button.x<=79 && event.button.y<=576 && event.button.y>=538){
									go_to_next_page("src/menu.bmp",image,renderer,rect1,texture);
									flag=2;
									choice=0;
								}
								if(event.button.x>=93 && event.button.x<=129 && event.button.y<=576 && event.button.y>=538){
									if(load_gamestatut(line)==1 || gamestatut==1){
										go_to_next_page("src/game_easy.bmp",image,renderer,rect1,texture);
										flag=5;
										choice=0;
									}
									if(load_gamestatut(line)==2 || gamestatut==2){
										go_to_next_page("src/game_medium.bmp",image,renderer,rect1,texture);
										flag=5;
										choice=0;
									}
									if(load_gamestatut(line)==3 || gamestatut==3){
										go_to_next_page("src/game_hard.bmp",image,renderer,rect1,texture);
										flag=5;
										choice=0;
									}
								}
								
								//carre

								if(event.button.x>=387 && event.button.x<=415 && event.button.y<=548 && event.button.y>=521){
									choice=3;
								}
								//cercle
								if(event.button.x>=434 && event.button.x<=468 && event.button.y<=548 && event.button.y>=521){
									choice=2;

								}
								//triangle
								if(event.button.x>=481 && event.button.x<=517 && event.button.y<=548 && event.button.y>=521){
									choice=1;
								}
								//etoile
								if(event.button.x>=521 && event.button.x<=563 && event.button.y<=548 && event.button.y>=521){
									choice=4;
								}
								if(load_gamestatut(line)==1 || gamestatut==1 && !(load_gamestatut(line)==2 || gamestatut==2)){
									detect_case_easy(rect2,textcar,caractere,event,choice,renderer,checktab_easy);	
								}
								if(load_gamestatut(line)==2 || gamestatut==2){
									detect_case_medium(rect2,textcar,caractere,event,choice,renderer,checktab_medium);	
								}
								if(load_gamestatut(line)==3 || gamestatut==3){
									detect_case_hard(rect2,textcar,caractere,event,choice,renderer,checktab_hard);	
								}
								
								//done
								if(event.button.x>=740 && event.button.x<=822 && event.button.y<=578 && event.button.y>=538){
								//callsolver 
										if(solver(checktab_easy)==1 && (/*load_gamestatut(line)==1 ||*/ gamestatut==1)){
											go_to_next_page("src/Score_100.bmp",image,renderer,rect1,texture);
											check_player_and_deliver_point(head,pseudo_nom,100);
											
											flag=8;

										}
										if(solver(checktab_medium)==1 && (/*load_gamestatut(line)==2 ||*/ gamestatut==2)){
											go_to_next_page("src/Score_200.bmp",image,renderer,rect1,texture);
											check_player_and_deliver_point(head,pseudo_nom,200);
										
											flag=8;
										}
										if(solver(checktab_hard)==1 && (/*load_gamestatut(line)==3 ||*/ gamestatut==3)){
											go_to_next_page("src/Score_300.bmp",image,renderer,rect1,texture);
											check_player_and_deliver_point(head,pseudo_nom,300);
										
											flag=8;
										}

										if(solver(checktab_easy)==0 && (load_gamestatut(line)==1 || gamestatut==1)){
											go_to_next_page("src/You_wrong.bmp",image,renderer,rect1,texture);
											check_player_and_deliver_point(head,pseudo_nom,0);
											flag=8;
										}
										if(solver(checktab_medium)==0 && (load_gamestatut(line)==2 || gamestatut==2)){
											go_to_next_page("src/You_wrong.bmp",image,renderer,rect1,texture);
											check_player_and_deliver_point(head,pseudo_nom,0);
											flag=8;
										}
										if(solver(checktab_hard)==0 && (load_gamestatut(line)==3 || gamestatut==3)){
											go_to_next_page("src/You_wrong.bmp",image,renderer,rect1,texture);
											check_player_and_deliver_point(head,pseudo_nom,0);
											flag=8;
										}			
								}

							}
							else if(flag==8){
								if(event.button.x>=818 && event.button.x<=855 && event.button.y<=570 && event.button.y>=530){
									go_to_next_page("src/menu.bmp",image,renderer,rect1,texture);
									flag=2;
								}	
							}
							
						default:break;		
					}	

				case SDL_KEYDOWN:
                    switch (event.key.keysym.sym){
                    	case SDLK_TAB:

                    		printf("\npassword:");
  							i++;                  		
                   			break;	
                       	case SDLK_BACKSPACE:	
                       		
                			tab_len[i]=tab_len[i]-1;
                       		tab_pseu_pass[i][tab_len[i]]=' ';
                       		system("cls");
                       		printf("pseudonym:");
                       		printf("%s\n",pseudo_nom);
                      		break;

                       		
                       	case SDLK_a:
                            tab_pseu_pass[i][tab_len[i]]='a';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
 
                       case SDLK_b:
                   			tab_pseu_pass[i][tab_len[i]]='b';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                          	break;

                        case SDLK_c:
                            tab_pseu_pass[i][tab_len[i]]='c';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;

                        case SDLK_d:
                            tab_pseu_pass[i][tab_len[i]]='d';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;

                        case SDLK_e:
                            tab_pseu_pass[i][tab_len[i]]='e';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;

                        case SDLK_f:
                            tab_pseu_pass[i][tab_len[i]]='f';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                        case SDLK_g:
                            tab_pseu_pass[i][tab_len[i]]='g';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                        case SDLK_h:
                            tab_pseu_pass[i][tab_len[i]]='h';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                        case SDLK_i:
                            tab_pseu_pass[i][tab_len[i]]='i';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                        case SDLK_j:
                            tab_pseu_pass[i][tab_len[i]]='j';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                        case SDLK_k:
                            tab_pseu_pass[i][tab_len[i]]='k';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                        case SDLK_l:
                            tab_pseu_pass[i][tab_len[i]]='l';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                        case SDLK_m:
                            tab_pseu_pass[i][tab_len[i]]='m';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                        case SDLK_n:
                            tab_pseu_pass[i][tab_len[i]]='n';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                        case SDLK_o:
                            tab_pseu_pass[i][tab_len[i]]='o';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                        case SDLK_p:
                            tab_pseu_pass[i][tab_len[i]]='p';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                        case SDLK_q:
                            tab_pseu_pass[i][tab_len[i]]='q';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                         	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	
                        case SDLK_r:
                            tab_pseu_pass[i][tab_len[i]]='r';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                        case SDLK_s:
                            tab_pseu_pass[i][tab_len[i]]='s';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                        case SDLK_t:
                            tab_pseu_pass[i][tab_len[i]]='t';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                        case SDLK_u:
                            tab_pseu_pass[i][tab_len[i]]='u';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                        case SDLK_v:
                            tab_pseu_pass[i][tab_len[i]]='v';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                        case SDLK_w:
                            tab_pseu_pass[i][tab_len[i]]='w';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                        case SDLK_x:
                            tab_pseu_pass[i][tab_len[i]]='x';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                        case SDLK_y:
                            tab_pseu_pass[i][tab_len[i]]='y';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                        case SDLK_z:
                            tab_pseu_pass[i][tab_len[i]]='z';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                        case SDLK_0:
                            tab_pseu_pass[i][tab_len[i]]='0';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                        case SDLK_1:
                            tab_pseu_pass[i][tab_len[i]]='1';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                        case SDLK_2:
                            tab_pseu_pass[i][tab_len[i]]='2';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                        case SDLK_3:
                            tab_pseu_pass[i][tab_len[i]]='3';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                        case SDLK_4:
                            tab_pseu_pass[i][tab_len[i]]='4';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                        case SDLK_5:
                            tab_pseu_pass[i][tab_len[i]]='5';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                        case SDLK_6:
                            tab_pseu_pass[i][tab_len[i]]='6';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                        case SDLK_7:
                            tab_pseu_pass[i][tab_len[i]]='7';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                        case SDLK_8:
                            tab_pseu_pass[i][tab_len[i]]='8';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                        case SDLK_9:
                            tab_pseu_pass[i][tab_len[i]]='9';
                            printf("%c",tab_pseu_pass[i][tab_len[i]]);
                            tab_len[i]+=1;
                         	break;
                         	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	  	

                        default: continue;	
                            
                    }
            		break;	


				default:break; 
			}
			
		}
		SDL_RenderPresent(renderer);	
	}
	//printf("%c",name_top_players[0][0]);	
	SDL_StopTextInput();   //stoptextinput
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;

}

