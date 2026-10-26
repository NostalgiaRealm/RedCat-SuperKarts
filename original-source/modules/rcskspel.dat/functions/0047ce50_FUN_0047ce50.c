/*
 * FUN_0047ce50 at 0047ce50
 * undefined FUN_0047ce50(void)
 * Address ranges: 0047ce50-0047cedf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0047ce50(int *param_1)

{
  int *piVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004d0fd8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  if (param_1 != DAT_00544fb0) {
    do {
      FUN_0047ce50(param_1[2]);
      piVar1 = (int *)*param_1;
      FUN_004bc150(param_1[8]);
      param_1[8] = 0;
      param_1[9] = 0;
      param_1[10] = 0;
      FUN_0040b4f0(1);
      FUN_004bc150(param_1);
      param_1 = piVar1;
    } while (piVar1 != DAT_00544fb0);
  }
  ExceptionList = local_c;
  return;
}

