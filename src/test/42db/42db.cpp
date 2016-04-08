#include <iostream>
#include <string>
#include <fstream>

int main(void)
{
	std::ifstream file;

	try {
		file.open("42.data");

		std::string line;
		while (std::getline(file, line))
		{
			std::cout << "<";
			int nb_arg;
			int rank, sex, campus, prom, finish, wallet, points, medals;
			float average, level;
			char login[9];

			nb_arg = sscanf(line.data(), "%d, %s %d, %d, %d, %d, %d, %d, %d, %f, %f",
					&rank,
					login,
					&sex,
					&campus,
					&prom,
					&finish,
					&wallet,
					&points,
					&medals,
					&average,
					&level);
			if (nb_arg == 11) {
				login[8] = '\0';
				std::cout << "rank: " << rank << "login: " << login;
			}
			std::cout << ">" << std::endl;
		}
	}

//	catch (const std::exception& e) {
//		std::cout << e.what() << std::endl;
//	}

	catch (...) {
		std::cout << "fuckya" << std::endl;
	}
	return 0;
}
