// #include<bits/stdc++.h>
// using namespace std;
// class data{

//  public:
//  int number;
//  int salary;
//  //char name[100];
//   char *name=NULL;

//  ///constructor : it is default constructor which is first called automatically whenever we access the class
//  data()
//   {
//      cout<<"yes it's my own constructor"<<endl;
//   }

//   ///overriding constructor means we are implementing a constructor of our own
//   data(int n,int s,char *a):data()
//   {  number=n;
//      salary=s ;      ///it is called parameterized constructor
//      setname(a);
//     /* cout<<a<<endl;
//      int l=strlen(a);
//      name=new char[l+1];
//      strcpy(name,a);*/
//   }
   
//    data(int c)
//    {
//       number=c;

//    }
//   void  print()
//   {   data();  ///constructor calling (not recommended)
//     cout<<name<<endl<<salary<<endl<<number<<endl;
//   }

//    void setname(char *a)     //we are dynamically allocating name array and are setting name using function
//    {  int l=strlen(a);
//       name=new char [l+1];
//       strcpy(name,a);
//    }

//    data (data &X):data()   ///our own call constructor where object is passed by reference to avoid recursive calling of call fucntion
//    {                        ///we can also do constructor delegation
//       number=5000;
//       salary=X.salary;
//       int l=strlen(X.name);
//       name= new char[l+1];
//       setname(X.name);
//    }
   
//    ~data(){
//       cout<<"destructing the object allocated dynamically";
//       if(name!=NULL)
//       {
//          delete [] name;
//       }
//    }
// };
// int main()
// {
//    data d(10,2000,"shubham");   /// when we pass parameters then parametrized constructor is called
//    d.print();
// /*
//    data E;     ///when no paramter is passed then default constructor is being called

//    /// we can not do like this

//   // data F;          ///the default constructor will be called here and if we call the parametrized constructor
//   // F(100,10,"aman");  ///it will show error because both the constructors can not be called for the same object as only one constructor can be calledautomatically


//    ///two ways to call copy constructor
//  //  data f(d);  or  data f=d;*/   ///it copies all the members from the original object to this object this is done by default copy constructor

//    data C(d);  //when both initialisation and declaration is done copy constructor is called
//    C.name[0]='b';
//   C.name[0]='b';   // here only C name's will change as we have made our own call comstructor and it is not calling default call constructor
//    C.print();
//    d.print();
    
//     data F ; // default constructor is called
//     F=d;//copy assignment is called bcoz constructor is called only one time
//    data E(10);

//  return 0;

// }
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> even={{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,0}};
vector<vector<int>> odd={{0,-1},{-1,0},{0,1},{1,1},{1,0},{1,-1}};
vector<vector<bool>> vis;
int max1=0;
	
void tower(int r,int c,int tower_no,int current_tower,vector<vector<int>> &a,int ans,int n,int m)
{
	if(current_tower==tower_no)
	{
		if(ans>max1) max1=ans;
		return ;
	}

		vis[r][c]=true;
		ans+=a[r][c];
		if(c%2==0){

		for(int j=0;j<6;j++)
		{
			int nr=r+even[j][0];
			int nc=c + even[j][1];
		if(nr>=0 && nr<n && nc>=0 &&nc<m && !vis[nr][nc])
		{
			vis[nr][nc]=true;
			tower(nr,nc,tower_no,current_tower+1,a,ans,n,m);
			vis[nr][nc]=false;
		}
	}
	}
	else{

		for(int j=0;j<6;j++)
		{
			int nr=r+odd[j][0];
			int nc=c + odd[j][1];
		if(nr>=0 && nr<n && nc>=0 &&nc<m && !vis[nr][nc])
		{
			vis[nr][nc]=true;
			tower(nr,nc,tower_no,current_tower+1,a,ans,n,m);
			vis[nr][nc]=false;
		}
	 }
	 }
	return ;

}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> a;
	vector<int> b;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{	int c;
			cin>>c;
			b.push_back(c);
		}
		a.push_back(b);
	}
	vis.resize(n,vector<bool>(m,false));
	tower(0,0,4,0,a,0,n,m);
	cout<<max1;
	return 0;
}