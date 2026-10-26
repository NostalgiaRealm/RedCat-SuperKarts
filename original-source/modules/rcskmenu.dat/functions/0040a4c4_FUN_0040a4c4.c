/*
 * FUN_0040a4c4 at 0040a4c4
 * undefined __register FUN_0040a4c4(LCID param_1, LCTYPE param_2, undefined4 * param_3, int * param_4)
 * Address ranges: 0040a4c4-0040a50d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040a4c4(LCID param_1,LCTYPE param_2,undefined4 *param_3,int *param_4)

{
  int iVar1;
  CHAR local_104 [256];
  
  iVar1 = GetLocaleInfoA(param_1,param_2,local_104,0x100);
  if (iVar1 < 1) {
    FUN_00403ba4(param_4,param_3);
  }
  else {
    FUN_00403c38(param_4,(undefined4 *)local_104,iVar1 - 1);
  }
  return;
}

