/*
 * FUN_00404360 at 00404360
 * undefined FUN_00404360(void)
 * Address ranges: 00404360-00404502
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00404360(float param_1,int param_2,float *param_3,float param_4)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float local_24;
  
  FUN_004afce0();
  FUN_004afce0(s_p_range____f__p_next_wp____d__p__004ddbc8,(double)param_1,param_2,(double)param_4);
  iVar1 = param_2 * 0x50 + 8 + DAT_00680ae0;
  fVar2 = *(float *)(param_2 * 0x50 + 8 + DAT_00680ae0) - *param_3;
  fVar3 = *(float *)(iVar1 + 4) - param_3[1];
  fVar4 = *(float *)(iVar1 + 8) - param_3[2];
  local_24 = 128.0 - param_4;
  FUN_004afce0(s_l_delta____f__004ddbf8,(double)local_24);
  if (local_24 < 0.0) {
    local_24 = local_24 * -1.0;
  }
  FUN_004afce0(s_l_delta____f__004ddc08,(double)local_24);
  if (8.0 < local_24) {
    local_24 = 8.0;
  }
  FUN_004afce0(s_l_delta____f__004ddc18,(double)local_24);
  fVar5 = (8.0 - local_24) * 0.125 * 0.5 + 1.0;
  FUN_004afce0(s_l_factor____f__004ddc28,(double)fVar5);
  fVar5 = fVar5 * param_1;
  FUN_004afce0(s_p_range____f__004ddc38,(double)fVar5);
  if (SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar4 * fVar4) < fVar5 * param_4) {
    FUN_004afce0();
    return 1;
  }
  FUN_004afce0();
  return 0;
}

