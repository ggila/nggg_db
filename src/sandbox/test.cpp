
#include <iostream>
#include "pf/pf.h"
#include "rm/rm_filescan.hpp"

#include "ft/assert.hpp"
#include "ft/utils.hpp"
#include "ft/padformat.hpp"

#include <cerrno>

#include "ftrb/error.hpp"

struct ManagerWrapper
{

public:
	PF_Manager		m;
	PF_FileHandle	fh;

	ManagerWrapper() {

		FTPAD();
		int err;

		err = this->m.ResizeBuffer(2);
 		FTASSERT(err == 0, ftrb::errToStr(err));

		err = this->m.CreateFile("tarace");
		FTASSERT(err == 0, ftrb::errToStr(err));

		err = this->m.OpenFile("tarace", fh);
		FTASSERT(err == 0, ftrb::errToStr(err));
	}

	~ManagerWrapper() {

		FTPAD();
		int err;

		err = this->m.CloseFile(fh);
		FTASSERT(err == 0, ftrb::errToStr(err));

		// err = this->m.DestroyFile("tarace");
		// FTASSERT(err == 0, ftrb::errToStr(err));
	}

};


void	work(void)
{
	ManagerWrapper	mw;
	// int				err;
	char *ptr;



	mw.m.PrintBuffer();
	return ;
}



int							main(void)
{

	FTPADB();
	work();
	FTPADE();
	return (0);
}
