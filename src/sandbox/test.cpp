
#include <iostream>
#include "pf.h"
#include "ft/assert.hpp"
#include "ft/utils.hpp"

#include <cerrno>

#include "ftrb/error.hpp"

int							main(void)
{
	PF_FileHandle	fh;
	PF_Manager		m;
	PF_PageHandle	ph;
	int				err;

	errno = 0;
	err = m.CreateFile("tarace");
	FTASSERT(err == 0, ftrb::errToStr(err));


	FTASSERT(true);



	return (0);
}
