// Movie.hh
#ifndef MOVIE_HH
#define MOVIE_HH
#include <string>

class Movie {
public:
  static const int CHILDRENS   = 2;
  static const int REGULAR     = 0;
  static const int NEW_RELEASE = 1;

  Movie( const std::string& title, int priceCode = REGULAR );

  int getPriceCode() const;
  void setPriceCode( int arg );
  std::string getTitle() const;

  double getCharge( int daysRented ) const;

private:
  std::string movieTitle;
  int moviePriceCode;
};

inline Movie::Movie( const std::string& title, int priceCode ): 
  movieTitle( title ),
  moviePriceCode( priceCode )
{}

inline int Movie::getPriceCode() const { return moviePriceCode; }

inline void Movie::setPriceCode( int arg ) { moviePriceCode = arg; }

inline std::string Movie::getTitle() const { return movieTitle; }

#endif // MOVIE_HH
