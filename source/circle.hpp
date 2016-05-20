#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include <cmath>
#include "vec2.hpp"




class Circle 
{
  public:
    Circle();
    Circle(Vec2 const& ctr, float r);

    

    //set
    void radius(float r); 
    void center(Vec2 const& ctr);

    //get
    Vec2 center() const ;
    float radius() const;


  private:
    Vec2 center_;
    float radius_;

};

bool operator<(Circle const& c, Circle const& d);
bool operator>(Circle const& c, Circle const& d);
bool operator==(Circle const& c,Circle const& d);

#endif