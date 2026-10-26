/*
 * FUN_00408400 at 00408400
 * undefined FUN_00408400(void)
 * Address ranges: 00408400-004085c8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00408400(float param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  float *pfVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  
  iVar5 = (int)param_1;
  puVar2 = (undefined4 *)(param_2 * 0x50 + 8 + DAT_00680ae0);
  iVar6 = (int)param_1 * 0x24;
  iVar7 = (&DAT_00505108)[(int)param_1 * 9];
  fVar8 = (float10)FUN_00407f50(param_1,*puVar2,puVar2[1],puVar2[2]);
  if (fVar8 <= (float10)400.0) {
    if (-400.0 <= (float)fVar8) {
      param_1 = (float)fVar8 * 0.25;
    }
    else {
      param_1 = -100.0;
    }
  }
  else {
    param_1 = 100.0;
  }
  iVar7 = iVar7 * 0xd0;
  fVar4 = *(float *)(iVar7 + 0xac + DAT_0067ee20);
  pfVar3 = (float *)(iVar7 + 0xac + DAT_0067ee20);
  fVar8 = (float10)FUN_0048f4e0();
  *pfVar3 = (float)((float10)*pfVar3 - fVar8 * (float10)(fVar4 * 10.0));
  fVar4 = *(float *)(iVar7 + 0x9c + DAT_0067ee20);
  iVar1 = iVar7 + DAT_0067ee20;
  fVar8 = (float10)FUN_0048f4e0();
  *(float *)(iVar1 + 0xac) =
       (float)((float10)*(float *)(iVar1 + 0xac) - fVar8 * (float10)(fVar4 * 5.0));
  fVar4 = *(float *)(iVar7 + 0xa4 + DAT_0067ee20);
  fVar8 = (float10)FUN_0048f4e0();
  *(float *)(iVar7 + 0xac + DAT_0067ee20) =
       (float)(fVar8 * (float10)(fVar4 * 0.006666667) * (float10)param_1 +
              (float10)*(float *)(iVar7 + 0xac + DAT_0067ee20));
  if (*(float *)(iVar7 + 0xac + DAT_0067ee20) <= 1.0) {
    if (*(float *)(iVar7 + 0xac + DAT_0067ee20) < -1.0) {
      *(undefined4 *)(iVar7 + 0xac + DAT_0067ee20) = 0xbf800000;
    }
  }
  else {
    *(undefined4 *)(iVar7 + 0xac + DAT_0067ee20) = 0x3f800000;
  }
  if ((ABS(param_1) < _DAT_004de8cc) && ((*(uint *)(&DAT_00505114 + iVar6) & 0x400) == 0)) {
    *(undefined4 *)(iVar7 + 0xac + DAT_0067ee20) = 0;
  }
  FUN_00408270(iVar5,param_2,param_3,param_1);
  return;
}

