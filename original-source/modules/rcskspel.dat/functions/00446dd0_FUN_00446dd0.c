/*
 * FUN_00446dd0 at 00446dd0
 * undefined FUN_00446dd0(void)
 * Address ranges: 00446dd0-00446fab
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00446dd0(undefined1 *param_1)

{
  float *pfVar1;
  int iVar2;
  uint3 uVar3;
  int iVar4;
  float10 fVar5;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  undefined1 auStack_c [12];
  
  if (param_1 == (undefined1 *)0x0) {
    FUN_004afee0(s_Invalid_pathInfo___s__d__004efbe4,s_D__work_rcsk_Code_game_pth_PathC_004efbb4,
                 0x2b2);
  }
  if ((DAT_00543774 & 1) == 0) {
    DAT_00543774 = DAT_00543774 | 1;
    _DAT_00543770 = GetTickCount();
  }
  iVar4 = *(int *)(param_1 + 0x10);
  iVar2 = *(int *)(param_1 + 4) + -2;
  if ((iVar2 <= *(int *)(param_1 + 8)) && (param_1[0x1c] != '\0')) {
    *(undefined4 *)(param_1 + 8) = 0;
  }
  if (*(int *)(param_1 + 8) < iVar2) {
    pfVar1 = (float *)FUN_00445120(&fStack_18,*(undefined4 *)(param_1 + 0x18),*(int *)(param_1 + 4),
                                   *(int *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),
                                   CONCAT31((int3)((uint)iVar2 >> 8),param_1[0x1d]));
    fStack_24 = *pfVar1;
    fStack_20 = pfVar1[1];
    fStack_1c = pfVar1[2];
    pfVar1 = (float *)FUN_00445120(auStack_c,*(undefined4 *)(param_1 + 0x18),
                                   *(undefined4 *)(param_1 + 4),*(int *)(param_1 + 8) + 1,
                                   *(undefined4 *)(param_1 + 0xc),param_1[0x1d]);
    fStack_18 = *pfVar1;
    fStack_14 = pfVar1[1];
    fStack_10 = pfVar1[2];
  }
  iVar4 = iVar4 * 0xd0;
  *(int *)(iVar4 + 0x1c + DAT_0067ee20) = DAT_0053be40;
  if (*(int *)(param_1 + 8) < *(int *)(param_1 + 4) + -2) {
    GetTickCount();
    _DAT_00543770 = GetTickCount();
    fVar5 = (float10)fpatan((float10)fStack_10 - (float10)fStack_1c,
                            (float10)fStack_18 - (float10)fStack_24);
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    *(float *)(DAT_006a5c38 + *(int *)(iVar4 + 0xc + DAT_0067ee20) * 0xa9 + 0x78) =
         (float)(((fVar5 - (float10)3.1415927 * (float10)0.5) * (float10)_DAT_004fc8f4) /
                (float10)6.2831855);
    iVar2 = DAT_006a5c38 + *(int *)(iVar4 + 0xc + DAT_0067ee20) * 0xa9;
    *(float *)(iVar2 + 0x50) = fStack_24;
    *(float *)(iVar2 + 0x54) = fStack_20;
    *(float *)(iVar2 + 0x58) = fStack_1c;
    FUN_004a09e0();
  }
  iVar2 = *(int *)(&DAT_0053f664 + *(int *)(param_1 + 0x18) * 0x340);
  uVar3 = (uint3)((uint)iVar2 >> 8);
  if ((iVar2 != 0) && (iVar2 == DAT_0053be40)) {
    *param_1 = 0;
    return CONCAT31(uVar3,1);
  }
  return (uint)uVar3 << 8;
}

