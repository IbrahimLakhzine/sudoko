
int solver(void){
	int cases[4][4];
	for(int i=0;i<=3;i++){
		for(int j=0;j<=3;j++){
			printf("entrez 1 ou 2 ou 3 ou 4:");
			scanf("%d",&cases[i][j]);		
		}
	}
	
	for(int k=0;k<=3;k++){
		for(int l=0;l<=3;l++){
			for(int i=0;i<=3;i++){
				for(int j=0;j<=3;j++){
					if(k==i && l==j){
						continue;	
					}
					if(i==k || j==l){
						if(cases[i][j]==cases[k][l]){
							return 0; 
						}
					}
				}
			}				
		}
	}


	for(int k=0;k<=3;k++){
		for(int l=0;l<=3;l++){
			for(int i=0;i<=3;i++){
				for(int j=0;j<=3;j++){
					if(k==i && l==j){
						continue;
					}
					if(i>=0 && i<=1 && j<=1 && j>=0 && k>=0 && k<=1 && l>=0 && l<=1){
						if((cases[i][j]==cases[k][l])){
							return 0; 
						}
					}
					if(i>=0 && i<=1 && j<=2 && j>=3 && k>=0 && k<=1 && l>=2 && l<=3){
						if((cases[i][j]==cases[k][l])){
							return 0; 
						}
					}
					if( i>=2 && i<=3 && j<=1 && j>=0 && k>=2 && k<=3 && l>=0 && l<=1){
						if((cases[i][j]==cases[k][l])){
							return 0; 
						}
					}
					if(i>=2 && i<=3 && j<=3 && j>=2 && (k>=2 && k<=3) && (l>=2 && l<=3) ){
						if((cases[i][j]==cases[k][l])){
							return 0; 
						}
					}
				}
			}				
		}
	}
	return 1; 
}