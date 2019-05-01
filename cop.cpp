#include<iostream>
#include<fstream>
#include<string.h>
#include<sstream>
#include<stdlib.h>
using namespace std;


#define MAX 15
fstream file;
int x,i,y,pos,offset;

class student
{
	public:
	fstream fp1;
	string name,branch,buffer;
        //char buffer1[100];
	int usn,semester;
	void read();
	void pack(int x);
	void write();
	void unpack(int);
	
	int hash(string);
	
	
}s;
student st[20];


class Hash
{ public:

	int a[MAX];
	int b[MAX];
	int k;
        char buffer1[100];
  public:
	Hash();
        void search(int);
        void printvalue(int);
	int create(int);
	int chainprob(int,int);
	void display();
}h;

Hash::Hash()
{
 int i;
 for(i=0;i<MAX;i++)
 {
 	a[i]=-1;
    b[i]=-1;
 }
  
}

int Hash::create(int num)
{
 int key;
 key=num%10;
 return key;
}

int Hash::chainprob(int key,int num)
{
 int flag,count=0;
 flag=0;
// file.open("hashtable",ios::out);
 if(a[key]==-1)//if the location indicated by hash key is empty
 {
 
   k=key;
  a[key]=num;
  return key;//place the number in the hash table
 // file<<1<<"|"<<num<<endl;
 }
 else
 {
  i=0;
  while(i<MAX)
  {
   if(a[i]!=-1)
       count++;
    i++;
  }
  if(count==MAX)        //checking for the hash full
  {
	  cout<<"\nHash Table Is Full Hence "<<num<<" Can not Be Inserted";
	  display();
     // getch();
	  exit(1);
  }
  //cout<<key;
  for(i=key+1;i<MAX;i++)//moving linearly down
    if(a[i]==-1)    // searching for empty location
    {
      a[i]=num;
      return i;
	   //placing the number at empty location
	  
	  if(b[key]==-1)
	  {
	  
	     b[key]=i;
	     return i;
	    //s.pack(st[i]);
      }
	  else 
	  {
	  
	     b[b[key]]=i;
	     return i;
	   
	  }
	  //cout<<i;
	    
   //   file.open("hashtable",ios::out);
     // file<<key<<"|"<<endl;
      //file.close();
      flag=1;
       
   //   file.close();
      break;
    }

//From key position to the end of array we have searched empty location
//and now we want to check empty location in the upper part of the array
 for(i=0;i<key&&flag==0;i++)//array from 0th to keyth loaction will be scanned
  if(a[i]==-1)
  {
   a[i]=num;
   b[key]=i;
   if(b[key]==-1)
   {
   	 b[key]=i;
   	 
   	 return i;
   	
   }
	    
	  else 
	  {
	  	 b[b[key]]=i;
	  	 return i;
	  	 	  	
	  }
	    
   flag=1;
   return i;
   break;
  }
 } //outer else
}//end

void Hash::display()
{
 int i;
 fstream fp1;
 fp1.open("hashtable",ios::out);
 cout<<"\n The Hash Table is..."<<endl;
 for(i=0;i<MAX;i++)
 {
//  cout<<"\n  "<<i<<"  "<<a[i];
  fp1<<i<<"  "<<a[i]<<" "<<b[i]<<endl;
 }
 fp1.close();
 
}


void Hash:: printvalue(int pos)
{

file.open("define.txt",ios::in);
  
                 
		        //hash=atoi(pos);
		offset=100*(pos);
		cout<<offset<<endl;
		
		file.seekg(offset,ios::beg);
		ifstream fp("define.txt");
		string temp;
		while(getline(fp,temp))
		{
				cout<<temp<<endl;
			
			   file.close();
        	}



}
 




void student::read()
{
	cout<<"\n usn:"<<endl;;
	cin>>usn;
	cout<<"\n name:"<<endl;;
	cin>>name;
	cout<<"\n branch:"<<endl;;
	cin>>branch;
	cout<<"\n semester:"<<endl;
	cin>>semester;
	//pack(s)
}


void student::pack(int x)
{ 
   string us,sem,temp;
	stringstream outusn,outsem;
	outusn<<usn;
	us=outusn.str();
	outsem<<semester;
	sem = outsem.str();
	buffer.erase();
	temp.erase();
	//temp+=us;
	temp+=us+'|'+name+'|'+branch+'|'+sem;
	for(;temp.size()<100;)temp+='$';
	buffer=temp;
	cout<<"\n buffer:"<<buffer<<endl;
	file.open("define.txt",ios::out|ios::in);
	        
	         file.seekp((x-1)*100, ios::beg);
		  file<<x<<"|"<<buffer;
	
		 
		   
        file.close();
}


void Hash::search(int key)
{
	Hash h;
    int k1=h.create(key);
    int hash,h1;
    
    
    if(a[k1]==key)
    {
       cout<<"key found->"<<k1<<endl;
        pos=k1;
		h.printvalue(pos);
       		
       
         
      }
    while(b[k1]!=-1)
    {
         if(a[b[k1]]==key)
        {
         cout<<"key found at->"<<b[k1]<<endl;
            pos=b[k1];
            h.printvalue(pos);
              
        }
         else
         {
         	k1++;
         	
		 }

    }     
 
           
            if(b[k1]==-1)
           {
	
             cout<<"key not found";
             
          }
        
   } 
  
   

int main()
{
	int choice,key1,x;
	student s;
	Hash h;
	int key;
	file.open("define.txt",ios::out);
	file.close();
	while(1)
	{
		cout<<"\n1.ADD\n2.Search\n3.EXIT:\n";
		cin>>choice;
		switch(choice)
		{
		case 1: cout<<"Enter the data:";
		s.read();
		key1=h.create(s.usn);//returns hash key
	    x=h.chainprob(key1,s.usn);
	cout<<x<<endl;//collision handled by linear probing
	    h.display();
	    s.pack(x);
		//s.write();
		break;

		case 2: cout<<"Enter the USN to be searched:";
		cin>>key;
                //key1=h.create(key);
		h.search(key);
		break;
		

		case 3: exit(0);
		}
	}
}


