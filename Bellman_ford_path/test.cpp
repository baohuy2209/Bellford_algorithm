#include <iostream>
 
using namespace std;
const int MAX = 3;
 
int main ()
{
   int  var[MAX] = {10, 100, 200};
   int *contro[MAX];
 
   for (int i = 0; i < MAX; i++)
   {
      contro[i] = &var[i]; // gan dia chi cua so nguyen.
   }
   for (int i = 0; i < MAX; i++)
   {
      cout << "Gia tri cua var[" << i << "] = ";
      cout << *contro[i] + 20 << endl;
   }
   return 0;
}