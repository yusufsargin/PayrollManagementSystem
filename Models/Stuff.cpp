//
// Created by user on 28.12.2020.
//

class Stuff
{
private:
    double insurance;
    double food;
public:
    Stuff():insurance(0.0),food(0.0){}
    void setInsurance(double insurance)
    {
        this->insurance = insurance;
    }
    void setFood(double food)
    {
        this->food = food;
    }
    double getInsurance(){return insurance;}
    double getFood(){return food;}
};
