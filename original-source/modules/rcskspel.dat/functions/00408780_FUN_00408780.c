/*
 * FUN_00408780 at 00408780
 * undefined FUN_00408780(void)
 * Address ranges: 00408780-00408853
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00408780(int param_1)

{
  float *pfVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  float10 fVar5;
  undefined4 local_4;
  
  iVar2 = param_1;
  iVar4 = (&DAT_00505108)[param_1 * 9];
  cVar3 = FUN_00407d70(param_1,&local_4,&param_1);
  if (cVar3 == '\x01') {
    FUN_00408400(iVar2,local_4,param_1);
    return;
  }
  iVar4 = iVar4 * 0xd0;
  pfVar1 = (float *)(iVar4 + 0xa4 + DAT_0067ee20);
  fVar5 = (float10)FUN_0048f4e0();
  *pfVar1 = (float)((float10)*pfVar1 -
                   fVar5 * (float10)*(float *)(iVar4 + 0xa4 + DAT_0067ee20) * (float10)4.0);
  pfVar1 = (float *)(iVar4 + 0x9c + DAT_0067ee20);
  fVar5 = (float10)FUN_0048f4e0();
  *pfVar1 = (float)((float10)*pfVar1 -
                   fVar5 * (float10)*(float *)(iVar4 + 0x9c + DAT_0067ee20) * (float10)4.0);
  pfVar1 = (float *)(iVar4 + 0xac + DAT_0067ee20);
  fVar5 = (float10)FUN_0048f4e0();
  *pfVar1 = (float)((float10)*pfVar1 -
                   fVar5 * (float10)*(float *)(iVar4 + 0xac + DAT_0067ee20) * (float10)5.0);
  return;
}

