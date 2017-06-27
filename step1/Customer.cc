// Customer.cc
#include <sstream>
#include <vector>
#include "Customer.hh"

using std::ostringstream;
using std::vector;

std::string Customer::statement()
{
  double totalAmount = 0;
  int frequentRenterPoints = 0;
  std::vector< Rental >::iterator iter = customerRentals.begin();
  std::vector< Rental >::iterator iter_end = customerRentals.end();
  std::ostringstream result;
  result << "Rental Record for " << getName() << "\n";
  for ( ; iter != iter_end; ++iter ) {
    double thisAmount = 0;
    Rental each = *iter;

    thisAmount = amountFor( each );

    // add frequent renter points
    frequentRenterPoints++;
    // add bonus for a two day new release rental
    if ( ( each.getMovie().getPriceCode() == Movie::NEW_RELEASE )
         && each.getDaysRented() > 1 ) frequentRenterPoints++;

    // show figures for this rental
    result << "\t" << each.getMovie().getTitle() << "\t"
           << thisAmount << "\n";
    totalAmount += thisAmount;
  }
  // add footer lines
  result << "Amount owed is " << totalAmount << "\n";
  result << "You earned " << frequentRenterPoints
         << " frequent renter points";
  return result.str();
}

double Customer::amountFor( const Rental& each ) const
{
  double thisAmount = 0;
  switch ( each.getMovie().getPriceCode() ) {
    case Movie::REGULAR:
      thisAmount += 2;
      if ( each.getDaysRented() > 2 )
        thisAmount += ( each.getDaysRented() - 2 ) * 1.5;
      break;
    case Movie::NEW_RELEASE:
      thisAmount += each.getDaysRented() * 3;
      break;
    case Movie::CHILDRENS:
      thisAmount += 1.5;
      if ( each.getDaysRented() > 3 )
        thisAmount += ( each.getDaysRented() - 3 ) * 1.5;
      break;
  }
  return thisAmount;
}
