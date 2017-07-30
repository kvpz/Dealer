# Makefile for tests

CC= g++
CarLib= /home/kevin/Documents/mysqlStuff/data/BMWCars/

color.test.x: $(CarLib)Color.hpp
	$(CC) -ocolor.test.x test_color.cpp -I$(CarLib)

model.test.x: $(CarLib)model.hpp
	$(CC) -omodel.test.x test_model.cpp -I$(CarLib)

car.test.x: $(CarLib)Car.hpp $(CarLib)Color.hpp $(CarLib)model.hpp
	$(CC) -ocar.test.x test_car.cpp -I$(CarLib)

upholstery.test.x: $(CarLib)upholstery.hpp
	$(CC) -oupholstery.test.x test_upholstery.cpp -I$(CarLib)
