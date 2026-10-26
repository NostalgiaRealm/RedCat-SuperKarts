/*
 * FUN_004994f0 at 004994f0
 * undefined FUN_004994f0(void)
 * Address ranges: 004994f0-0049957b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_004994f0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_new__s__d__004de824,
                 s_______Libs_Win3DLib_Include_arra_004fa4c0,0xb9,param_1 + 0x14,
                 *(undefined4 *)(param_1 + 4),param_1 + 0x2d);
  }
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = *(int *)(param_1 + 4);
  if (iVar1 < iVar2) {
    iVar4 = *(int *)(param_1 + 0x10);
    iVar3 = iVar1;
    do {
      if (*(char *)(iVar4 + iVar3) == '\0') goto LAB_00499572;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  iVar3 = 0;
  if (0 < iVar1) {
    iVar4 = *(int *)(param_1 + 0x10);
    do {
      if (*(char *)(iVar4 + iVar3) == '\0') {
LAB_00499572:
        *(undefined1 *)(iVar4 + iVar3) = 1;
        *(int *)(param_1 + 8) = iVar3;
        return iVar3;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  FUN_004afee0(s__s__d____T_ARRAY__new_array__s_0_004de7d8,
               s_______Libs_Win3DLib_Include_arra_004fa4c0,0xce,param_1 + 0x14,iVar2,param_1 + 0x2d)
  ;
  return -1;
}

