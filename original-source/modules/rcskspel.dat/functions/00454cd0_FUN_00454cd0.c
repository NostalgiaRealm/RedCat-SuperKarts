/*
 * FUN_00454cd0 at 00454cd0
 * undefined FUN_00454cd0(void)
 * Address ranges: 00454cd0-00454d35
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00454cd0(int *param_1)

{
  int *piVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004cdde8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  if (param_1 != DAT_00543d54) {
    do {
      FUN_00454cd0(param_1[2]);
      piVar1 = (int *)*param_1;
      FUN_004bc150(param_1);
      param_1 = piVar1;
    } while (piVar1 != DAT_00543d54);
  }
  ExceptionList = local_c;
  return;
}

