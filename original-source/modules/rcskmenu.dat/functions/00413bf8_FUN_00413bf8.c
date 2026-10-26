/*
 * FUN_00413bf8 at 00413bf8
 * undefined __register FUN_00413bf8(undefined4 * param_1, int * param_2)
 * Address ranges: 00413bf8-00413c56
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00413bf8(undefined4 *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *local_14;
  undefined1 local_10;
  int local_c;
  undefined1 local_8;
  
  iVar2 = 0;
  FUN_00403b50(param_2);
  if (DAT_0047d61c != (code *)0x0) {
    FUN_00403ba4(param_2,param_1);
    while( true ) {
      iVar1 = (*DAT_0047d61c)(*param_2);
      if (iVar1 == 0) break;
      iVar2 = iVar2 + 1;
      local_10 = 0xb;
      local_8 = 0;
      local_14 = param_1;
      local_c = iVar2;
      FUN_00408a5c((byte *)"%s_%d",&local_14,1,param_2);
    }
  }
  return;
}

