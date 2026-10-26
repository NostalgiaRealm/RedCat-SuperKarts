/*
 * FUN_004237a0 at 004237a0
 * undefined FUN_004237a0(void)
 * Address ranges: 004237a0-004237d8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004237a0(int *param_1,char param_2)

{
  uint uVar1;
  
  uVar1 = FUN_0042376c((int)param_1);
  if (param_2 != (char)uVar1) {
    if (param_2 == '\0') {
      param_1[0x10] = param_1[0x10] | 0x40;
    }
    else {
      param_1[0x10] = param_1[0x10] & 0xffffffbf;
    }
    (**(code **)(*param_1 + 0x74))();
  }
  return;
}

