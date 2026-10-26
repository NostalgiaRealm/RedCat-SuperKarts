/*
 * FUN_0042bb88 at 0042bb88
 * undefined __register FUN_0042bb88(int * param_1, int param_2)
 * Address ranges: 0042bb88-0042bbb2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042bb88(int *param_1,int param_2)

{
  if ((*(byte *)(param_1 + 0x11) & 8) != 0) {
    param_1[0x95] = param_2;
    *(byte *)(param_1 + 0x22) = *(byte *)(param_1 + 0x22) | 8;
    return;
  }
  FUN_0043f10c(param_1,param_2);
  return;
}

