MKGEN_SRCSBIN_PF :=\
	build/src/src_pf/pf_buffermgr.o\
	build/src/src_pf/pf_error.o\
	build/src/src_pf/pf_filehandle.o\
	build/src/src_pf/pf_hashtable.o\
	build/src/src_pf/pf_manager.o\
	build/src/src_pf/pf_pagehandle.o\
	build/src/src_pf/pf_statistics.o\
	build/src/src_pf/statistics.o
MKGEN_SRCSBIN_PF_TEST1 :=\
	build/src/src_pf_test1/pf_test1.o
MKGEN_SRCSBIN_PF_TEST2 :=\
	build/src/src_pf_test2/pf_test2.o
MKGEN_SRCSBIN_PF_TEST3 :=\
	build/src/src_pf_test3/pf_test3.o
MKGEN_SRCSBIN_RM :=\
	build/src/src_rm/temp.o
build/src/src_pf/pf_buffermgr.o: include/linkedlist.h include/pf.h include/pf_buffermgr.h include/pf_hashtable.h include/pf_internal.h include/redbase.h include/statistics.h src/src_pf/pf_buffermgr.cc | build/src/src_pf/
build/src/src_pf/pf_error.o: include/pf.h include/pf_internal.h include/redbase.h src/src_pf/pf_error.cc | build/src/src_pf/
build/src/src_pf/pf_filehandle.o: include/pf.h include/pf_buffermgr.h include/pf_hashtable.h include/pf_internal.h include/redbase.h src/src_pf/pf_filehandle.cc | build/src/src_pf/
build/src/src_pf/pf_hashtable.o: include/pf.h include/pf_hashtable.h include/pf_internal.h include/redbase.h src/src_pf/pf_hashtable.cc | build/src/src_pf/
build/src/src_pf/pf_manager.o: include/pf.h include/pf_buffermgr.h include/pf_hashtable.h include/pf_internal.h include/redbase.h src/src_pf/pf_manager.cc | build/src/src_pf/
build/src/src_pf/pf_pagehandle.o: include/pf.h include/pf_internal.h include/redbase.h src/src_pf/pf_pagehandle.cc | build/src/src_pf/
build/src/src_pf/pf_statistics.o: include/linkedlist.h include/pf.h include/redbase.h include/statistics.h src/src_pf/pf_statistics.cc | build/src/src_pf/
build/src/src_pf/statistics.o: include/linkedlist.h include/statistics.h src/src_pf/statistics.cc | build/src/src_pf/
build/src/src_pf_test1/pf_test1.o: include/linkedlist.h include/pf.h include/pf_hashtable.h include/pf_internal.h include/redbase.h include/statistics.h src/src_pf_test1/pf_test1.cc | build/src/src_pf_test1/
build/src/src_pf_test2/pf_test2.o: include/linkedlist.h include/pf.h include/pf_hashtable.h include/pf_internal.h include/redbase.h include/statistics.h src/src_pf_test2/pf_test2.cc | build/src/src_pf_test2/
build/src/src_pf_test3/pf_test3.o: include/pf.h include/pf_hashtable.h include/pf_internal.h include/redbase.h src/src_pf_test3/pf_test3.cc | build/src/src_pf_test3/
build/src/src_rm/temp.o: src/src_rm/temp.cpp | build/src/src_rm/
