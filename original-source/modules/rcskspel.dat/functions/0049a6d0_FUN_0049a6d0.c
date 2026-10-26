/*
 * FUN_0049a6d0 at 0049a6d0
 * undefined FUN_0049a6d0(void)
 * Address ranges: 0049a6d0-0049a745
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0049a6d0(float *param_1,uint param_2)

{
  int iVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  float local_30 [12];
  
  iVar1 = -(int)param_1;
  iVar4 = 4;
  do {
    iVar3 = (DAT_004fc8f8 & param_2) * 4;
    *(float *)((int)local_30 + iVar1 + (int)param_1) =
         *(float *)(iVar3 + DAT_006a5cd0) * *param_1 - *(float *)(iVar3 + DAT_006a5c88) * param_1[2]
    ;
    pfVar2 = param_1 + 3;
    iVar4 = iVar4 + -1;
    *(float *)((int)local_30 + iVar1 + -4 + (int)pfVar2) =
         *(float *)(iVar3 + DAT_006a5c88) * *param_1 + *(float *)(iVar3 + DAT_006a5cd0) * param_1[2]
    ;
    *param_1 = *(float *)((int)local_30 + iVar1 + -0xc + (int)pfVar2);
    param_1[1] = *(float *)((int)local_30 + iVar1 + -8 + (int)pfVar2);
    param_1[2] = *(float *)((int)local_30 + iVar1 + -4 + (int)pfVar2);
    param_1 = pfVar2;
  } while (iVar4 != 0);
  return;
}

