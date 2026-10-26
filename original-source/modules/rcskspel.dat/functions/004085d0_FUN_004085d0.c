/*
 * FUN_004085d0 at 004085d0
 * undefined FUN_004085d0(void)
 * Address ranges: 004085d0-0040877b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004085d0(int param_1)

{
  float *pfVar1;
  int iVar2;
  undefined4 uVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  float10 fVar10;
  float10 fVar11;
  undefined4 local_8;
  
  iVar8 = param_1 * 0x24;
  iVar9 = (&DAT_00505108)[param_1 * 9] * 0xd0;
  iVar7 = *(int *)(iVar9 + 0xc + DAT_0067ee20);
  iVar6 = FUN_00444ba0(*(undefined4 *)(&DAT_0050511c + iVar8));
  iVar2 = *(int *)(&DAT_00505118 + iVar8);
  fVar4 = *(float *)(DAT_006a5c38 + 0x50 + iVar7 * 0xa9) -
          *(float *)(&DAT_0053f67c + (iVar2 + iVar6 * 0x34) * 0x10);
  iVar7 = *(int *)(iVar9 + 0xc + DAT_0067ee20);
  iVar6 = FUN_00444ba0(*(undefined4 *)(&DAT_0050511c + iVar8));
  fVar5 = *(float *)(DAT_006a5c38 + 0x58 + iVar7 * 0xa9) -
          *(float *)(&DAT_0053f684 + (iVar2 + iVar6 * 0x34) * 0x10);
  if (SQRT(fVar4 * fVar4 + fVar5 * fVar5) < 20.0) {
    *(int *)(&DAT_00505118 + iVar8) = iVar2 + 1;
  }
  pfVar1 = (float *)(iVar9 + 0xac + DAT_0067ee20);
  fVar10 = (float10)FUN_0048f4e0();
  *pfVar1 = (float)((float10)*pfVar1 -
                   fVar10 * (float10)*(float *)(iVar9 + 0xac + DAT_0067ee20) * (float10)4.0);
  iVar7 = FUN_00444ba0(*(undefined4 *)(&DAT_0050511c + iVar8));
  uVar3 = *(undefined4 *)(&DAT_0053f67c + (*(int *)(&DAT_00505118 + iVar8) + iVar7 * 0x34) * 0x10);
  iVar7 = FUN_00444ba0(*(undefined4 *)(&DAT_0050511c + iVar8));
  fVar10 = (float10)FUN_00407f50(param_1,uVar3,local_8,
                                 *(undefined4 *)
                                  (&DAT_0053f684 +
                                  (*(int *)(&DAT_00505118 + iVar8) + iVar7 * 0x34) * 0x10));
  fVar11 = (float10)FUN_0048f4e0();
  *(float *)(iVar9 + 0xac + DAT_0067ee20) =
       (float)(fVar11 * (float10)(float)fVar10 * (float10)0.02 +
              (float10)*(float *)(iVar9 + 0xac + DAT_0067ee20));
  return;
}

