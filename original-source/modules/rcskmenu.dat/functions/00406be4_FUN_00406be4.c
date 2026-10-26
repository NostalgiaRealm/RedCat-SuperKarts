/*
 * FUN_00406be4 at 00406be4
 * undefined __register FUN_00406be4(LPCVOID param_1, SIZE_T param_2, UINT param_3)
 * Address ranges: 00406be4-00406bfe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00406be4(LPCVOID param_1,SIZE_T param_2,UINT param_3)

{
  HGLOBAL pvVar1;
  
  pvVar1 = GlobalHandle(param_1);
  GlobalUnlock(pvVar1);
  pvVar1 = GlobalReAlloc(pvVar1,param_2,param_3);
  GlobalLock(pvVar1);
  return;
}

