/*
 * FUN_0044b810 at 0044b810
 * undefined FUN_0044b810(void)
 * Address ranges: 0044b810-0044b861
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044b810(int *param_1,int *param_2)

{
  FUN_004427e8(param_1,param_2);
  param_2[1] = param_2[1] | *(uint *)(&DAT_0047ba24 + (uint)*(byte *)(param_1 + 0x81) * 4);
  if (((*PTR_DAT_0047c7a0 != '\0') && ((char)param_1[0x4e] != '\0')) &&
     ((char)param_1[0x81] == '\x01')) {
    param_2[1] = param_2[1] & 0xff7fffff;
    param_2[2] = param_2[2] | 0x200;
  }
  param_2[9] = param_2[9] & 0xfffffffc;
  return;
}

