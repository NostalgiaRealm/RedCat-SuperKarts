/*
 * FUN_0044eb50 at 0044eb50
 * undefined FUN_0044eb50(void)
 * Address ranges: 0044eb50-0044eb82
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_0044eb50(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 < -2) {
    if (iVar1 < 0) {
      FUN_004afee0(s___s__Illegal_Loop__d_at_line__d_004f0b88,
                   s_D__work_rcsk_Code_game_msh_MshAn_004f0b60,iVar1,0x10b);
      return 0;
    }
  }
  else if (iVar1 < 0) {
    return -1;
  }
  return iVar1 - *(int *)(param_1 + 0x14);
}

