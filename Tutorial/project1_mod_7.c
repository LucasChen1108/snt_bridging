#include<stdio.h>
int main(void){
	int i,j,n,m,nn;
	printf("$ ./a.out \n");
	printf("Enter n: ");
	scanf("%d",&n);
	
	
	printf("Output Multiplication Table\n");
	printf("---+");
	for(i=1;i<n;i++){
		printf("---");
	}
	printf("\n   |");
	for(i=1;i<n;i++){
		printf("%3d",i);
	}
	printf("\n---+");
	for(i=1;i<n;i++){
		printf("---");
	}
	printf("\n");
	for(i=0;i<n-1;i++){
		printf("%3d|",i+1);
		for(j=0;j<n-1;j++){
			printf("%3d",(i+1)*(j+1)%n);
		}
		printf("\n");
	}
	printf("---+");
	for(i=1;i<n;i++){
		printf("---");
	}
	
	
	printf("\nOutput Inverse Table\n");
	printf("---+");
	for(i=1;i<n;i++){
		printf("---");
	}
	printf("\n   |");
	for(i=1;i<n;i++){
		printf("%3d",i);
	}
	printf("\n---+");
	for(i=1;i<n;i++){
		printf("---");
	}
	printf("\n");
	for(i=0;i<n-1;i++){
		printf("%3d|",i+1);
		for(j=0;j<n-1;j++){
			if((i+1)*(j+1)%n==1){
				printf("  *");
			}else{
				printf("   ");
			}
		}
		printf("\n");
	}
	printf("---+");
	for(i=1;i<n;i++){
		printf("---");
	}
	
	
	printf("\nOutput Quadratic Residue\n");
	printf("---+");
	for(i=1;i<n;i++){
		printf("---");
	}
	printf("\n");
	for(i=1;i<n;i++){
		m=0;
		for(j=1;j<n;j++){
			if(j*j%n==i){
				m=1;
				break;
			}
		}
		if(m==1){
			printf("%3d|",i);
			for(j=1;j<n;j++){
				if(j*j%n==i){
					printf("%3d",j);
				}
			}
			printf("\n");
		}
	}
	printf("---+");
	for(i=1;i<n;i++){
		printf("---");
	}
	
	
	printf("\nOutput Fractal\n");
	printf("   ");
	for(i=1;i<=n;i++){
		printf("%d",i/10);
	}
	printf("\n");
	printf("   ");
	for(i=1;i<=n;i++){
		printf("%d",i%10);
	}
	printf("\n");
	for(i=n;i>=1;i--){
		printf(" %02d",i);
		for(j=1;j<=i;j++){
			printf(" ");
		}
		for(j=i+1;j<=n;j++){
			m=0;
			for(nn=1;nn<n;nn++){
				if(nn*nn%j==i){
					m=1;
				}
			}
			if(m==1){
				printf("@");
			}else{
				printf(".");
			}
		}
		printf("\n");
	}
}