/*
 * FUN_00440f18 at 00440f18
 * undefined __register FUN_00440f18(int * param_1, int param_2)
 * Address ranges: 00440f18-00440f2f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00440f18(int *param_1,int param_2)

{
  if ((PTR_DAT_0047c9d8[9] != '\0') && (*(int *)(param_2 + 4) == 0)) {
    (**(code **)(*param_1 + 0x74))();
  }
  return;
}

