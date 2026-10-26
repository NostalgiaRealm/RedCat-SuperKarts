/*
 * FUN_0040b720 at 0040b720
 * undefined FUN_0040b720(void)
 * Address ranges: 0040b720-0040b778
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040b720(uint param_1)

{
  uint uVar1;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_004ccc50;
  pvStack_10 = ExceptionList;
  uVar1 = param_1 | 0x1f;
  if (0xfffffffd < (param_1 | 0x1f)) {
    uVar1 = param_1;
  }
  uVar1 = uVar1 + 2;
  local_8 = 0;
  if ((int)uVar1 < 0) {
    uVar1 = 0;
  }
  ExceptionList = &pvStack_10;
  operator_new(uVar1);
  FUN_0040b7a0();
  return;
}

