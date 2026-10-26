/*
 * FUN_00452d30 at 00452d30
 * undefined FUN_00452d30(void)
 * Address ranges: 00452d30-00452d95
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00452d30(int *param_1)

{
  int *piVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004cdca8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  if (param_1 != DAT_00543d2c) {
    do {
      FUN_00452d30(param_1[2]);
      piVar1 = (int *)*param_1;
      FUN_004bc150(param_1);
      param_1 = piVar1;
    } while (piVar1 != DAT_00543d2c);
  }
  ExceptionList = local_c;
  return;
}

