// RegularPrice.cc
#include "RegularPrice.hh"
#include "Movie.hh"

int RegularPrice::
getPriceCode() const
{
  return Movie::REGULAR;
}

double RegularPrice::getCharge( int daysRented ) const
{
  double result = 2;
  if ( daysRented > 2 )
    result += ( daysRented - 2 ) * 1.5 ;
  return result;
}
