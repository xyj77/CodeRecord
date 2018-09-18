#include<iostream>
#include<math.h>
using namespace std;
float max(float a, float b, float c){
    float z,p;
    if (a > b)p = a;else p = b;
    if (p > c)z = p;else z = c;
    return z;
}
float min(float a, float b, float c){
    float z, p;
    if (a < b)p = a;else p = b;
    if (p < c)z = p;else z = c;
    return z;
}
float mid(float a, float b, float c){
    float z;
    if (a != max(a, b, c) || min(a, b, c))z = a;
	else if (b != max(a, b, c) || min(a, b, c))z = b;
    else z = c;
    return z;
}
bool isTriangle(float a, float b, float c){
    if (a < 0 || b < 0 || c < 0) return false;
	float s, x, y, z, p;
    p = a + b + c / 2;
    s = sqrt(p*(p - a)*(p - b)*(p - c));
    x = max(a, b, c);
    y = mid(a, b, c);
    z = min(a, b, c);
    
    if (z + y <= x) return false;
    return true;
}
int main(){
    float a, b, c;
    cin>>a>>b>>c;
    cout<<isTriangle(a, b, c)<<endl;
    return 0;
}

