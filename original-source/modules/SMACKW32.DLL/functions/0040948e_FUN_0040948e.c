/*
 * FUN_0040948e at 0040948e
 * undefined __cdecl FUN_0040948e(undefined4 * param_1)
 * Address ranges: 0040948e-00409539
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Unable to track spacebase fully for stack */

void __cdecl FUN_0040948e(undefined4 *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  undefined4 extraout_ECX_02;
  uint extraout_EDX;
  undefined4 extraout_EDX_00;
  longlong lVar5;
  undefined4 uStackY_24;
  
  pcVar1 = (code *)*param_1;
  uVar2 = *(undefined4 *)param_1[5];
  if (DAT_004104e0 == 0) {
    iVar3 = -(DAT_0040f0c0 + 3U & 0xfffffffc);
    *(undefined4 *)(&stack0xffffffe0 + iVar3) = 0x4094ce;
    FUN_00409450(param_1,0);
    *(undefined4 *)(&stack0xffffffe0 + iVar3) = 0x4094d5;
    lVar5 = FUN_00408937(extraout_ECX,extraout_EDX);
    if ((int)lVar5 == 0) {
      *(undefined4 *)(&stack0xffffffe0 + iVar3) = uVar2;
      *(undefined4 *)((int)&uStackY_24 + iVar3) = 0x4094e2;
      CloseHandle(*(HANDLE *)(&stack0xffffffe0 + iVar3));
      return;
    }
  }
  iVar3 = (*(code *)PTR_FUN_0040ef44)();
  *(undefined4 *)(iVar3 + 0xde) = uVar2;
  iVar3 = 0;
  if (*(int *)(extraout_ECX_00 + 0xc) != 0) {
    iVar3 = ((uint)(&stack0x00000fe3 + -*(int *)(extraout_ECX_00 + 0xc)) >> 8 & 0xfffff0) << 8;
  }
  piVar4 = (int *)(*(code *)PTR_FUN_0040ef44)();
  *piVar4 = iVar3;
  uStackY_24 = 0x40951c;
  SetEvent(*(HANDLE *)(extraout_ECX_01 + 0x10));
  FUN_004084f5(extraout_ECX_02,extraout_EDX_00);
  (*(code *)PTR_FUN_0040ef84)();
  (*pcVar1)();
  FUN_004093fe();
  return;
}

