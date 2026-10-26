/*
 * FUN_00448bf4 at 00448bf4
 * undefined FUN_00448bf4(void)
 * Address ranges: 00448bf4-00448c1d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00448bf4(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (((param_2 != 0) && (param_2 != 0)) &&
     (*(char *)(*(int *)(param_2 + 0x14) + 0x10) == *(char *)(param_1 + 0x48))) {
    uVar1 = FUN_004029bc();
    *(undefined4 *)(param_2 + 0x20) = uVar1;
  }
  return;
}

