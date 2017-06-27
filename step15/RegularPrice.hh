// RegularPrice.hh
#ifndef REGULARPRICE_HH
#define REGULARPRICE_HH
#include "Price.hh"

class RegularPrice : public Price {
public:

  virtual int getPriceCode() const;
  virtual double getCharge( int daysRented ) const;

};

#endif // REGULARPRICE_HH
