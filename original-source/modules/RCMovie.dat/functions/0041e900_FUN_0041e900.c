/*
 * FUN_0041e900 at 0041e900
 * undefined4 __fastcall FUN_0041e900(int * param_1)
 * Address ranges: 0041e900-0041e921
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_0041e900(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_0041e8f0(param_1);
  if (0 < iVar1) {
    iVar1 = FUN_0041e8e0((int)param_1);
    if (0 < iVar1) {
      return 0;
    }
  }
  return 1;
}

