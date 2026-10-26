/*
 * FUN_00415dd0 at 00415dd0
 * undefined FUN_00415dd0(void)
 * Address ranges: 00415dd0-00415f75
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00415dd0(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  iVar7 = DAT_00680b2c;
  local_1c = 0;
  local_10 = 0;
  iVar8 = DAT_00508610;
  if (0 < DAT_00680b2c) {
    local_c = 0;
    do {
      local_14 = 0;
      iVar2 = *(int *)(local_c + 0xe8 + DAT_00680b28);
      if (0 < iVar2) {
        local_18 = local_c + 0x154;
        do {
          iVar10 = *(int *)(local_18 + DAT_00680b28) * 0x50;
          iVar3 = *(int *)(iVar10 + 4 + DAT_00680ae0);
          if (DAT_00507f40 == '\0') {
            iVar4 = 0;
            if (0 < iVar8 + 1) {
              piVar6 = &DAT_006b6a20;
              do {
                iVar9 = iVar4 + 0x45;
                iVar4 = iVar4 + 1;
                *piVar6 = iVar9;
                piVar6 = piVar6 + 1;
              } while (iVar4 < iVar8 + 1);
            }
          }
          if (iVar3 != -1) {
            iVar4 = 0;
            if (0 < iVar8 + 1) {
              piVar6 = &DAT_006b6a20;
              do {
                if (iVar3 == *piVar6) goto LAB_00415e93;
                iVar4 = iVar4 + 1;
                piVar6 = piVar6 + 1;
              } while (iVar4 < iVar8 + 1);
            }
          }
          iVar4 = iVar8 + 1;
LAB_00415e93:
          if ((-1 < iVar4) && (iVar4 < iVar8 + 1)) {
            iVar9 = iVar4 * 0x14;
            local_1c = local_1c + 1;
            (&DAT_005072c0)[iVar4 * 5] = (&DAT_005072c0)[iVar4 * 5] + 1;
            uVar5 = FUN_00493a20(local_10);
            iVar3 = DAT_00680ae0;
            *(undefined4 *)(&DAT_005072c4 + iVar9) = uVar5;
            iVar8 = DAT_00508610;
            puVar1 = (undefined4 *)(iVar10 + 8 + iVar3);
            *(undefined4 *)(&DAT_005072c8 + iVar9) = *puVar1;
            *(undefined4 *)(&DAT_005072cc + iVar9) = puVar1[1];
            *(undefined4 *)(&DAT_005072d0 + iVar9) = puVar1[2];
            if (local_1c == iVar8 + 1) goto LAB_00415f3d;
          }
          local_14 = local_14 + 1;
          local_18 = local_18 + 4;
        } while (local_14 < iVar2);
      }
      local_10 = local_10 + 1;
      local_c = local_c + 0x984;
    } while (local_10 < iVar7);
  }
LAB_00415f3d:
  iVar7 = 0;
  DAT_005072b8 = 1;
  if (0 < iVar8 + 1) {
    piVar6 = &DAT_005072c0;
    while (*piVar6 == 1) {
      iVar7 = iVar7 + 1;
      piVar6 = piVar6 + 5;
      if (iVar8 + 1 <= iVar7) {
        DAT_005072b8 = 1;
        return;
      }
    }
    DAT_005072b8 = 0;
  }
  return;
}

