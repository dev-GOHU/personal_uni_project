#include<stdio.h> //ǥ�� ����� �Լ��� ����� �� �ְ��ϴ� �������
#include<math.h>
#define MAX_SIZE 101 //�迭�� �ִ� ���� 
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t)) //�� ������ ���� ���� �ٲٴ� ��ũ�� �Լ� 
void sort(int[], int);

void main(void){
	int i, n; //i: ������ element�� index ; n: list�� ���� 
	int list[MAX_SIZE]; //������ �迭 
	
	//�迭�� ���̸� �Է¹���
	printf("Enter the number of numbers to generate: ");
	scanf("%d", &n);
	
	//n�� ��� ������ ������ �Ѿ�� �� ����ó�� 
	if (n<1 || n>MAX_SIZE){
		fprintf(stderr, "Improper value of n\n");
		exit(1);
	}
	
	//n���� element�� ���� ������ ���� ���� 
	for(i=0;i<n;i++){
		list[i]=rand() % 1000;
		printf("%d ", list[i]);
	}
	
	sort(list, n); //����Ʈ ����
	
	//���ĵ� ����Ʈ�� ��� 
	printf("\n Sorted array:\n");
	for(i=0;i<n;i++)
		printf("%d ", list[i]);
	printf("\n");
}

//sort�Լ� ���� 
void sort(int list[], int n){ //list: ���� ����� �迭 ; n: list�� ���� 
	int i, j, min, temp;  
	//i: Access�ϰ� �ִ� element�� index. 
	//j: list[i]�� ���ϰ� �ִ� element�� index. 
	//min: i��° ���� ���� index
	//temp: list[i]�� list[j]�� ���� ���� �ٲٱ� ���� ������ ���� 
	for(i=0;i<n-1;i++){
		min=i; //���� index�� i�� element�� �ּڰ����� �����Ѵ�. 
		//index�� i+1�� element���� ���ʷ� ���ذ���. 
		for(j=i+1;j<n;j++)
			//list[j]�� list[min]���� ������ min�� j�� �����Ѵ�. 
			if(list[j]<list[min])
				min=j;
		SWAP(list[i], list[min], temp); //i��°�� ���� ���� ���� element�� ���� index�� i�� element�� ���� ���� �ٲ۴�. 
	}
}
