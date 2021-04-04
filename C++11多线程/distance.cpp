#include <bits/stdc++.h>
using namespace std;
#define M_PI 3.14159265358979323846

double gcj_distance(double latA, double lngA, double latB, double lngB) {
	const double earthR = 6371000;
	double x = cos(latA*M_PI/180) * cos(latB*M_PI/180) * cos((lngA-lngB)*M_PI/180);
	double y = sin(latA*M_PI/180) * sin(latB*M_PI/180);
	double s = x + y;
	if (s > 1) {
		s = 1;
	}
	if (s < -1) {
		s = -1;
	}
	double alpha = acos(s);
	double distance = alpha * earthR;
	return distance;
}

double gcj_distance2(double latA, double lngA, double latB, double lngB) {
	const double earthR = 6371000;
	latA = latA < 0 ? 90 - latA : latA < 90 ? 90 - latA : latA;
	latB = latB < 0 ? 90 - latB : latB < 90 ? 90 - latB : latB;//cout<<"latA="<<latA<<", latB="<<latB<<endl;
	double x = sin(latA*M_PI/180) * sin(latB*M_PI/180) * cos((lngA-lngB)*M_PI/180);
	double y = cos(latA*M_PI/180) * cos(latB*M_PI/180);
	double s = x + y;
	if (s > 1) {
		s = 1;
	}
	if (s < -1) {
		s = -1;
	}
	double alpha = acos(s);
	double distance = alpha * earthR;
	return distance;
}

int main()
{
	double x = -29.6, y = -62.6;
	double lon_lat[4][2] = {{-29.75, -62.75},
							{-29.75, -62.5},
							{-29.5, -62.5},
							{-29.5, -62.75
							}};
	for(int i=0; i<4; i++)
	{
		double dist = gcj_distance(lon_lat[i][0], lon_lat[i][1], x, y);
		double dist2 = gcj_distance2(lon_lat[i][0], lon_lat[i][1], x, y);
		cout<<"dist = "<<dist<<",\tdist2="<<dist2<<endl;
	}
	cout<<gcj_distance(11.0, 108.75, 11.492089, 108.896863)<<",\t"<<gcj_distance2(11.0, 108.75, 11.492089, 108.896863)<<endl;
	cout<<gcj_distance(111.0, 108.75, 111.492089, 108.896863)<<",\t"<<gcj_distance2(111.0, 108.75, 111.492089, 108.896863)<<endl;
	return 0;
}
