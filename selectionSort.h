#define HEADER_H
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

void sort(int list[], int n){ //list: 정렬 대상인 배열 ; n: list의 길이 
	int i, j, min;  
	//i: Access하고 있는 element의 index. 
	//j: list[i]와 비교하고 있는 element의 index. 
	//min: i번째 작은 수의 index
	int tmp;
	for(i=0;i<n-1;i++){
		min=i; //먼저 index가 i인 element를 최솟값으로 설정한다. 
		//index가 i+1인 element부터 차례로 비교해간다. 
		for(j=i+1;j<n;j++)
			//list[j]가 list[min]보다 작으면 min에 j를 대입한다. 
			if(list[j]<list[min])
				min=j;
		SWAP(list[i], list[min], tmp); //i번째로 작은 값을 가진 element의 값과 index가 i인 element의 값을 서로 바꾼다. 
	}
}
