#include<iostream>
using namespace std;

int main()
{
	string crc,encoded;
	int i,j;
	cout<<"Enter the message\n";
	getline(cin,encoded);
	cout<<"Enter the crc generator polynomial\n";
	getline(cin,crc);
	
	for(i=0;i<=encoded.length()-crc.length();){
	for(j=0;j<crc.length();j++)
	encoded[i+j]=encoded[i+j]==crc[j]?'0':'1';
	for(;i<encoded.length() && encoded[i]!='1';i++);
	}

	cout<<"Encoded message\n";
	cout<<"\n"<<encoded<<"\n";
	string se="";
	int len=encoded.length();
	for(i=0;i<len;i++)
	se=se+'0';
	
	if(encoded==se)
	cout<<"No error in transmission\n";
	else 
	cout<<"Error in transmissin\n";
	return 0;

}
