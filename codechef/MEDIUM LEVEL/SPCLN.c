#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>

int N,M,k,i;
int max=0;

int E[100][100];
// N debris,M buttons, k constraints

//int *constraint;
int *constraint;
  int constraints[100][2];

void copy(int a[],int b[]){
    int c;
    for(c=0;c<N;c++){
        a[c]=b[c];
    }
}
int is_valid(int target[],int button){
    int counter;
    for(counter=0;counter<N;counter++){
        if(target[counter]==1 && (constraint[counter]!=1 || E[counter][button]==-1)){
            return 0;
        }
    }
    return 1;
}


void destroy(int button, int left,int sum){
    //printf("destroy(%d,%d,%d)\n",button,left,sum);
    //int printer;


    int * bin=(int *) malloc(sizeof(int)*N);
    int B,Btest;
    int prevleft,prevsum;
    prevleft=left;
    int prevconstraint[100];
    copy(prevconstraint,constraint);
    /*for(printer=0;printer<N;printer++){
		printf("%d",prevconstraint[printer]);
    }
  printf(" pc \n");*/
    prevsum=sum;
    for(B=0;B<pow(2,N);B++){
        Btest=B;
        int c;
	int looper;
        sum=prevsum;
        left=prevleft;
        copy(constraint,prevconstraint);
	/*for(printer=0;printer<N;printer++){
		printf("%d",constraint[printer]);
    	}
        printf("\n");*/
        for(looper=N-1;looper>=0;looper--){
            bin[looper]=Btest%2;
            Btest=Btest/2;
	    //printf("%d",bin[looper]);
        }
	//printf( "was bin for %d\n",B);
        if(is_valid(bin,button)){  // checks if none of the constraint debris is getting destroyed
            for(i=0;i<N;i++){
                if(bin[i]==1){
                    left+=-1;
		    //assert(left>=0);
	           /* if(left<0){

			printf("left<0 for %d,%d and number B is %d\n",button,left,B);
		    }*/
	            sum+= E[i][button];
                    // update constraint[] and constraints[][]
                    constraint[i]=-1; //destroyed
                    for(c=0;c<k;c++){
                        if(constraints[c][0]==i){
                            constraints[c][1]=-constraints[c][1];
                        }

                    }



                }


            }

	    c=0;
            for(i=0;i<N;i++){
                if(constraint[i]==0 && bin[i]!=1){
                    for(c=0;c<k;c++){
                        if(constraints[c][1]==i){
                            break;
                        }
                    }

                }
                if(c==k){
                    constraint[i]=1;
                }
            }

            if(left==0){
                if(sum>max){
                    max=sum;
                }
            }

            else if(button<M-1){
                destroy(button+1,left,sum);

            }

            else{ // even at the last button all debris were not destroyed

            }

            //reset constraints

            for(i=0;i<N;i++){
                if(bin[i]==1){
                    for(c=0;c<k;c++){
                        if(constraints[c][0]==i && constraints[c][1]<0){
                            constraints[c][1]=-constraints[c][1];
                        }
                    }
                }
            }



        }
    }

}

int main(void) {
	// your code goes here
	scanf("%d %d",&N,&M);
	int counter1,counter2;
	for(counter1=0;counter1<N;counter1++){
	    for(counter2=0;counter2<M;counter2++){
	        scanf("%d",&E[counter1][counter2]);
	    }
	}
	scanf("%d",&k);



    //int left_debris=N;
    constraint=(int*) malloc(sizeof(int)*N);

    int i;
    for(i=0;i<N;i++){
        constraint[i]=1; // 1 indicates not destroyed + not constraint
    }

    for(counter1=0;counter1<k;counter1++){
        scanf("%d %d",&constraints[counter1][0],&constraints[counter1][1]);
	constraints[counter1][0]--;
	constraints[counter1][1]--;

    }

    for(counter1=0;counter1<k;counter1++){
        constraint[constraints[counter1][1]]=0; // set all those constraints to 0
	//printf("%d",constraints[counter1][1]);
    }

	destroy(0,N,0);

	printf("%f",(float)max/N);


	return 0;
}

