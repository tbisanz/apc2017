// Movie.cpp
#include "Movie.hh"

#include <stdexcept>
#include "RegularPrice.hh"
#include "ChildrensPrice.hh"
#include "NewReleasePrice.hh"


const int Movie::CHILDRENS;
const int Movie::REGULAR;
const int Movie::NEW_RELEASE;

Movie::Movie( const std::string& title, int priceCode ): 
  movieTitle( title ),
  moviePrice( 0)
{
  setPriceCode( priceCode );
}

Movie::Movie( const Movie& movie ): 
  movieTitle( movie.movieTitle ), 
  moviePrice( 0 )
{
  setPriceCode( movie.getPriceCode() );
}

Movie& Movie::operator=( const Movie& rhs )
{
  if ( this == &rhs )
    return *this;
  movieTitle = rhs.movieTitle;
  setPriceCode( rhs.getPriceCode() );
  return *this;
}

int Movie::getPriceCode() const
{
  return moviePrice->getPriceCode();
}

void Movie::setPriceCode( int arg )
{
  delete moviePrice;
  switch ( arg ) {
  case REGULAR:
    moviePrice = new RegularPrice;
    break;
  case CHILDRENS:
    moviePrice = new ChildrensPrice;
    break;
  case NEW_RELEASE:
    moviePrice = new NewReleasePrice;
    break;
  default:
    throw std::invalid_argument("Incorrect Price Code");
  }
}


double Movie::getCharge( int daysRented ) const
{
  return moviePrice->getCharge( daysRented );
}


int Movie::getFrequentRenterPoints( int daysRented ) const
{
  return moviePrice->getFrequentRenterPoints( daysRented );
}

