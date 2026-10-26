/*
 * FUN_00406470 at 00406470
 * undefined FUN_00406470(void)
 * Address ranges: 00406470-00406721
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00406470(int param_1,undefined4 param_2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  
  switch(param_2) {
  case 4:
    (&DAT_00503f20)[param_1 * 0x47] = DAT_0050504c;
    return;
  case 5:
    (&DAT_00503f20)[param_1 * 0x47] = _DAT_00505050;
    return;
  case 6:
    (&DAT_00503f20)[param_1 * 0x47] = _DAT_00505054;
    return;
  case 8:
    (&DAT_00503f20)[param_1 * 0x47] = _DAT_00505058;
    return;
  case 0xe:
    if ((&DAT_0053a6a4)[DAT_0053b9b4 * 0x25] == 0) {
      (&DAT_005081c0)[param_1 * 0x1c] = 1;
LAB_004065ab:
      FUN_00417e30((&DAT_00503ef0)[param_1 * 0x47]);
      (&DAT_00503ef4)[param_1 * 0x47] = 9;
      return;
    }
    iVar4 = param_1 * 0x11c;
    if ((*(int *)(&DAT_00503f1c + iVar4) == 0xf) &&
       (fVar5 = (float10)FUN_0048f4d0(),
       (float10)10.0 < fVar5 - (float10)*(float *)(&DAT_00504008 + iVar4))) {
      *(int *)(&DAT_00503efc + iVar4) = *(int *)(&DAT_00503efc + iVar4) + 1;
      fVar5 = (float10)FUN_0048f4d0();
      iVar3 = DAT_0053ba1c;
      *(float *)(&DAT_00504008 + iVar4) = (float)fVar5;
      *(undefined4 *)(&DAT_00503f1c + iVar4) = 0xe;
      if (iVar3 <= *(int *)(&DAT_00503efc + iVar4)) {
        (&DAT_005081c0)[param_1 * 0x1c] = 1;
        goto LAB_004065ab;
      }
    }
    break;
  case 0xf:
    *(undefined4 *)(&DAT_00503f1c + param_1 * 0x11c) = 0xf;
    return;
  case 0x35:
    pfVar1 = (float *)(DAT_0053be28 * 0xd0 + 0xa4 + DAT_0067ee20);
    fVar2 = *pfVar1;
    iVar3 = (&DAT_00503ef0)[param_1 * 0x47] * 0xd0;
    iVar4 = iVar3 + DAT_0067ee20;
    if (((fVar2 < *(float *)(iVar3 + 0x9c + DAT_0067ee20)) && (fVar2 < *(float *)(iVar4 + 0xa0))) &&
       (fVar2 < *(float *)(iVar4 + 0xa4))) {
      *(float *)(iVar4 + 0xa4) = *pfVar1;
    }
    iVar4 = (&DAT_00503ef0)[param_1 * 0x47] * 0xd0;
    *(float *)(iVar4 + 0xa4 + DAT_0067ee20) = *(float *)(iVar4 + 0xa4 + DAT_0067ee20) * 1.2;
    FUN_0040dc10(param_1);
    return;
  case 0x40:
    FUN_0040d5c0(param_1);
    return;
  case 0x41:
    if ((&DAT_00503f8c)[param_1 * 0x11c] != '\0') {
      (&DAT_00503f8c)[param_1 * 0x11c] = 0;
      return;
    }
    break;
  case 0x43:
    FUN_00441b40((&DAT_00503ef0)[param_1 * 0x47]);
    return;
  case 0x44:
    FUN_00441c30((&DAT_00503ef0)[param_1 * 0x47]);
  }
  return;
}

