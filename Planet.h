#include<vector>

class planet{
    private:
    double Mass;
    int n;
    std::vector<double> x;
    std::vector<double> p;

    public:
    planet();
    planet(double Mass,std::vector<double> x,std::vector<double> p);
    void update_x(double h); 
    void update_p(double h,planet p,std::vector<double> (*gravity)(planet p1, planet p2));
    std::vector<double> get_x();
    std::vector<double> get_p();
    double getMass();
    int getDim(); 
};
