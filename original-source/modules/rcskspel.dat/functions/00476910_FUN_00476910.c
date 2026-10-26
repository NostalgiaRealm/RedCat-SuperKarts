/*
 * FUN_00476910 at 00476910
 * undefined FUN_00476910(void)
 * Address ranges: 00476910-00476947
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00476910(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 8);
  for (iVar2 = *(int *)(param_1 + 4); iVar2 != iVar1; iVar2 = iVar2 + 0x20) {
    FUN_00445a40();
  }
  FUN_004bc150(*(undefined4 *)(param_1 + 4));
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}

