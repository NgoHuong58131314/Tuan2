//Tim duong di cua con chuot trong me cung
#include<stdio.h>
#include<conio.h>
#include<string.h>
FILE *f;
int a[10][10];
int sd, sc;
int n = 5;	//Kich thuoc that cua ma tran
int x, y;	//Vi tri cau chuot
// ma tran gia so
//Vi tri 1 chuot di duoc; Vi tri 0 khong di duoc
int h[4]={1,0,0,-1};	//Co 4 vi tri ma chuot co the di duoc
int v[4]={0,-1,1,0};
void DocFile()
{
	f=fopen("input4.txt","r");
	if(f==NULL){
		printf("\nMo file khong thanh cong. Xin kiem tra lai!");
	}
	else{
		fscanf(f, "%d", &sd);
		fscanf(f, "%d", &sc);
		for(int i=0; i<sd; i++)
			for(int j=0; j<sc; j++)
				fscanf(f, "%d", &a[i][j]);
		
	}
	fclose(f);
}
void XuatMaTran()
{
	printf("\n            Ma Tran                 \n");
	printf("Sd = %d\t", sd);
	printf("Sc = %d\n", sc);
	for(int i=0; i<sd; i++){
		for(int j=0; j<sc; j++)		
			printf("%5d",a[i][j]);
			printf("\n");
	}
}
void GhiFile()
{
	f = fopen("output4.txt", "w");
	fprintf(f, "%d\t", sd);
	fprintf(f, "%d\n", sc);
	for(int i=0; i<sd; i++){
		for(int j=0; j<sc; j++)
			fprintf(f, "%5d", a[i][j]);
			fprintf(f, "\n");
	}
	fclose(f);
}

// In nghiem
void In_nghiem()
{ 
	printf("-------------------------------------\n");
   	for (sd=1; sd<=5; sd++)
   	{ 	
	   for (sc=1; sc<=5; sc++)
    	if (a[sd][sc]==2){
    		printf(" *");
			fprintf(f," *");
		}		
		else
			printf("%2d",a[sd][sc]);
			fprintf(f, "%2d", a[sd][sc]);
      		printf("\n");
      		fprintf(f, "\n");		
	}
   	printf("-------------------------------------\n");
   	fprintf(f, "-------------------------------------\n");
}

// Thu chon duong di cua chuot
void thu(int i)
{ 
  	int p,q;
	//Co 4 vi tri ma chuot co the di den vi tri (x, y)
    for(int j=0; j<=3; j++)
    {	p=x+h[j];
      	q=y+v[j];
       	if(a[p][q]==1)
	  	{ 	x=p; y=q;
	    	a[p][q]=2;
	    	if (y!=n)
	      		thu(i+1);
	    	else
	      		In_nghiem();
	      		a[p][q]=1;
	      		x=x-h[j];
	      		y=y-v[j];
	   }
    }

}
int main()
{
	DocFile();
	GhiFile();
	XuatMaTran();
	printf("\nVi tri ma chuot co the di duoc\n");
	//Vi tri xuat phat cua chuot
	for (int t=0; t<5; t++)
      	if (a[t][1]==1){
       		x=t; y=1;
			a[t][1]=2;
	 		thu(1);
	 		a[t][1]=1;
		}
}
