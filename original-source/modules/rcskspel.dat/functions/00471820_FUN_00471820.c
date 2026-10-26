/*
 * FUN_00471820 at 00471820
 * undefined FUN_00471820(void)
 * Address ranges: 00471820-00471840
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00471820(int *param_1)

{
  int iVar1;
  
  iVar1 = 0xc;
  do {
    if (*param_1 != 0) {
      FUN_004b08e0(*param_1);
    }
    param_1 = param_1 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

