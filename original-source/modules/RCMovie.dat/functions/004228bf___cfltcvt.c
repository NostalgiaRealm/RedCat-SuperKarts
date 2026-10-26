/*
 * __cfltcvt at 004228bf
 * errno_t __cdecl __cfltcvt(double * arg, char * buffer, size_t sizeInBytes, int format, int precision, int caps)
 * Address ranges: 004228bf-0042290f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: Library Function - Single Match  __cfltcvt  Library: Visual Studio 2003 Release
 */

/* Library Function - Single Match
    __cfltcvt
   
   Library: Visual Studio 2003 Release */

errno_t __cdecl
__cfltcvt(double *arg,char *buffer,size_t sizeInBytes,int format,int precision,int caps)

{
  char *pcVar1;
  undefined1 *puVar2;
  
  if ((sizeInBytes == 0x65) || (sizeInBytes == 0x45)) {
    puVar2 = FUN_004225f8(arg,buffer,format,precision);
  }
  else {
    if (sizeInBytes == 0x66) {
      pcVar1 = FUN_004226fc(arg,buffer,format);
      return (errno_t)pcVar1;
    }
    puVar2 = (undefined1 *)FUN_004227da(arg,buffer,format,precision);
  }
  return (errno_t)puVar2;
}

