#include<iostream>
using namespace std;

int main()
{
	string msg,crc,encoded="";
	int i,j;
	cout<<"Enter the message\n";
	getline(cin,msg);
	cout<<"Enter the crc generator polynomial\n";
	getline(cin,crc);
	encoded+=msg;
	
	int m=msg.length(),n=crc.length();
	
	for(i=1;i<=n-1;i++)
	encoded+='0';
	
	for(i=0;i<=encoded.length()-n;){
	for(j=0;j<n;j++)
	encoded[i+j]=encoded[i+j]==crc[j]?'0':'1';
	for(;i<encoded.length() && encoded[i]!='1';i++);
	}
	cout<<"Encoded message\n";
	cout<<msg+encoded.substr(encoded.length()-n+1);
}
