/*
 * FUN_004113c8 at 004113c8
 * undefined FUN_004113c8(void)
 * Address ranges: 004113c8-004113ff
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004113c8(int *param_1)

{
  if (param_1[4] != 0) {
    (**(code **)(*param_1 + 0x74))();
    FUN_004043f8((VARIANTARG *)param_1[3],"\x0e\vTStringItem\b",param_1[4]);
    param_1[4] = 0;
    (**(code **)(*param_1 + 0x28))(param_1,0);
    (**(code **)(*param_1 + 0x70))();
  }
  return;
}

