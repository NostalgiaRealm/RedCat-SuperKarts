/*
 * FUN_00493540 at 00493540
 * undefined FUN_00493540(void)
 * Address ranges: 00493540-00493693
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00493540(int param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float10 fVar4;
  
  if ((param_2 < 0) || (DAT_00680b2c < param_2)) {
    FUN_004afee0(s___s___d_Illegal_chunk___d_004fab60,s_D__work_rcsk_Code_Engine_Prog_If_004faa80,
                 0x18b,param_2);
  }
  if ((param_3 < 0) || (1 < param_3)) {
    FUN_004afee0(s___s___d_Illegal_direction___d_004fabb4,
                 s_D__work_rcsk_Code_Engine_Prog_If_004faa80,0x191,param_3);
  }
  iVar3 = *(int *)(DAT_0068021c + param_2 * 4);
  fVar1 = *(float *)(DAT_00680b28 + 0x48 + iVar3 * 0x984);
  fVar2 = *(float *)(DAT_00680b28 + iVar3 * 0x984 + 0x50);
  fVar4 = SQRT((float10)fVar1 * (float10)fVar1 + (float10)fVar2 * (float10)fVar2);
  fVar1 = (float)((float10)fVar1 / fVar4);
  fVar4 = (float10)fVar2 / fVar4;
  if (param_3 == 0) {
    fVar4 = (float10)fpatan(fVar4,(float10)fVar1);
    iVar3 = *(int *)(param_1 * 0xd0 + 0xc + DAT_0067ee20);
    fVar4 = (float10)_DAT_004fc8f4 * (float10)0.5 +
            ((fVar4 - (float10)3.1415927 * (float10)0.5) * (float10)_DAT_004fc8f4) /
            (float10)6.2831855;
  }
  else {
    if (param_3 != 1) {
      return;
    }
    fVar4 = (float10)fpatan(fVar4,(float10)fVar1);
    iVar3 = *(int *)(param_1 * 0xd0 + 0xc + DAT_0067ee20);
    fVar4 = ((fVar4 - (float10)3.1415927 * (float10)0.5) * (float10)_DAT_004fc8f4) /
            (float10)6.2831855;
  }
  *(float *)(DAT_006a5c38 + iVar3 * 0xa9 + 0x78) = (float)fVar4;
  return;
}

