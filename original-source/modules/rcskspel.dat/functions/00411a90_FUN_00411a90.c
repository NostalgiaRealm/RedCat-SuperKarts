/*
 * FUN_00411a90 at 00411a90
 * undefined FUN_00411a90(void)
 * Address ranges: 00411a90-00411b32
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00411a90(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  float fStack00000008;
  
  iVar2 = FUN_0040c900();
  fStack00000008 = (float)iVar2 * 6.0 + 60.0;
  cVar1 = FUN_00417e90(param_1);
  if (cVar1 != '\0') {
    fStack00000008 = fStack00000008 + fStack00000008;
  }
  iVar2 = 2;
  do {
    iVar3 = FUN_004906b0(iVar2);
    if (iVar3 == -1) {
      FUN_004afee0(s__s__d____No_sub_object__004dff58,s_D__work_rcsk_Code_game_Rcr_utils_004dff30,
                   0x52);
    }
    iVar2 = iVar2 + 1;
    *(float *)(DAT_006a5c38 + iVar3 * 0xa9 + 0x60) = fStack00000008;
  } while (iVar2 < 4);
  return;
}

