/*
 * FUN_00434290 at 00434290
 * undefined __register FUN_00434290(int * param_1, undefined4 param_2, undefined4 param_3)
 * Address ranges: 00434290-004342a9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00434290(int *param_1,undefined4 param_2,undefined4 param_3)

{
  if ((char)param_2 != (char)param_1[0xd]) {
    *(char *)(param_1 + 0xd) = (char)param_2;
    FUN_00403088(param_1,param_2,param_3);
  }
  return;
}

