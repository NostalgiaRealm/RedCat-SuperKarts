/*
 * FUN_004bbc00 at 004bbc00
 * undefined FUN_004bbc00(void)
 * Address ranges: 004bbc00-004bbc48
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004bbc00(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar1 = *(int *)(DAT_006b5c10 + 8);
  iVar3 = DAT_006b5c10;
  while( true ) {
    if (iVar1 == -1) {
      FUN_004afee0(s__s__d_____get_control_index__win_00502454,
                   s_C__libraries_dxdraw_Forms_cpp_00502310,0x2ef,param_1);
      return -1;
    }
    if (*(int *)(iVar3 + 0x18) == param_1) break;
    iVar1 = *(int *)(iVar3 + 0x24);
    iVar3 = iVar3 + 0x1c;
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}

