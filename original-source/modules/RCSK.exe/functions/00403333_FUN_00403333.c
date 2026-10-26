/*
 * FUN_00403333 at 00403333
 * undefined4 __cdecl FUN_00403333(undefined4 param_1)
 * Address ranges: 00403333-0040334d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00403333(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_00408c60 != (code *)0x0) {
    iVar1 = (*DAT_00408c60)(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}

