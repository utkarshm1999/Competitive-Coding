#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int N,Q,R,i,max,nmax,j,k,len,count,left,len1;
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
		max=nmax=0;
		for(j=0;j<R;j++){
			count=0;
			//cval[j]=0;
			len1=strlen(S[j]);
			while(S[j][count]==test[count] && count<len && count<len1) count++;
			cval[j]=count;
			if(max<cval[j]) max=cval[j];
		}


		for(j=0;j<R;j++){
			if(cval[j]==max){
				maxi[nmax]=j;
				nmax++;
			}
		}
		//printf("max=%d nmax=%d maxi[0]=%d\n",max,nmax,maxi[0]);
		//left=nmax;

		for(j=0;j<nmax-1;j++){
			if(strcmp(S[maxi[j]],S[maxi[j+1]])<0){
				maxi[j+1]=maxi[j];
			}
		}

		printf("%s\n",S[maxi[nmax-1]]);
	}


	return 0;
}
