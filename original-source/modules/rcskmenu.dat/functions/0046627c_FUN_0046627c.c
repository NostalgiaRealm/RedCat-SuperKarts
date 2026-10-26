/*
 * FUN_0046627c at 0046627c
 * undefined __register FUN_0046627c(int * param_1, int param_2, char param_3)
 * Address ranges: 0046627c-004662a9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046627c(int *param_1,int param_2,char param_3)

{
  FUN_0043ec20(param_1,param_2,param_3);
  if ((param_3 == '\x01') && (param_2 == param_1[0x7f])) {
    FUN_004662ac((int)param_1,0);
  }
  return;
}

