MKGEN_SRCSBIN_PF :=\
	build/src/pf/pf_buffermgr.o\
	build/src/pf/pf_error.o\
	build/src/pf/pf_filehandle.o\
	build/src/pf/pf_hashtable.o\
	build/src/pf/pf_manager.o\
	build/src/pf/pf_pagehandle.o\
	build/src/pf/pf_statistics.o\
	build/src/pf/statistics.o
MKGEN_SRCSBIN_PF_TEST1 :=\
	build/src/pf_test1/pf_test1.o
MKGEN_SRCSBIN_PF_TEST2 :=\
	build/src/pf_test2/pf_test2.o
MKGEN_SRCSBIN_PF_TEST3 :=\
	build/src/pf_test3/pf_test3.o
MKGEN_SRCSBIN_RM :=\
	build/src/ftrb/error.o\
	build/src/rm/rid.o\
	build/src/rm/rm_manager.o
MKGEN_SRCSBIN_SANDBOX :=\
	build/src/ftrb/error.o\
	build/src/sandbox/test.o
build/src/ftrb/error.o: include/ftrb/error.hpp include/pf/pf.h include/redbase.h src/ftrb/error.cpp | build/src/ftrb/
build/src/pf/pf_buffermgr.o: include/linkedlist.h include/pf/pf.h include/pf/pf_buffermgr.h include/pf/pf_hashtable.h include/pf/pf_internal.h include/redbase.h include/statistics.h src/pf/pf_buffermgr.cc | build/src/pf/
build/src/pf/pf_error.o: include/pf/pf.h include/pf/pf_internal.h include/redbase.h src/pf/pf_error.cc | build/src/pf/
build/src/pf/pf_filehandle.o: include/pf/pf.h include/pf/pf_buffermgr.h include/pf/pf_hashtable.h include/pf/pf_internal.h include/redbase.h src/pf/pf_filehandle.cc | build/src/pf/
build/src/pf/pf_hashtable.o: include/pf/pf.h include/pf/pf_hashtable.h include/pf/pf_internal.h include/redbase.h src/pf/pf_hashtable.cc | build/src/pf/
build/src/pf/pf_manager.o: include/pf/pf.h include/pf/pf_buffermgr.h include/pf/pf_hashtable.h include/pf/pf_internal.h include/redbase.h src/pf/pf_manager.cc | build/src/pf/
build/src/pf/pf_pagehandle.o: include/pf/pf.h include/pf/pf_internal.h include/redbase.h src/pf/pf_pagehandle.cc | build/src/pf/
build/src/pf/pf_statistics.o: include/linkedlist.h include/pf/pf.h include/redbase.h include/statistics.h src/pf/pf_statistics.cc | build/src/pf/
build/src/pf/statistics.o: include/linkedlist.h include/statistics.h src/pf/statistics.cc | build/src/pf/
build/src/pf_test1/pf_test1.o: include/linkedlist.h include/pf/pf.h include/pf/pf_hashtable.h include/pf/pf_internal.h include/redbase.h include/statistics.h src/pf_test1/pf_test1.cc | build/src/pf_test1/
build/src/pf_test2/pf_test2.o: include/linkedlist.h include/pf/pf.h include/pf/pf_hashtable.h include/pf/pf_internal.h include/redbase.h include/statistics.h src/pf_test2/pf_test2.cc | build/src/pf_test2/
build/src/pf_test3/pf_test3.o: include/pf/pf.h include/pf/pf_hashtable.h include/pf/pf_internal.h include/redbase.h src/pf_test3/pf_test3.cc | build/src/pf_test3/
build/src/rm/rid.o: src/rm/rid.cpp | build/src/rm/
build/src/rm/rm_manager.o: include/pf/pf.h include/redbase.h include/rm/rm_manager.hpp src/rm/rm_manager.cpp | build/src/rm/
build/src/sandbox/test.o: include/ftrb/error.hpp include/pf/pf.h include/redbase.h src/sandbox/test.cpp | build/src/sandbox/
