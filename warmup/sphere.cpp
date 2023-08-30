#include <iostream>	 // this has the cout, cin definitions
#include <stdlib.h>      // this has atoi and atof and exit
#include <math.h>         // this has atan
#include <string>
//#include "pbPlots.hpp"
//#include "supporLib.hpp"
//#include "multiplot.h"
using namespace std;     // if omitted, then need std::cout, std::cin

double get_volume(double R, double n){
	
	double V = pow(M_PI,n/2.0)*pow(R,n)/tgamma(n/2+1);
	return V;
	
}

void sphere(){
	//RGBABitmapImageReference *imageRef = CreateRGBABitmapImageReference();
	//Multiplot m(50,50,640,400);
	
	vector<vector<double> > map;
	vector<double> Rs;
	vector<TGraph*> graphs;
	TCanvas* c1 = new TCanvas("c1","N-sphere",1400,900);
	c1->cd(0);
	

	for(double j=1; j <2.01;j= j+0.05){
		Rs.push_back(j);
	}

	auto mg = new TMultiGraph;

	for(int i = 0; i < 51; i++){
		map.push_back(std::vector<double>());
		for(double R : Rs){
			double V = get_volume(R, (double) i);
			map[i].push_back(V);
		}
		graphs.push_back(new TGraph(Rs.size(), Rs.data(), map[i].data()));
		/*if (i == 0)
				graphs.back()->Draw();
		else
			graphs.back()->Draw("Same");*/
	}
	mg -> SetTitle("N-sphere Plot;R (radius);V (volume)");

	for(int i=0;i< 51 ;i++){
		mg->Add(graphs[i]);
	}
//	graphs[50]->Draw();
	mg->Draw("apl");
//	c1->Update();
//	c1->Show();
	c1->SaveAs("plot.png");

	
	std::cout << "Wait for key!\n";
//	std::string value = "";
//	std::cin >> value;
}

