/*
 * FUN_0040bbf0 at 0040bbf0
 * undefined FUN_0040bbf0(void)
 * Address ranges: 0040bbf0-0040be4b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040bbf0(int param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  bool bVar10;
  float10 extraout_ST0;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar9 = param_1 * 0x11c;
  cVar2 = FUN_0040eba0();
  if (cVar2 == '\0') {
    return 1;
  }
  iVar3 = param_1;
  FUN_00451450(param_1);
  cVar2 = FUN_004523d0(iVar3);
  if ((cVar2 != '\0') && (cVar2 = FUN_0040be60(param_1), cVar2 != '\0')) {
    FUN_0040bbd0(param_1);
    return 0;
  }
  if (*(int *)(&DAT_00503f60 + iVar9) == 0) {
    return 0;
  }
  cVar2 = FUN_00417e90(param_1);
  iVar3 = DAT_0053be60;
  if (cVar2 == '\0') {
    iVar3 = (&DAT_005081b8)[param_1 * 0x1c];
  }
  iVar3 = FUN_004105c0(iVar3);
  if (iVar3 < 0) {
    return 0;
  }
  if (0.0 < *(float *)(&DAT_00503f88 + iVar9)) {
    FUN_0048f4e0();
    *(float *)(&DAT_00503f88 + iVar9) =
         (float)((float10)*(float *)(&DAT_00503f88 + iVar9) - extraout_ST0);
    return 1;
  }
  puVar1 = (undefined4 *)(*(int *)(iVar3 * 0xd0 + 0x24 + DAT_0067ee20) * 0x50 + 8 + DAT_00680ae0);
  local_c = *puVar1;
  local_8 = puVar1[1];
  local_4 = puVar1[2];
  uVar4 = FUN_0040ec30((&DAT_00503ef0)[param_1 * 0x47],&local_c);
  iVar5 = FUN_00410380(iVar3);
  iVar3 = *(int *)(&DAT_00505934 + (&DAT_00503f5c)[param_1 * 0x47] * 0x18);
  if (iVar3 == 1) goto switchD_0040bdfa_caseD_1;
  cVar2 = FUN_00417e90(param_1);
  iVar6 = DAT_0053be60;
  if (cVar2 == '\0') {
    iVar6 = (&DAT_005081b8)[param_1 * 0x1c];
  }
  if (iVar6 < 0) {
    iVar6 = 0;
  }
  if (DAT_00508610 < iVar6) {
    iVar6 = DAT_00508610;
  }
  if (iVar3 == 2) {
    if (iVar5 == -1) {
      if (1 < iVar6) goto switchD_0040bdfa_caseD_1;
    }
    else {
      bVar10 = (&DAT_00503ef4)[iVar5 * 0x47] != 0x1a;
LAB_0040be15:
      if (!bVar10) {
switchD_0040bdfa_caseD_1:
        FUN_0040c0c0(param_1,uVar4);
        goto LAB_0040bd97;
      }
    }
  }
  else {
    if (iVar5 == -1) {
      iVar3 = FUN_004be6c9();
      iVar3 = iVar3 % 5 + 1;
      uVar7 = uVar4;
    }
    else {
      uVar7 = *(undefined4 *)(&DAT_00505934 + (&DAT_00503f5c)[iVar5 * 0x47] * 0x18);
    }
    if (iVar3 == 3) {
      switch(uVar7) {
      case 1:
      case 2:
        goto switchD_0040bdfa_caseD_1;
      case 3:
        uVar8 = FUN_004be6c9();
        uVar8 = uVar8 & 0x80000001;
        bVar10 = uVar8 == 0;
        if ((int)uVar8 < 0) {
          bVar10 = (uVar8 - 1 | 0xfffffffe) == 0xffffffff;
        }
        goto LAB_0040be15;
      }
    }
  }
  FUN_0040c370(param_1,uVar4);
LAB_0040bd97:
  *(undefined4 *)(&DAT_00503f88 + iVar9) = 0x3e800000;
  *(int *)(&DAT_00503f60 + iVar9) = *(int *)(&DAT_00503f60 + iVar9) + -1;
  return 1;
}

