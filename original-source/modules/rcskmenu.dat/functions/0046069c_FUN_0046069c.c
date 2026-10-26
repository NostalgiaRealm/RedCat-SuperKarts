/*
 * FUN_0046069c at 0046069c
 * undefined FUN_0046069c(void)
 * Address ranges: 0046069c-004606c2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046069c(int *param_1,int param_2,char param_3)

{
  FUN_0043ec20(param_1,param_2,param_3);
  if (((char)param_1[0x7e] != '\0') && (param_3 == '\x01')) {
    (**(code **)(*param_1 + 0x74))();
  }
  return;
}

