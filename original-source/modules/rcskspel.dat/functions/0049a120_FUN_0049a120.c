/*
 * FUN_0049a120 at 0049a120
 * undefined FUN_0049a120(void)
 * Address ranges: 0049a120-0049a2d0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0049a120(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  undefined4 *puVar8;
  float *pfVar9;
  int iVar10;
  float10 fVar11;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 local_30 [8];
  float local_28 [10];
  
  iVar7 = param_2;
  local_60 = *param_1;
  local_5c = param_1[1];
  local_54 = param_1[3];
  local_58 = param_1[2];
  local_50 = param_1[4];
  local_4c = param_1[5];
  local_48 = param_1[6];
  local_44 = param_1[7];
  local_3c = param_1[9];
  local_40 = param_1[8];
  local_38 = param_1[10];
  local_34 = param_1[0xb];
  FUN_0049a630(local_30,param_2);
  fVar1 = *(float *)(iVar7 + 0x30);
  fVar2 = (float)param_1[0xc];
  fVar3 = *(float *)(iVar7 + 0x34);
  fVar4 = (float)param_1[0xd];
  fVar5 = *(float *)(iVar7 + 0x38);
  fVar6 = (float)param_1[0xe];
  iVar10 = 4;
  pfVar9 = local_28;
  do {
    iVar10 = iVar10 + -1;
    pfVar9[-2] = (fVar1 - fVar2) + pfVar9[-2];
    pfVar9[-1] = (fVar3 - fVar4) + pfVar9[-1];
    *pfVar9 = (fVar5 - fVar6) + *pfVar9;
    pfVar9 = pfVar9 + 3;
  } while (iVar10 != 0);
  FUN_0049a6d0(local_30,-param_1[0x11]);
  puVar8 = param_3;
  iVar10 = FUN_0049a2e0(&local_60,local_30,param_3);
  if (iVar10 == 0) {
    return (float10)1.0;
  }
  fVar11 = (float10)FUN_0049ab10(local_30,&local_60,*puVar8,puVar8[1],puVar8[2],&param_2,&local_64);
  fVar1 = (float)fVar11;
  if (param_2 != -1) {
    _DAT_00680b78 = 1;
    iVar10 = iVar7 + param_2 * 0xc;
    _DAT_00680b7c = *(undefined4 *)(iVar7 + param_2 * 0xc);
    _DAT_00680b80 = *(undefined4 *)(iVar10 + 4);
    _DAT_00680b84 = *(undefined4 *)(iVar10 + 8);
    _DAT_00680b98 = local_64;
  }
  if ((1.0 < fVar1) || (fVar1 < 0.0)) {
    FUN_004afee0(s__s__d____Clip_cannot_be___f__004fb80c,s_D__work_rcsk_Code_Engine_Prog_Bb_004fb7e4
                 ,0x1af,(double)fVar1);
  }
  return (float10)fVar1;
}

