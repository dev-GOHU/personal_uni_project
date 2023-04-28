#include<stdio.h> //ǥ�� ����� �Լ��� ����� �� �ְ��ϴ� �������
#include<stdlib.h> //rand() �Լ��� ����� �� �ְ� �ϴ� ������� 
#include<time.h> //�ð� ���� ������� 
#include<stdbool.h> //boolean type �ڷ����� ����� �� �ֵ��� �ϴ� ������� 
#define MAX_SIZE 101 //�迭�� �ִ� ���� 

//�Լ� �̸� ���� 
void sort(int[], int);
void swap(int* n1, int* n2);
int binSearch(int list[], int arrlen, int target);

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
	
	int target = list[rand()%n]; //ã�� ��ǥ ���� 
	//ã�� ��ǥ�� �ִ� ��ġ ��� 
	printf("target %d�� %d��° element�� �ֽ��ϴ�.", target, binSearch(list, n, target)+1); 
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
/* parameter
list: target�� ���� ������ �����Ǵ� list
arrlen: list�� ����
target: ã���� �ϴ� ��� 
*/ 
/* return: target�� �ִ� element�� index */
int binSearch(int list[], int arrlen, int target){
	int left = 0, right = arrlen-1; //left�� �� ó�� ��ġ, right�� �� ������ ��ġ�� ���� 
	int mid = (left+right)/2; //mid�� left�� right�� �߰� ��ġ�� ���� 
	while(true){
		// target�� mid��ġ�� �ִ� element�� ������ ũ�� left�� mid �ٷ� �ڷ� �ٲٰ� �ٽ� �ݺ��Ѵ�. 
		if(target>list[mid])
			left=mid+1;
		//target�� mid��ġ�� �ִ� element�� ���� ������ mid���� ��ȯ�Ѵ�.
		else if(target==list[mid])
			return mid;
		//target�� mid��ġ�� �ִ� element�� ������ ������ right�� mid �ٷ� ������ �ٲٰ� �ٽ� �ݺ� 
		else
			right=mid-1;
		if(left>right) //left�� right���� Ŀ���� target�� list�� ���ų� list�� ���ĵ��� ���� ���̹Ƿ� -1�� ��ȯ. 
			return -1;
		mid = (left+right)/2;
	}
}
