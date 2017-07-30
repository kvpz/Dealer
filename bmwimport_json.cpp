/*
  This program will read BMW model details from a json and import into MySQL Database.
  bmwmodels.json data representation
  { series { [ <number> { ..., "bodystyles":{..., <number>: { dealerContribution: {...}, }} }
 */

#include <iostream>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <cassert>
#include <exception>
#include <sstream>
#include <fstream>
#include <Car.hpp>
#include "_mysql.h"
#include "mysql_driver.h"

#define HOST "127.0.0.1"
#define USER "root"
#define PSWD "hRe3dn1La#m"
#define DB "Cars"

/*
  Print only the simple elements of a JSON object
 */
void print(boost::property_tree::ptree const& pt)
{
    using boost::property_tree::ptree;
    ptree::const_iterator end = pt.end();
    for(ptree::const_iterator it = pt.begin(); it != end; ++it)
    {
	if(!it->second.empty())
	{
	    if(it->first != "") // not an array index
	    {
		std::cout << "=== " <<  it->first << " ===" << std::endl;

	    }
	    print(it->second);
	}
	else
	    std::cout << it->first << ": " << it->second.data() << std::endl;
	std::cout << std::endl;
    }
    
}


int main()
{
    /*
      sql::mysql::MySQL_Driver * driver;
      sql::Connection * mysql_con;

      driver = sql::mysql::get_mysql_driver_instance();
      mysql_con = driver->connect(HOST, USER, PSWD);
    
      std::cout << "Opening connection " << USER << "@" << HOST << std::endl;
      if(!mysql_con->isValid())
      {
      std::cout << "!! CONNECTION FAILED !!" << std::endl;
      }    

      // Create statement
      sql::Statement * stmt;
      stmt = mysql_con->createStatement();
      stmt->execute("USE " DB);
      stmt->execute("DROP TABLE IF EXISTS Cars");
      stmt->execute("CREATE TABLE Cars(id varchar(5), bodystyle varchar(10))");
      //stmt->execute("INSERT INTO test(id, label) VALUE(1, 'a')");
      stmt->execute("INSERT INTO Cars(id, bodystyle) VALUE('172B', 'coupe')");
      delete stmt;
    */    
    try
    {	
	boost::property_tree::ptree pt;
	boost::property_tree::read_json("byo_230icoupe.json", pt);

	// Loop through all 9 BMW Series
	BOOST_FOREACH(boost::property_tree::ptree::value_type &v, pt.get_child("byoConfiguration"))
	{
	    std::cout << "Main loop start: " << v.first << std::endl;
	    // v is a pair<basic_string, basic_tree<_string<char>,basic_string<char>> >
	    //assert(v.first.empty());
	    
	    //std::cout << "### Series: " << v.second.get_child("displayName").data() << std::endl; // displayName
	    //std::cout << "orderWeight: " << v.second.get_child("orderWeight").data() << std::endl;
	    print(v.second); // prints the simple Series element's values (not including "bodyStyles")
	    
	    
	    //PopulateCar(v.second, car);
	}

	
	// This should print "bodyStyles"
	//std::cout << pt.get_child("series").get_child("").front().second.front().first << std::endl;
	
    }
    catch(std::exception const& e)
    {
	std::cerr << e.what() << std::endl;
    }

    //delete mysql_con;
    //delete driver;
    
    return EXIT_SUCCESS;
}
