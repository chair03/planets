#include<iostream>
#include <cmath>
#include<fstream>
#include"Planet.cpp"

double dist(planet p1,planet p2){
    std::vector<double> r1 = p1.get_x();
    std::vector<double> r2 = p2.get_x();
    int n = p1.getDim();
    double r = 0;
    for(int i = 0;i<n;i++){
        r += pow((r1[i]-r2[i]),2);
    }

    return sqrt(r);
}

std::vector<double> gravity(planet p1,planet p2){
    int n = p1.getDim();
    double G = 6.67408e-11;
    double r = dist(p1,p2);
    double m1 = p1.getMass();
    double m2 = p2.getMass();
    std::vector<double> r1 = p1.get_x();
    std::vector<double> r2 = p2.get_x();
    double force_constant = G*m1*m1/r;
    std::vector<double> force;
    for(int i = 0;i<n;i++){
        force[i] += force_constant*(r1[i] - r2[i]); 
    }
    return force;
}


int main(){
    planet sun(2,{-0.5,0},{-0.94,0.65});
    planet earth(1,{-0.6,-0.2},{1.86,0.7});
    planet riza(1,{0.5,0.1},{-0.44,-1.4});
    planet citialpha5(0.4,{0.6,0.3},{1.15,-1.5});
    
    int numIterations = 500;
    double h = 0.01;
    std::ofstream myfile;
    myfile.open ("example.csv");
    std::cout<<"Opening file"<<"\n";
    for(int i = 0; i < numIterations;i++){
        if(i%5 == 0){
            std::cout<<"Writing to file"<<"\n";
        }
        std::vector<double> x1;
        std::vector<double> x2;
        std::vector<double> x3;
        std::vector<double> x4;
        x1 = earth.get_x();
        x2 = sun.get_x();
        x3 = riza.get_x();
        x4 = citialpha5.get_x();
        if(i%5 == 0){
            std::cout<<"Writing to file"<<"\n";
        }
        myfile<<x1[0]<<","<<x1[1]<<",";
        myfile<<x2[0]<<","<<x2[1]<<",";
        //myfile<<x3[0]<<","<<x3[1]<<",";
        myfile<<x4[0]<<","<<x4[1]<<"\n";
        if(i%5 == 0){
            std::cout<<"Writing to file"<<"\n";
        }
        sun.update_x(h);
        earth.update_x(h);
        sun.update_x(h);
        riza.update_x(h);
        citialpha5.update_x(h);
        earth.update_p(h,sun,gravity);
        sun.update_p(h,earth,gravity);
        riza.update_p(h,sun,gravity);
        citialpha5.update_p(h,sun,gravity);
    }
    myfile.close();
    return 0;
}