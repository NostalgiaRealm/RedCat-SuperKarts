/*
 * FUN_00456e20 at 00456e20
 * undefined FUN_00456e20(void)
 * Address ranges: 00456e20-004571ee
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00456e20(int param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 *puVar9;
  int *local_4;
  
  FUN_004575a0();
  piVar6 = (int *)*param_3;
  local_4 = param_3;
  if (piVar6 == DAT_00544a84) {
    piVar8 = (int *)param_3[2];
  }
  else {
    piVar2 = (int *)param_3[2];
    piVar8 = piVar6;
    if (piVar2 != DAT_00544a84) {
      for (piVar8 = (int *)*piVar2; piVar8 != DAT_00544a84; piVar8 = (int *)*piVar8) {
        piVar2 = piVar8;
      }
      piVar8 = (int *)piVar2[2];
      local_4 = piVar2;
      if (piVar2 != param_3) {
        piVar6[1] = (int)piVar2;
        *piVar2 = *param_3;
        if (piVar2 == (int *)param_3[2]) {
          piVar8[1] = (int)piVar2;
        }
        else {
          piVar8[1] = piVar2[1];
          *(int **)piVar2[1] = piVar8;
          piVar2[2] = param_3[2];
          *(int **)(param_3[2] + 4) = piVar2;
        }
        if (*(int **)(*(int *)(param_1 + 4) + 4) == param_3) {
          *(int **)(*(int *)(param_1 + 4) + 4) = piVar2;
        }
        else {
          puVar7 = (undefined4 *)param_3[1];
          if ((int *)*puVar7 == param_3) {
            *puVar7 = piVar2;
          }
          else {
            puVar7[2] = piVar2;
          }
        }
        local_4 = param_3;
        piVar2[1] = param_3[1];
        iVar1 = piVar2[5];
        piVar2[5] = param_3[5];
        param_3[5] = iVar1;
        goto LAB_00456f4f;
      }
    }
  }
  piVar8[1] = local_4[1];
  if (*(int **)(*(int *)(param_1 + 4) + 4) == param_3) {
    *(int **)(*(int *)(param_1 + 4) + 4) = piVar8;
  }
  else {
    puVar7 = (undefined4 *)param_3[1];
    if ((int *)*puVar7 == param_3) {
      *puVar7 = piVar8;
    }
    else {
      puVar7[2] = piVar8;
    }
  }
  piVar6 = *(int **)(param_1 + 4);
  if ((int *)*piVar6 == param_3) {
    if ((int *)param_3[2] == DAT_00544a84) {
      *piVar6 = param_3[1];
    }
    else {
      piVar3 = (int *)*piVar8;
      piVar2 = piVar8;
      while (piVar5 = piVar3, piVar5 != DAT_00544a84) {
        piVar2 = piVar5;
        piVar3 = (int *)*piVar5;
      }
      *piVar6 = (int)piVar2;
    }
  }
  if (*(int **)(*(int *)(param_1 + 4) + 8) == param_3) {
    if ((int *)*param_3 == DAT_00544a84) {
      piVar6 = (int *)param_3[1];
    }
    else {
      piVar2 = (int *)piVar8[2];
      piVar6 = piVar8;
      while (piVar3 = piVar2, piVar3 != DAT_00544a84) {
        piVar6 = piVar3;
        piVar2 = (int *)piVar3[2];
      }
    }
    *(int **)(*(int *)(param_1 + 4) + 8) = piVar6;
  }
LAB_00456f4f:
  if (local_4[5] == 1) {
    if (piVar8 != *(int **)(*(int *)(param_1 + 4) + 4)) {
      do {
        if (piVar8[5] != 1) break;
        piVar6 = *(int **)piVar8[1];
        if (piVar8 == piVar6) {
          piVar6 = (int *)((undefined4 *)piVar8[1])[2];
          if (piVar6[5] == 0) {
            piVar6[5] = 1;
            *(undefined4 *)(piVar8[1] + 0x14) = 0;
            iVar1 = piVar8[1];
            piVar6 = *(int **)(iVar1 + 8);
            *(int *)(iVar1 + 8) = *piVar6;
            if ((int *)*piVar6 != DAT_00544a84) {
              ((int *)*piVar6)[1] = iVar1;
            }
            piVar6[1] = *(int *)(iVar1 + 4);
            if (iVar1 == *(int *)(*(int *)(param_1 + 4) + 4)) {
              *(int **)(*(int *)(param_1 + 4) + 4) = piVar6;
            }
            else {
              piVar2 = *(int **)(iVar1 + 4);
              if (iVar1 == *piVar2) {
                *piVar2 = (int)piVar6;
              }
              else {
                piVar2[2] = (int)piVar6;
              }
            }
            *piVar6 = iVar1;
            *(int **)(iVar1 + 4) = piVar6;
            piVar6 = *(int **)(piVar8[1] + 8);
          }
          if ((*(int *)(*piVar6 + 0x14) != 1) || (*(int *)(piVar6[2] + 0x14) != 1)) {
            if (*(int *)(piVar6[2] + 0x14) == 1) {
              *(undefined4 *)(*piVar6 + 0x14) = 1;
              iVar1 = *piVar6;
              piVar6[5] = 0;
              *piVar6 = *(int *)(iVar1 + 8);
              if (*(int **)(iVar1 + 8) != DAT_00544a84) {
                (*(int **)(iVar1 + 8))[1] = (int)piVar6;
              }
              *(int *)(iVar1 + 4) = piVar6[1];
              if (piVar6 == *(int **)(*(int *)(param_1 + 4) + 4)) {
                *(int *)(*(int *)(param_1 + 4) + 4) = iVar1;
              }
              else {
                piVar2 = (int *)piVar6[1];
                if (piVar6 == (int *)piVar2[2]) {
                  piVar2[2] = iVar1;
                }
                else {
                  *piVar2 = iVar1;
                }
              }
              *(int **)(iVar1 + 8) = piVar6;
              piVar6[1] = iVar1;
              piVar6 = *(int **)(piVar8[1] + 8);
            }
            piVar6[5] = *(int *)(piVar8[1] + 0x14);
            *(undefined4 *)(piVar8[1] + 0x14) = 1;
            *(undefined4 *)(piVar6[2] + 0x14) = 1;
            puVar7 = (undefined4 *)piVar8[1];
            puVar9 = (undefined4 *)puVar7[2];
            puVar7[2] = *puVar9;
            if ((int *)*puVar9 != DAT_00544a84) {
              ((int *)*puVar9)[1] = (int)puVar7;
            }
            puVar9[1] = puVar7[1];
            if (puVar7 == *(undefined4 **)(*(int *)(param_1 + 4) + 4)) {
              *(undefined4 **)(*(int *)(param_1 + 4) + 4) = puVar9;
              *puVar9 = puVar7;
            }
            else {
              piVar6 = (int *)puVar7[1];
              if (puVar7 == (undefined4 *)*piVar6) {
                *piVar6 = (int)puVar9;
                *puVar9 = puVar7;
              }
              else {
                piVar6[2] = (int)puVar9;
                *puVar9 = puVar7;
              }
            }
LAB_004571c3:
            puVar7[1] = puVar9;
            break;
          }
        }
        else {
          if (piVar6[5] == 0) {
            piVar6[5] = 1;
            *(undefined4 *)(piVar8[1] + 0x14) = 0;
            piVar6 = (int *)piVar8[1];
            iVar1 = *piVar6;
            *piVar6 = *(int *)(iVar1 + 8);
            if (*(int **)(iVar1 + 8) != DAT_00544a84) {
              (*(int **)(iVar1 + 8))[1] = (int)piVar6;
            }
            *(int *)(iVar1 + 4) = piVar6[1];
            if (piVar6 == *(int **)(*(int *)(param_1 + 4) + 4)) {
              *(int *)(*(int *)(param_1 + 4) + 4) = iVar1;
            }
            else {
              piVar2 = (int *)piVar6[1];
              if (piVar6 == (int *)piVar2[2]) {
                piVar2[2] = iVar1;
              }
              else {
                *piVar2 = iVar1;
              }
            }
            *(int **)(iVar1 + 8) = piVar6;
            piVar6[1] = iVar1;
            piVar6 = *(int **)piVar8[1];
          }
          if ((*(int *)(piVar6[2] + 0x14) != 1) || (*(int *)(*piVar6 + 0x14) != 1)) {
            if (*(int *)(*piVar6 + 0x14) == 1) {
              *(undefined4 *)(piVar6[2] + 0x14) = 1;
              piVar2 = (int *)piVar6[2];
              piVar6[5] = 0;
              piVar6[2] = *piVar2;
              if ((int *)*piVar2 != DAT_00544a84) {
                ((int *)*piVar2)[1] = (int)piVar6;
              }
              piVar2[1] = piVar6[1];
              if (piVar6 == *(int **)(*(int *)(param_1 + 4) + 4)) {
                *(int **)(*(int *)(param_1 + 4) + 4) = piVar2;
              }
              else {
                piVar3 = (int *)piVar6[1];
                if (piVar6 == (int *)*piVar3) {
                  *piVar3 = (int)piVar2;
                }
                else {
                  piVar3[2] = (int)piVar2;
                }
              }
              *piVar2 = (int)piVar6;
              piVar6[1] = (int)piVar2;
              piVar6 = *(int **)piVar8[1];
            }
            piVar6[5] = *(int *)(piVar8[1] + 0x14);
            *(undefined4 *)(piVar8[1] + 0x14) = 1;
            *(undefined4 *)(*piVar6 + 0x14) = 1;
            puVar7 = (undefined4 *)piVar8[1];
            puVar9 = (undefined4 *)*puVar7;
            *puVar7 = puVar9[2];
            if ((int *)puVar9[2] != DAT_00544a84) {
              ((int *)puVar9[2])[1] = (int)puVar7;
            }
            puVar9[1] = puVar7[1];
            if (puVar7 == *(undefined4 **)(*(int *)(param_1 + 4) + 4)) {
              *(undefined4 **)(*(int *)(param_1 + 4) + 4) = puVar9;
            }
            else {
              puVar4 = (undefined4 *)puVar7[1];
              if (puVar7 == (undefined4 *)puVar4[2]) {
                puVar4[2] = puVar9;
              }
              else {
                *puVar4 = puVar9;
              }
            }
            puVar9[2] = puVar7;
            goto LAB_004571c3;
          }
        }
        piVar6[5] = 0;
        piVar8 = (int *)piVar8[1];
      } while (piVar8 != *(int **)(*(int *)(param_1 + 4) + 4));
    }
    piVar8[5] = 1;
  }
  FUN_004bc150(local_4);
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -1;
  *param_2 = param_3;
  return;
}

