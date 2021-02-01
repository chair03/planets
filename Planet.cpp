#include "Planet.h"

planet::planet(){
    this->Mass = 1;
    std::vector<double> vec = {0,0};
    this->n = 2;
    this->x = vec;
    this->p = vec;
}


planet::planet(double Mass,std::vector<double> x,std::vector<double> p){
    this->Mass = Mass;
    this->x = x;
    this->p = p;
    this->n = x.size();
}

std::vector<double> planet::get_x() {
    return this->x;
}

std::vector<double> planet::get_p(){
    return this->p;
}

double planet::getMass(){
    return this->Mass;
}

int planet::getDim(){
    return this->n;
}

void planet::update_x(double h){
    int dim = this->n;
    for(int i = 0;i<dim;i++){
        (this->x)[i] += (this->p)[i];
    }
}

void planet::update_p(double h,planet p,std::vector<double> (*gravity)(planet p1, planet p2)){
    int dim = this->n;
    std::vector<double> Force = gravity(*this,p);
    for(int i = 0;i<dim;i++){
        (this->p)[i] += h*Force[i];
    }
}