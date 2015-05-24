#include <iostream>
#include<vector>
#include<functional>
#include<limits>

using namespace std;

class ok
{
private:
    int w;
public:
    int objects[25],siz = 25;
    int & operator [] (  int index )
  {
  #ifndef NO-CHECK
  if( index < 0 || index >= siz  )
  //throw ArrayIndexOutOfBoundsException( );
  #endif
  return objects [  index ]  ;
  }

  const int &  operator[] (  int index )  const
  {
  #ifndef NO-CHECK
  if( index < 0 ||  index >= siz  )
  //throw ArrayIndexOutOfBoundsException( );
  #endif
  return objects [  index ]  ;
  }
    //static int x;
    //static const int BLACK;
    int z;
    const int con = 7;
};
//int ok::x = 5;
int main()
{
    cout << "Hello world!" << endl;
    vector<int> a;
    cout<<"hi"<<INT_MAX<<endl;
    cout<<sizeof(ok)<<endl;
    //terminate();
//    cout<<ok::x;
    ok y;
    return 0;
}
