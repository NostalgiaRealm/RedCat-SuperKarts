/*
 * FUN_00412d30 at 00412d30
 * undefined FUN_00412d30(void)
 * Address ranges: 00412d30-00412df5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00412d30(int param_1,int param_2)

{
  int iVar1;
  undefined1 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004cce98;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_004be6c9();
  iVar1 = FUN_00493a20(((DAT_0053b9cc + param_2 * -3) - DAT_0053b9d0) + -5);
  if (param_1 < 2) {
    if (*(int *)(DAT_00680b28 + 0xe4 + iVar1 * 0x984) < 2) {
      ExceptionList = local_c;
      return;
    }
    uVar2 = 0;
  }
  else {
    if (*(int *)(DAT_00680b28 + 0xe8 + iVar1 * 0x984) < 2) {
      ExceptionList = local_c;
      return;
    }
    uVar2 = 1;
  }
  FUN_00493430(iVar1,0,uVar2);
  ExceptionList = local_c;
  return;
}

