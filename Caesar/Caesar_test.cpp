#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>

//��������������㷨
 
using namespace std;

void encry(string str,int n,int mode)  //str�������룬n��Կ��ģʽ
{
	if(mode==1)
	{
		for(int i=0;i<str.size();i++)
		{
			if(str[i]>='A'&&str[i]<='Z')
				str[i]=(str[i]-'A'+n)%26+'A';
			else if(str[i]>='a'&&str[i]<='z')
				str[i]=(str[i]-'a'+n)%26+'a';		
		}
		cout<<"������ɣ�"<<str<<endl;
//			FileOut(str);
//			cout<<"��������ļ�"<<endl; 
	}

	 else
	 {
	 		cout<<"��ģʽ��֧�ִ���ܣ�"<<endl; 
	 }

}

void decry(string str,int n,int mode) //str�������ַ�����nΪ��Կ��ģʽ
{
	if(mode==2)
	{
		for(int i=0;i<str.size();i++)
		{
			if(str[i]>='A'&&str[i]<='Z')
				str[i]=(str[i]-'A'+26-n)%26+'A';
			else if(str[i]>='a'&&str[i]<='z')
				str[i]=(str[i]-'a'+26-n)%26+'a';
			
		}
		cout<<"������ɣ�"<<str<<endl; 		
	 } 
	 else
	 {
	 	cout<<"��ģʽ��֧�ִ���ܣ�"<<endl; 
	 }
} 

int main(void)
{
	string str;
	int model;
	int n;
	while(1)
	{
		cout<<"�������룺��ѡ��ģʽ��\n";
		cout<<"1.����\n";
		cout<<"2.����\n";
		cout<<"3.�˳�\n";
		cin>>model;
		cout<<endl; 
		switch(model)
		{
			case 1:
				cout<<"������Ҫ���ܵ��ַ�����";
				cin>>str;
				cout<<"������������㷨��ƫ��������";
				cin>>n;
				encry(str,n,model);
				cout<<endl;
				break;
			case 2:
			 	cout<<"������Ҫ���ܵ��ַ�����";
				cin>>str;
				cout<<"������ԭ�����㷨��ƫ��������";
				cin>>n;
				decry(str,n,model);
				cout<<endl;
				break;
			case 3:
				return 0;
				break;
			default:
				break;
		}
		
		
	}
	
	return 0;
	
	
}









