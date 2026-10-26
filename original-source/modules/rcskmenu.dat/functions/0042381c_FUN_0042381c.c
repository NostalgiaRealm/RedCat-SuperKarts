/*
 * FUN_0042381c at 0042381c
 * undefined __register FUN_0042381c(int * param_1, int param_2, char param_3)
 * Address ranges: 0042381c-00423848
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042381c(int *param_1,int param_2,char param_3)

{
  FUN_0043ec20(param_1,param_2,param_3);
  if ((param_3 == '\x01') && (param_2 == param_1[0x4a])) {
    param_1[0x4a] = 0;
  }
  return;
}

