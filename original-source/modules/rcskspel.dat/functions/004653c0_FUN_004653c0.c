/*
 * FUN_004653c0 at 004653c0
 * undefined FUN_004653c0(void)
 * Address ranges: 004653c0-0046546a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004653c0(int param_1)

{
  char cVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_004cf76a;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  cVar1 = FUN_00415be0(DAT_0053be28);
  if (cVar1 == '\0') {
    if (*(int *)(param_1 + 0x10) != 0) {
      if (*(int *)(param_1 + 0x14) != 2) goto LAB_00465423;
      FUN_00465820();
    }
    *(undefined4 *)(param_1 + 0x14) = 1;
    FUN_004654b0();
  }
  else if (*(int *)(param_1 + 0x10) != 0) {
    if (*(int *)(param_1 + 0x14) == 1) {
      FUN_00465820();
      ExceptionList = local_10;
      return;
    }
LAB_00465423:
    FUN_00465570();
    ExceptionList = local_10;
    return;
  }
  ExceptionList = local_10;
  return;
}

