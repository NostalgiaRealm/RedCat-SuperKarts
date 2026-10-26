/*
 * FUN_00463bb0 at 00463bb0
 * undefined FUN_00463bb0(void)
 * Address ranges: 00463bb0-00463c86
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00463bb0(int *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  int iVar6;
  
  param_1[0x15] = (int)((float)param_1[0x1f] * param_2[3]);
  param_1[0x14] = (int)param_2[3];
  param_1[0x16] = (int)((float)param_1[0x20] * param_2[5]);
  pfVar5 = (float *)FUN_004583d0();
  param_1[0x11] = (int)(*pfVar5 * param_2[4] + *param_2);
  iVar6 = FUN_004583d0();
  param_1[0x12] = (int)(*(float *)(iVar6 + 4) * param_2[5] + param_2[1]);
  iVar6 = FUN_004583d0();
  param_1[0x13] = (int)(*(float *)(iVar6 + 8) + param_2[2]);
  pfVar5 = (float *)(**(code **)(*param_1 + 0x20))();
  fVar1 = param_2[7];
  fVar2 = pfVar5[1];
  fVar3 = param_2[8];
  fVar4 = pfVar5[2];
  param_1[0x17] = (int)(param_2[6] * *pfVar5);
  param_1[0x18] = (int)(fVar1 * fVar2);
  param_1[0x19] = (int)(fVar3 * fVar4);
  pfVar5 = (float *)FUN_004583f0();
  fVar1 = param_2[10];
  fVar2 = pfVar5[1];
  fVar3 = param_2[0xb];
  fVar4 = pfVar5[2];
  param_1[0x1a] = (int)(*pfVar5 + param_2[9]);
  param_1[0x1b] = (int)(fVar1 + fVar2);
  param_1[0x1c] = (int)(fVar3 + fVar4);
  return;
}

