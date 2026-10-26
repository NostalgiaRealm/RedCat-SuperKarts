/*
 * FUN_0042ad58 at 0042ad58
 * undefined FUN_0042ad58(void)
 * Address ranges: 0042ad58-0042ada5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042ad58(int *param_1,int *param_2)

{
  FUN_0042a58c(param_1,param_2);
  param_2[1] = param_2[1] | *(uint *)(&DAT_0047b73c + (uint)*(byte *)(param_1 + 0x82) * 4);
  if (((*PTR_DAT_0047c7a0 != '\0') && ((char)param_1[0x4e] != '\0')) &&
     ((char)param_1[0x82] == '\x01')) {
    param_2[1] = param_2[1] & 0xff7fffff;
    param_2[2] = param_2[2] | 0x200;
  }
  return;
}

