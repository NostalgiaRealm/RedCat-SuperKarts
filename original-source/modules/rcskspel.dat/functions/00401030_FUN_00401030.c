/*
 * FUN_00401030 at 00401030
 * undefined FUN_00401030(void)
 * Address ranges: 00401030-004010dc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00401030(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (param_1 < 0xf) {
    iVar1 = (&DAT_00503ef0)[param_1 * 0x47];
  }
  else {
    FUN_004afee0(s__Out_of_FSM_array_index__Functio_004dd8ef + 1);
    iVar1 = param_1;
  }
  iVar1 = FUN_00414360(iVar1,*param_2,param_2[1],param_2[2]);
  if (200 < iVar1) {
    *(undefined4 *)(&DAT_00503f28 + param_1 * 0x11c) = 0x42c80000;
    return;
  }
  if (iVar1 < -200) {
    *(undefined4 *)(&DAT_00503f28 + param_1 * 0x11c) = 0xc2c80000;
    return;
  }
  *(float *)(&DAT_00503f28 + param_1 * 0x11c) = (float)iVar1 * 0.5;
  return;
}

