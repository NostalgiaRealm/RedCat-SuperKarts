/*
 * FUN_004146c3 at 004146c3
 * uint __cdecl FUN_004146c3(int * param_1, int param_2, int param_3, uint param_4, int param_5)
 * Address ranges: 004146c3-004147d6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __cdecl FUN_004146c3(int *param_1,int param_2,int param_3,uint param_4,int param_5)

{
  byte bVar1;
  uint local_14;
  byte local_10 [4];
  byte local_c [4];
  int local_8;
  
  local_14 = 0;
  FUN_004015a6((byte *)s__s__d__004350cc);
  FUN_004015a6((byte *)s_y____d___xsize____d___pitch____d_004350d4);
  do {
    bVar1 = *(byte *)(param_2 + local_14 + param_3 * param_5);
    local_c[0] = bVar1;
    if ((bVar1 & 0xc0) == 0xc0) {
      local_8 = FUN_00414634(param_2,local_14,param_3,param_4 - local_14,param_4);
      local_10[0] = (byte)local_8 | 0xc0;
      FUN_0041fe82((char *)local_10,1,1,param_1);
      FUN_0041fe82((char *)local_c,1,1,param_1);
      local_14 = local_14 + local_8;
    }
    else {
      FUN_0041fe82((char *)local_c,1,1,param_1);
      local_14 = local_14 + 1;
    }
  } while (local_14 < param_4);
  FUN_004015a6((byte *)s__s__d__00435104);
  return local_14;
}

