/*
 * FUN_0045d470 at 0045d470
 * undefined FUN_0045d470(void)
 * Address ranges: 0045d470-0045d55e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0045d470(undefined4 param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  undefined1 local_1c [4];
  int local_18;
  int local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004ce7d6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00464150(local_1c,param_1,param_2);
  local_4 = 0;
  if (local_14 != 0) {
    FUN_0045d560(local_1c,param_3,param_3 + 4,param_3 + 8);
    if (local_18 != 0) {
      cVar1 = *(char *)(local_18 + -1);
      if ((cVar1 != '\0') && (cVar1 != -1)) {
        *(char *)(local_18 + -1) = cVar1 + -1;
        ExceptionList = local_c;
        return 1;
      }
      FUN_004bc150(local_18 + -1);
    }
    ExceptionList = local_c;
    return 1;
  }
  if (local_18 != 0) {
    cVar1 = *(char *)(local_18 + -1);
    if ((cVar1 != '\0') && (cVar1 != -1)) {
      *(char *)(local_18 + -1) = cVar1 + -1;
      ExceptionList = local_c;
      return 0;
    }
    FUN_004bc150(local_18 + -1);
  }
  ExceptionList = local_c;
  return 0;
}

