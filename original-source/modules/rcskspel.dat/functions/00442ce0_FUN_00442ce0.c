/*
 * FUN_00442ce0 at 00442ce0
 * undefined FUN_00442ce0(void)
 * Address ranges: 00442ce0-00442d6b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00442ce0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_24 [9];
  
  iVar1 = DAT_0053be2c;
  local_24[0] = 0;
  local_24[1] = 1;
  local_24[2] = 2;
  local_24[3] = 3;
  local_24[4] = 4;
  local_24[5] = 5;
  local_24[6] = 6;
  local_24[7] = 5;
  local_24[8] = 6;
  if ((DAT_0053be2c < 0) || (8 < DAT_0053be2c)) {
    FUN_004afee0(s__s___d__Illegal_car__Car_was___d_004edb10,
                 s_D__work_rcsk_Code_game_txt_reml__004edaec,0x3a,DAT_0053be2c);
  }
  iVar2 = iVar1 * 2;
  if (param_1 == 0) {
    iVar2 = iVar1 * 2 + 1;
  }
  FUN_00442a20(local_24[iVar1],iVar2);
  return;
}

