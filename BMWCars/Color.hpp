/*
  Represent the colors that BMW car can have. The data that fits this model
  can be found in the JSON file provided by https://www.bmwusa.com/api/byo/models/...

  EXAMPLE - PROPERTY PATH: .byoConfiguration.colors["0"] 
  Code: P0475
  Category: Metallic
  *featureTier: false
  *featureConflict: false
  *hasConflict: false
  image: https://cache.bmwusa.com/cosy.arox?client=byo&brand=wbbm&view=paint_200x75&paint=P0475
  *isIncluded: false
  *isPackageElement: false
  *isPackageRequired: false
  *isPriority: false
  *isSubItem: false
  name: Black Sapphire Metallic
  optionType: ExteriorColors
  *packages: ["S0ZMP"]
  price: $700.00

  Example Note: "*" means the feature is not currently implemented in code.
  
  colorsPackageMap located at .byoConfiguration.colorsPackageMap maps a 
  color that a package can have. For the 230i, the colors only match up to 
  the M series. 
*/

#include <iostream>

#define IMAGE_URL "https://www.bmwusa.com/cosy.arox?client=byo&brand=wbbm&view=paint_200x75&paint="

namespace Dealership
{    
    class Color
    {
	friend class Upholstery;
    public:
	struct RGB;
	Color()
	{
	    _rgb = new RGB();
	}
	
	Color(std::string code, std::string category, std::string name,
	      std::string optionType, float price);

	// Accessors
	struct RGB* GetRGB() { return _rgb; }
	const std::string GetImageUrl() { return IMAGE_URL + _code; }
	
	// Modifiers
	void SetRGB(short r, short g, short b);
	void SetCode(std::string);
	void SetCategory(std::string);
	void SetName(std::string);
	void SetOptionType(std::string);
	void SetPrice(float);
	
    private:
	std::string _code;
	std::string _category;
	std::string _name;
	std::string _optionType;
	float _price;
	
	struct RGB
	{
	    short red, green, blue;
	    RGB() {}
	    RGB(short r, short g, short b) : red(r), green(g), blue(b){ }
	}* _rgb;
	
    };

    Color::Color(std::string code, std::string category, std::string name,
		 std::string optionType, float price)
	: _code(code), _category(category), _name(name), _optionType(optionType), _price(price)
    {}

    void Color::SetRGB(short r, short g, short b)
    {
	_rgb->red = r;
	_rgb->green = g;
	_rgb->blue = b;
    }

    void Color::SetCode(std::string code)
    {
	_code = code;
    }
    
    void Color::SetCategory(std::string category)
    {
	_category = category;
    }
    
    void Color::SetName(std::string name)
    {
	_name = name;
    }
    
    void Color::SetOptionType(std::string optionType)
    {
	_optionType = optionType;
    }
}

