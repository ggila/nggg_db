#include <iostream>
#include <string>
#include <fstream>

#include "rm/rm_manager.hpp"
#include "rm/rm_record.hpp"
#include "rm/rm_filehandle.hpp"


struct record {
	int id;
	char login[9];
	int rank, sex, campus, prom, finish, wallet, points, medals;
	float average, level;
};

int main(void)
{
	PF_Manager pfm;
	rm::FileHandle rmfh;
	rm::Manager &rmm = rm::Manager::getInstance(pfm);
	int rc;

	rmm.createFile("42.db", sizeof(record));
	std::tie(rc, rmfh) = rmm.openFile("42.db");

	pfm.PrintBuffer();
	try {
		std::ifstream file;
		std::string line;
		int id = 0;

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

			r.id = id++;
			if (id < 10)
				rmfh.insertRec((const char*)&r);

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

	pfm.PrintBuffer();

	return 0;
}
