/*
 * FUN_004089b0 at 004089b0
 * undefined FUN_004089b0(void)
 * Address ranges: 004089b0-00408b32
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004089b0(int param_1)

{
  float *pfVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  float10 fVar7;
  undefined4 local_8;
  
  iVar5 = param_1 * 0x24;
  iVar4 = (&DAT_00505108)[param_1 * 9];
  if (*(int *)(&DAT_0050511c + iVar5) == 0) {
    iVar3 = FUN_00444ba0(0);
    uVar2 = *(undefined4 *)(&DAT_0053f68c + iVar3 * 0x340);
    iVar3 = FUN_00444ba0(*(undefined4 *)(&DAT_0050511c + iVar5));
    fVar7 = (float10)FUN_00407f50(param_1,uVar2,local_8,
                                  *(undefined4 *)(&DAT_0053f694 + iVar3 * 0x340));
    iVar3 = *(int *)(iVar4 * 0xd0 + 0xc + DAT_0067ee20);
    *(float *)(DAT_006a5c38 + iVar3 + 0x78 + iVar3 * 0xa8) =
         (float)(fVar7 + (float10)*(float *)(DAT_006a5c38 + iVar3 + 0x78 + iVar3 * 0xa8));
  }
  iVar3 = *(int *)(&DAT_00505118 + iVar5);
  bVar6 = false;
  if (iVar3 == 0) {
    if (DAT_004ecd7c == 0) {
      iVar3 = FUN_0042a4d0(1);
      if (2000 < iVar3) {
        *(undefined4 *)(&DAT_00505118 + iVar5) = 1;
      }
    }
    iVar3 = *(int *)(&DAT_00505118 + iVar5);
    bVar6 = iVar3 == 0;
  }
  if (!bVar6 && -1 < iVar3) {
    FUN_004085d0(param_1);
    pfVar1 = (float *)(iVar4 * 0xd0 + 0xa4 + DAT_0067ee20);
    if (*(float *)(iVar4 * 0xd0 + 0xa4 + DAT_0067ee20) < DAT_0050504c) {
      fVar7 = (float10)FUN_0048f4e0();
      *pfVar1 = (float)(fVar7 * (float10)5.0 + (float10)*pfVar1);
      return;
    }
    *pfVar1 = DAT_0050504c;
    return;
  }
  iVar4 = iVar4 * 0xd0;
  *(undefined4 *)(iVar4 + 0xa4 + DAT_0067ee20) = 0;
  *(undefined4 *)(iVar4 + 0x9c + DAT_0067ee20) = 0;
  *(undefined4 *)(iVar4 + 0xac + DAT_0067ee20) = 0;
  return;
}

