/*
 * FUN_004237f4 at 004237f4
 * undefined __register FUN_004237f4(int * param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 004237f4-0042381a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004237f4(int *param_1,undefined4 param_2,undefined4 param_3)

{
  if ((char)param_2 != *(char *)((int)param_1 + 0x12f)) {
    *(char *)((int)param_1 + 0x12f) = (char)param_2;
    FUN_00403088(param_1,param_2,param_3);
    (**(code **)(*param_1 + 0x74))();
  }
  return;
}

