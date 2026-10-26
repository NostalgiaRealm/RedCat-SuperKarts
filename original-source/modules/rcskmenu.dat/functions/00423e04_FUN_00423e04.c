/*
 * FUN_00423e04 at 00423e04
 * undefined FUN_00423e04(void)
 * Address ranges: 00423e04-00423eb7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00423e04(int *param_1,int *param_2)

{
  FUN_004427e8(param_1,param_2);
  FUN_00442714(param_1,(int)param_2,"EDIT");
  param_2[1] = param_2[1] | 0xc0U | *(uint *)(&DAT_0047b62c + (uint)*(byte *)(param_1 + 0x7d) * 4) |
               *(uint *)(&DAT_0047b644 + (uint)(*(char *)((int)param_1 + 0x1f5) != '\0') * 4) |
               *(uint *)(&DAT_0047b64c + (uint)*(byte *)((int)param_1 + 0x1f6) * 4) |
               *(uint *)(&DAT_0047b654 + (uint)*(byte *)((int)param_1 + 0x1fb) * 4) |
               *(uint *)(&DAT_0047b660 + (uint)*(byte *)((int)param_1 + 0x1f9) * 4) |
               *(uint *)(&DAT_0047b668 + (uint)*(byte *)((int)param_1 + 0x1fa) * 4);
  if (((*PTR_DAT_0047c7a0 != '\0') && ((char)param_1[0x4e] != '\0')) &&
     ((char)param_1[0x7d] == '\x01')) {
    param_2[1] = param_2[1] & 0xff7fffff;
    param_2[2] = param_2[2] | 0x200;
  }
  return;
}

