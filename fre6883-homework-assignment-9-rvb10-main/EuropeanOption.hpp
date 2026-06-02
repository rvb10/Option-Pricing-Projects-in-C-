#ifndef EuropeanOption_hpp
#define EuropeanOption_hpp

#include <string>
using namespace std;

class EuropeanOption
{
private:
	double r;	
	double sig; 
	double K;	
	double T;	
	double U;	
	double b;	
	char *optType;

	double CallPrice() const;
	double PutPrice() const;
	double CallDelta() const;
	double PutDelta() const;
	double CallGamma() const;
	double PutGamma() const;
	double CallVega() const;
	double PutVega() const;

	double n(double x) const;
	double N(double x) const;

public: 
	EuropeanOption(double r_, double sig_, double K_, double T_, double U_, double b_, char* optType_ = (char*)"C");

	EuropeanOption(const EuropeanOption &o2);
	virtual ~EuropeanOption();

	EuropeanOption &operator=(const EuropeanOption &option2);

	double Price() const;
	double Delta() const;
	
	void toggle(); 
};

#endif
