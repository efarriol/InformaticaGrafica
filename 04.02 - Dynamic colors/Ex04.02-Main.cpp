#include "Game.h"


int main(int argc, char ** argv) {
	Game game("Example 04.02.Dynamic Colors", 800, 800,true,60,true);

	try {
		game.run();
	}
	catch (std::exception e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
	}

	return 0;
}