/*
 * FUN_0046e1a4 at 0046e1a4
 * undefined FUN_0046e1a4(void)
 * Address ranges: 0046e1a4-0046e1e0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046e1a4(int *param_1,int param_2,char param_3)

{
  FUN_0043ec20(param_1,param_2,param_3);
  if ((param_3 == '\x01') && (param_2 == param_1[0xbd])) {
    if (*(char *)((int)param_1 + 0x2c9) != '\0') {
      FUN_0046e1e4((int)param_1);
    }
    param_1[0xbd] = 0;
  }
  return;
}

