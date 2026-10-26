/*
 * FUN_00406be0 at 00406be0
 * undefined FUN_00406be0(void)
 * Address ranges: 00406be0-00406edd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00406be0(void)

{
  float fVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int *local_44;
  int *local_40;
  int local_34;
  int local_30;
  int local_28 [10];
  
  iVar9 = DAT_00508610;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = 0;
  local_28[8] = 0;
  local_34 = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[9] = 0;
  iVar4 = DAT_00508610;
  if (0 < DAT_00508610) {
    piVar7 = local_28;
    local_40 = &DAT_00508224;
    do {
      if (local_40[-0x19] == 0) {
        cVar3 = FUN_00417e90(local_34);
        iVar4 = DAT_0053be28;
        if (cVar3 == '\0') {
          iVar4 = local_40[-0x1a];
        }
        fVar1 = (float)*(int *)(DAT_00504f98 + 0x60 +
                               *(int *)(iVar4 * 0xd0 + 0x10 + DAT_0067ee20) * 0x6c);
        if (DAT_0053be50 == 0) {
          cVar3 = FUN_00417e90(local_34);
          iVar4 = DAT_0053be60;
          if (cVar3 == '\0') {
            iVar4 = local_40[-0x1b];
          }
          if (iVar4 < DAT_0053be60) {
            if (1.0 <= (float)DAT_0053be70 - fVar1) {
              FUN_004387e0(local_34,iVar9);
              goto LAB_00406cc7;
            }
            local_28[iVar9] = local_28[iVar9] + 1;
          }
          else {
            if (fVar1 - (float)DAT_0053be70 < 1.0) goto LAB_00406cc7;
            FUN_004387e0(iVar9,local_34);
            local_28[iVar9] = local_28[iVar9] + 1;
          }
        }
        else {
LAB_00406cc7:
          *piVar7 = *piVar7 + 1;
        }
        iVar8 = local_34 + 1;
        iVar4 = DAT_00508610;
        if (iVar8 < DAT_00508610) {
          local_44 = local_40 + 2;
          piVar6 = piVar7;
          do {
            piVar6 = piVar6 + 1;
            if (local_44[1] == 0) {
              cVar3 = FUN_00417e90(iVar8);
              iVar4 = DAT_0053be28;
              if (cVar3 == '\0') {
                iVar4 = *local_44;
              }
              fVar2 = (float)*(int *)(DAT_00504f98 + 0x60 +
                                     *(int *)(iVar4 * 0xd0 + 0x10 + DAT_0067ee20) * 0x6c);
              cVar3 = FUN_00417e90(local_34);
              if (cVar3 == '\0') {
                local_30 = local_40[-0x1b];
              }
              else {
                local_30 = DAT_0053be60;
              }
              cVar3 = FUN_00417e90(iVar8);
              iVar4 = DAT_0053be60;
              if (cVar3 == '\0') {
                iVar4 = local_44[-1];
              }
              if (local_30 < iVar4) {
                if (1.0 <= fVar2 - fVar1) {
                  FUN_004387e0(local_34,iVar8);
                  goto LAB_00406dde;
                }
              }
              else {
                if (fVar1 - fVar2 < 1.0) goto LAB_00406dde;
                FUN_004387e0(iVar8,local_34);
              }
              *piVar6 = *piVar6 + 1;
            }
            else {
LAB_00406dde:
              *piVar7 = *piVar7 + 1;
            }
            iVar8 = iVar8 + 1;
            local_44 = local_44 + 0x1c;
            iVar4 = DAT_00508610;
          } while (iVar8 < DAT_00508610);
        }
      }
      else {
        if ((DAT_0053be50 == 0) || (local_40[-0x1c] <= DAT_0053be58)) {
          local_28[iVar9] = local_28[iVar9] + 1;
        }
        else {
          *piVar7 = *piVar7 + 1;
        }
        if (local_34 + 1 < iVar4) {
          iVar8 = iVar4 - (local_34 + 1);
          piVar5 = local_40;
          piVar6 = piVar7;
          do {
            piVar6 = piVar6 + 1;
            if ((piVar5[3] == 0) || (local_40[-0x1c] <= *piVar5)) {
              *piVar6 = *piVar6 + 1;
            }
            else {
              *piVar7 = *piVar7 + 1;
            }
            piVar5 = piVar5 + 0x1c;
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
        }
      }
      local_34 = local_34 + 1;
      local_40 = local_40 + 0x1c;
      piVar7 = piVar7 + 1;
    } while (local_34 < iVar4);
  }
  iVar9 = 0;
  if (-1 < iVar4) {
    piVar7 = local_28;
    piVar6 = &DAT_005081b8;
    do {
      cVar3 = FUN_00417e90(iVar9);
      piVar5 = &DAT_0053be60;
      if (cVar3 == '\0') {
        piVar5 = piVar6;
      }
      iVar9 = iVar9 + 1;
      *piVar5 = *piVar7;
      piVar6 = piVar6 + 0x1c;
      piVar7 = piVar7 + 1;
    } while (iVar9 <= DAT_00508610);
  }
  return;
}

