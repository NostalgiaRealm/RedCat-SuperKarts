/*
 * FUN_0043df60 at 0043df60
 * undefined FUN_0043df60(void)
 * Address ranges: 0043df60-0043df8a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0043df60(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_00497bd0(param_1,DAT_0053be28);
  if (iVar1 != 0) {
    *param_2 = DAT_0053be28;
    return 1;
  }
  return 0;
}

