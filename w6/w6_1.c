#define MAX_DEGREE //������ �� �ִ� �ְ� ���� 

typedef struct{
	int max_degree; //�� ���׽��� �ְ� ���� 
	float coe[MAX_DEGREE]; //�� ���� ��� 
} Polynomial;

Polynomial Add(Polynomial poly1, Polynomial poly2){
	Polynomial result; //�ᱣ�� 
	result.max_degree = poly1.max_degree>poly2.max_degree?poly1.max_degree:poly2.max_degree;
	for(int i=0;i<result.max_degree;i++){
		result.coe[i] = poly1.coe[i]+poly2.coe[2];
	}
	return result;
}


void main(void){
	
	return 0;
}
