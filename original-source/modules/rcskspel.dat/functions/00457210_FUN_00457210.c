/*
 * FUN_00457210 at 00457210
 * undefined FUN_00457210(void)
 * Address ranges: 00457210-00457275
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00457210(int *param_1)

{
  int *piVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004cdeb8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  if (param_1 != DAT_00544a84) {
    do {
      FUN_00457210(param_1[2]);
      piVar1 = (int *)*param_1;
      FUN_004bc150(param_1);
      param_1 = piVar1;
    } while (piVar1 != DAT_00544a84);
  }
  ExceptionList = local_c;
  return;
}

