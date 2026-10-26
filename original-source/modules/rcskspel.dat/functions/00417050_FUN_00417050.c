/*
 * FUN_00417050 at 00417050
 * undefined FUN_00417050(void)
 * Address ranges: 00417050-0041709c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00417050(int param_1)

{
  int iVar1;
  
  if (param_1 == DAT_0053be28) {
    return *(undefined4 *)(&DAT_0050815c + DAT_00508610 * 4);
  }
  iVar1 = FUN_00407580(param_1);
  if (iVar1 == -1) {
    FUN_004afee0(s___s___d_Request_for_wheels_on_gr_004e1018,
                 s_D__work_rcsk_Code_game_car_phys__004e0ff4,0x143);
  }
  return *(undefined4 *)(&DAT_0050815c + iVar1 * 4);
}

