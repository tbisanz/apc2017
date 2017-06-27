// Rental.cc
#include "Rental.hh"

double Rental::getCharge() const 
{
  return rentedMovie.getCharge( nDaysRented );
}
  
int Rental::getFrequentRenterPoints() const 
{
  return rentedMovie.getFrequentRenterPoints( nDaysRented ); 
}
