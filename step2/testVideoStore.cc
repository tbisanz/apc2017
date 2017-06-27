
#include "Movie.hh"
#include "Rental.hh"
#include "Customer.hh"

#include <iostream>
#include <sstream>
using std::stringstream;
#include <string>
using std::string;

#include "gtest/gtest.h"

namespace VideoStoreTests {

  class VideoStoreTest : public ::testing::Test {

  public:
    VideoStoreTest() : 
      movie( "Title", Movie::REGULAR ),
      rental( movie, 3 ),
      customer( "Maria Grazia Pia" ) {
    }
    virtual ~VideoStoreTest() {}

    //virtual void SetUp() {}
    //virtual void TearDown() {}

    Movie movie;
    Rental rental;
    Customer customer;
  
  };

  // Movie

  // Test getPriceCode:
  TEST_F( VideoStoreTest, testgetPriceCode ) {
    int pc= movie.getPriceCode();
    EXPECT_EQ( pc, Movie::REGULAR );
  }

  // Test setPriceCode:
  TEST_F( VideoStoreTest, testsetPriceCode ) {
    movie.setPriceCode( Movie::CHILDRENS );
    int pc= movie.getPriceCode();
    EXPECT_EQ( pc, Movie::CHILDRENS );
  }

  // Test getTitle:
  TEST_F( VideoStoreTest, testgetTitle ) {
    std::string title= movie.getTitle();
    EXPECT_EQ( title, "Title" );
  }

  // Rental

  // getDaysRented
  TEST_F( VideoStoreTest, testgetDaysRented ) {
    int gdr= rental.getDaysRented();
    EXPECT_EQ( gdr, 3 );
  }

  // getMovie
  TEST_F( VideoStoreTest, testgetMovie ) {
    const Movie& m = rental.getMovie();
    EXPECT_EQ( m.getTitle(), movie.getTitle() );
    EXPECT_EQ( m.getPriceCode(), movie.getPriceCode() );
  }

  // Customer

  // getName
  TEST_F( VideoStoreTest, testgetName ) {
    string name = customer.getName();
    EXPECT_EQ( name, "Maria Grazia Pia" );
  }

  // statement
  TEST_F( VideoStoreTest, teststatement ) {

    // Expected printout
    string line1( "Rental Record for Maria Grazia Pia");
    string line2( "Snow White and the Seven Dwarfs" );
    string line3( "Gone with the Wind" );
    string line4( "Amount owed is 3.5" );
    string line5( "You earned 2 frequent renter points" );
    stringstream ss;
    ss << line1 << std::endl 
       << "\t" << line2 << "\t" << 1.5  << std::endl
       << "\t" << line3 << "\t" << 2 << std::endl
       << line4 << std::endl
       << line5;
    string reference = ss.str();

    // Setup a test case involving movies and rentals
    Movie snow( "Snow White and the Seven Dwarfs" );
    snow.setPriceCode( Movie::CHILDRENS );
    Rental snowRental( snow, 3 );
    Movie gone( "Gone with the Wind" );
    gone.setPriceCode( Movie::REGULAR );
    Rental goneRental( gone, 1 );
    customer.addRental( snowRental );
    customer.addRental( goneRental );

    // The test: the receipt generated by the software must conform 
    // to what is expected in this test case
    string receipt = customer.statement();
    EXPECT_EQ( receipt, reference );

  }

} // Namespace VideoStoreTests


// Main must be provided:
int main( int argc, char **argv ) {
  ::testing::InitGoogleTest( &argc, argv );
  return RUN_ALL_TESTS();
}
