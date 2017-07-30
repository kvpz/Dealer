/*
  upholstery.cpp
  Upholstery is a friend of Color.

  Contains information pertaining to the interior.
  
  < IMPORTANT PROPERTY PATHS >
  .byoConfiguration.leathers
  .byoConfiguration.leathers["0"].packages
  .byoConfiguration.leathers["0"].byooption
  .byoConfiguration.leathersPackageMap
  
  An upholstery is part of many packages which can be identified in 
  the leathersPackageMap object.
  
*/

#include <iostream>
#include <Color.hpp>
#include <option.hpp>

class Upholstery : public Option
{
    
public:

    // Accessors

    // Modifiers
    void SetRGB(short r, short g, short b) { _rgb = new Dealership::Color::RGB(r,g,b); }
    
private:
    std::string _name;
    std::string _code;
    std::string _optionType; // "InteriorColors"
    std::string _price; // list price
    std::string _familyCode;
    Dealership::Color::RGB* _rgb;
    std::string _type;
};


