#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>

int main(){
	double cx,cy,cz,qx,qy,qz,dx,dy,dz,px,py,pz,r;
	double d,CP;
	double a1,a2,a3,b1,b2,b3,A,B,C,D,E,X,Y,Z;
	double t1,t2;
	int T,i;
	scanf("%d",&T);
	for(i=0;i<T;i++){
		
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",&px,&py,&pz,&qx,&qy,&qz,&dx,&dy,&dz,&cx,&cy,&cz,&r);
		
		
		a1=cx-px;
		a2=cy-py;
		a3=cz-pz;
		b1=qx-px;
		b2=qy-py;
		b3=qz-pz;
		CP=a1*a1+a2*a2+a3*a3; //square of CP
		d=pow(CP-r*r,0.5);
		A=(a1*b1+a2*b2+a3*b3)/d;
		B=(a1*dx+a2*dy+a3*dz)/d;
		C=2.0*(b1*dx+b2*dy+b3*dz);	
		D=dx*dx+dy*dy+dz*dz;
		E=b1*b1+b2*b2+b3*b3;
		X=D-B*B;
		Y=C-2.0*A*B;
		Z=E-A*A;		
		printf("%lf %lf %lf\n",X,Y,Z);	
		//CP=(cx-px)*(cx-px)+(cy-py)*(cy-py)+(cz-pz)*(cz-pz); //square of CP
		if(X!=0){
			t1=(-Y+pow(Y*Y-4.0*X*Z,0.5))/(X*2.0);		
			t2=(-Y-pow(Y*Y-4.0*X*Z,0.5))/(X*2.0);
               	
			printf("%lf %lf\n",t1,t2);
		}
		else{
			printf("%lf/n",(-Z/Y));
		}
		
		

	}
	return 0;
}
