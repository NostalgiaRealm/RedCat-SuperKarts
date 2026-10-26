/*
 * FUN_004a1ad0 at 004a1ad0
 * undefined FUN_004a1ad0(void)
 * Address ranges: 004a1ad0-004a1de4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004a1ad0(float *param_1,float *param_2,float *param_3,float *param_4,float param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  undefined4 uVar5;
  int iVar6;
  float *pfVar7;
  float10 fVar8;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float fStack_f0;
  float fStack_ec;
  float fStack_e8;
  float local_e4;
  float fStack_e0;
  float fStack_dc;
  float fStack_d8;
  float fStack_d4;
  float fStack_d0;
  float local_cc [4];
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  undefined1 auStack_8c [12];
  undefined1 auStack_80 [64];
  undefined1 auStack_40 [64];
  
  pfVar4 = (float *)&DAT_006a5c90;
  pfVar7 = local_cc;
  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
    *pfVar7 = *pfVar4;
    pfVar4 = pfVar4 + 1;
    pfVar7 = pfVar7 + 1;
  }
  if (((*param_3 == *param_2) && (param_3[1] == param_2[1])) && (param_3[2] == param_2[2])) {
    FUN_004afee0(s__s__d____Divide_by_zero__at__fro_004fc990,
                 s_D__work_libs_DX3D_D3dutils_cpp_004fc9b4,0x4e);
  }
  pfVar4 = (float *)FUN_00405f20(*param_3 - *param_2,param_3[1] - param_2[1],param_3[2] - param_2[2]
                                );
  fStack_d8 = *pfVar4;
  fStack_d4 = pfVar4[1];
  fStack_d0 = pfVar4[2];
  fVar8 = (float10)FUN_00405f40(&fStack_d8);
  pfVar4 = (float *)FUN_004175f0(auStack_8c,&fStack_d8,(float)SQRT(fVar8));
  fVar1 = *pfVar4;
  fVar2 = pfVar4[1];
  fVar3 = pfVar4[2];
  fStack_fc = fVar3 * param_4[1] - fVar2 * param_4[2];
  fStack_f8 = fVar1 * param_4[2] - fVar3 * *param_4;
  fStack_f4 = fVar2 * *param_4 - fVar1 * param_4[1];
  fStack_f0 = fStack_f4 * fVar2 - fStack_f8 * fVar3;
  fStack_ec = fStack_fc * fVar3 - fStack_f4 * fVar1;
  fStack_e8 = fStack_f8 * fVar1 - fStack_fc * fVar2;
  local_e4 = fStack_fc;
  fStack_e0 = fStack_f8;
  fStack_dc = fStack_f4;
  fStack_d8 = fStack_f0;
  fStack_d4 = fStack_ec;
  fStack_d0 = fStack_e8;
  fVar8 = (float10)FUN_00405f40(&fStack_fc);
  pfVar4 = (float *)FUN_004175f0(auStack_8c,&fStack_fc,(float)SQRT(fVar8));
  fStack_fc = *pfVar4;
  fStack_f8 = pfVar4[1];
  fStack_f4 = pfVar4[2];
  fVar8 = (float10)FUN_00405f40(&fStack_f0);
  pfVar4 = (float *)FUN_004175f0(auStack_8c,&fStack_f0,(float)SQRT(fVar8));
  fStack_f0 = *pfVar4;
  fStack_ec = pfVar4[1];
  fStack_e8 = pfVar4[2];
  local_cc[0] = fStack_fc;
  fStack_9c = -(fStack_f4 * param_2[2] + fStack_fc * *param_2 + fStack_f8 * param_2[1]);
  fStack_bc = fStack_f8;
  fStack_ac = fStack_f4;
  local_cc[1] = fStack_f0;
  fStack_b8 = fStack_ec;
  fStack_a8 = fStack_e8;
  local_cc[2] = fVar1;
  fStack_b4 = fVar2;
  fStack_98 = -(fStack_e8 * param_2[2] + fStack_f0 * *param_2 + fStack_ec * param_2[1]);
  fStack_a4 = fVar3;
  fStack_94 = -(fVar3 * param_2[2] + fVar1 * *param_2 + fVar2 * param_2[1]);
  if (param_5 != 0.0) {
    uVar5 = FUN_004a21a0(auStack_80,-param_5,local_cc);
    pfVar4 = (float *)FUN_004a2560(auStack_40,uVar5);
    pfVar7 = local_cc;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *pfVar7 = *pfVar4;
      pfVar4 = pfVar4 + 1;
      pfVar7 = pfVar7 + 1;
    }
  }
  pfVar4 = local_cc;
  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
    *param_1 = *pfVar4;
    pfVar4 = pfVar4 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

