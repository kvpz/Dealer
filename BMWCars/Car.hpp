/*
  Class for a BMW car.
  There can be more than one car for a model because of variations
  in the powertrain, for example.

  A car can be only one model.
  A car can only have one body style.
  A car can only have one VIN.
  A car can only have one stock number.
  

*/
#include <iostream>
//#include <string>
#include <model.hpp>
#include <Color.hpp>

class Car : public Model
{
public:
    
    // Accessors
    char GetSeries() { return _series; }
    std::string GetBodyStyle() { return _bodyStyle; }
    std::string GetVIN() { return _VIN; }
    std::string GetStockNumber() { return _stockNumber; }
    std::string GetFrontViewURL() { return _frontViewURL; }
    
    // Modifiers
    void SetSeries(const char&);
    void SetBodyStyle(const std::string&);
    void SetVIN(const std::string&);
    void SetStockNumber(const std::string&);
    void SetFrontViewURL(const std::string&);
    
private:
    char _series;
    std::string _bodyStyle;
    std::string _VIN;
    std::string _stockNumber;
    std::string _frontViewURL; // walkaround360DegViewUrlPart
    
};

void Car::SetSeries(const char& series)
{
    _series = series;
}

void Car::SetBodyStyle(const std::string& bodyStyle)
{
    _bodyStyle = bodyStyle;
}

void Car::SetVIN(const std::string& vin)
{
    _VIN = vin;
}

void Car::SetStockNumber(const std::string& stockNumber) 
{
    _stockNumber = stockNumber;
}

void Car::SetFrontViewURL(const std::string& url)
{
    _frontViewURL = url;
}
    
