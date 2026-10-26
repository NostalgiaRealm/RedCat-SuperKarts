/*
 * FUN_0040ef64 at 0040ef64
 * undefined __register FUN_0040ef64(PVOID param_1)
 * Address ranges: 0040ef64-0040f01b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040ef64(PVOID param_1)

{
  undefined1 *puVar1;
  int *piVar2;
  LPCVOID pvVar3;
  int iVar4;
  undefined4 *in_FS_OFFSET;
  _MEMORY_BASIC_INFORMATION *p_Var5;
  SIZE_T SVar6;
  undefined4 uStack_38;
  undefined1 *puStack_34;
  undefined1 *puStack_30;
  _MEMORY_BASIC_INFORMATION local_20;
  
  puStack_30 = (undefined1 *)0x40ef79;
  piVar2 = (int *)FUN_0040fa70(DAT_0047d624);
  puStack_34 = &LAB_0040f01c;
  uStack_38 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_38;
  iVar4 = piVar2[2] + -1;
  puStack_30 = &stack0xfffffffc;
  puVar1 = &stack0xfffffffc;
  if (-1 < iVar4) {
    do {
      SVar6 = 0x1c;
      p_Var5 = &local_20;
      pvVar3 = (LPCVOID)FUN_0040f6b0(piVar2,iVar4);
      VirtualQuery(pvVar3,p_Var5,SVar6);
      if ((param_1 == (PVOID)0x0) || (param_1 == local_20.AllocationBase)) {
        FUN_0040f550(piVar2,iVar4);
      }
      iVar4 = iVar4 + -1;
      puVar1 = puStack_30;
    } while (iVar4 != -1);
  }
  puStack_30 = puVar1;
  iVar4 = (**(code **)(*DAT_0047d628 + 0x14))();
  iVar4 = iVar4 + -1;
  if (-1 < iVar4) {
    do {
      SVar6 = 0x1c;
      p_Var5 = &local_20;
      pvVar3 = (LPCVOID)(**(code **)(*DAT_0047d628 + 0x18))(DAT_0047d628,iVar4);
      VirtualQuery(pvVar3,p_Var5,SVar6);
      if ((param_1 == (PVOID)0x0) || (param_1 == local_20.AllocationBase)) {
        (**(code **)(*DAT_0047d628 + 0x44))(DAT_0047d628,iVar4);
      }
      iVar4 = iVar4 + -1;
    } while (iVar4 != -1);
  }
  *in_FS_OFFSET = uStack_38;
  puStack_30 = &LAB_0040f023;
  puStack_34 = (undefined1 *)0x40f01b;
  FUN_0040fad4(DAT_0047d624);
  return;
}

