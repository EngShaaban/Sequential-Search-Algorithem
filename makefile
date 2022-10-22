################################################################################
# _ Make file for  < SequentialSearch > project.
################################################################################

#_define compiler name.
 CC = gcc 
 
 #_define compile flage.
 COMPILEFLAG = -c
 
 target = file.exe 
 outs   = *.o *.exe 
 
prog_src := $(wildcard LIST_LLBased/*.c) 
priv_src := $(wildcard LIST_LLBased/*.c)

src  := $(wildcard  LIST_LLBased/*.c  *.c)
hdr  = $(wildcard *.h LIST_LLBased/ *.h )

print:
	@echo $(src)
	
 
 #_Search for any header files you need in current directory
 # or LIB/ sub-directories.
 vpath %.h DS_LIB  %.h LIST_LLBased %.c LIST_LLBased 
 
 all: $(target)
 file.exe: main.o  LIST_LLBased_prog.o  LIST_LLBased_private.o  SequentialSearch.o
	@$(CC) $^ -o $@  

main.o:                   main.c
	@$(CC) $(COMPILEFLAG) $< -o  $@ 
	
SequentialSearch.o:  SequentialSearch.c SequentialSearch.h
	@$(CC) $(COMPILEFLAG) $< -o  $@ 
	
LIST_LLBased_prog.o: LIST_LLBased/LIST_LLBased_prog.c  DS_ErrorStatus.h  STD_TYPES.h
	@$(CC) $(COMPILEFLAG) $< -o  $@ 
	
LIST_LLBased_private.o: $(priv_src)     DS_ErrorStatus.h  STD_TYPES.h 	
	@$(CC) $(COMPILEFLAG) $< -o  $@ 


#%.o:  %.c
#	  @$(CC) $(COMPILEFLAG) $< -o $@   
#	  
	  
clean: 
		@rm -rf $(outs)	  