#include<stdio.h>
#define MAX_TERM 101 /*최대 항의 수+1*/

typedef struct{
    int col;
    int row;
    int value;
} Term; //각 항

//행렬 a를 전치시켜 res를 생성
void transpose(Term a[], Term res[]){
    //a 항의 갯수가 0개 이하일 경우 에러 처리
    if(a[0].value<=0){
        printf("Error: 충분하지 않은 항의 갯수");
        return;
    }
    //res의 행, 열, 값의 갯수를 지정
    res[0].col = a[0].row;
    res[0].row = a[0].col;
    res[0].value = a[0].value;

    //현재 res에 저장한 항의 갯수
    int cur = 1;
    
    for(int i=0;i<res[0].col;i++){
        for(int j=1;j<a[0].value+1;j++){
            //a[j]의 행이 현 res의 열이 아닐 경우 a의 다음 항을 탐색
            if(a[j].row!=i)
                continue;
            //res의 항 저장
            res[cur].col=a[j].row;
            res[cur].row=a[j].col;
            res[cur].value=a[j].value;
            cur++;
        }
    }
}

//행렬을 출력하기 위한 함수
void print_matrix(Term a[]){
    int cur = 1;
    for(int i=0; i<a[0].col;i++){
        for(int j=0;j<a[0].row;j++){
            if(a[cur].col==i && a[cur].row==j){
                printf("%3d ", a[cur].value);
                cur++;
            }
            else{
                printf("%3d ", 0);
            }
        }
        printf("\n");
    }
}

void main(void){
    Term a[MAX_TERM] = {
        {6,6,8},
        {0,0,15},
        {0,3,22},
        {0,5,-15},
        {1,1,11},
        {1,2,3},
        {2,3,-6},
        {4,0,91},
        {5,2,28}
    };
    printf("a\n");
    print_matrix(a);
    printf("\n");

    Term b[MAX_TERM];
    transpose(a, b);
    printf("b\n");
    print_matrix(b);
}