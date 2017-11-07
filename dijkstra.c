#include<stdio.h>
#include<stdlib.h>
#define infinity 999
void dij(int n,int v,int cost[10][10],int dist[])
{
	int i,u,w,count,min,flag[10];
	for(i=1;i<=n;i++)
		flag[i]=0,dist[i]=cost[v][i];

	count=2;
	while(count<=n)
	{
		min=99;
		for(w=1;w<=n;w++)
			if(dist[w]<min && !flag[w])
				min=dist[w],u=w;
		
		count++;
		flag[u]=1;
		
		for(w=1;w<=n;w++)
			if(dist[w]>(dist[u]+cost[u][w]) && !flag[w])
				dist[w]=dist[u]+cost[u][w];
	}
}


void main()
{
	int i,j,cost[10][10],dist[10],v,n;
	printf("\nEnter number of nodes:");
	scanf("%d",&n);
	printf("\nCost matrix:\n");
	for(i=1;i<=n;i++){
	  for(j=1;j<=n;j++){
		scanf("%d",&cost[i][j]);
		if(cost[i][j]==0)
			cost[i][j]=infinity;
	}}
	printf("\nEnter the source vertex\n");
	scanf("%d",&v);
	dij(n,v,cost,dist);
	
	for(i=1;i<=n;i++)
		if(i!=v)
			printf("%d-->%d,cost=%d\n",v,i,dist[i]);
}
