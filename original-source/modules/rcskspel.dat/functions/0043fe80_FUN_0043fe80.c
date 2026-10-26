/*
 * FUN_0043fe80 at 0043fe80
 * undefined FUN_0043fe80(void)
 * Address ranges: 0043fe80-0043fef9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0043fe80(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 * 0xd0 + 0x14 + DAT_0067ee20);
  if (iVar1 == 0) {
    iVar1 = FUN_0043c5c0(param_1,0x40800000,0);
    if (iVar1 != 0) {
      FUN_0043b790(param_1,0);
    }
  }
  else {
    if (iVar1 == 1) {
      FUN_0043c870(param_1,0x400,0x40000000);
      return 1;
    }
    if (iVar1 == 3) {
      FUN_0043cbf0(param_1,0x400);
      return 1;
    }
  }
  return 1;
}

