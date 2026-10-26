/*
 * __cfltcvt at 004c1bfa
 * errno_t __cdecl __cfltcvt(double * arg, char * buffer, size_t sizeInBytes, int format, int precision, int caps)
 * Address ranges: 004c1bfa-004c1c4a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  __cfltcvt  Library: Visual Studio 2003 Release
 */

/* Library Function - Single Match
    __cfltcvt
   
   Library: Visual Studio 2003 Release */

errno_t __cdecl
__cfltcvt(double *arg,char *buffer,size_t sizeInBytes,int format,int precision,int caps)

{
  errno_t eVar1;
  
  if ((sizeInBytes == 0x65) || (sizeInBytes == 0x45)) {
    eVar1 = FUN_004c1933(arg,buffer,format,precision);
  }
  else {
    if (sizeInBytes == 0x66) {
      eVar1 = FUN_004c1a37(arg,buffer,format);
      return eVar1;
    }
    eVar1 = FUN_004c1b15(arg,buffer,format,precision);
  }
  return eVar1;
}

