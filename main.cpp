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
    double force_constant = G*m1*m2/r;
    std::vector<double> force;
    
    for(int i = 0;i<n;i++){
        double dis = r1[i] - r2[i];
        force.push_back(force_constant*dis); 
    }
    return force;
}




int main(){
    planet sun(2.0,{-0.5,0},{-0.94,0.65});
    planet earth(1.0,{-0.6,-0.2},{1.86,0.7});
    planet riza(1.0,{0.5,0.1},{-0.44,-1.4});
    planet alpha(0.4,{0.6,0.3},{1.15,-1.49999});
    std::vector<planet> planets = {sun,earth,riza,alpha};

    // hyperparamters
    int numIterations = 500;
    double h = 0.01;
    
    std::ofstream myfile;
    myfile.open ("example.csv");
    
    for(int i = 0; i < numIterations;i++){
       for(int j = 0;j<planets.size();j++){
           std::vector<double> x1;
           x1 = planets[j].get_x();
           if(j == planets.size()-1){
                myfile<<x1[0]<<","<<x1[1]<<"\n";
           }
           else{
               myfile<<x1[0]<<","<<x1[1]<<",";
           }
           
           planets[j].update_x(h);
           for(int k = 0;k<planets.size();k++){
               if(k != j){
                planets[j].update_p(h,planets[k],gravity);
               }
           }

       }
    }
    myfile.close();
    return 0;
}