/*
 * FUN_004589c0 at 004589c0
 * undefined FUN_004589c0(void)
 * Address ranges: 004589c0-00458aa0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004589c0(int *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  
  pfVar5 = (float *)FUN_004583d0();
  fVar2 = *pfVar5;
  fVar3 = pfVar5[1];
  fVar4 = pfVar5[2];
  param_1[0x15] = (int)((float)param_1[0x1f] * param_2[4]);
  param_1[0x14] = (int)param_2[3];
  param_1[0x16] = (int)((float)param_1[0x20] * param_2[5]);
  param_1[0x11] = (int)(fVar2 * param_2[4] + *param_2);
  param_1[0x12] = (int)(fVar3 * param_2[5] + param_2[1]);
  param_1[0x13] = (int)(fVar4 + param_2[2]);
  pfVar5 = (float *)(**(code **)(*param_1 + 0x20))();
  fVar2 = param_2[7];
  fVar3 = pfVar5[1];
  fVar4 = param_2[8];
  fVar1 = pfVar5[2];
  param_1[0x17] = (int)(param_2[6] * *pfVar5);
  param_1[0x18] = (int)(fVar2 * fVar3);
  param_1[0x19] = (int)(fVar4 * fVar1);
  pfVar5 = (float *)FUN_004583f0();
  fVar2 = param_2[10];
  fVar3 = pfVar5[1];
  fVar4 = param_2[0xb];
  fVar1 = pfVar5[2];
  param_1[0x1a] = (int)(param_2[9] + *pfVar5);
  param_1[0x1b] = (int)(fVar2 + fVar3);
  param_1[0x1c] = (int)(fVar4 + fVar1);
  return;
}

