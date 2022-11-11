/*
한수는 크기가 2N × 2N인 2차원 배열을 Z모양으로 탐색하려고 한다. 예를 들어, 2×2배열을 왼쪽 위칸, 오른쪽 위칸, 왼쪽 아래칸, 오른쪽 아래칸 순서대로 방문하면 Z모양이다.
N이 주어졌을 때, r행 c열을 몇 번째로 방문하는지 출력하는 프로그램을 작성하시오.*/
#include <stdio.h>
int func(int n, int r, int c){
    if(n==0) return 0;
    int half = 1;
    for(int i=0; i<n-1; i++) half *=2;
    if(r<half && c<half) return func(n-1, r, c);
    if(r<half && c>=half) return half * half + func(n-1, r, c-half);
    if(r>=half && c<half) return half * half * 2 + func(n-1, r-half, c);
    return half * half * 3 + func(n-1, r-half, c-half);

    
}
int main(){
    int n, r, c;
    scanf("%d %d %d", &n, &r, &c);
    printf("%d", func(n,r,c));
}
// 사각형을 4분할 해서 재귀로 해결한다.



