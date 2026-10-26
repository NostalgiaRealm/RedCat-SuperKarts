/*
 * FUN_0044ccfc at 0044ccfc
 * undefined __register FUN_0044ccfc(int param_1)
 * Address ranges: 0044ccfc-0044cd60
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044ccfc(int param_1)

{
  LPVOID pvVar1;
  int *piVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  undefined4 *local_8;
  
  puStack_14 = &stack0xfffffffc;
  local_8 = (undefined4 *)0x0;
  puStack_18 = &LAB_0044cd61;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  pvVar1 = LockResource(*(HGLOBAL *)(param_1 + 8));
  *(LPVOID *)(param_1 + 0xc) = pvVar1;
  if (pvVar1 == (LPVOID)0x0) {
    FUN_0044cb68(DAT_0047d868,2,(int *)&local_8);
    piVar2 = FUN_0040ac64((int *)&DAT_0044ca4c,'\x01',local_8);
    FUN_00403604(piVar2);
  }
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_0044cd68;
  puStack_18 = (undefined1 *)0x44cd60;
  FUN_00403b50((int *)&local_8);
  return;
}

