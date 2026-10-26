/*
 * FUN_004980d0 at 004980d0
 * undefined FUN_004980d0(void)
 * Address ranges: 004980d0-00498279
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004980d0(uint param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  FUN_004afce0(s_Initing_T_ARRAY_for_cameras__004fb380);
  if (DAT_00680bac != 0) {
    if ((DAT_00680bac == 1) &&
       (FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_00680bcd,&DAT_00680bb4,
                     DAT_00680ba4), DAT_00680ba0 != (uint *)0x0)) {
      iVar4 = *(int *)((int)DAT_00680ba0 + -4);
      iVar2 = (int)DAT_00680ba0 + -4;
      if (-1 < iVar4 + -1) {
        do {
          FUN_00405f70();
          FUN_00405f70();
          FUN_00405f70();
          FUN_00405f70();
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      FUN_004bc150(iVar2);
    }
    if (DAT_00680bac != 0) {
      FUN_004bc150(DAT_00680bb0);
      DAT_00680bac = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  if ((int)param_1 < 0) {
    FUN_004afee0(s__s__d____T_ARRAY_construction__i_004de770,
                 s_______Libs_Win3DLib_Include_arra_004fa4c0,0x107,&DAT_00680bcd,&DAT_00680bb4,
                 param_1);
  }
  puVar1 = operator_new(param_1 * 0x178 + 4);
  if (puVar1 == (uint *)0x0) {
    DAT_00680ba0 = (uint *)0x0;
    puVar1 = DAT_00680ba0;
  }
  else {
    *puVar1 = param_1;
    uVar3 = param_1;
    puVar1 = puVar1 + 1;
    if (-1 < (int)(param_1 - 1)) {
      do {
        FUN_00498340();
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
  }
  DAT_00680ba0 = puVar1;
  DAT_00680ba4 = param_1;
  DAT_00680ba8 = 0;
  DAT_00680bb0 = operator_new(param_1);
  FUN_004afce0(s_T_ARRAY___alloc___16_16s___16_16_004de744,&DAT_00680bcd,&DAT_00680bb4,DAT_00680ba4)
  ;
  DAT_00680bac = 1;
  iVar2 = 0;
  if (0 < (int)param_1) {
    do {
      iVar4 = iVar2 + 1;
      *(undefined1 *)((int)DAT_00680bb0 + iVar2) = 0;
      iVar2 = iVar4;
    } while (iVar4 < (int)param_1);
  }
  FUN_004afce0(s_CAMERA___d_cameras_inited__004fb364,param_1);
  return;
}

