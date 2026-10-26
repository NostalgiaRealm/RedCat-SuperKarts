/*
 * FUN_00408d00 at 00408d00
 * undefined FUN_00408d00(void)
 * Address ranges: 00408d00-00408f11
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00408d00(int param_1)

{
  float *pfVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  
  iVar7 = param_1 * 0x24;
  uVar2 = *(uint *)(&DAT_00505114 + iVar7);
  if ((uVar2 & 0x20) == 0) {
    if ((uVar2 & 0x40) == 0) {
      iVar6 = (-(uint)((uVar2 & 0x80) != 0) & 0xfffffffe) + 2;
    }
    else {
      iVar6 = 1;
    }
  }
  else {
    iVar6 = 3;
  }
  iVar5 = (&DAT_00505108)[param_1 * 9];
  iVar4 = FUN_00444ba0(*(undefined4 *)(&DAT_0050511c + iVar7));
  if (*(int *)(&DAT_00505118 + iVar7) < *(int *)(&DAT_0053f674 + iVar4 * 0x340)) {
    iVar4 = iVar5 * 0xd0;
    iVar7 = *(int *)(*(int *)(iVar4 + 0x24 + DAT_0067ee20) * 0x50 + 0x18 + DAT_00680ae0);
    if ((iVar7 != -1) &&
       (cVar3 = FUN_004116d0(iVar5,iVar7,iVar6,(uVar2 & 0x1000) != 0), cVar3 != '\x01')) {
      pfVar1 = (float *)(iVar4 + 0xa4 + DAT_0067ee20);
      fVar8 = (float10)FUN_0048f4e0();
      *pfVar1 = (float)((float10)*pfVar1 -
                       fVar8 * (float10)*(float *)(iVar4 + 0xa4 + DAT_0067ee20) * (float10)4.0);
      pfVar1 = (float *)(iVar4 + 0x9c + DAT_0067ee20);
      fVar8 = (float10)FUN_0048f4e0();
      *pfVar1 = (float)((float10)*pfVar1 -
                       fVar8 * (float10)*(float *)(iVar4 + 0x9c + DAT_0067ee20) * (float10)4.0);
      pfVar1 = (float *)(iVar4 + 0xac + DAT_0067ee20);
      fVar8 = (float10)FUN_0048f4e0();
      *pfVar1 = (float)((float10)*pfVar1 -
                       fVar8 * (float10)*(float *)(iVar4 + 0xac + DAT_0067ee20) * (float10)4.0);
      return;
    }
    FUN_004085d0(param_1);
    pfVar1 = (float *)(iVar4 + 0xa4 + DAT_0067ee20);
    if (DAT_0050504c <= *(float *)(iVar4 + 0xa4 + DAT_0067ee20)) {
      *pfVar1 = DAT_0050504c;
    }
    else {
      fVar8 = (float10)FUN_0048f4e0();
      *pfVar1 = (float)(fVar8 * (float10)5.0 + (float10)*pfVar1);
    }
    if (*(float *)(iVar4 + 0xa4 + DAT_0067ee20) < 5.0) {
      *(undefined4 *)(iVar4 + 0xa4 + DAT_0067ee20) = 0x40a00000;
      return;
    }
  }
  else {
    iVar5 = iVar5 * 0xd0;
    *(undefined4 *)(iVar5 + 0xa4 + DAT_0067ee20) = 0;
    *(undefined4 *)(iVar5 + 0x9c + DAT_0067ee20) = 0;
    *(undefined4 *)(iVar5 + 0xac + DAT_0067ee20) = 0;
    *(undefined4 *)(iVar5 + 0x44 + DAT_0067ee20) = 0;
    (&DAT_0053f998)[*(int *)(&DAT_0050511c + iVar7) * 0xd0] = 0;
  }
  return;
}

