/*
 * FUN_0041ffce at 0041ffce
 * undefined __stdcall FUN_0041ffce(PVOID param_1, PEXCEPTION_RECORD param_2)
 * Address ranges: 0041ffce-0042001c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041ffce(PVOID param_1,PEXCEPTION_RECORD param_2)

{
  void *pvVar1;
  
  pvVar1 = ExceptionList;
  RtlUnwind(param_1,(PVOID)0x41fff6,param_2,(PVOID)0x0);
  param_2->ExceptionFlags = param_2->ExceptionFlags & 0xfffffffd;
  *(void **)pvVar1 = ExceptionList;
  ExceptionList = pvVar1;
  return;
}

