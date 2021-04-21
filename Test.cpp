#include "NumberWithUnits.hpp"
#include "doctest.h"
#include <stdexcept>
using namespace ariel;
using namespace std;

TEST_CASE("Arithmetic operators"){
    NumberWithUnits km2(2,"km");
    NumberWithUnits km3(3,"km");
    NumberWithUnits m3(3,"m");
    NumberWithUnits hour2(2,"hour");
    NumberWithUnits min3(3,"min");
    CHECK((km2+km3)==NumberWithUnits(5,"km"));
    CHECK((km3-km2)==NumberWithUnits(1,"km"));
    CHECK((hour2+min3)==NumberWithUnits(2.03,"hour"));
    CHECK((hour2-min3)==NumberWithUnits(1.57,"hour"));
    CHECK(-km2==NumberWithUnits(-2,"km"));
    CHECK(+min3==NumberWithUnits(3,"min"));
    km2+=m3;
    CHECK(km2==NumberWithUnits(5.003,"km"));
    km3-=km2;
    CHECK(km3==NumberWithUnits(1,"km"));
    km3=km3*2;
    CHECK(km3==NumberWithUnits(2,"km"));
    // arithmetic betwwen diffrent types
    CHECK_THROWS(km2+hour2);
    CHECK_THROWS(km3-min3);
    CHECK_THROWS(km2+=hour2);
    

}
TEST_CASE(">=,<=,<,>,==,!=")
{
    NumberWithUnits kg2(2,"kg");
    NumberWithUnits kg3(3,"kg");
    NumberWithUnits kg(3,"kg");
    CHECK((kg3>kg2)==true);
    CHECK((kg2<kg3)==true);
    CHECK((kg3<=kg3)==true);
    CHECK((kg2>=kg2)==true);
    CHECK((kg3==kg)==true);
    CHECK((kg3!=kg2)==true);
}
TEST_CASE("++,--")
{
    NumberWithUnits kg2(2,"kg");
    kg2++;
    CHECK(kg2==NumberWithUnits(3,"kg"));
    kg2--;
    CHECK(kg2==NumberWithUnits(2,"kg"));
    CHECK(++kg2==NumberWithUnits(3,"kg"));
    CHECK(--kg2==NumberWithUnits(2,"kg"));
}



