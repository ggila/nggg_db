#include <iostream>
#include <string>
#include <fstream>

int main(void)
{
	std::ifstream file("~/Desktop/42.data");
	std::string line;

	while (std::getline(file, line))
	{
		int rank, sex, campus, prom, finish, wallet, points, medals;
		float average, level;
		char *login;

		scanf("%d, %s, %d, %d, %d, %d, %d, %d, %d, %f, %f",
				rank,
				login,
				sex,
				campus,
				prom,
				finish,
				wallet,
				points,
				medals,
				average,
				level);
		std::cout << "rank: " << rank << "login: " << login << std::endl;
	}

	return 0;
}
