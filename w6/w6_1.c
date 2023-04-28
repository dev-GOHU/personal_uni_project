#define MAX_DEGREE //지정할 수 있는 최고 차수 

typedef struct{
	int max_degree; //이 다항식의 최고 차수 
	float coe[MAX_DEGREE]; //각 항의 계수 
} Polynomial;

Polynomial Add(Polynomial poly1, Polynomial poly2){
	Polynomial result; //결괏값 
	result.max_degree = poly1.max_degree>poly2.max_degree?poly1.max_degree:poly2.max_degree;
	for(int i=0;i<result.max_degree;i++){
		result.coe[i] = poly1.coe[i]+poly2.coe[2];
	}
	return result;
}


void main(void){
	
	return 0;
}
