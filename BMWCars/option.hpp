/*
  option.hpp

  Notes for parsing JSON:
  Check if "isCozyRelevant" is true. This means that the image link is
  relevant to this option.
  It's important to check for combination prices because options that are
  part of a package end up being cheaper than if they were bought separately.
  See .byoConfiguration.options["0"].byooption.combinationPrices
  Packages can contain exclusive options!

  An option can belong to many packages.
*/

#include <iostream>
#include <vector>

class Option
{
public:

    // Accessor
    const std::string& GetCode() { return _code; }
    const std::string& GetName() { return _name; }
    const std::string& GetCategory() { return _category; }
    const std::string& GetSalesGroup() { return _salesGroup; }
    const std::string& GetDescription() { return _description; }
    const std::string& GetImage() { return _image; }
    const float GetPrice() { return _price; }

    // Mutators
    void SetCode(std::string&);
    void SetName(std::string&);
    void SetCategory(std::string&);
    void SetSalesGroup(std::string&);
    void SetDescription(std::string&);
    void SetImage(std::string&);
    void SetPrice(float);
  
private:
    std::string _code;
    std::string _familyCode;
    std::string _name;
    std::string _imageUrl;
    float _price;
    std::string _description; // longDescription
    std::string _category; // ex. "ConvenienceOptions
    std::string _salesGroup;
    std::vector<std::string> _comboCodes;
};

void Option::SetCode(std::string& code)
{
    _code = code;
}

void Option::SetName(std::string& name)
{
    _name = name; 
}

void Option::SetCategory(std::string& category)
{
    _category = category;
}

void Option::SetSalesGroup(std::string& salesGroup)
{
    _salesGroup = salesGroup;
}

void Option::SetDescription(std::string& description)
{
    _description = description;
}

void Option::SetImage(std::string& imageurl)
{
    _imageUrl = imageurl;
}

void Option::SetPrice(float price)
{
    _price = price;
}
