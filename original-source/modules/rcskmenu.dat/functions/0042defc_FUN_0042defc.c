/*
 * FUN_0042defc at 0042defc
 * undefined FUN_0042defc(void)
 * Address ranges: 0042defc-0042df32
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042defc(int *param_1,undefined4 param_2,undefined4 param_3)

{
  if ((*(byte *)(param_1 + 8) & 0x10) == 0) {
    *(char *)((int)param_1 + 0x213) = (char)param_2;
  }
  if ((char)param_2 != '\x01') {
    FUN_00403088(param_1,param_2,param_3);
  }
  if (param_1[0x93] != 0) {
    (**(code **)(*(int *)param_1[0x93] + 0x10))();
  }
  return;
}

