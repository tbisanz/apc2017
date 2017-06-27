// Rental.cc
#include "Rental.hh"

double Rental::getCharge() const 
{
  return rentedMovie.getCharge( nDaysRented );
}
  
int Rental::getFrequentRenterPoints() const 
{
  if ( ( getMovie().getPriceCode() == Movie::NEW_RELEASE )
       && getDaysRented() > 1 )
    return 2;
  else
    return 1;
}
