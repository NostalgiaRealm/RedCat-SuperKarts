/*
 * FUN_004512b0 at 004512b0
 * undefined FUN_004512b0(void)
 * Address ranges: 004512b0-0045136d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004512b0(int param_1,char *param_2)

{
  void *pvVar1;
  int *piVar2;
  int *unaff_ESI;
  char *pcStack_1c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cdbf6;
  pvStack_c = ExceptionList;
  pcStack_1c = s_CBonusController__AddBonus_004f13f4;
  ExceptionList = &pvStack_c;
  FUN_004afce0();
  pvVar1 = operator_new(0x20);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    pcStack_1c = (char *)0x4512f6;
    piVar2 = (int *)FUN_00453eb0();
  }
  local_4 = 0xffffffff;
  if (piVar2 == (int *)0x0) {
    pcStack_1c = "";
    param_2 = s_CBonusController__AddBonus__Unab_004f1410;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&param_2);
  }
  pcStack_1c = param_2;
  (**(code **)(*piVar2 + 4))();
  (**(code **)(*unaff_ESI + 8))(param_2);
  FUN_0044fb60(param_2);
  FUN_00459170(*(undefined4 *)(*(int *)(param_1 + 0x34) + 8),1,&pcStack_1c);
  ExceptionList = piVar2;
  return;
}

