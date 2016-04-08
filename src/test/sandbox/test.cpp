
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
	PF_PageHandle pfph;
	int				err;
	PageNum pn;
	char *ptr;

	std::cout << "" << std::endl;
	err = mw.fh.AllocatePage(pfph);
	FTASSERT(err == 0, ftrb::errToStr(err));

	err = pfph.GetPageNum(pn);
	FTASSERT(err == 0, ftrb::errToStr(err));

	err = mw.fh.UnpinPage(pn);
	FTASSERT(err == 0, ftrb::errToStr(err));

	std::cout << "ALLOCED PAGE " << pn << std::endl;
	std::cout << "LOOP" << std::endl;

	for (int i = 0; i <= 6; i++)
	{
		std::cout << "index " << i << std::endl;
		err = mw.fh.GetThisPage(i, pfph);
		FTASSERT(err == 0, ftrb::errToStr(err));

		err = pfph.GetPageNum(pn);
		FTASSERT(err == 0, ftrb::errToStr(err));

		err = mw.fh.UnpinPage(pn);
		FTASSERT(err == 0, ftrb::errToStr(err));

		// err = mw.fh.UnpinPage(pn);
		// FTASSERT(err == 0, ftrb::errToStr(err));

		std::cout << "" << std::endl;
	}


	err = mw.fh.DisposePage(1);
	FTASSERT(err == 0, ftrb::errToStr(err));

	err = mw.fh.DisposePage(3);
	FTASSERT(err == 0, ftrb::errToStr(err));

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
