/*
 * FUN_00444bd0 at 00444bd0
 * undefined FUN_00444bd0(void)
 * Address ranges: 00444bd0-00444df2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00444bd0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_24;
  CHAR local_20 [32];
  
  wsprintfA(local_20,s_etappe_d_pth_004ef1b0,DAT_0053b9b4);
  iVar1 = FUN_004bf445(local_20,&PTR_DAT_004ef1c0);
  iVar3 = 0;
  if (iVar1 == 0) {
    DAT_00543760 = 0;
    return;
  }
  FUN_004bf930(&local_24,4,1,iVar1);
  if (local_24 != -1) {
    FUN_004afee0(s__s___d__Incorrect_version_path_f_004ef1e8,
                 s_D__work_rcsk_Code_game_pth_main__004ef1c4,0x70,local_24,DAT_0053b9b4);
  }
  FUN_004bf930(&DAT_00543760,4,1,iVar1);
  if (0 < DAT_00543760) {
    do {
      iVar2 = FUN_00444ba0(iVar3,4,1,iVar1);
      FUN_004bf930(&DAT_0053f660 + iVar2 * 0xd0);
      iVar2 = FUN_00444ba0(iVar3,4,1,iVar1);
      FUN_004bf930(&DAT_0053f664 + iVar2 * 0x340);
      iVar2 = FUN_00444ba0(iVar3,4,1,iVar1);
      FUN_004bf930(&DAT_0053f668 + iVar2 * 0xd0);
      iVar2 = FUN_00444ba0(iVar3,4,1,iVar1);
      FUN_004bf930(&DAT_0053f66c + iVar2 * 0xd0);
      iVar2 = FUN_00444ba0(iVar3,4,1,iVar1);
      FUN_004bf930(&DAT_0053f670 + iVar2 * 0x340);
      iVar2 = FUN_00444ba0(iVar3,4,1,iVar1);
      FUN_004bf930(&DAT_0053f674 + iVar2 * 0x340);
      iVar2 = FUN_00444ba0(iVar3);
      if (0x31 < *(int *)(&DAT_0053f674 + iVar2 * 0x340)) {
        iVar2 = FUN_00444ba0(iVar3);
        iVar2 = FUN_00444ba0(iVar3,*(undefined4 *)(&DAT_0053f674 + iVar2 * 0x340));
        FUN_004afee0(s__s___d__Not_enough_memory_alloca_004ef224,iVar3,(&DAT_0053f668)[iVar2 * 0xd0]
                    );
      }
      iVar2 = FUN_00444ba0(iVar3,iVar1);
      iVar2 = FUN_00444ba0(iVar3,0x10,*(undefined4 *)(&DAT_0053f674 + iVar2 * 0x340));
      FUN_004bf930(&DAT_0053f678 + iVar2 * 0x340);
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_00543760);
  }
  return;
}

