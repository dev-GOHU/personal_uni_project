#include<stdio.h> //ǥ�� ����� �Լ��� ����� �� �ְ��ϴ� �������
#include<stdlib.h> //rand() �Լ��� ����� �� �ְ� �ϴ� ������� 
#include<time.h> //�ð� ���� ������� 
#define MAX_SIZE 101 //�迭�� �ִ� ���� 

//�Լ� �̸� ���� 
void sort(int[], int);
void swap(int* n1, int* n2);
int binSearch(int list[], int target, int left, int right);

void main(void){
	int i, n; //i: ������ element�� index ; n: list�� ���� 
	int list[MAX_SIZE]; //������ �迭 
	srand((unsigned int)time(NULL)); //rand()�Լ��� �ð��� ���� ������ ���� �������� �ϴ� �Լ�. 
	
	//�迭�� ���̸� �Է¹���
	printf("Enter the number of numbers to generate: ");
	scanf("%d", &n);
	
	//n�� ��� ������ ������ �Ѿ�� �� ����ó�� 
	if(n<1 || n>MAX_SIZE){
		fprintf(stderr, "Improper value of n\n");
		exit(1);
	}
	
	//n���� element�� ���� ������ ���� ���� 
	for(i=0;i<n;i++){
		list[i]=rand() % 1000;
	}
	
	sort(list, n); //����Ʈ ����
	
	//���ĵ� ����Ʈ�� ��� 
	printf("list : ");
	for(i=0;i<n;i++)
		printf("%d ", list[i]);
	printf("\n");
	
	int target = list[rand()%n]; //target�� �ȿ� �ִ� element �߿��� �����ϰ� ����. 
	//ã�� ��ǥ�� �ִ� ��ġ ��� 
	printf("target %d�� %d��° element�� �ֽ��ϴ�.", target, binSearch(list, target, 0, n-1)+1); 
	return 0;
}

//��ũ�� �Լ��� SWAP�� �Ϲ� �Լ��� �ٲ� swap 
void swap(int * n1, int * n2){ //�� ������ �ּҸ� �Է¹���  
	int tmp = *n1; 
	*n1=*n2;
	*n2=tmp;
}

//sort�Լ� ���� 
void sort(int list[], int n){ //list: ���� ����� �迭 ; n: list�� ���� 
	int i, j, min;  
	//i: Access�ϰ� �ִ� element�� index. 
	//j: list[i]�� ���ϰ� �ִ� element�� index. 
	//min: i��° ���� ���� index

	for(i=0;i<n-1;i++){
		min=i; //���� index�� i�� element�� �ּڰ����� �����Ѵ�. 
		//index�� i+1�� element���� ���ʷ� ���ذ���. 
		for(j=i+1;j<n;j++)
			//list[j]�� list[min]���� ������ min�� j�� �����Ѵ�. 
			if(list[j]<list[min])
				min=j;
		swap(&list[i], &list[min]); //i��°�� ���� ���� ���� element�� ���� index�� i�� element�� ���� ���� �ٲ۴�. 
	}
}

//Binary Search
/* parameters
list: target�� ���� ������ �����Ǵ� list 
target: ã���� �ϴ� ��� 
left: target�� �ִ� ��ġ ������ �ּڰ� 
right: target�� �ִ� ��ġ ������ �ִ� 
*/ 
/* return: target�� �ִ� element�� index */ 
int binSearch(int list[], int target, int left, int right){
	int mid = (left+right)/2;
	if(target>list[mid])
		return binSearch(list, target, mid+1, right);
	else if(target==list[mid])
		return mid;
	else
		return binSearch(list, target, left, mid-1);
} 
