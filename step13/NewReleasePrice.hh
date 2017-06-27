// NewReleasePrice.hh
#ifndef NEWRELEASEPRICE_HH
#define NEWRELEASEPRICE_HH
#include "Price.hh"

class NewReleasePrice : public Price {
public:
  virtual int getPriceCode() const;
};

#endif // NEWRELEASEPRICE_HH
