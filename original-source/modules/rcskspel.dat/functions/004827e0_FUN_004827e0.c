/*
 * FUN_004827e0 at 004827e0
 * undefined FUN_004827e0(void)
 * Address ranges: 004827e0-00482839
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004827e0(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xdc) != 0) {
    FUN_004bc150(*(int *)(param_1 + 0xdc));
  }
  iVar1 = *(int *)(param_1 + 0x9c);
  *(undefined4 *)(param_1 + 0xdc) = 0;
  if (iVar1 != 0) {
    FUN_004be99e(iVar1,0x5c,*(undefined4 *)(iVar1 + -4),FUN_00484a60);
    FUN_004bc150(iVar1 + -4);
    *(undefined4 *)(param_1 + 0x9c) = 0;
    return;
  }
  *(undefined4 *)(param_1 + 0x9c) = 0;
  return;
}

