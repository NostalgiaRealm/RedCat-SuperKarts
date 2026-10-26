/*
 * FUN_00443600 at 00443600
 * undefined FUN_00443600(void)
 * Address ranges: 00443600-0044368d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00443600(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_0053d4d8 == 0) {
    FUN_004afee0(s__s__d____please_call_init_anims___004ee9a0,
                 s_D__work_rcsk_Code_game_Menuanim__004ee97c,0x1e5);
  }
  FUN_004b8350(&DAT_006abb58);
  FUN_004bb690();
  FUN_004bb710(&DAT_004ee6a0,&DAT_004ee5d0);
  uVar1 = FUN_004b9af0(&DAT_0053d348,s_rc_ind_004ee9cc,&DAT_006abb58);
  uVar1 = FUN_004b9af0(&DAT_0053d410,s_rc_img_004ee9d4,uVar1);
  iVar2 = FUN_004b7ee0(uVar1);
  if (iVar2 != 0) {
    FUN_004b8350(&DAT_006abb58);
    return 2000;
  }
  return 0;
}

