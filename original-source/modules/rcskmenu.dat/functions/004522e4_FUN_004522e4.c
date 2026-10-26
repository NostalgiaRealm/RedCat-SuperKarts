/*
 * FUN_004522e4 at 004522e4
 * undefined FUN_004522e4(void)
 * Address ranges: 004522e4-0045237c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004522e4(int *param_1,undefined2 *param_2,int *param_3,undefined4 *param_4)

{
  int *piVar1;
  SIZE_T dwBytes;
  HGLOBAL pvVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  
  *param_2 = 8;
  *param_4 = 0;
  puStack_18 = (undefined1 *)0x452307;
  piVar1 = (int *)FUN_00402e7c((int *)&PTR_FUN_0040e594,'\x01',param_3);
  puStack_1c = &LAB_0045237d;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  puStack_18 = &stack0xfffffffc;
  (**(code **)(*param_1 + 0x44))(param_1,piVar1);
  dwBytes = FUN_004118b0(piVar1);
  pvVar2 = GlobalAlloc(0x42,dwBytes);
  *param_3 = (int)pvVar2;
  if (*param_3 == 0) {
    FUN_0040ac58();
  }
  puVar3 = GlobalLock((HGLOBAL)*param_3);
  uVar4 = FUN_004118b0(piVar1);
  FUN_0040282c((undefined4 *)piVar1[1],puVar3,uVar4);
  GlobalUnlock((HGLOBAL)*param_3);
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_00452384;
  puStack_1c = (undefined1 *)0x45237c;
  FUN_00402eac(piVar1);
  return;
}

