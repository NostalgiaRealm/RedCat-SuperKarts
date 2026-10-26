/*
 * FUN_00468f10 at 00468f10
 * undefined FUN_00468f10(void)
 * Address ranges: 00468f10-00468ff1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00468f10(undefined4 param_1)

{
  char cVar1;
  int local_24;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cfd91;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004afce0();
  __ftol();
  FUN_00469690();
  FUN_0042eab0(param_1);
  FUN_0046bbd0();
  local_4 = 0;
  FUN_00469110();
  FUN_0046c1e0();
  FUN_004afce0();
  if (local_24 != 0) {
    cVar1 = *(char *)(local_24 + -1);
    if ((cVar1 != '\0') && (cVar1 != -1)) {
      *(char *)(local_24 + -1) = cVar1 + -1;
      ExceptionList = local_c;
      return;
    }
    FUN_004bc150();
  }
  ExceptionList = local_c;
  return;
}

