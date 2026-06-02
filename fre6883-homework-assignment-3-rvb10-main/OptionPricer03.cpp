#include <iostream>
using namespace std;
 class DefInt{
    private:
        double a,b;
        double (*f)(double);
    public:
        DefInt(double limit_lower, double limit_upper, double (*func)(double)) : a(limit_lower), b(limit_upper), f(func) {}
        double ByTrapzoid(int N){
            double h = (b-a)/(N);
            double sum = (f(a) + f(b))/2;
            double x_h = 0;

            for(int k=1;k<N;k++){
                x_h = a + k * h;
                sum += f(x_h);
            }
            sum = sum * h;
            return sum;
        }
        double BySimpson(int N){ 
            //int N = 1000;
            double h = (b-a)/(N);
            double sum = f(a) + f(b);
            double x_h = 0;
            for(int k=1;k<N;k++){
                x_h = a + k * h;
                if (k % 2 == 1){
                    sum += 4 * f(x_h);
                }
                else{
                    sum += 2 * f(x_h);
                }          
            }
            sum = sum * (h/3);
            return sum;
        }   
};
double f(double x) { return (x*x*x) - (x*x) + 1; }
int main(){
    double a,b;
    //int N;
    //cout << "Enter N: ";
	//cin >> N;
    cout << "Enter a: " ;
	cin >> a;
    cout << "Enter b: ";
	cin >> b;
    DefInt MyInt(a, b, f);
	cout << "By Trapzoid: " << MyInt.ByTrapzoid(1000) << endl;
	cout << "By Simpson: " << MyInt.BySimpson(1000) << endl;
    return 0;
}

/*
Enter a: 1
Enter b: 2
By Trapzoid: 2.41667
By Simpson: 2.41667
*/

