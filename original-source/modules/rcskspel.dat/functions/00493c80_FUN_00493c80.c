/*
 * FUN_00493c80 at 00493c80
 * undefined FUN_00493c80(void)
 * Address ranges: 00493c80-00493ff2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00493c80(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  uint uStack_28;
  uint uStack_24;
  uint uStack_20;
  uint uStack_1c;
  uint uStack_18;
  uint uStack_14;
  uint uStack_10;
  uint uStack_c;
  uint uStack_8;
  uint uStack_4;
  
  uVar1 = param_1;
  iVar3 = FUN_004b96d0(param_1);
  if (iVar3 == 0) {
    FUN_004afee0(s__s__d____File_open_failed_for_fi_004face0,
                 s_D__work_rcsk_Code_Engine_Prog_rd_004fad08,0x49,uVar1);
  }
  FUN_004bf930(&param_1,4,1,iVar3);
  uVar1 = param_1;
  if (DAT_00680aec != 0) {
    if ((DAT_00680aec == 1) &&
       (FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_00680b0d,&DAT_00680af4,
                     DAT_00680ae4), DAT_00680ae0 != (uint *)0x0)) {
      FUN_004945d0(3);
    }
    if (DAT_00680aec != 0) {
      FUN_004bc150(DAT_00680af0);
      DAT_00680aec = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  if ((int)uVar1 < 0) {
    FUN_004afee0(s__s__d____T_ARRAY_construction__i_004de770,
                 s_______Libs_Win3DLib_Include_arra_004fa4c0,0x107,&DAT_00680b0d,&DAT_00680af4,uVar1
                );
  }
  puVar4 = operator_new(uVar1 * 0x50 + 4);
  if (puVar4 == (uint *)0x0) {
    DAT_00680ae0 = (uint *)0x0;
    puVar4 = DAT_00680ae0;
  }
  else {
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
    if (-1 < (int)(uVar1 - 1)) {
      uStack_44 = uVar1;
      do {
        FUN_00494460();
        uStack_44 = uStack_44 - 1;
      } while (uStack_44 != 0);
    }
  }
  DAT_00680ae0 = puVar4;
  DAT_00680ae4 = uVar1;
  DAT_00680ae8 = 0;
  DAT_00680af0 = operator_new(uVar1);
  FUN_004afce0(s_T_ARRAY___alloc___16_16s___16_16_004de744,&DAT_00680b0d,&DAT_00680af4,DAT_00680ae4)
  ;
  DAT_00680aec = 1;
  iVar6 = 0;
  if (0 < (int)uVar1) {
    do {
      iVar5 = iVar6 + 1;
      *(undefined1 *)((int)DAT_00680af0 + iVar6) = 0;
      iVar6 = iVar5;
    } while (iVar5 < (int)uVar1);
  }
  uStack_44 = 0;
  if ((int)param_1 < 1) {
LAB_00493fd3:
    FUN_004b9840(iVar3);
    return;
  }
LAB_00493e07:
  FUN_004bf930(&uStack_2c,4,1,iVar3);
  FUN_004bf930(&uStack_30,4,1,iVar3);
  FUN_004bf930(&uStack_18,4,1,iVar3);
  FUN_004bf930(&uStack_14,4,1,iVar3);
  FUN_004bf930(&uStack_10,4,1,iVar3);
  FUN_004bf930(&uStack_34,4,1,iVar3);
  FUN_004bf930(&uStack_40,4,1,iVar3);
  FUN_004bf930(&uStack_3c,4,1,iVar3);
  FUN_004bf930(&uStack_38,4,1,iVar3);
  uVar2 = uStack_2c;
  uVar1 = uStack_30;
  uStack_24 = uStack_40;
  uStack_1c = uStack_34;
  uStack_28 = uStack_3c;
  uStack_4 = uStack_10;
  uStack_20 = uStack_38;
  uStack_c = uStack_18;
  uStack_8 = uStack_14;
  iVar6 = DAT_00680ae8;
  if (DAT_00680aec == 0) {
    FUN_004afee0(s__s__d____T_ARRAY__get_new__s__d__004de824,
                 s_______Libs_Win3DLib_Include_arra_004fa4c0,0xb9,&DAT_00680af4,DAT_00680ae4,
                 &DAT_00680b0d);
    iVar6 = DAT_00680ae8;
  }
  for (; iVar6 < (int)DAT_00680ae4; iVar6 = iVar6 + 1) {
    if (*(char *)(iVar6 + (int)DAT_00680af0) == '\0') goto LAB_00493fe4;
  }
  iVar6 = 0;
  if (0 < DAT_00680ae8) {
    do {
      if (*(char *)(iVar6 + (int)DAT_00680af0) == '\0') goto LAB_00493fe4;
      iVar6 = iVar6 + 1;
    } while (iVar6 < DAT_00680ae8);
  }
  FUN_004afee0(s__s__d____T_ARRAY__new_array__s_0_004de7d8,
               s_______Libs_Win3DLib_Include_arra_004fa4c0,0xce,&DAT_00680af4,DAT_00680ae4,
               &DAT_00680b0d);
  iVar6 = -1;
  goto LAB_00493f68;
LAB_00493fe4:
  *(undefined1 *)(iVar6 + (int)DAT_00680af0) = 1;
  DAT_00680ae8 = iVar6;
LAB_00493f68:
  FUN_004afce0(s_Loaded_type__d_and_trigger___d_o_004facb0,uVar2,uVar1,iVar6);
  puVar4 = DAT_00680ae0 + iVar6 * 0x14;
  *puVar4 = uVar2;
  puVar4[1] = uVar1;
  puVar4[2] = uStack_c;
  puVar4[3] = uStack_8;
  puVar4[4] = uStack_4;
  puVar4[6] = uStack_28;
  puVar4[7] = uStack_24;
  puVar4[8] = uStack_20;
  puVar4[5] = uStack_1c;
  uStack_44 = uStack_44 + 1;
  if ((int)param_1 <= (int)uStack_44) goto LAB_00493fd3;
  goto LAB_00493e07;
}

