/*
 * FUN_00491d30 at 00491d30
 * undefined FUN_00491d30(void)
 * Address ranges: 00491d30-0049246b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00491d30(float param_1,float param_2,int param_3)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  float10 fVar7;
  float fVar8;
  undefined4 uVar9;
  undefined4 local_48;
  float fStack_44;
  float fStack_40;
  int iStack_3c;
  float fStack_38;
  float fStack_34;
  float local_30;
  int iStack_2c;
  int iStack_28;
  int *local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined1 auStack_c [12];
  
  local_48 = 0;
  fVar7 = (float10)FUN_0048f4e0();
  local_30 = (float)fVar7;
  _DAT_0067ee70 = _DAT_0067ee70 + 1.0;
  fVar7 = (float10)FUN_0048f4e0();
  _DAT_0067ee74 = (float)(fVar7 + (float10)_DAT_0067ee74);
  local_18 = FUN_00497b30(param_1,param_2,&local_20,&local_1c,&local_14,&local_10);
  local_24 = &DAT_0067ee7c;
  iVar5 = DAT_0067ee20;
  do {
    piVar6 = local_24;
    if (local_24[-1] != 0) {
      iVar1 = *local_24;
      iVar4 = iVar1 * 0xd0;
      if (*(int *)(iVar4 + 0x44 + iVar5) != 0) {
        if ((iVar1 < 0) || (DAT_0067ee24 <= iVar1)) {
          FUN_004afee0(s__s__d____T_ARRAY__get_used___ill_004e4300,
                       s_______Libs_Win3DLib_Include_arra_004fa4c0,0x43,iVar1,&DAT_0067ee34,
                       DAT_0067ee24,&DAT_0067ee4d);
          iVar5 = DAT_0067ee20;
        }
        if ((*(char *)(DAT_0067ee30 + iVar1) != '\0') && (*(int *)(iVar4 + iVar5) == 1)) {
          iStack_28 = __ftol();
          *(float *)(iVar4 + 0x9c + iVar5) = (float)iStack_28 * 0.0001;
          iVar5 = DAT_0067ee20;
          iVar3 = __ftol();
          *(float *)(iVar4 + 0xa4 + iVar5) = (float)iVar3 * 0.0001;
          iStack_28 = *(int *)(iVar4 + 0x1c + DAT_0067ee20);
          if ((iVar1 == DAT_00680ad8) ||
             (((*(byte *)(iVar4 + 4 + DAT_0067ee20) & 4) != 0 &&
              (fVar7 = (float10)FUN_0048f4e0(), (float10)0.0666 < fVar7)))) {
            param_2 = local_30 * 0.125;
            iVar5 = 8;
          }
          else {
            iVar5 = 1;
            param_2 = local_30;
          }
          iStack_3c = iVar5;
          if (((local_20 <= iStack_28) && (iStack_28 <= local_1c)) ||
             (*(int *)(iVar4 + 0x50 + DAT_0067ee20) != 0)) {
            FUN_00493860(iVar1);
            if (iVar5 != 0) {
              do {
                iStack_2c = iVar5;
                if ((DAT_00680ad0 == 0) || ((*(byte *)(iVar4 + 4 + DAT_0067ee20) & 8) != 0)) {
                  local_48 = 0;
                  param_1 = 1.0;
                }
                else {
                  fVar7 = (float10)FUN_00499c30(iVar1,&local_48,param_2);
                  param_1 = (float)fVar7;
                }
                if ((((*(byte *)(iVar4 + 4 + DAT_0067ee20) & 4) == 0) && (iVar1 != DAT_00680ad8)) ||
                   ((DAT_00680ad0 == 0 ||
                    (iVar5 = FUN_00492470(iVar1,param_2,auStack_c,param_1,&local_48), iVar5 == 0))))
                {
                  fStack_40 = param_2;
                  if (param_2 < 0.0) {
                    fStack_40 = 0.0;
                  }
                  if ((*(byte *)(iVar4 + 4 + DAT_0067ee20) & 4) == 0) {
                    uVar9 = 0;
                    fVar8 = fStack_40;
                    goto LAB_00492047;
                  }
                  FUN_004929b0(iVar1,fStack_40,param_1,local_48,0,auStack_c);
                }
                else {
                  fStack_44 = param_2;
                  if (param_2 < 0.0) {
                    fStack_44 = 0.0;
                  }
                  if ((*(byte *)(iVar4 + 4 + DAT_0067ee20) & 4) == 0) {
                    uVar9 = 1;
                    fVar8 = fStack_44;
LAB_00492047:
                    FUN_004911a0(fVar8,param_1,local_48,uVar9,auStack_c);
                  }
                  else {
                    FUN_004929b0(iVar1,fStack_44,param_1,local_48,1,auStack_c);
                  }
                }
                FUN_004a09e0();
                FUN_0049c4f0();
                iVar5 = FUN_0049c6e0();
                if (iVar5 == 0) {
                  *(undefined4 *)(iVar4 + 0x4c + DAT_0067ee20) = 0;
                }
                else {
                  pcVar2 = *(code **)(iVar4 + 0x5c + DAT_0067ee20);
                  if ((pcVar2 != (code *)0x0) && (*(int *)(iVar4 + 0x4c + DAT_0067ee20) == 0)) {
                    (*pcVar2)(iVar1);
                  }
                  *(undefined4 *)(iVar4 + 0x4c + DAT_0067ee20) = 1;
                  *(undefined4 *)(DAT_006a5b60 * 0xd0 + 0x4c + DAT_0067ee20) = 1;
                  if (DAT_006a5b5c == 1) {
                    iVar5 = DAT_006a5b64 * 0xd0 + DAT_0067ee20;
                    pcVar2 = *(code **)(iVar5 + 0x5c);
                    if ((pcVar2 != (code *)0x0) && (*(int *)(iVar5 + 0x4c) == 0)) {
                      (*pcVar2)(DAT_006a5b64);
                      *(undefined4 *)(DAT_006a5b64 * 0xd0 + 0x4c + DAT_0067ee20) = 1;
                    }
                  }
                }
                iVar5 = iStack_2c + -1;
              } while (iStack_2c + -1 != 0);
              iStack_2c = 0;
              iVar5 = iStack_3c;
            }
            FUN_004932e0(iVar1);
            if (iVar1 == param_3) {
              if ((*(byte *)(iVar4 + 4 + DAT_0067ee20) & 1) != 0) {
                uVar9 = 1;
LAB_0049215b:
                FUN_004937e0(iVar1,uVar9);
              }
            }
            else if ((*(byte *)(iVar4 + 4 + DAT_0067ee20) & 1) != 0) {
              uVar9 = 0;
              goto LAB_0049215b;
            }
            FUN_004936a0(iVar1);
          }
          if ((((local_18 != 0) && (*(int *)(iVar4 + 0x50 + DAT_0067ee20) == 0)) &&
              (local_14 <= iStack_28)) && (iStack_28 <= local_10)) {
            FUN_00493860(iVar1);
            iVar3 = iStack_3c;
            if (0 < iVar5) {
              do {
                if ((DAT_00680ad0 == 0) || ((*(byte *)(iVar4 + 4 + DAT_0067ee20) & 8) != 0)) {
                  local_48 = 0;
                  param_1 = 1.0;
                }
                else {
                  fVar7 = (float10)FUN_00499c30(iVar1,&local_48,param_2);
                  param_1 = (float)fVar7;
                }
                if ((((*(byte *)(iVar4 + 4 + DAT_0067ee20) & 4) == 0) && (iVar1 != DAT_00680ad8)) ||
                   ((DAT_00680ad0 == 0 ||
                    (iVar5 = FUN_00492470(iVar1,param_2,auStack_c,param_1,&local_48), iVar5 == 0))))
                {
                  fStack_34 = param_2;
                  if (param_2 < 0.0) {
                    fStack_34 = 0.0;
                  }
                  if ((*(byte *)(iVar4 + 4 + DAT_0067ee20) & 4) == 0) {
                    uVar9 = 0;
                    fVar8 = fStack_34;
                    goto LAB_00492306;
                  }
                  FUN_004929b0(iVar1,fStack_34,param_1,local_48,0,auStack_c);
                }
                else {
                  fStack_38 = param_2;
                  if (param_2 < 0.0) {
                    fStack_38 = 0.0;
                  }
                  if ((*(byte *)(iVar4 + 4 + DAT_0067ee20) & 4) == 0) {
                    uVar9 = 1;
                    fVar8 = fStack_38;
LAB_00492306:
                    FUN_004911a0(fVar8,param_1,local_48,uVar9,auStack_c);
                  }
                  else {
                    FUN_004929b0(iVar1,fStack_38,param_1,local_48,1,auStack_c);
                  }
                }
                FUN_004a09e0();
                FUN_0049c4f0();
                iVar5 = FUN_0049c6e0();
                if (iVar5 == 0) {
                  *(undefined4 *)(iVar4 + 0x4c + DAT_0067ee20) = 0;
                }
                else {
                  pcVar2 = *(code **)(iVar4 + 0x5c + DAT_0067ee20);
                  if ((pcVar2 != (code *)0x0) && (*(int *)(iVar4 + 0x4c + DAT_0067ee20) == 0)) {
                    (*pcVar2)(iVar1);
                  }
                  *(undefined4 *)(iVar4 + 0x4c + DAT_0067ee20) = 1;
                  *(undefined4 *)(DAT_006a5b60 * 0xd0 + 0x4c + DAT_0067ee20) = 1;
                  if (DAT_006a5b5c == 1) {
                    iVar5 = DAT_006a5b64 * 0xd0 + DAT_0067ee20;
                    pcVar2 = *(code **)(iVar5 + 0x5c);
                    if ((pcVar2 != (code *)0x0) && (*(int *)(iVar5 + 0x4c) == 0)) {
                      (*pcVar2)(DAT_006a5b64);
                      *(undefined4 *)(DAT_006a5b64 * 0xd0 + 0x4c + DAT_0067ee20) = 1;
                    }
                  }
                }
                iVar3 = iVar3 + -1;
              } while (iVar3 != 0);
            }
            FUN_004932e0(iVar1);
            if (iVar1 == param_3) {
              if ((*(byte *)(iVar4 + 4 + DAT_0067ee20) & 1) != 0) {
                uVar9 = 1;
LAB_00492413:
                FUN_004937e0(iVar1,uVar9);
              }
            }
            else if ((*(byte *)(iVar4 + 4 + DAT_0067ee20) & 1) != 0) {
              uVar9 = 0;
              goto LAB_00492413;
            }
            FUN_004936a0(iVar1);
          }
          iVar5 = DAT_0067ee20;
          *(undefined4 *)(iVar4 + 0xb4 + DAT_0067ee20) = 0;
          *(undefined4 *)(iVar4 + 0xb8 + iVar5) = 0;
          iVar4 = iVar4 + iVar5;
          *(undefined4 *)(iVar4 + 0xbc) = 0;
          *(undefined4 *)(iVar4 + 0xc0) = 0;
          iVar5 = DAT_0067ee20;
          piVar6 = local_24;
        }
      }
    }
    local_24 = piVar6 + 2;
    if (0x67fe1b < (int)local_24) {
      return;
    }
  } while( true );
}

