#include <iostream>
#include <string>
#include <fstream>

#include "rm/rm_manager.hpp"
#include "rm/rm_record.hpp"


struct record {
	int id;
	char login[9];
	int rank, sex, campus, prom, finish, wallet, points, medals;
	float average, level;
};

int main(void)
{
	PF_Manager pfm;
	rm::Manager &rmm = rm::Manager::getInstance(pfm);

	rmm.createFile("42.db", sizeof(record));
	pfm.PrintBuffer();
	try {
		std::ifstream file;
		std::string line;

		file.open("42.data");
		while (std::getline(file, line))
		{
			int nb_arg;
			record r;

			nb_arg = sscanf(line.c_str(), "%d, %[a-z-], %d, %d, %d, %d, %d, %d, %d, %f, %f",
					&r.rank,
					r.login,
					&r.sex,
					&r.campus,
					&r.prom,
					&r.finish,
					&r.wallet,
					&r.points,
					&r.medals,
					&r.average,
					&r.level);

//			if (nb_arg == 11) {
//				rmr();
//			}
		}
	}

	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	catch (...) {
		std::cout << "fuckya" << std::endl;
	}
	return 0;
}
