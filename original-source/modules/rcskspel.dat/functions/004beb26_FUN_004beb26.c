/*
 * FUN_004beb26 at 004beb26
 * undefined FUN_004beb26(void)
 * Address ranges: 004beb26-004beb74
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004beb26(PVOID param_1,PEXCEPTION_RECORD param_2)

{
  void *pvVar1;
  
  pvVar1 = ExceptionList;
  RtlUnwind(param_1,(PVOID)0x4beb4e,param_2,(PVOID)0x0);
  param_2->ExceptionFlags = param_2->ExceptionFlags & 0xfffffffd;
  *(void **)pvVar1 = ExceptionList;
  ExceptionList = pvVar1;
  return;
}

