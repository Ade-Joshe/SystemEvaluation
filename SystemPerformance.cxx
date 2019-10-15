#include <iostream>

using namespace std;

float throughput(int x)
{
	// formular for throughput
	float z = 0.267 + (0.044 * x);
	return z;
}

float averageServiceRate(int x)
{
	// formular for average service rate of this system
	float z = 1.081 + (0.013 * x);
	return z;
}

auto responseTime(int x)
{
	// given that 5mins is the service rate, resulting to 12 services per hour.
	double trafficRate = x/12;
	
	cout<< "where m is " << x << endl;
	cout << "throughput is: " << throughput(x) << endl;
	cout << "average service rate is: " << averageServiceRate(x) << endl;
	
	float time = 1 / (averageServiceRate(x) - throughput(x));
	cout << "response time is: " << time << endl;

	if(trafficRate > 0.6)
	{
		cout<<"Saturation is most likely attained in this system at the moment"<<endl;
	}
	return 0;
}

int main()
{
	// here is to assume 20 persons are on the queue
	for(int i = 0;i <=20;i++)
	{
		responseTime(i);
	}
}
