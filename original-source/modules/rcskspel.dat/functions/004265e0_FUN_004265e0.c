/*
 * FUN_004265e0 at 004265e0
 * undefined FUN_004265e0(void)
 * Address ranges: 004265e0-0042666e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004265e0(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                 float param_5)

{
  float *pfVar1;
  float local_24;
  undefined4 local_20;
  float local_1c;
  undefined1 local_18 [4];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  pfVar1 = (float *)FUN_00415b90(local_18,param_1,param_4);
  local_14 = 0;
  local_10 = 0;
  local_24 = param_5 + *pfVar1;
  local_20 = 0x3f800000;
  local_1c = pfVar1[2] + 0.0;
  FUN_004a19e0(&local_c,&local_24,param_3);
  *param_2 = local_c;
  param_2[1] = local_8;
  param_2[2] = local_4;
  return;
}

