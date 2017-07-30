/*
  package.cpp
  
  conflictRemoveOptions: there are several conflicts for M sports package
  for the 230i. Conflicts can be detected by .byoConfiguration.packages[4].hasConflict
  where the 4 is only for this example. These options can be determined by a unique
  code. Also some options may be unique to this package, or can only be obtained with
  a package, but the options will be placed in the same Option table in the database.

*/

#include <iostream>
#include <vector>

class Package
{
public:
    
private:
    std::string _code;
    std::string _name;
    std::string _price; // list price
    std::string _description; // long description
    std::string _category; // "packages"
    std::vector<std::string> _options; // optionCodes
    
};
