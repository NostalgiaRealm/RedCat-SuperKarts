/*
 * FUN_00491530 at 00491530
 * undefined FUN_00491530(void)
 * Address ranges: 00491530-0049166f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00491530(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  iVar3 = 0;
  iVar5 = -1;
  if (0 < DAT_0067ee24) {
    do {
      if (*(char *)(DAT_0067ee30 + iVar3) == '\x01') {
        iVar5 = iVar3;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_0067ee24);
  }
  iVar3 = FUN_00497b30(param_1,param_2,&local_10,&local_c,&local_8,&local_4);
  iVar6 = 0;
  if (-1 < iVar5) {
    iVar7 = 0;
    iVar4 = DAT_0067ee20;
    do {
      if (*(int *)(iVar7 + 0x44 + iVar4) != 0) {
        if ((iVar7 < 0) || (DAT_0067ee24 <= iVar6)) {
          FUN_004afee0(s__s__d____T_ARRAY__get_used___ill_004e4300,
                       s_______Libs_Win3DLib_Include_arra_004fa4c0,0x43,iVar6,&DAT_0067ee34,
                       DAT_0067ee24,&DAT_0067ee4d);
          iVar4 = DAT_0067ee20;
        }
        if (*(char *)(DAT_0067ee30 + iVar6) != '\0') {
          iVar1 = *(int *)(iVar7 + 0x1c + iVar4);
          if ((((local_10 <= iVar1) && (iVar1 <= local_c)) || (*(int *)(iVar7 + 0x50 + iVar4) != 0))
             && (pcVar2 = *(code **)(iVar7 + 0x54 + iVar4), pcVar2 != (code *)0x0)) {
            (*pcVar2)(iVar6);
            iVar4 = DAT_0067ee20;
          }
          if (((iVar3 != 0) && (*(int *)(iVar7 + 0x50 + iVar4) == 0)) &&
             ((iVar1 = *(int *)(iVar7 + 0x1c + iVar4), local_8 <= iVar1 &&
              ((iVar1 <= local_4 &&
               (pcVar2 = *(code **)(iVar7 + 0x54 + iVar4), pcVar2 != (code *)0x0)))))) {
            (*pcVar2)(iVar6);
            iVar4 = DAT_0067ee20;
          }
        }
      }
      iVar6 = iVar6 + 1;
      iVar7 = iVar7 + 0xd0;
    } while (iVar6 <= iVar5);
  }
  FUN_00491d30(param_1,param_2,param_3);
  return;
}

