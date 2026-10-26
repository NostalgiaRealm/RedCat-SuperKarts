/*
 * FUN_004436e0 at 004436e0
 * undefined FUN_004436e0(void)
 * Address ranges: 004436e0-0044376d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004436e0(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_0053d4d8 == 0) {
    FUN_004afee0(s__s__d____please_call_init_anims___004eea50,
                 s_D__work_rcsk_Code_game_Menuanim__004eea2c,0x1fe);
  }
  FUN_004b8350(&DAT_006abb58);
  FUN_004bb690();
  FUN_004bb710(&DAT_004ee6a0,&DAT_004ee608);
  uVar1 = FUN_004b9af0(&DAT_0053d348,s_rc_ind_004eea7c,&DAT_006abb58);
  uVar1 = FUN_004b9af0(&DAT_0053d410,s_rc_img_004eea84,uVar1);
  iVar2 = FUN_004b7ee0(uVar1);
  if (iVar2 != 0) {
    FUN_004b8350(&DAT_006abb58);
    return 2000;
  }
  return 0;
}

