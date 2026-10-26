/*
 * FUN_00447210 at 00447210
 * undefined FUN_00447210(void)
 * Address ranges: 00447210-0044728e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00447210(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x10) != -1) {
    *(undefined4 *)(*(int *)(param_1 + 0x10) * 0xd0 + 0x44 + DAT_0067ee20) = 0;
    iVar1 = *(int *)(*(int *)(param_1 + 0x10) * 0xd0 + 0x18 + DAT_0067ee20);
    if (-1 < iVar1) {
      FUN_004afce0(s__s__d____Stopping_dynamic_object_004efc30,
                   s_D__work_rcsk_Code_game_pth_PathC_004efc00,0x342);
      FUN_0049dd20(iVar1);
      FUN_0049d7a0();
      FUN_004afce0(s__s__d____Done_stopping_dynamic_o_004efc8c,
                   s_D__work_rcsk_Code_game_pth_PathC_004efc5c,0x344);
    }
  }
  return;
}

