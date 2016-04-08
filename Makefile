
UNAME			:= $(shell uname | cut -c1-6)

# ============================================================================ #
# Modules

# Git submodule to init
MODULES					:= libft_cpp

ifeq ($(UNAME),CYGWIN)
  MAKE_LIBFT_CPP		:= -C\ libft_cpp\ LD_CPP="x86_64-w64-mingw32-g++"
else
  MAKE_LIBFT_CPP		:= -C\ libft_cpp\ BASE_FLAGS="-m32"
endif


# ============================================================================ #
# Sources Directories

# include search path for .o dependencies
MKGEN_INCLUDESDIRS		:= include
# Obj files directory
MKGEN_OBJDIR			:= build
# Source files directories
MKGEN_SRCSDIRS_PF		:= src/pf
MKGEN_SRCSDIRS_PF_TEST1	:= src/test/pf_test1
MKGEN_SRCSDIRS_PF_TEST2	:= src/test/pf_test2
MKGEN_SRCSDIRS_PF_TEST3	:= src/test/pf_test3
MKGEN_SRCSDIRS_RM		:= src/rm src/ftrb
MKGEN_SRCSDIRS_SANDBOX	:= src/test/sandbox src/ftrb

# mkgen -> MKGEN_SRCSBIN_* variables
# mkgen -> $(MKGEN_OBJDIR)/**/*.o rules


# ============================================================================ #
# Default  flags
BASE_FLAGS		= -Wall -Wextra
HEAD_FLAGS		= $(addprefix -I,$(INCLUDEDIRS))
LD_FLAGS		=

MAKEFLAGS		+= -j

# ========================== #
# From stanford makefile:

# The STATS_OPTION can be set to -DPF_STATS or to nothing to turn on and
# off buffer manager statistics.  The student should not modify this
# flag at all!
BASE_FLAGS		+= -DPF_STATS
# ========================== #


# ============================================================================ #
# Build mode
#	NAME		link; target
#	CC_LD		link; ld
#	SRCSBIN		separate compilation; sources
#	INCLUDEDIRS	separate compilation; sources includes path
#	LIBSBIN		link; dependancies
#	LIBSMAKE	separate compilation; makefiles to call

BUILD_MODE = pf

ifeq ($(BUILD_MODE),pf)
  NAME			:= libpf.a
  CC_LD			= $(CC_AR)
  BASE_FLAGS	+= -O2

  SRCSBIN		= $(MKGEN_SRCSBIN_PF) #gen by mkgen
  INCLUDEDIRS	= $(MKGEN_INCLUDESDIRS)

else ifeq ($(BUILD_MODE),rm)
  NAME			:= librm.a
  CC_LD			= $(CC_AR)

  SRCSBIN		= $(MKGEN_SRCSBIN_RM) #gen by mkgen
  INCLUDEDIRS	= $(MKGEN_INCLUDESDIRS) libft_cpp/_objs/_public

  LIBSMAKE		= $(MAKE_LIBFT_CPP)
  LIBSBIN		= libft_cpp/libft.a

else ifeq ($(BUILD_MODE),pf_test1)
  NAME			:= pf_test1
  CC_LD			= $(CC_CPP)
  LD_FLAGS		+= -L. -lpf

  SRCSBIN		= $(MKGEN_SRCSBIN_PF_TEST1) #gen by mkgen
  INCLUDEDIRS	= $(MKGEN_INCLUDESDIRS)

  LIBSMAKE		= BUILD_MODE=pf
  LIBSBIN			= libpf.a

else ifeq ($(BUILD_MODE),pf_test2)
  NAME			:= pf_test2
  CC_LD			= $(CC_CPP)
  LD_FLAGS		+= -L. -lpf

  SRCSBIN		= $(MKGEN_SRCSBIN_PF_TEST2) #gen by mkgen
  INCLUDEDIRS	= $(MKGEN_INCLUDESDIRS)

  LIBSMAKE		= BUILD_MODE=pf
  LIBSBIN		= libpf.a

else ifeq ($(BUILD_MODE),pf_test3)
  NAME			:= pf_test3
  CC_LD			= $(CC_CPP)
  LD_FLAGS		+= -L. -lpf

  SRCSBIN		= $(MKGEN_SRCSBIN_PF_TEST3) #gen by mkgen
  INCLUDEDIRS	= $(MKGEN_INCLUDESDIRS)

  LIBSMAKE		= BUILD_MODE=pf
  LIBSBIN		= libpf.a

else ifeq ($(BUILD_MODE),sandbox)
  NAME			:= sandbox
  CC_LD			= $(CC_CPP)
  LD_FLAGS		+= -L. -lpf -lrm -Llibft_cpp -lft
  # LD_FLAGS		+= -lboost_unit_test_framework

  SRCSBIN		= $(MKGEN_SRCSBIN_SANDBOX) #gen by mkgen
  INCLUDEDIRS	= $(MKGEN_INCLUDESDIRS) libft_cpp/_objs/_public

  LIBSMAKE		= BUILD_MODE=pf BUILD_MODE=rm
  LIBSBIN		= libpf.a librm.a

endif


# ============================================================================ #
# Compilers
C_FLAGS			= $(HEAD_FLAGS) $(BASE_FLAGS)
CPP_FLAGS		= $(HEAD_FLAGS) $(BASE_FLAGS) -std=c++14

ifeq ($(UNAME),CYGWIN)
  CC_C			= x86_64-w64-mingw32-gcc
  CC_CPP		= x86_64-w64-mingw32-g++
  CC_AR			= x86_64-w64-mingw32-ar
  ifeq ($(CC_LD),$(CC_CPP))
    LD_FLAGS	+= -static
  endif
else
  CC_C			= clang
  CC_CPP		= clang++
  CC_AR			= ar
  BASE_FLAGS	+= -m32
endif

ifeq ($(CC_LD),$(CC_AR))
  LD_FLAGS_		= rcs $@ $(LD_FLAGS)
else
  LD_FLAGS_		= -o $@ $(LD_FLAGS) $(BASE_FLAGS)
endif


# ============================================================================ #
# Misc
MODULE_RULES	:= $(addsuffix /.git,$(MODULES))
PRINT_OK		= printf '  \033[32m$<\033[0m\n'
PRINT_LINK		= printf '\033[32m$@\033[0m\n'
PRINT_MAKE		= printf '\033[32mmake $@\033[0m\n'
DEPEND			:= depend.mk
SHELL			:= /bin/bash

# ============================================================================ #
# Rules

# Default rule (needed to be before any include)
all: _all_git

-include $(DEPEND)

_all_git: $(MODULE_RULES)
	$(MAKE) _all_libs

_all_libs: $(LIBSMAKE)
	$(MAKE) _all_separate_compilation

_all_separate_compilation: $(SRCSBIN)
	$(MAKE) _all_linkage

_all_linkage: $(NAME)

# Linking
$(NAME): $(LIBSBIN) $(SRCSBIN)
	$(CC_LD) $(LD_FLAGS_) $(SRCSBIN) && $(PRINT_LINK)

# Compiling
$(MKGEN_OBJDIR)/%.o: %.c
	$(CC_C) $(C_FLAGS) -c $< -o $@ && $(PRINT_OK)
$(MKGEN_OBJDIR)/%.o: %.cpp
	$(CC_CPP) $(CPP_FLAGS) -c $< -o $@ && $(PRINT_OK)
$(MKGEN_OBJDIR)/%.o: %.cc
	$(CC_CPP) $(CPP_FLAGS) -c $< -o $@ && $(PRINT_OK)

# Init submodules
$(MODULE_RULES):
	git submodule init $(@:.git=)
	git submodule update $(@:.git=)

# Compile libs
$(LIBSMAKE):
	$(MAKE) $@ && $(PRINT_MAKE)

# Create obj directories
$(MKGEN_OBJDIR)/%/:
	mkdir -p $@

# Clean obj files
clean:
	rm -f $(SRCSBIN)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Clean and make
re: fclean
	$(MAKE) all


# ============================================================================ #
# Special targets
.SILENT:
.PHONY: all clean fclean re _all_git _all_libs _all_separate_compilation _all_linkage $(LIBSMAKE)
