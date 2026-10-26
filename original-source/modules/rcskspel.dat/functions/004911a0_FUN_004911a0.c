/*
 * FUN_004911a0 at 004911a0
 * undefined FUN_004911a0(void)
 * Address ranges: 004911a0-004914c4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004911a0(int param_1,float param_2,undefined4 param_3,int param_4)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  float10 extraout_ST0;
  
  if (param_2 < 0.0) {
    FUN_004afee0(s__s__d____Illegal_dt___f__while_i_004fa8d4,
                 s_D__work_rcsk_Code_Engine_Prog_ob_004fa444,0x39e,(double)param_2);
  }
  FUN_004c062b((double)*(float *)(DAT_006a5c38 + *(int *)(param_1 + 0xc) * 0xa9 + 0x78));
  __ftol();
  __ftol();
  iVar6 = __ftol();
  iVar7 = DAT_006a5c38 + *(int *)(param_1 + 0xc) * 0xa9;
  fVar2 = *(float *)(param_1 + 0xac);
  *(undefined4 *)(iVar7 + 0x54) = *(undefined4 *)(iVar7 + 0x54);
  *(float *)(iVar7 + 0x50) = (float)(extraout_ST0 + (float10)*(float *)(iVar7 + 0x50));
  *(float *)(iVar7 + 0x58) = (float)iVar6 * 0.0001 + *(float *)(iVar7 + 0x58);
  if (param_4 == 0) {
    iVar6 = *(int *)(param_1 + 0xc);
    *(float *)(DAT_006a5c38 + iVar6 + 0x78 + iVar6 * 0xa8) =
         (_DAT_004fc8f4 * param_2 * fVar2) / 6.2831855 +
         *(float *)(DAT_006a5c38 + iVar6 + 0x78 + iVar6 * 0xa8);
  }
  iVar6 = __ftol();
  iVar6 = (-iVar6 & DAT_004fc8f8) * 4;
  pfVar1 = (float *)(param_1 + 0x9c);
  fVar2 = *(float *)(iVar6 + DAT_006a5c88);
  fVar3 = *pfVar1;
  fVar4 = *(float *)(iVar6 + DAT_006a5cd0);
  *pfVar1 = *(float *)(iVar6 + DAT_006a5cd0) * *pfVar1 -
            *(float *)(iVar6 + DAT_006a5c88) * *(float *)(param_1 + 0xa4);
  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 0xa0);
  fVar5 = *(float *)(param_1 + 0x90);
  *(float *)(param_1 + 0xa4) = fVar4 * *(float *)(param_1 + 0xa4) + fVar2 * fVar3;
  *pfVar1 = fVar5 * *(float *)(param_1 + 0xb4) * param_2 + *pfVar1;
  *(float *)(param_1 + 0xa0) =
       fVar5 * *(float *)(param_1 + 0xb8) * param_2 + *(float *)(param_1 + 0xa0);
  *(float *)(param_1 + 0xa4) =
       fVar5 * *(float *)(param_1 + 0xbc) * param_2 + *(float *)(param_1 + 0xa4);
  *(float *)(param_1 + 0xac) =
       *(float *)(param_1 + 0xc0) * *(float *)(param_1 + 0x94) * param_2 +
       *(float *)(param_1 + 0xac);
  return;
}

