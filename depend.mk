MKGEN_SRCSBIN_42DB :=\
	build/src/test/42db/42db.o
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
	build/src/test/pf_test1/pf_test1.o
MKGEN_SRCSBIN_PF_TEST2 :=\
	build/src/test/pf_test2/pf_test2.o
MKGEN_SRCSBIN_PF_TEST3 :=\
	build/src/test/pf_test3/pf_test3.o
MKGEN_SRCSBIN_RM :=\
	build/src/ftrb/error.o\
	build/src/ftrb/rid.o\
	build/src/rm/rm_filehandle.o\
	build/src/rm/rm_filescan.o\
	build/src/rm/rm_manager.o\
	build/src/rm/rm_record.o
MKGEN_SRCSBIN_SANDBOX :=\
	build/src/ftrb/error.o\
	build/src/ftrb/rid.o\
	build/src/test/sandbox/test.o
build/src/ftrb/error.o: include/ftrb/error.hpp include/pf/pf.h include/redbase.h src/ftrb/error.cpp | build/src/ftrb/
build/src/ftrb/rid.o: include/ftrb/rid.hpp include/pf/pf.h include/redbase.h include/rm/rm.h src/ftrb/rid.cpp | build/src/ftrb/
build/src/pf/pf_buffermgr.o: include/linkedlist.h include/pf/pf.h include/pf/pf_buffermgr.h include/pf/pf_hashtable.h include/pf/pf_internal.h include/redbase.h include/statistics.h src/pf/pf_buffermgr.cc | build/src/pf/
build/src/pf/pf_error.o: include/pf/pf.h include/pf/pf_internal.h include/redbase.h src/pf/pf_error.cc | build/src/pf/
build/src/pf/pf_filehandle.o: include/pf/pf.h include/pf/pf_buffermgr.h include/pf/pf_hashtable.h include/pf/pf_internal.h include/redbase.h src/pf/pf_filehandle.cc | build/src/pf/
build/src/pf/pf_hashtable.o: include/pf/pf.h include/pf/pf_hashtable.h include/pf/pf_internal.h include/redbase.h src/pf/pf_hashtable.cc | build/src/pf/
build/src/pf/pf_manager.o: include/pf/pf.h include/pf/pf_buffermgr.h include/pf/pf_hashtable.h include/pf/pf_internal.h include/redbase.h src/pf/pf_manager.cc | build/src/pf/
build/src/pf/pf_pagehandle.o: include/pf/pf.h include/pf/pf_internal.h include/redbase.h src/pf/pf_pagehandle.cc | build/src/pf/
build/src/pf/pf_statistics.o: include/linkedlist.h include/pf/pf.h include/redbase.h include/statistics.h src/pf/pf_statistics.cc | build/src/pf/
build/src/pf/statistics.o: include/linkedlist.h include/statistics.h src/pf/statistics.cc | build/src/pf/
build/src/rm/rm_filehandle.o: include/ftrb/error.hpp include/ftrb/rid.hpp include/ftrb/waryoperation.hpp include/pf/pf.h include/redbase.h include/rm/rm.h include/rm/rm_filehandle.hpp include/rm/rm_record.hpp src/rm/rm_filehandle.cpp | build/src/rm/
build/src/rm/rm_filescan.o: include/ftrb/rid.hpp include/pf/pf.h include/redbase.h include/rm/rm.h include/rm/rm_filescan.hpp include/rm/rm_record.hpp src/rm/rm_filescan.cpp | build/src/rm/
build/src/rm/rm_manager.o: include/ftrb/error.hpp include/ftrb/rid.hpp include/ftrb/waryoperation.hpp include/pf/pf.h include/redbase.h include/rm/rm.h include/rm/rm_filehandle.hpp include/rm/rm_manager.hpp include/rm/rm_record.hpp src/rm/rm_manager.cpp | build/src/rm/
build/src/rm/rm_record.o: include/ftrb/rid.hpp include/pf/pf.h include/redbase.h include/rm/rm.h include/rm/rm_record.hpp src/rm/rm_record.cpp | build/src/rm/
build/src/test/42db/42db.o: include/ftrb/rid.hpp include/ftrb/waryoperation.hpp include/pf/pf.h include/redbase.h include/rm/rm.h include/rm/rm_filehandle.hpp include/rm/rm_manager.hpp include/rm/rm_record.hpp src/test/42db/42db.cpp | build/src/test/42db/
build/src/test/pf_test1/pf_test1.o: include/linkedlist.h include/pf/pf.h include/pf/pf_hashtable.h include/pf/pf_internal.h include/redbase.h include/statistics.h src/test/pf_test1/pf_test1.cc | build/src/test/pf_test1/
build/src/test/pf_test2/pf_test2.o: include/linkedlist.h include/pf/pf.h include/pf/pf_hashtable.h include/pf/pf_internal.h include/redbase.h include/statistics.h src/test/pf_test2/pf_test2.cc | build/src/test/pf_test2/
build/src/test/pf_test3/pf_test3.o: include/pf/pf.h include/pf/pf_hashtable.h include/pf/pf_internal.h include/redbase.h src/test/pf_test3/pf_test3.cc | build/src/test/pf_test3/
build/src/test/sandbox/test.o: include/ftrb/error.hpp include/pf/pf.h include/redbase.h include/rm/rm_filescan.hpp src/test/sandbox/test.cpp | build/src/test/sandbox/
