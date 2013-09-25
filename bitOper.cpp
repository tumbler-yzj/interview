#include <iostream>
#include <cstdlib>
using namespace std;

// Bit Operation Implements Add, Submit, Multiply, Divide
// Use only Integer with little length

// add
int add( int a, int b ){ 
 int c;
 while( c = (a&b) ){
  a = (a^b);
  b = (c<<1);
 }
 return (a^b);
}

// complementary code
int rev( int a ){
 return add((~a), 1);
}

// is positive
int ispos( int a ){
 return (a&0xFFFF) && !(a&0x8000);
}

// is negative
int isneg( int a ){
 return a&0x8000;
}

// is 0
int iszero( int a ){
 return !(a&0xFFFF);
}

// if or not have a > b >= 0
int isbig_pos( int a, int b ){
 int c = 1;
 b = (a^b);
 if( iszero(b) ) return 0;
 while( b >>= 1 ){
  c <<= 1;
 }
 return (c&a);
}

// if or not have a > b
int isbig( int a, int b ){
 if( isneg(a) ){
  if( isneg(b) ){
   return isbig_pos( rev(b), rev(a) );
  }
  return 0;
 }
 if( isneg(b) ) return 1;
 return isbig_pos(a, b);
}

// submit
int sub( int a, int b ){ 
 return add(a, rev(b));
}

// two positive numbers multiply
int pos_mul( int a, int b ){
 int c = 0x8000;
 int re = a;
 while( (c>>=1) && (!(b&c)) );
 while( c >>= 1 ){
  re <<= 1;
  if( c&b )
   re = add(re, a);
 }
 return re;
}

// multiply
int mul( int a, int b ){
 if( iszero(a) || iszero(b) ) return 0;
 if( ispos(a) && ispos(b) )
  return pos_mul(a, b);
 if( isneg(a) ){
  if( isneg(b) ){
   return pos_mul( rev(a), rev(b) );
  }
  return rev( pos_mul( rev(a), b ) );
 }
 return rev( pos_mul(a, rev(b)) );
}

// two positive numbers divide
int pos_div( int a, int b ){
 int re = 0, temp = b;
 if( isbig_pos(b, a) ) return 0;
 do{
  temp <<= 1;
 }while( !isbig_pos(temp, a) );
 while( isbig_pos(temp, b) ){
  re <<= 1;
  temp >>= 1;
  if( !isbig_pos(temp, a) ){
   a = sub(a, temp);
   re = add(re, 1);
  }
 }
 return re;
}

// divide
int idiv( int a, int b ){
 if( iszero(b) ) {
  cout << "error" << endl;
  exit(1);
 }
 if( iszero(a) ) return 0;
 if( ispos(a) ){
  if( ispos(b) )
   return pos_div(a, b);
  return rev( pos_div( a, rev(b)) );
 }
 if( ispos(b) )
  return rev( pos_div( rev(a), b ) );
 return pos_div( rev(a), rev(b) );
}

int main () {
 int a, b;
//  while( cin >> a >> b){
//   if(isbig(a,b)&&(a<=b)) cout << "big error" << endl;
//   if(add(a,b) != (a+b)) cout << "add error" << endl;
//   if(sub(a,b) != (a-b)) cout << "sub error" << endl;
//   if(mul(a,b) != (a*b)) cout << "mul error" << endl;
//   if(idiv(a,b) != (a/b)) cout << "div error" << endl;
//  }

 a=8;
 b=-4;
 int c=add(a,b);
 cout<<c<<endl;
 c=sub(a,b);
 cout<<c<<endl;
 c=mul(a,b);
 cout<<c<<endl;
 c=idiv(a,b);
 cout<<c<<endl;
 while(1);
 return 0;
} 
