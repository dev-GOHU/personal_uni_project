#define HEADER_H
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

void sort(int list[], int n){ //list: ���� ����� �迭 ; n: list�� ���� 
	int i, j, min;  
	//i: Access�ϰ� �ִ� element�� index. 
	//j: list[i]�� ���ϰ� �ִ� element�� index. 
	//min: i��° ���� ���� index
	int tmp;
	for(i=0;i<n-1;i++){
		min=i; //���� index�� i�� element�� �ּڰ����� �����Ѵ�. 
		//index�� i+1�� element���� ���ʷ� ���ذ���. 
		for(j=i+1;j<n;j++)
			//list[j]�� list[min]���� ������ min�� j�� �����Ѵ�. 
			if(list[j]<list[min])
				min=j;
		SWAP(list[i], list[min], tmp); //i��°�� ���� ���� ���� element�� ���� index�� i�� element�� ���� ���� �ٲ۴�. 
	}
}
