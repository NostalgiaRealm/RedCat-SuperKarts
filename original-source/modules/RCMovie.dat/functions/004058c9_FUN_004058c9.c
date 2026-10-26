/*
 * FUN_004058c9 at 004058c9
 * int __cdecl FUN_004058c9(byte * param_1, uint * param_2)
 * Address ranges: 004058c9-00405a3b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_004058c9(byte *param_1,uint *param_2)

{
  uint *puVar1;
  int local_dc;
  uint local_d8 [50];
  ushort local_10 [2];
  int local_c;
  uint local_8;
  
  local_dc = 0;
  local_c = 0;
  local_10[0] = DAT_0042ed30;
  local_8 = DAT_0042ed34;
  if (param_2 == (uint *)0x0) {
    param_2 = &local_8;
  }
  for (; *param_1 != 0; param_1 = param_1 + 1) {
    local_10[0] = (ushort)*param_1;
    puVar1 = FUN_0041fb70(param_2,(char *)local_10);
    if (puVar1 == (uint *)0x0) {
      *(byte *)((int)local_d8 + local_c) = *param_1;
      local_c = local_c + 1;
      if (0xc6 < local_c) {
        FUN_0040187a((byte *)s__get_ini_arguments_online___s__d_0042ed9c);
      }
    }
    else {
      *(undefined1 *)((int)local_d8 + local_c) = 0;
      FUN_0041f7a0((uint *)(&DAT_004384b0 + local_dc * 200),local_d8);
      local_dc = local_dc + 1;
      if (100 < local_dc) {
        FUN_0040187a((byte *)s__get_ini_arguments_online___s__d_0042ed44);
      }
      local_c = 0;
    }
  }
  *(undefined1 *)((int)local_d8 + local_c) = 0;
  FUN_0041f7a0((uint *)(&DAT_004384b0 + local_dc * 200),local_d8);
  DAT_0043d400 = local_dc + 1;
  return local_dc + 1;
}

