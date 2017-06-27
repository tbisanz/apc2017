// RegularPrice.hh
#ifndef REGULARPRICE_HH
#define REGULARPRICE_HH
#include "Price.hh"

class RegularPrice : public Price {
public:
  virtual int getPriceCode() const;
};

#endif // REGULARPRICE_HH
