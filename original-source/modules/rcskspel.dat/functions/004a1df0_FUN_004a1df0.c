/*
 * FUN_004a1df0 at 004a1df0
 * undefined FUN_004a1df0(void)
 * Address ranges: 004a1df0-004a20d0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004a1df0(undefined4 *param_1,float *param_2,float *param_3,float *param_4)

{
  float *pfVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  float *pfVar5;
  float10 fVar6;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  float fStack_e8;
  float fStack_e4;
  float fStack_e0;
  float fStack_dc;
  float fStack_d8;
  float fStack_d4;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  float afStack_c0 [4];
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  undefined4 local_80 [12];
  float local_50;
  float local_4c;
  float local_48;
  undefined1 auStack_40 [64];
  
  puVar2 = &DAT_006a5c90;
  puVar4 = local_80;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  local_50 = -*param_2;
  local_4c = -param_2[1];
  local_48 = -param_2[2];
  if (((*param_3 == *param_2) && (param_3[1] == param_2[1])) && (param_3[2] == param_2[2])) {
    FUN_004afee0(s__s__d____Divide_by_zero__at__fro_004fc990,
                 s_D__work_libs_DX3D_D3dutils_cpp_004fc9b4,0x7d);
  }
  local_100 = *param_3 - *param_2;
  local_fc = param_3[1] - param_2[1];
  local_f8 = param_3[2] - param_2[2];
  local_f4 = local_100;
  local_f0 = local_fc;
  local_ec = local_f8;
  fVar6 = (float10)FUN_00405f40(&local_f4);
  fStack_dc = (float)SQRT(fVar6);
  pfVar1 = (float *)FUN_004175f0(&local_100,&local_f4,fStack_dc);
  fStack_e8 = *pfVar1;
  fStack_e4 = pfVar1[1];
  fStack_e0 = pfVar1[2];
  local_100 = fStack_e0 * param_4[1] - fStack_e4 * param_4[2];
  local_fc = fStack_e8 * param_4[2] - fStack_e0 * *param_4;
  local_f8 = fStack_e4 * *param_4 - fStack_e8 * param_4[1];
  local_f4 = local_f8 * fStack_e4 - local_fc * fStack_e0;
  local_f0 = local_100 * fStack_e0 - local_f8 * fStack_e8;
  local_ec = local_fc * fStack_e8 - local_100 * fStack_e4;
  fStack_d8 = local_f4;
  fStack_d4 = local_f0;
  fStack_d0 = local_ec;
  fStack_cc = local_100;
  fStack_c8 = local_fc;
  fStack_c4 = local_f8;
  fVar6 = (float10)FUN_00405f40(&fStack_cc);
  fStack_dc = (float)SQRT(fVar6);
  pfVar1 = (float *)FUN_004175f0(&local_f4,&fStack_cc,fStack_dc);
  fStack_cc = *pfVar1;
  fStack_c8 = pfVar1[1];
  fStack_c4 = pfVar1[2];
  fVar6 = (float10)FUN_00405f40(&fStack_d8);
  fStack_dc = (float)SQRT(fVar6);
  pfVar1 = (float *)FUN_004175f0(&local_100,&fStack_d8,fStack_dc);
  local_f4 = *pfVar1;
  local_f0 = pfVar1[1];
  local_ec = pfVar1[2];
  pfVar1 = (float *)FUN_00405f20(-local_f4,-local_f0,-local_ec);
  fStack_d8 = *pfVar1;
  fStack_d4 = pfVar1[1];
  fStack_d0 = pfVar1[2];
  pfVar1 = (float *)&DAT_006a5c90;
  pfVar5 = afStack_c0;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar5 = *pfVar1;
    pfVar1 = pfVar1 + 1;
    pfVar5 = pfVar5 + 1;
  }
  afStack_c0[0] = fStack_cc;
  fStack_b0 = fStack_c8;
  fStack_a0 = fStack_c4;
  afStack_c0[2] = fStack_e8;
  fStack_a8 = fStack_e4;
  fStack_98 = fStack_e0;
  afStack_c0[1] = fStack_d8;
  fStack_ac = fStack_d4;
  fStack_9c = fStack_d0;
  puVar2 = (undefined4 *)FUN_004a2560(auStack_40,afStack_c0,local_80);
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

