/*
 * FUN_00446b80 at 00446b80
 * undefined FUN_00446b80(void)
 * Address ranges: 00446b80-00446be3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_00446b80(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  FUN_00446170();
  if (param_1 < 0x80) {
    iVar1 = FUN_00446170();
    if (0x7f < param_1) {
      FUN_004477c0();
    }
    return (uint)((1 << ((byte)param_1 & 0x1f) & *(uint *)(iVar1 + 0xc + (param_1 >> 5) * 4)) != 0);
  }
  uVar2 = FUN_004afee0(s_Index_out_of_range___s__d__004efb30,
                       s_D__work_rcsk_Code_game_pth_PathC_004efb00,0x260);
  return uVar2 & 0xffffff00;
}

