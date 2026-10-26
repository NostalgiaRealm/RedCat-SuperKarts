/*
 * FUN_004916f0 at 004916f0
 * undefined FUN_004916f0(void)
 * Address ranges: 004916f0-004918e3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004916f0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_8;
  int local_4;
  
  iVar2 = 0;
  iVar4 = -1;
  if (0 < DAT_0067ee24) {
    do {
      if (*(char *)(DAT_0067ee30 + iVar2) == '\x01') {
        iVar4 = iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_0067ee24);
  }
  iVar3 = FUN_00497ab0(param_1,param_2,&param_2,&param_1,&local_8,&local_4);
  iVar5 = 0;
  iVar2 = DAT_0067ee20;
  if (-1 < iVar4) {
    iVar6 = 0;
    do {
      if (*(int *)(iVar6 + 0x44 + iVar2) != 0) {
        if ((iVar6 < 0) || (DAT_0067ee24 <= iVar5)) {
          FUN_004afee0(s__s__d____T_ARRAY__get_used___ill_004e4300,
                       s_______Libs_Win3DLib_Include_arra_004fa4c0,0x43,iVar5,&DAT_0067ee34,
                       DAT_0067ee24,&DAT_0067ee4d);
          iVar2 = DAT_0067ee20;
        }
        if (*(char *)(DAT_0067ee30 + iVar5) != '\0') {
          iVar1 = *(int *)(iVar6 + 0x1c + iVar2);
          if ((((param_2 <= iVar1) && (iVar1 <= param_1)) && (*(int *)(iVar6 + 0x3c + iVar2) != 0))
             && (*(int *)(iVar6 + 0x28 + iVar2) != -1)) {
            FUN_004931a0(iVar5);
            iVar2 = DAT_0067ee20;
          }
          if (((iVar3 != 0) && (iVar1 = *(int *)(iVar6 + 0x1c + iVar2), local_8 <= iVar1)) &&
             ((iVar1 <= local_4 &&
              ((*(int *)(iVar6 + 0x3c + iVar2) != 0 && (*(int *)(iVar6 + 0x28 + iVar2) != -1)))))) {
            FUN_004931a0(iVar5);
            iVar2 = DAT_0067ee20;
          }
        }
      }
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + 0xd0;
    } while (iVar5 <= iVar4);
  }
  iVar5 = 0;
  if (-1 < iVar4) {
    iVar6 = 0;
    do {
      if (*(int *)(iVar6 + 0x44 + iVar2) != 0) {
        if ((iVar6 < 0) || (DAT_0067ee24 <= iVar5)) {
          FUN_004afee0(s__s__d____T_ARRAY__get_used___ill_004e4300,
                       s_______Libs_Win3DLib_Include_arra_004fa4c0,0x43,iVar5,&DAT_0067ee34,
                       DAT_0067ee24,&DAT_0067ee4d);
          iVar2 = DAT_0067ee20;
        }
        if (*(char *)(DAT_0067ee30 + iVar5) != '\0') {
          iVar1 = *(int *)(iVar6 + 0x1c + iVar2);
          if (((param_2 <= iVar1) && (iVar1 <= param_1)) && (*(int *)(iVar6 + iVar2 + 0x3c) != 0)) {
            FUN_00490d40();
            iVar2 = DAT_0067ee20;
          }
          if (iVar3 != 0) {
            iVar1 = *(int *)(iVar6 + 0x1c + iVar2);
            if (((local_8 <= iVar1) && (iVar1 <= local_4)) && (*(int *)(iVar6 + iVar2 + 0x3c) != 0))
            {
              FUN_00490d40();
              iVar2 = DAT_0067ee20;
            }
          }
        }
      }
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + 0xd0;
    } while (iVar5 <= iVar4);
  }
  return;
}

