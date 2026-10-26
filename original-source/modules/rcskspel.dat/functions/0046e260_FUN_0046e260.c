/*
 * FUN_0046e260 at 0046e260
 * undefined FUN_0046e260(void)
 * Address ranges: 0046e260-0046e2ec
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0046e260(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_004d057c;
  local_10 = ExceptionList;
  iVar2 = 0;
  local_8 = 0;
  ExceptionList = &local_10;
  FUN_0046e330();
  FUN_00451450();
  iVar1 = FUN_004521b0();
  if (iVar1 != *(int *)(param_1 + 0x3c)) {
    if (0xc < iVar1) {
      iVar1 = 0xc;
    }
    for (; iVar3 = iVar1, iVar2 < iVar1; iVar2 = iVar2 + 1) {
      (**(code **)(**(int **)(param_1 + 0xc + iVar2 * 4) + 0x28))(&DAT_004d2db0);
    }
    for (; iVar3 < 0xc; iVar3 = iVar3 + 1) {
      (**(code **)(**(int **)(param_1 + 0xc + iVar3 * 4) + 0x28))(&DAT_004d2db4);
    }
    *(int *)(param_1 + 0x3c) = iVar1;
  }
  ExceptionList = local_10;
  return;
}

