/*
 * FUN_004561e0 at 004561e0
 * undefined FUN_004561e0(void)
 * Address ranges: 004561e0-0045634d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004561e0(int param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int local_28 [10];
  
  if (param_1 == -1) {
    param_1 = DAT_00508610;
  }
  cVar1 = FUN_00417e90(param_1);
  iVar7 = DAT_0053be28;
  if (cVar1 == '\0') {
    iVar7 = (&DAT_005081bc)[param_1 * 0x1c];
  }
  iVar7 = *(int *)(iVar7 * 0xd0 + 0x1c + DAT_0067ee20);
  cVar1 = FUN_00417e90(param_1);
  iVar9 = DAT_0053be28;
  if (cVar1 == '\0') {
    iVar9 = (&DAT_005081bc)[param_1 * 0x1c];
  }
  cVar1 = FUN_00415be0(iVar9);
  iVar9 = 0;
  if (-1 < DAT_00508610) {
    piVar8 = local_28;
    piVar6 = &DAT_005081bc;
    do {
      cVar2 = FUN_00417e90(iVar9);
      iVar3 = DAT_0053be28;
      if (cVar2 == '\0') {
        iVar3 = *piVar6;
      }
      iVar3 = *(int *)(iVar3 * 0xd0 + 0x1c + DAT_0067ee20);
      if (cVar1 == '\x01') {
        iVar5 = iVar3 - iVar7;
        *piVar8 = iVar5;
        if (iVar3 < iVar7) {
LAB_004562c6:
          *piVar8 = *(int *)(DAT_00680b70 + 8) + iVar5;
        }
      }
      else {
        iVar5 = iVar7 - iVar3;
        *piVar8 = iVar5;
        if (iVar7 < iVar3) goto LAB_004562c6;
      }
      iVar9 = iVar9 + 1;
      piVar6 = piVar6 + 0x1c;
      piVar8 = piVar8 + 1;
    } while (iVar9 <= DAT_00508610);
  }
  iVar3 = 0;
  iVar9 = 0x7fffffff;
  iVar7 = -2;
  if (-1 < DAT_00508610) {
    piVar8 = local_28;
    do {
      iVar5 = *piVar8;
      if (((iVar5 < iVar9) && (iVar3 != param_1)) && (1 < iVar5)) {
        iVar7 = iVar3;
        iVar9 = iVar5;
      }
      iVar3 = iVar3 + 1;
      piVar8 = piVar8 + 1;
    } while (iVar3 <= DAT_00508610);
  }
  uVar4 = FUN_0044fbc0();
  uVar4 = FUN_0044fb50(uVar4);
  iVar3 = FUN_00456ad0(uVar4);
  if ((iVar9 <= *(int *)(iVar3 + 0xc)) || (iVar9 = -2, *(int *)(iVar3 + 0xc) < 2)) {
    iVar9 = iVar7;
  }
  return iVar9;
}

