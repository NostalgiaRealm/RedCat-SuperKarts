/*
 * FUN_00483ef0 at 00483ef0
 * undefined FUN_00483ef0(void)
 * Address ranges: 00483ef0-00483fbd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00483ef0(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004d1416;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00483960(param_2);
  iVar1 = *(int *)(param_2 + 0x9c);
  if (iVar1 != 0) {
    FUN_004be99e(iVar1,0x5c,*(undefined4 *)(iVar1 + -4),FUN_00484a60);
    FUN_004bc150(iVar1 + -4);
  }
  *(undefined4 *)(param_2 + 0x9c) = 0;
  iVar1 = *(int *)(param_1 + 4);
  piVar2 = operator_new(iVar1 * 0x5c + 4);
  uStack_4 = 0;
  if (piVar2 != (int *)0x0) {
    *piVar2 = iVar1;
    FUN_004be91c(piVar2 + 1,0x5c,iVar1,FUN_00484a40,FUN_00484a60);
    *(int **)(param_2 + 0x9c) = piVar2 + 1;
    ExceptionList = pvStack_c;
    return;
  }
  *(undefined4 *)(param_2 + 0x9c) = 0;
  ExceptionList = pvStack_c;
  return;
}

