/*
 * FUN_00472cfc at 00472cfc
 * undefined __register FUN_00472cfc(int param_1)
 * Address ranges: 00472cfc-00472ebd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00472cfc(int param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int *in_FS_OFFSET;
  int iStack_54;
  undefined4 *puVar4;
  int iStack_40;
  undefined1 *puStack_3c;
  undefined1 *puStack_38;
  int iStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  uint *local_20;
  int local_1c [3];
  undefined4 *local_10;
  uint *local_c;
  undefined4 *local_8;
  
  puStack_2c = &stack0xfffffffc;
  puStack_38 = &stack0xfffffffc;
  local_8 = (undefined4 *)0x0;
  local_c = (uint *)0x0;
  local_10 = (undefined4 *)0x0;
  local_1c[2] = 0;
  local_1c[1] = 0;
  local_1c[0] = 0;
  local_20 = (uint *)0x0;
  puStack_30 = &LAB_00472ee0;
  iStack_34 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_34;
  puStack_3c = &LAB_00472ebe;
  iStack_40 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_40;
  bVar1 = FUN_0045a9e0(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80));
  iVar3 = *(int *)(PTR_DAT_0047c8a4 + (bVar1 & 0x7f) * 4);
  if ((*(int *)(param_1 + 0x330) < 0) || (iVar3 < *(int *)(param_1 + 0x330))) {
    FUN_00473204();
    FUN_0045c4c8(0x3b,local_1c + 2);
    FUN_00407f60(iVar3 + 1,local_1c + 1);
    FUN_0045c4c8(0x3c,local_1c);
    iStack_54 = local_1c[0];
    FUN_00403e90((int *)&local_10,5);
    puVar4 = local_10;
    FUN_0045c4f0(0x18,(int *)&local_20);
    FUN_00460df0(local_20,puVar4,4);
  }
  else {
    cVar2 = FUN_004734b4(param_1,PTR_DAT_0047c8a4,extraout_ECX);
    if (cVar2 != '\0') {
      iVar3 = *(int *)(*(int *)PTR_DAT_0047c670 + 0x80);
      FUN_0045aa44(iVar3,CONCAT31((int3)((uint)PTR_DAT_0047c670 >> 8),*(undefined1 *)(iVar3 + 0x25))
                   ,CONCAT31((int3)((uint)extraout_ECX_00 >> 8),*(undefined1 *)(iVar3 + 0x24)),1);
      iVar3 = FUN_00458468(*(int *)(*(int *)PTR_DAT_0047c670 + 0x90));
      if (iVar3 == 999) {
        *(undefined4 *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x14) = 0;
        FUN_00458480(*(int *)(*(int *)PTR_DAT_0047c670 + 0x90),0);
        *(undefined1 *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x26) = 1;
        *(undefined1 *)(param_1 + 0x33c) = 1;
      }
      else {
        *(int *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x14) = iVar3;
        FUN_00458480(*(int *)(*(int *)PTR_DAT_0047c670 + 0x90),iVar3);
        *(undefined1 *)(param_1 + 0x33c) = 0;
        FUN_0045c4c8(0x3d,(int *)&local_8);
        puVar4 = local_8;
        FUN_0045c4f0(0x15,(int *)&local_c);
        FUN_00460df0(local_c,puVar4,4);
      }
    }
  }
  *in_FS_OFFSET = iStack_54;
  return;
}

