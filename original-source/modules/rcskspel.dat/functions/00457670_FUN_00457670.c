/*
 * FUN_00457670 at 00457670
 * undefined FUN_00457670(void)
 * Address ranges: 00457670-004576a6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_00457670(int param_1)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = 0;
  if (0 < DAT_00508610 + 1) {
    pcVar2 = (char *)(param_1 + 0xc);
    do {
      if (*pcVar2 == '\0') {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
      pcVar2 = pcVar2 + 0x10;
    } while (iVar1 < DAT_00508610 + 1);
  }
  FUN_004afee0(s__s__d____Could_not_find_a_free_e_004f2338,
               s_D__work_rcsk_Code_game_rcr_bubbl_004f2308,0x50);
  return -1000;
}

