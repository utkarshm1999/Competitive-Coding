#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int N,Q,R,i,max,nmax,j,k,len,count,left,len1,prevmax;
	int maxi[100000],cval[100000];
	char S[100000][11];
	char test[11];
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%s",S[i]);	
	}
	scanf("%d",&Q);
	for(i=0;i<Q;i++){
		
		scanf("%d %s",&R,test);
		len=strlen(test);
		prevmax=max=nmax=0;
		int loop=1;
		//printf("0\n");
		for(j=0;j<R;j++){	
			count=0;
			//cval[j]=0;
			//len1=strlen(S[j]);
			//printf("0.5\n");
			while(S[j][count]==test[count] && count<len) count++;
			cval[j]=count;
			//printf("2\n");
			if(max<=cval[j]){
				max=cval[j];
				if(prevmax==max){
					maxi[nmax]=j;
					nmax++;
				}
				else{
					nmax=0;
					maxi[nmax]=j;
					nmax++;
					prevmax=max;
				}
			}
		
		}
		//printf("1\n");
		/*for(j=0;j<R;j++){
			if(cval[j]==max){
				maxi[nmax]=j;
				nmax++;			
			}*/
		
		//printf("max=%d nmax=%d maxi[0]=%d\n",max,nmax,maxi[0]);
		//left=nmax;
		if(nmax!=1){		
			for(j=0;j<nmax-1;j++){
				/*if(strcmp(S[maxi[j]],S[maxi[j+1]])<0){ 
					maxi[j+1]=maxi[j];
				}*/
				for(k=max-1;S[maxi[j]][k]!='\0' && S[maxi[j+1]][k]!='\0';k++){
					if((int)S[maxi[j]][k]>(int)S[maxi[j+1]][k] && S[maxi[j]][k]!='\0' && S[maxi[j+1]][k]!='\0'){
						maxi[j+1]=maxi[j];
					}
					else{
						if(S[maxi[j]][k]=='\0' && S[maxi[j+1]][k]!='\0') maxi[j+1]=maxi[j];
					}
					
				}
			}

			
			printf("%s\n",S[maxi[nmax-1]]);
		}
		else{
			printf("%s\n",S[maxi[0]]);
		}
		//printf("3\n");	
		
		
	}	
	

	return 0;
}
