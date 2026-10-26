/*
 * FUN_004380b8 at 004380b8
 * undefined __register FUN_004380b8(int * param_1, short param_2)
 * Address ranges: 004380b8-004380c9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004380b8(int *param_1,short param_2)

{
  if (param_2 != (short)param_1[0x15]) {
    *(short *)(param_1 + 0x15) = param_2;
    (**(code **)(*param_1 + 0x38))(param_1,1);
  }
  return;
}

