#include <stdio.h>
#include <math.h>


float f(float x){
	return   x*x*x-6*x*x+4 ;
}

int main(int argc,char *argv[]){
	float a,b,m;
	double E=pow(10.0,-4.0);
	printf("dose ta akra toy diasthmatos:\n");
	scanf("%f %f",&a,&b);
	//we consider that the equation f(x)=0
	//has only one root in (a,b)
	m=(a+b)/2.0;
	while(fabs(f(m))>E){
		if ((f(a)*f(m))<0){ 
			b=m;
			m=(a+b)/2.0;
		}	
		if ((f(m)*f(b))<0){
			a=m;
	        m=(a+b)/2.0;	
		}		
	}
	printf("the root is %f and f(root)=%f",m,f(m));
	return 0;
}