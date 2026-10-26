/*
 * FUN_00404288 at 00404288
 * undefined __register FUN_00404288(BSTR param_1, LPCSTR param_2)
 * Address ranges: 00404288-00404295
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00404288(BSTR param_1,LPCSTR param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_2 != (LPCSTR)0x0) {
    iVar1 = *(int *)(param_2 + -4);
  }
  FUN_004041e0(param_1,param_2,iVar1);
  return;
}

