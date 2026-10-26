/*
 * FUN_00445800 at 00445800
 * undefined FUN_00445800(void)
 * Address ranges: 00445800-004458b2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00445800(int param_1)

{
  char cVar1;
  int iVar2;
  
  if ((param_1 < 0) || (9 < param_1)) {
    FUN_004afee0(s__s___d__Illegal_index_active_pat_004ef588,
                 s_D__work_rcsk_Code_game_pth_main__004ef564,0x289,param_1);
  }
  param_1 = param_1 * 0x24;
  iVar2 = FUN_00444ba0(*(undefined4 *)(&DAT_0053f514 + param_1));
  iVar2 = (&DAT_0053f668)[iVar2 * 0xd0];
  cVar1 = FUN_00446b80(iVar2);
  if (cVar1 == '\0') {
    if ((iVar2 < 0) || (0xd < iVar2)) {
      FUN_004afee0(s__s___d__Incorrect_path_type___d_004ef5dc,
                   s_D__work_rcsk_Code_game_pth_main__004ef5b8,0x296,iVar2);
    }
    if (*(code **)(&DAT_004ef054 + iVar2 * 0x14) != (code *)0x0) {
      (**(code **)(&DAT_004ef054 + iVar2 * 0x14))(&DAT_0053f4fc + param_1);
      (&DAT_0053f4f8)[param_1] = 0;
      return;
    }
  }
  else {
    FUN_00447210(&DAT_0053f4fc + param_1);
  }
  (&DAT_0053f4f8)[param_1] = 0;
  return;
}

