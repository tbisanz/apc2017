// Price.hh
#ifndef PRICE_HH
#define PRICE_HH

class Price {
public:
  virtual ~Price();
  virtual int getPriceCode() const = 0;

  virtual double getCharge( int daysRented ) const = 0;
};

inline Price::~Price() {}

#endif // PRICE_HH
