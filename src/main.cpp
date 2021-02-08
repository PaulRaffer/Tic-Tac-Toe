#include <iostream>
#include <array>
#include <cassert>


using Field = std::array<std::array<char, 3>, 3>;


char check_field(Field const & field)
{
	char winner = ' ';
	
	for (int x = 0; x < 3; x++) {
		char p = field[0][x];
		if (p != ' ') {
			bool w = true;
			for (int y = 1; y < 3; y++) {
				if (p != field[y][x]) {
					w = false;
				}
			}
			if (w) {
				winner = p;
			}
		}
	}
	
	for (int y = 0; y < 3; y++) {
		char p = field[y][0];
		if (p != ' ') {
			bool w = true;
			for (int x = 1; x < 3; x++) {
				if (p != field[y][x]) {
					w = false;
				}
			}
			if (w) {
				winner = p;
			}
		}
	}
	
	return winner;
}

void print_field(Field const & field)
{
	for (auto & line : field) {
		for (char c : line) {
			std::cout << c;
		}
		std::cout << '\n';
	}
}

int main()
{
	char player = 'x';
	Field field;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			field[y][x] = ' ';
		}
	}
	
	do {
		if (player == 'x') {
			player = 'o';
		}
		else if (player == 'o') {
			player = 'x';
		}
		/* player = (
			player == 'x' ? 'y' :
			player == 'y' ? 'x' :
			'e'); */
	
		int choicex;
		int choicey;
	
		std::cout << "Spieler " << player << " gib die Koordinaten ein.";
		std::cin >> choicex >> choicey;
		
		field[choicey][choicex] = player;
		print_field(field);
		check_field(field);
	}
	while (check_field(field) == ' ');
	
	std::cout << "Winner: " << check_field(field) << '\n';
}
