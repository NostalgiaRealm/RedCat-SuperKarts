/*
 * FUN_0044ce98 at 0044ce98
 * undefined __register FUN_0044ce98(int param_1, int param_2, undefined * param_3)
 * Address ranges: 0044ce98-0044cf25
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044ce98(int param_1,int param_2,undefined *param_3)

{
  int *piVar1;
  undefined4 *in_FS_OFFSET;
  bool bVar2;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  undefined4 *local_c;
  int local_8;
  
  puStack_14 = &stack0xfffffffc;
  local_c = (undefined4 *)0x0;
  puStack_18 = &LAB_0044cf43;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  puStack_20 = (undefined1 *)0x44cebd;
  local_8 = param_1;
  FUN_0044cd70(param_1,param_2,param_3);
  puStack_20 = (undefined1 *)0x44cec5;
  FUN_0044ccfc(local_8);
  bVar2 = true;
  puStack_24 = &LAB_0044cf26;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  puStack_20 = &stack0xfffffffc;
  FUN_00402ae4(*(int **)(local_8 + 0xc),(int *)&DAT_0047bae8,4);
  if (!bVar2) {
    FUN_0044cb68(DAT_0047d868,5,(int *)&local_c);
    piVar1 = FUN_0040ac64((int *)&DAT_0044ca4c,'\x01',local_c);
    FUN_00403604(piVar1);
  }
  *in_FS_OFFSET = uStack_28;
  puStack_20 = &LAB_0044cf2d;
  puStack_24 = (undefined1 *)0x44cf25;
  FUN_0044cf50(local_8);
  return;
}

