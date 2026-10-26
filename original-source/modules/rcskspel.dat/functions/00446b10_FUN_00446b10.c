/*
 * FUN_00446b10 at 00446b10
 * undefined FUN_00446b10(void)
 * Address ranges: 00446b10-00446b63
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00446b10(int param_1)

{
  int iVar1;
  
  if ((*(char *)(param_1 + 8) != '\0') && (DAT_005437a4 != 0)) {
    FUN_004afce0(s__s__d____Deleting_CPathControlle_004efadc,
                 s_D__work_rcsk_Code_game_pth_PathC_004efaac,0x23c);
    *(undefined1 *)(param_1 + 8) = 0;
    iVar1 = DAT_005437a4;
    if (DAT_005437a4 != 0) {
      FUN_00446100();
      FUN_004bc150(iVar1);
    }
    DAT_005437a4 = 0;
  }
  return;
}

