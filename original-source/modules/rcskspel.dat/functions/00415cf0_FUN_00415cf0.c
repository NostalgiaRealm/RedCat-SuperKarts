/*
 * FUN_00415cf0 at 00415cf0
 * undefined FUN_00415cf0(void)
 * Address ranges: 00415cf0-00415d4d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

float10 FUN_00415cf0(int param_1)

{
  float fVar1;
  float10 fVar2;
  
  if ((param_1 < 0) || (8 < param_1)) {
    FUN_004afee0(s__s___d__Incorrect_index_car____d_004e0d3c,
                 s_D__work_rcsk_Code_game_Car_main__004e0d18,0x150,param_1);
  }
  if (DAT_0053bf00 == 0) {
    fVar1 = *(float *)(&DAT_00506910 + param_1 * 0x7c);
  }
  else {
    fVar1 = *(float *)(&DAT_0050692c + param_1 * 0x7c);
  }
  fVar2 = (float10)fVar1;
  if (DAT_0053bef0 != 0) {
    fVar2 = fVar2 + (float10)4.0;
  }
  return fVar2;
}

