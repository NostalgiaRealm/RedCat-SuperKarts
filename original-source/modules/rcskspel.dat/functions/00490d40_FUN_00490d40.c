/*
 * FUN_00490d40 at 00490d40
 * undefined FUN_00490d40(void)
 * Address ranges: 00490d40-00491192
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00490d40(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int *local_4c;
  int local_48;
  undefined1 local_40 [64];
  
  iVar3 = *(int *)(param_1 + 0xcc);
  if ((iVar3 == -1) || (*(int *)(param_1 + 200) == -1)) {
    iVar3 = *(int *)(param_1 + 0xc);
    iVar6 = *(int *)(DAT_006a5c38 + iVar3 + iVar3 * 0xa8);
    iVar3 = DAT_006a5c38 + iVar3 + iVar3 * 0xa8;
    if (iVar6 == 1) {
      uVar4 = *(undefined4 *)(iVar3 + 0x95);
    }
    else if (iVar6 == 2) {
      uVar4 = *(undefined4 *)
               (*(int *)(*(int *)(*(int *)(iVar3 + 4) * 9 + 4 + DAT_006a5f78) +
                        *(int *)(iVar3 + 8) * 4) * 0x10 + 4 + DAT_006a5f30);
    }
    else {
      FUN_004afee0(s___s___d_Invalid_object_type__004fa56c);
      uVar4 = 0;
    }
    FUN_0049c890(uVar4);
    if ((*(byte *)(param_1 + 4) & 2) != 0) {
      FUN_004903c0();
    }
    iVar3 = DAT_006a5c38 + *(int *)(param_1 + 0xc) * 0xa9;
    if (*(int *)(iVar3 + 0xa5) == 0) {
      if (*(char *)(iVar3 + 0x90) != '\0') {
        FUN_004a0d80();
      }
    }
    else {
      FUN_0048f5b0(*(int *)(param_1 + 0xc));
    }
    iVar6 = *(int *)(param_1 + 0xc);
    iVar3 = DAT_006a5c38 + iVar6 + iVar6 * 0xa8;
    iVar6 = *(int *)(DAT_006a5c38 + iVar6 + 0x99 + iVar6 * 0xa8);
    if (iVar6 == -1) {
      iVar6 = *(int *)(*(int *)(*(int *)(*(int *)(iVar3 + 4) * 9 + 4 + DAT_006a5f78) +
                               *(int *)(iVar3 + 8) * 4) * 0x10 + DAT_006a5f30);
    }
    piVar1 = (int *)(DAT_006a5ee0 + 0x9c + iVar6 * 0xbc);
    DAT_0067ee68 = DAT_0067ee68 + *piVar1 / 3;
    DAT_0067ee6c = DAT_0067ee6c + *piVar1;
  }
  else {
    iVar6 = *(int *)(param_1 + 0xc);
    iVar2 = *(int *)(DAT_006a5c38 + iVar6 + iVar6 * 0xa8);
    iVar6 = DAT_006a5c38 + iVar6 + iVar6 * 0xa8;
    if (iVar2 == 1) {
      uVar4 = *(undefined4 *)(iVar6 + 0x99);
      *(int *)(iVar6 + 0x99) = iVar3;
      if ((*(byte *)(param_1 + 4) & 2) != 0) {
        FUN_004903c0();
      }
      iVar3 = DAT_006a5c38 + *(int *)(param_1 + 0xc) * 0xa9;
      if (*(int *)(iVar3 + 0xa5) == 0) {
        if (*(char *)(iVar3 + 0x90) != '\0') {
          FUN_004a0d80();
        }
      }
      else {
        FUN_0048f5b0(*(int *)(param_1 + 0xc));
      }
      iVar6 = *(int *)(param_1 + 0xc);
      iVar3 = DAT_006a5c38 + iVar6 + iVar6 * 0xa8;
      iVar6 = *(int *)(DAT_006a5c38 + iVar6 + 0x99 + iVar6 * 0xa8);
      if (iVar6 == -1) {
        iVar6 = *(int *)(*(int *)(*(int *)(*(int *)(iVar3 + 4) * 9 + 4 + DAT_006a5f78) +
                                 *(int *)(iVar3 + 8) * 4) * 0x10 + DAT_006a5f30);
      }
      piVar1 = (int *)(DAT_006a5ee0 + 0x9c + iVar6 * 0xbc);
      DAT_0067ee68 = DAT_0067ee68 + *piVar1 / 3;
      DAT_0067ee6c = DAT_0067ee6c + *piVar1;
      *(undefined4 *)(DAT_006a5c38 + *(int *)(param_1 + 0xc) * 0xa9 + 0x99) = uVar4;
    }
    else if (iVar2 == 2) {
      *(int *)(iVar6 + 0x99) = iVar3;
      if ((*(byte *)(param_1 + 4) & 2) != 0) {
        FUN_004903c0();
      }
      iVar3 = DAT_006a5c38 + *(int *)(param_1 + 0xc) * 0xa9;
      if (*(int *)(iVar3 + 0xa5) == 0) {
        if (*(char *)(iVar3 + 0x90) != '\0') {
          FUN_004a0d80();
        }
      }
      else {
        FUN_0048f5b0(*(int *)(param_1 + 0xc));
      }
      iVar6 = *(int *)(param_1 + 0xc);
      iVar3 = DAT_006a5c38 + iVar6 + iVar6 * 0xa8;
      iVar6 = *(int *)(DAT_006a5c38 + iVar6 + 0x99 + iVar6 * 0xa8);
      if (iVar6 == -1) {
        iVar6 = *(int *)(*(int *)(*(int *)(*(int *)(iVar3 + 4) * 9 + 4 + DAT_006a5f78) +
                                 *(int *)(iVar3 + 8) * 4) * 0x10 + DAT_006a5f30);
      }
      piVar1 = (int *)(DAT_006a5ee0 + 0x9c + iVar6 * 0xbc);
      DAT_0067ee68 = DAT_0067ee68 + *piVar1 / 3;
      DAT_0067ee6c = DAT_0067ee6c + *piVar1;
      *(undefined4 *)(DAT_006a5c38 + *(int *)(param_1 + 0xc) * 0xa9 + 0x99) = 0xffffffff;
    }
  }
  local_48 = 0;
  if (0 < *(int *)(param_1 + 0x8c)) {
    local_4c = (int *)(param_1 + 100);
    do {
      iVar3 = *local_4c;
      puVar7 = (undefined4 *)(iVar3 * 0xa9 + 0x10 + DAT_006a5c38);
      puVar5 = (undefined4 *)
               FUN_004a2560(local_40,DAT_006a5c38 + *(int *)(param_1 + 0xc) * 0xa9 + 0x10,puVar7);
      for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar7 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
      }
      iVar6 = iVar3 * 0xa9 + DAT_006a5c38;
      if (*(int *)(iVar6 + 0xa5) == 0) {
        if (*(char *)(iVar6 + 0x90) != '\0') {
          FUN_004a0d80();
        }
      }
      else {
        FUN_0048f5b0(iVar3);
      }
      FUN_0048f910(iVar3);
      local_48 = local_48 + 1;
      local_4c = local_4c + 1;
    } while (local_48 < *(int *)(param_1 + 0x8c));
  }
  return;
}

