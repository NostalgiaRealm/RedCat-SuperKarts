/*
 * FUN_004918f0 at 004918f0
 * undefined FUN_004918f0(void)
 * Address ranges: 004918f0-00491d2b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004918f0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_10;
  int local_8;
  int local_4;
  
  iVar4 = -1;
  iVar2 = 0;
  local_10 = -1;
  if (0 < DAT_0067ee24) {
    do {
      if (*(char *)(DAT_0067ee30 + iVar2) == '\x01') {
        iVar4 = iVar2;
      }
      iVar2 = iVar2 + 1;
      local_10 = iVar4;
    } while (iVar2 < DAT_0067ee24);
  }
  iVar2 = FUN_00497ab0(param_1,param_2,&param_2,&param_1,&local_8,&local_4);
  iVar6 = 0;
  iVar4 = DAT_0067ee20;
  if (-1 < local_10) {
    iVar5 = 0;
    do {
      if (*(int *)(iVar5 + 0x44 + iVar4) != 0) {
        if ((iVar5 < 0) || (DAT_0067ee24 <= iVar6)) {
          FUN_004afee0(s__s__d____T_ARRAY__get_used___ill_004e4300,
                       s_______Libs_Win3DLib_Include_arra_004fa4c0,0x43,iVar6,&DAT_0067ee34,
                       DAT_0067ee24,&DAT_0067ee4d);
          iVar4 = DAT_0067ee20;
        }
        if (*(char *)(DAT_0067ee30 + iVar6) != '\0') {
          iVar3 = *(int *)(iVar5 + 0x1c + iVar4);
          if (((param_2 <= iVar3) && (iVar3 <= param_1)) && (*(int *)(iVar5 + 0x3c + iVar4) != 0)) {
            iVar3 = *(int *)(iVar5 + 0xc + iVar4);
            iVar1 = *(int *)(DAT_006a5c38 + iVar3 + iVar3 * 0xa8);
            iVar3 = DAT_006a5c38 + iVar3 + iVar3 * 0xa8;
            if (iVar1 == 1) {
              iVar3 = *(int *)(iVar3 + 0x95);
            }
            else if (iVar1 == 2) {
              iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(iVar3 + 4) * 9 + 4 + DAT_006a5f78) +
                                       *(int *)(iVar3 + 8) * 4) * 0x10 + 4 + DAT_006a5f30);
            }
            else {
              FUN_004afee0(s___s___d_Invalid_object_type__004fa56c);
              iVar3 = 0;
              iVar4 = DAT_0067ee20;
            }
            if (*(int *)(DAT_006a5e80 + 0x44 + iVar3 * 0x48) != 0) {
              FUN_00490d40();
              iVar4 = DAT_0067ee20;
            }
          }
          if (((iVar2 != 0) && (iVar3 = *(int *)(iVar5 + 0x1c + iVar4), local_8 <= iVar3)) &&
             ((iVar3 <= local_4 && (*(int *)(iVar5 + 0x3c + iVar4) != 0)))) {
            iVar3 = *(int *)(iVar5 + 0xc + iVar4);
            iVar1 = *(int *)(DAT_006a5c38 + iVar3 + iVar3 * 0xa8);
            iVar3 = DAT_006a5c38 + iVar3 + iVar3 * 0xa8;
            if (iVar1 == 1) {
              iVar3 = *(int *)(iVar3 + 0x95);
            }
            else if (iVar1 == 2) {
              iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(iVar3 + 4) * 9 + 4 + DAT_006a5f78) +
                                       *(int *)(iVar3 + 8) * 4) * 0x10 + 4 + DAT_006a5f30);
            }
            else {
              FUN_004afee0(s___s___d_Invalid_object_type__004fa56c);
              iVar3 = 0;
              iVar4 = DAT_0067ee20;
            }
            if (*(int *)(DAT_006a5e80 + 0x44 + iVar3 * 0x48) != 0) {
              FUN_00490d40();
              iVar4 = DAT_0067ee20;
            }
          }
        }
      }
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 0xd0;
    } while (iVar6 <= local_10);
  }
  iVar6 = 0;
  if (-1 < local_10) {
    iVar5 = 0;
    do {
      if (*(int *)(iVar5 + 0x44 + iVar4) != 0) {
        if ((iVar5 < 0) || (DAT_0067ee24 <= iVar6)) {
          FUN_004afee0(s__s__d____T_ARRAY__get_used___ill_004e4300,
                       s_______Libs_Win3DLib_Include_arra_004fa4c0,0x43,iVar6,&DAT_0067ee34,
                       DAT_0067ee24,&DAT_0067ee4d);
          iVar4 = DAT_0067ee20;
        }
        if (*(char *)(DAT_0067ee30 + iVar6) != '\0') {
          iVar3 = *(int *)(iVar5 + 0x1c + iVar4);
          if (((param_2 <= iVar3) && (iVar3 <= param_1)) && (*(int *)(iVar5 + 0x3c + iVar4) != 0)) {
            if (*(int *)(iVar5 + 0x28 + iVar4) != -1) {
              FUN_004931a0(iVar6);
              iVar4 = DAT_0067ee20;
            }
            iVar3 = *(int *)(iVar5 + 0xc + iVar4);
            iVar1 = *(int *)(DAT_006a5c38 + iVar3 + iVar3 * 0xa8);
            iVar3 = DAT_006a5c38 + iVar3 + iVar3 * 0xa8;
            if (iVar1 == 1) {
              iVar3 = *(int *)(iVar3 + 0x95);
            }
            else if (iVar1 == 2) {
              iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(iVar3 + 4) * 9 + 4 + DAT_006a5f78) +
                                       *(int *)(iVar3 + 8) * 4) * 0x10 + 4 + DAT_006a5f30);
            }
            else {
              FUN_004afee0(s___s___d_Invalid_object_type__004fa56c);
              iVar3 = 0;
              iVar4 = DAT_0067ee20;
            }
            if (*(int *)(DAT_006a5e80 + 0x44 + iVar3 * 0x48) == 0) {
              FUN_00490d40();
              iVar4 = DAT_0067ee20;
            }
          }
          if (((iVar2 != 0) && (iVar3 = *(int *)(iVar5 + 0x1c + iVar4), local_8 <= iVar3)) &&
             ((iVar3 <= local_4 && (*(int *)(iVar5 + 0x3c + iVar4) != 0)))) {
            if (*(int *)(iVar5 + 0x28 + iVar4) != -1) {
              FUN_004931a0(iVar6);
              iVar4 = DAT_0067ee20;
            }
            iVar3 = *(int *)(iVar5 + 0xc + iVar4);
            iVar1 = *(int *)(DAT_006a5c38 + iVar3 + iVar3 * 0xa8);
            iVar3 = DAT_006a5c38 + iVar3 + iVar3 * 0xa8;
            if (iVar1 == 1) {
              iVar3 = *(int *)(iVar3 + 0x95);
            }
            else if (iVar1 == 2) {
              iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(iVar3 + 4) * 9 + 4 + DAT_006a5f78) +
                                       *(int *)(iVar3 + 8) * 4) * 0x10 + 4 + DAT_006a5f30);
            }
            else {
              FUN_004afee0(s___s___d_Invalid_object_type__004fa56c);
              iVar3 = 0;
              iVar4 = DAT_0067ee20;
            }
            if (*(int *)(DAT_006a5e80 + 0x44 + iVar3 * 0x48) == 0) {
              FUN_00490d40();
              iVar4 = DAT_0067ee20;
            }
          }
        }
      }
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 0xd0;
    } while (iVar6 <= local_10);
  }
  return;
}

