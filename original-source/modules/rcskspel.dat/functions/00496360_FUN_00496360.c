/*
 * FUN_00496360 at 00496360
 * undefined FUN_00496360(void)
 * Address ranges: 00496360-004963be
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00496360(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = FUN_004967c0(param_2,2);
    return *(undefined4 *)(iVar1 + 0x10);
  }
  if (param_1 != 1) {
    if (param_1 != 2) {
      return 0xffffff;
    }
    iVar1 = FUN_004969b0(param_2,2);
    return *(undefined4 *)(iVar1 + 0x10);
  }
  iVar1 = FUN_00496870(param_2,2);
  return *(undefined4 *)(iVar1 + 0x10);
}

