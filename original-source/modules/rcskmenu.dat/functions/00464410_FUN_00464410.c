/*
 * FUN_00464410 at 00464410
 * undefined __register FUN_00464410(int * param_1)
 * Address ranges: 00464410-00464423
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00464410(int *param_1)

{
  if ((char)param_1[0x84] == '\0') {
    (**(code **)(*param_1 + 0xb8))(param_1,1);
  }
  return;
}

