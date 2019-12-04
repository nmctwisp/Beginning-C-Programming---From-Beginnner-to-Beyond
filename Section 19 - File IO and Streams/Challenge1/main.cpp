// Section 19
// Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
	std::string name;
	long population;
	double cost;
};

// Assume each country has at least 1 city
struct Country {
	std::string name;
	std::vector<City> cities;
};

struct Tours {
	std::string title;
	std::vector<Country> countries;
};

int main()
{
	Tours tours
	{ "Tour Ticket Prices from Miami",
		{
			{
				"Colombia", {
					{ "Bogota", 8778000, 400.98 },
					{ "Cali", 2401000, 424.12 },
					{ "Medellin", 2464000, 350.98 },
					{ "Cartagena", 972000, 345.34 }
				},
			},
			{
				"Brazil", {
					{ "Rio De Janiero", 13500000, 567.45 },
					{ "Sao Paulo", 11310000, 975.45 },
					{ "Salvador", 18234000, 855.99 }
				},
			},
			{
				"Chile", {
					{ "Valdivia", 260000, 569.12 },
					{ "Santiago", 7040000, 520.00 }
			},
		},
			{ "Argentina", {
				{ "Buenos Aires", 3010000, 723.77 }
			}
		},
	}
	};

	// Unformatted display so you can see how to access the vector elements
	std::cout << tours.title << std::endl;

	size_t row_size = 50;
	const char border_char = '#';
	row_size -= 1;
	std::cout << border_char << std::setw(row_size) << std::setfill(border_char) << border_char << std::endl;
	for (auto country : tours.countries) {

		// loop through the countries

		std::cout << border_char << std::setw(row_size / 2) << std::setfill(' ') << country.name << std::setw((row_size + 1) / 2) << std::setfill(' ') << border_char << std::endl;
		std::cout << border_char << std::setw(row_size) << std::setfill(border_char) << border_char << std::endl;

		for (auto city : country.cities) {
			// loop through the cities for each country
			std::cout << std::left << std::setfill(' ') << border_char << ' ';
			std::cout << std::setw((row_size / 3)-1) << city.name;
			std::cout << border_char << ' ' << std::setw((row_size / 3) - 2) << city.population;
			std::cout << border_char << ' ' << std::setw((row_size / 3) - 2) << city.cost << border_char <<std::endl;
			std::cout << border_char <<std::setw(row_size) << std::setfill(border_char) << border_char << std::endl;
			std::cout << std::resetiosflags(std::ios::left);
		}
	}

	std::cout << std::endl << std::endl;
	return 0;
}