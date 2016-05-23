#include "circle.hpp"
#include "vec2.hpp"
#include <cmath>
#include <algorithm>



Circle::Circle():
    center_{Vec2()},
    radius_{1.0f}
    {}
        

Circle::Circle(Vec2 const& ctr, float r) :
    center_{ctr},
    radius_{r}
    {}

Circle::Circle(float r) :
    center_{Vec2()},
    radius_{r}
    {}



void Circle::radius(float r) 
{radius_=r;}

void Circle::center(Vec2 const& ctr) 
{center_=ctr;}


Vec2 Circle::center() const 
{return center_;}

float Circle::radius() const 
{return radius_;}


bool operator<(Circle const& c, Circle const& d)
{
    return c.radius()<d.radius();
}


bool operator>(Circle const& c, Circle const& d)
{
    return c.radius()>d.radius();
}

bool operator==(Circle const& c, Circle const& d)
{
    return c.radius()==d.radius();
}



