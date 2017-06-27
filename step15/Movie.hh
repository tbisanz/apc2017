// Movie.hh
#ifndef MOVIE_HH
#define MOVIE_HH
#include <string>

#include "Price.hh"

class Movie {
public:
  static const int CHILDRENS   = 2;
  static const int REGULAR     = 0;
  static const int NEW_RELEASE = 1;

  Movie( const std::string& title, int priceCode = REGULAR );

  Movie( const Movie& );
  ~Movie();

  Movie& operator=( const Movie& rhs );

  int getPriceCode() const;
  void setPriceCode( int arg );
  std::string getTitle() const;

  double getCharge( int daysRented ) const;
  int getFrequentRenterPoints( int daysRented ) const;

private:
  std::string movieTitle;
  Price* moviePrice;
};

inline Movie::~Movie()
{
  delete moviePrice;
}

inline std::string Movie::getTitle() const { return movieTitle; }

#endif // MOVIE_HH
