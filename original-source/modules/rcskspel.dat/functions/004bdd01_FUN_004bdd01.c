/*
 * FUN_004bdd01 at 004bdd01
 * undefined FUN_004bdd01(void)
 * Address ranges: 004bdd01-004bdd27
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_004bdd01(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x50) != 0) {
    iVar1 = FUN_004bf2c5(*(int *)(param_1 + 0x50));
    if (iVar1 == 0) {
      FUN_004bdd28(0,2);
      return param_1;
    }
  }
  return 0;
}

