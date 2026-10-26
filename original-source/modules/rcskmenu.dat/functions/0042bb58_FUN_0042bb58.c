/*
 * FUN_0042bb58 at 0042bb58
 * undefined __register FUN_0042bb58(int * param_1, int param_2)
 * Address ranges: 0042bb58-0042bb82
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042bb58(int *param_1,int param_2)

{
  if ((*(byte *)(param_1 + 0x11) & 8) != 0) {
    param_1[0x94] = param_2;
    *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) | 4;
    return;
  }
  FUN_0043f0c8(param_1,param_2);
  return;
}

