/*
 * FUN_00414e70 at 00414e70
 * undefined FUN_00414e70(void)
 * Address ranges: 00414e70-00414f37
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414e70(int param_1,float param_2)

{
  int iVar1;
  float *pfVar2;
  float fVar3;
  float10 fVar4;
  float10 fVar5;
  
  param_1 = param_1 * 0xd0;
  iVar1 = param_1 + DAT_0067ee20;
  fVar4 = (float10)FUN_0048f4e0();
  fVar3 = *(float *)(iVar1 + 0xac);
  if (0.0 <= *(float *)(iVar1 + 0xa4)) {
    fVar5 = (float10)FUN_0048f4e0();
    fVar5 = fVar5 * (float10)param_2 * (float10)0.05;
  }
  else {
    fVar5 = (float10)FUN_0048f4e0();
    fVar5 = fVar5 * (float10)param_2 * (float10)-0.05;
  }
  *(float *)(param_1 + 0xac + DAT_0067ee20) =
       *(float *)(param_1 + 0xac + DAT_0067ee20) - (float)(fVar4 * (float10)fVar3 * (float10)3.0);
  *(float *)(param_1 + 0xac + DAT_0067ee20) =
       (float)((float10)*(float *)(param_1 + 0xac + DAT_0067ee20) - fVar5);
  pfVar2 = (float *)(param_1 + 0x9c + DAT_0067ee20);
  fVar4 = (float10)FUN_0048f4e0();
  *pfVar2 = (float)((float10)*pfVar2 -
                   fVar4 * (float10)*(float *)(param_1 + 0x9c + DAT_0067ee20) * (float10)4.0);
  return;
}

