#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int d,i,j,N,T,counter,max,sum,newi,newj;
	vector <vector <int>> v;
	vector<int> row;
    scanf("%d",&T);
    for(counter=0;counter<T;counter++){
        scanf("%d",&N);
        max=0;
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                scanf("%d",&d);
                row.push_back (d);
            }
            v.push_back(row);
            row.erase(row.begin(),row.end());
        }
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                sum=v[i][j];
                if(sum>max) max=sum;
                newi=i+1;
                newj=j+1;
                while(newi<N && newj<N){
                    sum+=v[newi][newj];
                    if(sum>max) max=sum;
                    newi++;
                    newj++;
                }
            }
        }
        v.erase(v.begin(),v.end());
        printf("%d\n",max);
    }



	return 0;
}
