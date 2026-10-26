/*
 * FUN_0044b53c at 0044b53c
 * undefined FUN_0044b53c(void)
 * Address ranges: 0044b53c-0044b5a1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0044b53c(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(byte *)(param_1 + 0x20) & 0x10) != 0) {
    iVar1 = FUN_0041acf4(*(int *)(param_1 + 0x128));
    if (iVar1 < 1) {
      return 1;
    }
    iVar1 = FUN_0041ad0c(*(int *)(param_1 + 0x128));
    if (iVar1 < 1) {
      return 1;
    }
  }
  if ((*(char *)(param_1 + 0x4b) == '\0') || ((byte)(*(char *)(param_1 + 0x4b) - 3U) < 2)) {
    uVar2 = FUN_0041acf4(*(int *)(param_1 + 0x128));
    *param_2 = uVar2;
  }
  if (*(byte *)(param_1 + 0x4b) < 3) {
    uVar2 = FUN_0041ad0c(*(int *)(param_1 + 0x128));
    *param_3 = uVar2;
  }
  return 1;
}

