/*
 * FUN_00457630 at 00457630
 * undefined FUN_00457630(void)
 * Address ranges: 00457630-00457655
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_00457630(int param_1)

{
  int iVar1;
  
  iVar1 = 10;
  do {
    FUN_004575f0();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *(undefined1 *)(param_1 + 0xa0) = 1;
  return param_1;
}

