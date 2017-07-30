#include <iostream>
#include <stdlib.h>
#include <Color.hpp>

//struct TestStruct;

namespace TestSpace
{
    //struct TestStruct;
    class TestClass
    {
	//struct TestStruct;
    public:
	struct TestStruct;
	
	//struct TestStruct* GetTestStruct(){ return (struct TestSpace::TestStruct*)malloc(sizeof(struct TestStruct)); }
	//struct TestSpace::TestStruct& GetTestStruct();// { return _testStruct; }
	struct TestStruct GetTestStruct();
	
    private:
	struct TestStruct
	{
	    TestStruct(){
		std::cout << "Hello from TestStruct Constructor" << std::endl;
	    }
	} _testStruct;

    };

    struct TestClass::TestStruct TestClass::GetTestStruct()
    {
	return _testStruct;
    }
}

void CreateRGBObject()
{

}

void Set_RGB_Values_With_SetRGB()
{
    Dealership::Color col;
    col.SetRGB(1,1,1);
    Dealership::Color::RGB* rgb = col.GetRGB();
    if(rgb->red == 1 && rgb->green == 1 && rgb->blue == 1)
    {
	std::cout << "RGB set successfully with Color::SetRGB()" << std::endl;
    }
    else
    {
	std::cout << "RGB not set successfully with Color::SetRGB()" << std::endl;
    }
}

void Get_Image_URL()
{
    Dealership::Color c;
    
}

int main()
{

    Dealership::Color color;
    std::cout << "Getting rgb object" << std::endl;

    /*
    Dealership::Color::RGB rgb = color.GetRGB();
    
    std::cout << "Setting RGB values" << std::endl;
    rgb.red = 100;
    rgb.green = 100;
    rgb.blue = 100;
    std::cout << "RGB values set" << std::endl;
    */
    
    Set_RGB_Values_With_SetRGB();

    
    
    return 0;
}
